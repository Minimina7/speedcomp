#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

// Function to translate each assembly instruction to machine code
int translate_instruction(char *instruction) {
    if (strcmp(instruction, "RA=0") == 0) return 0b00001000;
    if (strcmp(instruction, "RB=1") == 0) return 0b00011001;
    if (strcmp(instruction, "RO=RA") == 0) return 0b00100000;
    if (strcmp(instruction, "RB=RA+RB") == 0) return 0b00010000;
    if (strcmp(instruction, "JC=0") == 0) return 0b01110000;
    if (strcmp(instruction, "RA=RA+RB") == 0) return 0b00000000;
    if (strcmp(instruction, "RB=RA-RB") == 0) return 0b00010100;
    if (strcmp(instruction, "RA=RA-RB") == 0) return 0b00000100;
    if (strcmp(instruction, "J=2") == 0) return 0b10110010;
    
    // Return -1 if the instruction is not recognized
    return -1;
}

void assemble(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return;
    }
    
    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return;
    }

    printf("Input file %s opened successfully.\n", input_filename);
    printf("Output file %s opened successfully.\n", output_filename);

    char line[MAX_LINE_LENGTH];
    int line_number = 1;

    while (fgets(line, sizeof(line), input_file)) {
        line[strcspn(line, "\n")] = '\0';  // Remove newline character
        printf("Processing line %d: %s\n", line_number, line);  // Debug output

        int machine_code = translate_instruction(line);
        if (machine_code == -1) {
            fprintf(stderr, "Error: Unknown instruction at line %d: %s\n", line_number, line);
        } else {
            printf("Translated instruction: %s -> Machine Code: %08b\n", line, machine_code);
            fputc(machine_code, output_file);  // Write machine code as a byte to output
            fflush(output_file);  // Ensure the buffer is written immediately
        }
        line_number++;
    }

    printf("Closing files.\n");
    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.asm>\n", argv[0]);
        return 1;
    }

    char output_filename[100];
    snprintf(output_filename, sizeof(output_filename), "%s.bin", strtok(argv[1], "."));
    assemble(argv[1], output_filename);

    return 0;
}
