#include<stdio.h>
#include<stdlib.h>
#define MAX_LINE_LENGTH 1024
#define FILENAME "a.txt"
#define LOG_FILE "./logs/system.log"
//#define FILENAME "h:\\webtest\\studyc\\base\\a.txt"

//h/webtest/studyc/base


void setLog(char *str){
	FILE * lp = fopen(LOG_FILE,"a");		
	if(lp == NULL){
   		perror("log file no found");
		exit(EXIT_FAILURE);
	}
	fputs(str,lp);
	fclose(lp);
}


int main(int argc,char *argv[]){

	FILE *input;
	char *filename = argv[1];

	char *tmp,str_buffer[MAX_LINE_LENGTH] ;
	tmp = malloc(MAX_LINE_LENGTH);
	if(tmp == NULL){
		printf("no mem\n");
		exit(0);
	}

	input = fopen(filename,"r");
	if(input == NULL){
		 perror("file no found");
		 exit(EXIT_FAILURE);
	}

	while(fgets(tmp,MAX_LINE_LENGTH,input)){
	  printf("%s",tmp);	
      setLog(str_buffer);	
	}

	
	free(tmp);
	fclose(input);
	return 0;
}
