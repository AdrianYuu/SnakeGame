#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int main(){
	
	srand(time(NULL));

	int sizeR = 20;
	int sizeC = 20;
	char map[sizeR][sizeC];
	int flag = 0;
	
	int yPos = 8;
	int xPos = 8;
	
	int score = 0;
	
	int yFruit = (rand() % 18) + 1;
	int xFruit = (rand() % 18) + 1;
	
	int yTail[401];
	int xTail[401];
	int nTail = 1;
	
	while(flag == 0){

		system("cls");

		for(int i = 0; i < sizeR; i++){
			for(int j = 0; j < sizeC; j++){
				if(i == 0 || j == 0 || i == (sizeR - 1) || j == (sizeC - 1)){
					map[i][j] = '#';
				} else{
					map[i][j] = ' ';
				}
			}
		}
		
		map[yPos][xPos] = 'O';
		map[yFruit][xFruit] = 'X';
		yTail[0] = yPos;
		xTail[0] = xPos;
		
		if(map[yPos][xPos] == map[yFruit][xFruit]){
			score += 100;
			yFruit = (rand() % 18) + 1;
			xFruit = (rand() % 18) + 1;
			map[yFruit][xFruit] = 'X';
			map[yPos][xPos] = 'O';
			nTail++;
		}
		
		for(int i = 1; i < nTail; i++){
			map[yTail[i]][xTail[i]] = 'o';
		}
		
		for(int i = 0; i < sizeR; i++){
			for(int j = 0; j < sizeC; j++){
				if(i == 14 && j == (sizeC - 1)){	
					printf("%c    Score : %d", map[i][j], score);
				} else {
					printf("%c", map[i][j]);
				}
			}
			printf("\n");
		}
		
		printf("Move [w|a|s|d] : ");
		char command = getch();
		fflush(stdin);
		int cek1 = 1, cek2 = 1;
		
		switch(command){
			case 'w':{
				map[yPos][xPos] = ' ';
				yPos--;
				if(map[yPos][xPos] == '#'){
					cek1 = 0;
					yPos++;
				} else if(map[yPos][xPos] == 'o'){
					flag = 1;
				}
				map[yPos][xPos] = 'O';
				cek2 = 0;
				break;
			}
			
			case 'a':{
				map[yPos][xPos] = ' ';
				xPos--;
				if(map[yPos][xPos] == '#'){
					cek1 = 0;
					xPos++;
				} else if(map[yPos][xPos] =='o'){
					flag = 1;
				}
				map[yPos][xPos] = 'O';
				cek2 = 0;
				break;
			}
			
			case 's':{
				map[yPos][xPos] = ' ';
				yPos++;
				if(map[yPos][xPos] == '#'){
					cek1 = 0;
					yPos--;
				} else if(map[yPos][xPos] == 'o'){
					flag = 1;
				}
				map[yPos][xPos] = 'O';
				cek2 = 0;
				break;
			}
			
			case 'd':{
				map[yPos][xPos] = ' ';
				xPos++;
				if(map[yPos][xPos] == '#'){
					cek1 = 0;
					xPos--;
				} else if(map[yPos][xPos] == 'o'){
					flag = 1;
				}
				map[yPos][xPos] = 'O';
				cek2 = 0;
				break;
			}
		}
		
		if(cek1 == 1 && cek2 == 0){
			for(int i = nTail; i > 0; i--){
				yTail[i] = yTail[i - 1];
				xTail[i] = xTail[i - 1];
			}
		}
	}
	
	system("cls");
	printf("Game Over!\n");
	printf("Your score : %d\n", score);
	
	return 0;
}
