#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node* insert(struct node *head,int data){
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=data;
	if(head==NULL){
		ptr->next=NULL;
		return ptr;
	}else{
		struct node *temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		ptr->next=NULL;
		temp->next=ptr;
		return head;
	}
}
struct node *insertAtStart(struct node *head,int data){
	struct node * ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=data;
	ptr->next=head;
	return ptr;
}
int check(struct node *head){
	struct node *temp=head;
	if(temp==NULL) return 1;
	struct node *rev=NULL;
	while(temp!=NULL){
		rev=insertAtStart(rev,temp->data);
		temp=temp->next;
	}
	temp=head;
	struct node * reverse=rev;
	while(temp!=NULL){
		if(temp->data==reverse->data){
			temp=temp->next;
			reverse=reverse->next;
		}
		else{
			return -1;
		}
	}
	return 1;
}
int main(){
	int t;
	scanf("%d",&t);
	struct node *head[t];
	for(int i=0;i<t;i++){
		head[i]=NULL;
		for(int j=0;;j++){
			int data;
			scanf("%d",&data);
			if(data==-1)break;
			head[i]=insert(head[i],data);
		}
	}
	for(int i=0;i<t;i++){
		int ans=check(head[i]);
		if(ans==1){
			printf("true\n");
		}
		else{
			printf("false\n");
		}
	}
}