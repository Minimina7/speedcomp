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

// Function to read and process the .asm file and write machine code to .bin file

void assemble(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "wb");
    
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open input file %s\n", input_filename);
        return;
    }
    if (output_file == NULL) {
        fprintf(stderr, "Error: Could not open output file %s\n", output_filename);
        fclose(input_file);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 1;

    printf("Starting Assembler...\n");

    while (fgets(line, sizeof(line), input_file)) {
        // Remove newline character at the end
        line[strcspn(line, "\n")] = '\0';
        
        printf("Read line: %s\n", line);  // Debug: print each line read
        
        int machine_code = translate_instruction(line);
        
        if (machine_code == -1) {
            fprintf(stderr, "Error: Unknown instruction at line %d: %s\n", line_number, line);
        } else {
            printf("Translated instruction: %s -> %08b\n", line, machine_code);  // Debug: show translation
            fputc(machine_code, output_file);
        }

        line_number++;
    }

    printf("Successfully generated output file: %s\n", output_filename);

    fclose(input_file);
    fclose(output_file);
}
        


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.asm>\n", argv[0]);
        return 1;
    }

    char output_file[100];
    snprintf(output_file, sizeof(output_file), "%s.bin", strtok(argv[1], "."));

    assemble(argv[1], output_file);

    return 0;
}
