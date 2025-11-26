#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *pre;
struct node *next;
};
struct node *insert(struct node *head,int data){
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=data;
	ptr->next=NULL;
	if(head==NULL){
		ptr->pre=NULL;
		return ptr;
	}
	else{
		struct node *temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		ptr->pre=temp;
		temp->next=ptr;
		return head;
	}
}
void display(struct node *head){
	struct node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->pre;
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