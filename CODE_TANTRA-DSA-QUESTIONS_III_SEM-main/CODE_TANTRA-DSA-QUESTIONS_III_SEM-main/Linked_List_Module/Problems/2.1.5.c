#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
struct node* insert(struct node *head,int data){
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=data;
	ptr->next=head;
	return ptr;
}
void display(struct node *temp){
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int main(){
	struct node *head=NULL;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int data;
		scanf("%d",&data);
		head=insert(head,data);
	}
	display(head);
}