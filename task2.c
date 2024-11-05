#include <stdio.h>
#include <stdlib.h>


int main(){
        int     intXsize=10;
        int     intYsize=10;
        char    chrGrid[intXsize][intYsize];

        int intRobotPositionX=rand()%(intXsize);
        int intRobotPositionY=rand()%(intYsize); 

	int intCleaned=0;
	int intTrash=intXsize*intYsize;

        for(int i=0;i<intXsize;i++){
                for(int j=0;j<intYsize;j++){
                        chrGrid[i][j]='$';
                }
        }
	while (intCleaned<0.95*int



return 0;
}
