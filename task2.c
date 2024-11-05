#include <stdio.h>
#include <stdlib.h>

int main(){  


	int intXsize = 20;
	int intYsize = 20;
	char charGrid [intXsize][intYsize];


	for(int i=0 ; i < 40 ; i++){
		printf("=");
	}

	printf("\n               Grid              \n");

	for(int i=0 ; i < 40 ; i++){
                printf("=");
        }
	printf("\n");



	for (int i =0; i<intXsize ; i++ ){
                for (int j =0; j<intYsize; j++){
                        charGrid[i][j] = '*';
                }
        }

	for (int i =0; i<intXsize ; i++ ){
		for (int j =0; j<intYsize; j++){
			printf("%c ", charGrid[i][j]);
		}
		printf("\n");
	}





	for(int i=0 ; i < 40 ; i++){
                printf("=");
        }
	printf("\n");


}
