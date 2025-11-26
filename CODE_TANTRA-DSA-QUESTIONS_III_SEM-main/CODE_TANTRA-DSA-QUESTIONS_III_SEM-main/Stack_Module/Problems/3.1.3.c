#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#define max 100
typedef struct {
	char data[max];
	int top;
} Stack;
void push(Stack *s,char c){
	s->data[++(s->top)]=c;
}
char pop (Stack *s){
	return s->data[(s->top)--];
}
char peek(Stack *s){
	return s->data[s->top];
}
int isEmpty(Stack *s){
	return s->top==-1;
}
int precedence(char c){
	switch(c){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return 0;
	}
}
char * InfixToPostfix(char *expr) {
	// Write code here
	Stack s;
	s.top=-1;
	int len = strlen(expr);
	char *postfix = (char *)malloc(sizeof(char)*(len+1));
	int k=0;
	for(int i=0;i<len;i++){
		if(isalnum(expr[i])){
			postfix[k++]=expr[i];
		}else if(expr[i]=='('){
			push(&s,expr[i]);
		}else if(expr[i]==')'){
			while(!isEmpty(&s) && peek(&s) !='('){
			postfix[k++]=pop(&s);
			}
			pop(&s);
		}else{
			while(!isEmpty(&s) && precedence(peek(&s)) >=precedence(expr[i])){
				postfix[k++]=pop(&s);
			}
			push(&s,expr[i]);
		}
	}
	while(!isEmpty(&s)){
		postfix[k++]=pop(&s);
	}
	postfix[k]='\0';
	return postfix;
}
int main(int argc, char *argv[]) {
	char *expr = argv[1];
	printf("%s\n", InfixToPostfix(expr));
	return 0;
}