#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
struct node *insert(struct node *head,int data){
	struct node *ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=data;
	if(head==NULL){
		ptr->next=ptr;
		return ptr;
	}
	else{
		struct node *temp=head;
		while(temp->next!=head){
			temp=temp->next;
		}
		ptr->next=head;
		temp->next=ptr;
		return head;
	}
}
struct node *delete(struct node *head,int data){
	struct node *temp=head,*pre=NULL;
	if(temp->data==data){
		if(temp->next==head){
			free(temp);
			return head;
		}
		else{
            pre=temp->next;
			while(temp->next!=head){
				temp=temp->next;
			}
			temp->next=pre;
			return pre;
		}
	}
	while(temp->next!=head && temp->data!=data){
		pre=temp;
		temp=temp->next;
	}
	if(temp->data==data){
		pre->next=temp->next;
	}
	return head;
}
void display(struct node *head){
	struct node *temp=head;
	if(temp==NULL)return ;
	do{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=head);
}
int main(){
    int n;
	struct node *head=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int data;
		int choice;
		scanf("%d %d",&choice,&data);
		if(choice==1){
			head=insert(head,data);
		}else{
			head=delete(head,data);
		}
	}
	display(head);
}