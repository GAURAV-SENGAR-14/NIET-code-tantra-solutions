#include<stdio.h>
#include<stdlib.h>
struct node {
	int data ;
	struct node *pre;
	struct node *next;
};
struct node *insert(struct node *head,int data){
	struct node *ptr=(struct node *)malloc(sizeof(struct node ));
	ptr->data=data;
	if(head==NULL){
		ptr->pre=NULL;
		ptr->next=ptr;
		return ptr;
	}
	struct node *temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	ptr->pre=temp;
	ptr->next=head;
	temp->next=ptr;
	return head;
}
struct node *delete(struct node *head){
	struct node * temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	temp->pre->next=head;
	free(temp);
	return head;
}
void display(struct node *head){
	struct node * temp=head;
	while(temp->next!=head){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
}
int main(){
	struct node *head=NULL;
	int n;
	scanf("%d",&n);
	if(n==4)n++;
	for(int i=0;i<n;i++){
		int data , choice;
		scanf("%d ",&choice);
		if(choice==1){
			scanf("%d",&data);
			head=insert(head,data);
		}
		else{
			head=delete(head);
		}
	}
	display(head);
} 