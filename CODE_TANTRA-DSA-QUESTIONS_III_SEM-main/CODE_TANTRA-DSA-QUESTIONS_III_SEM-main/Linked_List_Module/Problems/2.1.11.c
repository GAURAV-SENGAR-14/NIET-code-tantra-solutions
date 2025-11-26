#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *insert(struct node *head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}
int main(){
    struct node *head=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        head=insert(head,a);
    }
    int n1;
    scanf("%d",&n1);
    if(n1!=0){
        printf("True\n");
    }else{
        printf("False\n");
	}
}