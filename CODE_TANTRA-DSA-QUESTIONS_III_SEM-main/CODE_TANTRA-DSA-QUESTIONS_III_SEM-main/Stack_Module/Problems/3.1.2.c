#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *push(struct node *top,int data){
	struct node *ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=data;
	ptr->next=top;
	return ptr;
}
struct node *pop(struct node *top){
	if(top==NULL)
		return top;
	return top->next;
}
void peek(struct node *top,int *value){
	if(top==NULL)return;
	*value=top->data;
}
void display(struct node *top){
	if(top==NULL){
		printf("Empty\n");
		return;
	}
	while(top->next!=NULL){
		printf("%d->",top->data);
		top=top->next;
	}
	printf("%d\n",top->data);
}
int main(){
	struct node *top=NULL;
	int n,peekvalue=-1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(a==1){
			int data;
			scanf("%d",&data);
			top=push(top,data);
		}
		else if(a==2){
			top=pop(top);
		}
		else{
			peek(top,&peekvalue);
		}
	}
	if(peekvalue!=-1){
		printf("%d\n",peekvalue);
	}
	display(top);
}