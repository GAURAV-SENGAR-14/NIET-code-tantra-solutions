#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("[");
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		if (i<n-1){
		printf("%d, ",arr[i]);
		}
	else{
		printf("%d",arr[i]);
	}
	}
	printf("]\n%d",sum);
} 
