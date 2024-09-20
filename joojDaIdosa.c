#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	int bankCount = 0;
	int bankSize = 1;

	char stringBank[16000][9];

int checkNumDots(char * input){
    int i ;
    int dots = 0;
	for(i=0;i<9;++i) {
	    if(input[i] == '.') {
	        dots +=1;
	    }
	}
	
	if(dots%2 != 0) return 0;
	else return 1;
}
int checkEnd(char * input){
	if(input[0] != '.' && input[0] == input[1] && input[2] == input[1]) return 1;// primeira linha

	else if(input[3] != '.' && input[3] == input[4] && input[5] == input[4]) return 1;// segunda linha

	else if(input[6] != '.' && input[6] == input[7] && input[8] == input[7]) return 1;// terceira linha

	else if(input[0] != '.' && input[0] == input[3] && input[6] == input[3]) return 1;// primeira coluna

	else if(input[1] != '.' && input[1] == input[4] && input[7] == input[4]) return 1;// segunda coluna

	else if(input[2] != '.' && input[2] == input[5] && input[8] == input[5]) return 1;// terceira coluna

	else if(input[0] != '.' && input[0] == input[4] && input[8] == input[4]) return 1;// diagonal principal

	else if(input[2] != '.' && input[2] == input[4] && input[6] == input[4]) return 1;// diagonal secundária

	else return 0;
}

void generateNodes(char * input, int next){ //next define se insere X ou O
	int i ;
	for(i=0;i<9;++i) {
		if(input[i] == '.') {
			bankSize+=1;
			memcpy(stringBank[bankSize-1],input,9);
			if(!next) stringBank[bankSize-1][i] = 'X';
			else  stringBank[bankSize-1][i] = 'O';
			//
			char printable[10];
			memcpy(printable,input,9);
			printable[9] = '\0';
			//printf("%s -> %s %d\n",printable,stringBank[bankSize-1],checkEnd(stringBank[bankSize-1]));
			printf("\"%s\" -> \"%s\";\n",printable,stringBank[bankSize-1]);

		}
	}
}

void main () {
	

	char start[9] = "O......X.";

	memcpy(stringBank[0],start,9);
	printf("digraph velha {\n");
	int next = 0; //se for 0 é X
				  //senão é O

	while (bankCount <= bankSize) {
		if(!checkEnd(stringBank[bankCount])) { //se não é um vértice folha
		    next = checkNumDots(stringBank[bankCount]);
			generateNodes(stringBank[bankCount],next); //gera novos nodos
			
			
			
		}
		++bankCount;

	}
	printf("}");



}
