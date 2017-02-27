#include<stdio.h>

// force use once,init variablie-list
   struct{
        char *name;  //姓名
        int num;  //学号
        int age;  //年龄
        char group;  //所在小组
        float score;  //成绩
    } structType1Var;
   
  // can use more times,not init variable-list 
  struct moreTimes   {
        char *name;  //姓名
        int num;  //学号
        int age;  //年龄
        char group;  //所在小组
        float score;  //成绩
  };
   
   // can use more times,can init variable-list 
  struct moreTimesVar   {
        char *name;  //姓名
        int num;  //学号
        int age;  //年龄
        char group;  //所在小组
        float score;  //成绩
  }structType3Var;
   
struct moreTimes initStruct2(struct moreTimes type2){
    type2.name = "Tom";
    type2.num = 12;
    type2.age = 18;
    type2.group = 'B';
    type2.score = 136.5;
    return type2;
}
typedef struct {

   char *name;
   char *month;

}personInfo;


void output(struct moreTimes stu1){
   printf("%s的学号是%d，年龄是%d，在%c组，今年的成绩是%.1f！\n", stu1.name, stu1.num, stu1.age, stu1.group, stu1.score);
   //printf("%s的学号是%d，年龄是%d，在%c组，今年的成绩是%.1f！\n", (*p1).name, p1->num, p1->age, p1->group, p1->score);

}


void outputPerson(personInfo * p){
   printf("%s的出生月份为%s\n",p->name,p->month);

}






int main(int argc,char *argv[]){

   
   
     struct  moreTimes stu1;
     struct  moreTimes * p1;
     struct  moreTimesVar v1;
     //stu1 = initStruct2(stu1);
     //output(stu1);
     personInfo test,*testPoint;
     int i = 1;
     while(*++argv != NULL){
	 if(i==1){
	    test.name = *argv;
	 }
	 if(i==2){
	    test.month = *argv;
	 }

         printf("%s is input \n",*argv);
	 i++;
     }

     testPoint = &test;
     outputPerson(testPoint);





     return 0;
}
