#include<stdio.h>
void push(int stack[],int data,int *top){
	stack[++(*top)]=data;
}
void pop(int *top){
	if(*top!=-1)
		(*top)--;
}
void peek(int stack[],int *value,int top){
	if(top!=-1)
		*value=stack[top];
	else
		*value=-1;
}
void display(int stack[],int top){
	if(top==-1){
		printf("Empty\n");
		return;
	}
	while(top!=0)
		printf("%d ",stack[top--]);
	printf("%d\n",stack[top--]);
}
int main(){
	int stack[100];
	int n,top=-1,peekvalue,count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(a==1){
			int data;
			scanf("%d",&data);
			push(stack,data,&top);
		}
		else if(a==2){
			pop(&top);
		}else{
			peek(stack,&peekvalue,top);
			count++;
		}
	}
	if(count!=0 && peekvalue!=-1)
		printf("%d\n",peekvalue);
	display(stack,top);
}
