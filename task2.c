#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(0));
        int     intXsize=10;
        int     intYsize=10;
        char    chrGrid[intXsize][intYsize];

        int	intRobotPositionX=rand()%(intXsize);
        int	intRobotPositionY=rand()%(intYsize); 

	int	intCleaned=0;
	int	intTrash=intXsize*intYsize;

	int	intDirection=0;
	//direction map
	//0:North
	//1:South
	//2:east
	//4:west

	int	intNextPosition=0;
        for(int i=0;i<intXsize;i++){
                for(int j=0;j<intYsize;j++){
                        chrGrid[i][j]='$';
                }
        }
	while(intDirection>4){
		intDirection=rand()%(intXsize);
	}




	while (intCleaned<0.95*intCleaned){
		chrGrid[intRobotPositionX][intRobotPositionY]=' ';
		intDirection=rand()%(intXsize);

		if (intDirection==0){
			if(intRobotPositionY==0){
				break;
			}
			else{
				intRobotPositionY=intRobotPositionY-1;
			}
                if (intDirection==1){
                        if(intRobotPositionY==intSizeY-1){
                                break;
                        }
                        else{
                                intRobotPositionY=intRobotPositionY-1;
                        }
                if (intDirection==2){
                        if(intRobotPositionX==intSizeX-1){
                                break;
                        }
                        else{
                                intRobotPositionX=intRobotPositionX+1;
                        }
                if (intDirection==3){
                        if(intRobotPositionX==0){
                                break;
                        }
                        else{
                                intRobotPositionX=intRobotPositionX-1;
                        }





return 0;
}
