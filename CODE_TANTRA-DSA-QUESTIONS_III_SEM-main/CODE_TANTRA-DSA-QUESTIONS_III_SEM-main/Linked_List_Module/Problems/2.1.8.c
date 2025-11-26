#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *insert(struct node *head,int data){
	struct node *ptr=(struct node*)malloc(sizeof(struct node ));
	ptr->data=data;
	ptr->next=NULL;
	if(head==NULL){
		head=ptr;
		return head;
	}
	struct node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=ptr;
	return head;
}
void middle(struct node *ptr,int n){
	int mid=n/2;
	for(int i=0;i<mid;i++){
		ptr=ptr->next;
	}
	printf("%d",ptr->data);
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
	middle(head,n);
}