#include<stdio.h>
int main(){
	int n,value,count;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	scanf("%d",&value);
	count=0;
	for(int i=0;i<n;i++){
		if (value==arr[i]){
			printf("%d",i);
			count++;
			break;
		}
	}
	if (count==0){
		printf("Not found");
	}
}