#include <stdio.h>
#include <stdlib.h>


int main(){
        int     intXsize=10;
        int     intYsize=10;
        char    chrGrid[intXsize][intYsize];

        int intRobotPositionX=rand()%(intXsize);
        int intRobotPositionY=rand()%(intYsize); 






        for(int i=0;i<intXsize;i++){
                for(int j=0;j<intYsize;j++){
                        chrGrid[i][j]='$';
                }
        }


	printf("%d\n",intRobotPositionX);
        printf("%d\n",intRobotPositionY);


return 0;
}
