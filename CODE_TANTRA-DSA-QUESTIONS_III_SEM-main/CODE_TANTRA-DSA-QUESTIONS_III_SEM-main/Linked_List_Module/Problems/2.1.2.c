#include<stdio.h>
#include<stdlib.h>
struct node {
	int data ;
	struct node *pre;
	struct node *next;
};
struct node* insert(struct node* head,int data){
	struct node * ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=data;
	ptr->next=NULL;
	if(head==NULL){
		ptr->pre=NULL;
		return ptr;
	}
	else{
		struct node * temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		ptr->pre=temp;
		temp->next=ptr;
		return head;
	}
}
struct node* delete(struct node* head,int data){
	struct node * temp=head;
	if(temp==NULL){
		free(temp);
		return head;
	}
	while(temp!=NULL && temp->data!=data){
		temp=temp->next;
	}
	if(temp==NULL){
		return head;
	}
	if(temp->pre==NULL){
		head=temp->next;
	}
	else{
		temp->pre->next=temp->next;
	}
	if(temp->next!=NULL){
		temp->next->pre=temp->pre;
	}
	free(temp);
	return head;
}
void display(struct node *head){
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
}
int main(){
	struct node * head=NULL;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,value;
		scanf("%d %d",&a,&value);
		if(a==1){
			head=insert(head,value);
		}
		else if (a==2){
			head=delete(head,value);
		}
	}
	display(head);
} 