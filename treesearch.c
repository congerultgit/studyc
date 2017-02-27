
#include <stdlib.h>
#include "fatal.h"
/*
Binary Sort Tree 二叉排序树 
Binary Search Tree  二叉搜索树
*/


typedef int ElementType;


#ifndef _Tree_H
#define _Tree_H
#endif  


typedef struct TreeNode *Position;
//指向结构体的指针 searchTree
typedef struct TreeNode *SearchTree;
//实际结构体 树形结构体
struct TreeNode
{
    ElementType Element;
    SearchTree  Left;
    SearchTree  Right;
};
SearchTree MakeEmpty( SearchTree T );
Position Find( ElementType X, SearchTree T );
Position FindMin( SearchTree T );
Position FindMax( SearchTree T );
SearchTree Insert( ElementType X, SearchTree T );
SearchTree Delete( ElementType X, SearchTree T );
//
ElementType Retrieve( Position P );







SearchTree MakeEmpty( SearchTree T )
{
            if( T != NULL )
            {
                MakeEmpty( T->Left );
                MakeEmpty( T->Right );
                free( T );
            }
            return NULL;
}


Position Find( ElementType X, SearchTree T )
        {
            if( T == NULL )
                return NULL;
            if( X < T->Element )
                return Find( X, T->Left );
            else
            if( X > T->Element )
                return Find( X, T->Right );
            else
                return T;
        }



Position FindMin( SearchTree T )
        {
            if( T == NULL )
                return NULL;
            else
            if( T->Left == NULL )
                return T;
            else
                return FindMin( T->Left );
        }



Position FindMax( SearchTree T )
        {
            if( T != NULL )
                while( T->Right != NULL )
                    T = T->Right;

            return T;
        }


/*
elementType x 整形 数字 1
searchTree T  指向treeNode的指针
当指针T为空是 初始化对应结构,  左右子树，指针为空 ,当前节点

 
 
 
*/
SearchTree Insert( ElementType X, SearchTree T ){
    if( T == NULL )
    {
        /* Create and return a one-node tree */
	  	T = malloc( sizeof( struct TreeNode ) );
	  	if( T == NULL ){
	      FatalError( "Out of space!!!" );
	    }else{
	     T->Element = X;
	      T->Left = T->Right = NULL;
	    }
	/*
	如果X小于当前 节点的值 ,left小
	使用left指针，继续插入
	 */    
    }else if( X < T->Element ){
         T->Left = Insert( X, T->Left );
    }else{
    	/*
    	如果X大于当前节点的值，right大,始终向右插入
    	 */
     	if( X > T->Element )T->Right = Insert( X, T->Right );
    }
            /* Else X is in the tree already; we'll do nothing */

     return T;  /* Do not forget this line!! */
}
/* END */


SearchTree Delete( ElementType X, SearchTree T )
        {
            Position TmpCell;

            if( T == NULL )
                Error( "Element not found" );
            else
            if( X < T->Element )  /* Go left */
                T->Left = Delete( X, T->Left );
            else
            if( X > T->Element )  /* Go right */
                T->Right = Delete( X, T->Right );
            else  /* Found element to be deleted */
            if( T->Left && T->Right )  /* Two children */
            {
                /* Replace with smallest in right subtree */
                TmpCell = FindMin( T->Right );
                T->Element = TmpCell->Element;
                T->Right = Delete( T->Element, T->Right );
            }
            else  /* One or zero children */
            {
                TmpCell = T;
                if( T->Left == NULL ) /* Also handles 0 children */
                    T = T->Right;
                else if( T->Right == NULL )
                    T = T->Left;
                free( TmpCell );
            }

            return T;
        }


ElementType Retrieve( Position P )
{
            return P->Element;
}

int main(int argc,char *argv[]){

	struct TreeNode *newtree,*point;
	int a;
	newtree = Insert(1,NULL);
	newtree = Insert(5,newtree);
	newtree = Insert(9,newtree);
	newtree = Insert(6,newtree );
	point = FindMax(newtree);
	printf("%d\n",point->Element);
	//printf("hello world\n");
	return 0;
}

