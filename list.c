#include <stdio.h>  
#include <stdlib.h>  
  
struct node {  
	int data;  
	struct node *next;  
};  
  
int datas[] = {1, 2, 4, 8, 16, 32, 64, 128};  
  
void list_head_init(struct node *head)  
{  
	head->data = 0;  
	head->next = NULL;  
}  
  
int  list_empty(struct node *head)  
{  
	return head->next == NULL;  
}  
  

  
void list_del(struct node *head)  
{  
	struct node *p = head->next;  
  
	if (list_empty(head)) return;  
  
	head->next = p->next;  
	free(p);  
}  
  
void list_destroy(struct node *head)  
{  
	while (head->next)  
		list_del(head);  
}  
  
void list_create(struct node *head)  
{  
	struct node *new;  
	int i;  
  
	for (i = 0; i < sizeof(datas) / sizeof(datas[0]); i++) {  
		new = (struct node *)malloc(sizeof(struct node));  
		new->data = datas[i];  
		new->next = NULL;  
  
		list_add_tail(new, head);  
	}  
}

void list_add_tail(struct node *new, struct node *head)  
{  
	struct node *p = head;  
  
	while (p->next) {  
		p = p->next;  //给上一个新创建的new指针 的next赋值为传值进来的new
	}  
	p->next = new;  
}    
  
void list_dump(struct node *head)  
{  
	struct node *p = head->next;  
  
	while (p) {  
		printf("%8d", p->data);  
		p = p->next;  
	}  
	printf("\n");  
}  
  
int main(void)  
{  
	struct node root, *head = &root;  
  
	list_head_init(head);  
  
	list_create(head);  
	list_dump(head);  
  
	list_destroy(head);  
  
	return 0;  
}     