#include<stdio.h>
#include<stdlib.h>
struct node {
	int coeff;
	int exp;
	struct node *next;
};
struct node *insert(struct node *head,int coeff,int exp){
	struct node *ptr=(struct node *)malloc(sizeof(struct node));
	ptr->coeff=coeff;
	ptr->exp=exp;
	ptr->next=NULL;
	if(head==NULL){
		return ptr;
	}
	else{
		struct node *temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=ptr;
		return head;
	}
}
struct node *sum(struct node *eq1,struct node *eq2){
	struct node *temp1=eq1;
	struct node *temp2=eq2;
	struct node *temp3=NULL;
	while(1){
		if(temp1!=NULL && temp2!=NULL){
			int exp1=temp1->exp;
			int exp2=temp2->exp;
			if(exp1==exp2){
				int coeff=temp1->coeff+temp2->coeff;
				temp3=insert(temp3,coeff,exp1);
				temp1=temp1->next;
				temp2=temp2->next;
			}
			else if(exp1<exp2){
				temp3=insert(temp3,temp2->coeff,exp2);
				temp2=temp2->next;
			}
			else{
				temp3=insert(temp3,temp1->coeff,exp1);
				temp1=temp1->next;
			}
		}
		if(temp1!=NULL && temp2==NULL){
			temp3=insert(temp3,temp1->coeff,temp1->exp);
			temp1=temp1->next;
		}
		if(temp2!=NULL && temp1==NULL){
			temp3=insert(temp3,temp2->coeff,temp2->exp);
			temp2=temp2->next;
		}
		if(temp1==NULL && temp2==NULL)break;
	}
	return temp3;
}
void display(struct node *head){
	struct node *temp=head;
	while(temp->next!=NULL){
		printf("%dx^%d + ",temp->coeff,temp->exp);
		temp=temp->next;
	}
	printf("%dx^%d\n",temp->coeff,temp->exp);
}
int main(){
	int a,b;
	struct node *eq1=NULL,*eq2=NULL;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		int coeff,exp;
		scanf("%d %d",&coeff,&exp);
		eq1=insert(eq1,coeff,exp);
	}
	scanf("%d",&b);
	for(int i=0;i<b;i++){
		int coeff,exp;
		scanf("%d %d",&coeff,&exp);
		eq2=insert(eq2,coeff,exp);
	}
	struct node *result;
	result=sum(eq1,eq2);
	display(eq1);
	display(eq2);
	display(result);
}