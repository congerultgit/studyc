#include<stdio.h>
#include <string.h>
#include "struct.h"
#include <stdlib.h>
person * perPoint = NULL;
person * initPerson(person * per,char **info){ 
	per->name = info[0];
	per->birthday = (int)info[1];
	per->qq = info[2];
	per->phone = info[3];
	per->other = info[4];
	return per;

}

void showPerson(person * per){
  printf("name is %s  \n",per->name);
  printf("birthday is %s  \n",per->birthday);
  printf("qq is %s  \n",per->qq);
  printf("phone is %s  \n",per->phone);
  printf("other is %s  \n",per->other);
}

void t(){
  printf("test go on \n");
}



void initModel(int argc,char *argv[]){
	perPoint = malloc(200);
	
	char *commond = argv[1];



	if( strcmp(argv[1],"set")==0){
          perPoint->name = argv[2];
	  perPoint->birthday = (int)argv[3];
	  perPoint->qq = argv[4];
	  perPoint->phone = argv[5];
	  perPoint->other = argv[6];
	  showPerson(perPoint);
	}
	free(perPoint);

       
}


/*
get user intput, save into a file
-name search the name info
printf("%s is input \n",*argv);

*/
int main(int argc,char *argv[]){

     char ** commond = argv; 

     char *option = "--help";

     option = commond[1];

     if(strcmp(option,"set")==0){ 
	initModel(argc,argv);      	
     
     }else if(strcmp(option,"get")==0){
     	initModel(argc,argv);  
     
     }else{
     	printf("option %s is no found",option);
     
     }

     return 0;
}
