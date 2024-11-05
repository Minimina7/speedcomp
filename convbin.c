#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Here is the function to convert assembly instruction to machine code


void check (char *str){
	int start = 0; 
	int end;
	while (isspace ((unsigned char) str[start])) start++;
	end = strlen(str) - 1;
	while (end >= start && isspace ((unsigned char) str[end])) end --;
	memmove(str, str + start, end - start + 1);
	str[end -start + 1] = '\0';
}




void instructions(char *instruction, FILE *fibonacci) {
	if (instruction[0] == ';' || strlen(instruction) == 0){
		return;
	}	

	char *ptr = strtok (instruction, " ");

	if (ptr == NULL){
		return;
	}
    ///////////////////

	if (strcmp(ptr, "RA=RA+RB") == 0){
		fprintf (fibonacci, "00000000\n");
	}
	else if (strcmp(ptr, "RB=RA+RB") == 0){
                fprintf (fibonacci, "00100000\n");
        }
	else if (strcmp(ptr, "RA=RA-RB") == 0){
                fprintf (fibonacci, "00000100\n");
        }
	else if (strcmp(ptr, "RB=RA-RB") == 0){
                fprintf (fibonacci, "00010100\n");
        }
	else if	(strcmp(ptr, "R0=RA") == 0){
                fprintf (fibonacci, "00100000\n");
        }
	else if ((strcmp(ptr, "RA=") == 0) || (strcmp(ptr, "RB=") == 0)|| (strcmp(ptr, "JC=") == 0) || (strcmp(ptr, "J=") == 0)){
		char reg = ptr;
		ptr = strtok (NULL, " ");
		if (ptr == NULL) {
			fprintf (stderr, "Error: the (%s) instruction is invalid \n", reg);   // stder for an error (standard error)
			return;
		}
       

		int immediate = atoi (ptr);   // convert imm to integr
		if (strcmp(reg, "RA=") == 0 && immediate >= 0 && immediate <= 7){
			fprintf(fibonacci.bin, "0001%03s\n", immediate);
		}
		else if (strcmp(reg, "RA=") == 0 && immediate >= 0 && immediate <= 7){
                        fprintf(fibonacci.bin, "0011%03s\n", immediate);
                }
		else if (strcmp(reg, "RA=") == 0 && immediate >= 0 && immediate <= 7){
                        fprintf(fibonacci.bin, "0111%03s\n", immediate);
                }
		else if (strcmp(reg, "RA=") == 0 && immediate >= 0 && immediate <= 7){
                        fprintf(fibonacci.bin, "1011%03s\n", immediate);
                }
		else {
			fprintf(stderr, "Error: the (%s) instruction is invalid \n", reg);   // stder for an error (standard error)
		}
	}
	else {
		fprintf (stderr, "Error: Unknown (%s)\n", ptr);
	}
}
	

///// void assemble_file

void assemble (char *fibonacci){
	FILE *Input = fopen ("fibonacci.asm", "r");
	FILE *Output = fopen ("fibonacci.bin", "w");

	char line[256];

	if (!Input || !Output){
		fprintf(stderr, "Error files");
		return;
	}

	////printf
	int x=1;

	while (fgets(line, sizeof(line), Input)){
		line[strcspn (line, "\n")] = '\0';
		check(line);

		if (strlen(line) == 0 || line [0] == ';'){
			x++;
			continue;
		}
		printf("line %d: %s ->", x, line);
		instructions(line, Output);
	}

//		printf(
		
		fclose(Input);
		fclose(Output);
}


int main (int argc, char *argv[]){

	if (argc != 2){
		fprintf(stderr, "Usage: %s <fibonacci.asm>\n", argv[0]);
		return 1;
	}

	char fibonacci[256];
	snprintf(fibonacci, sizeof(fibonacci), "%s.bin", argv[1]);

	char filename[256] = argv[1] 
	assemble(filename);
	return 0;
}
