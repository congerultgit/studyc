#include<stdio.h>
#include <stdlib.h>  
#include "stackli.h"
#include "fatal.h"
struct Node;
typedef struct Node *PtrToNode;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X,Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

struct Node{
	ElementType Element;
	PtrToNode Next;

};

int IsEmpty(Stack S){
	return S->Next == NULL;
}

void MakeEmpty(Stack S){
	if(S == NULL){ 
		Error("must use createstack first");
	}
	else{ 
		while(!IsEmpty(S))Pop(S);
	}

}

Stack CreateStack(void){
	Stack S;
	S = malloc(sizeof(struct Node));
	if( S == NULL)FatalError("out of space");
	S->Next == NULL;
	//MakeEmpty(S);
	return S;
}

void Push(ElementType X,Stack S){
	PtrToNode TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if(TmpCell == NULL)FatalError("out of space !!!");
	else{
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;	
	}	

}

ElementType Top(Stack S){

	if(!IsEmpty(S))return S->Next->Element;
	Error("Empty stack");
	return 0;

}

void Pop(Stack S){
	PtrToNode FirstCell; 
	
	if(IsEmpty(S))
		Error("Empty stack");
	else{
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free(FirstCell);
	
	}


}



int main(int argc,char *argv[]){

	int a = 100;
	printf("%d\r\n",a);	
	Stack test = NULL;
	//test = malloc(sizeof(struct Node));
	test = CreateStack();
	Push(1,test);
	Push(2,test);
	//test->Element = 2;
	printf("%d\r\n",test->Element);

	return 0;
}
