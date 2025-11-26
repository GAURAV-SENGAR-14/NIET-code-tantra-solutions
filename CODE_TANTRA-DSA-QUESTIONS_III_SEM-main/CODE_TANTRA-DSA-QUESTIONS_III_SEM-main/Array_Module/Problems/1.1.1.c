#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("[");
	for(int i=0;i<n;i++){
		if (i<n-1){
		printf("%d, ",arr[i]);
		}
		else{
			printf("%d]\n",arr[i]);
		}
	}
	for(int i=0;i<n-1;i++){
		if (arr[i]<=arr[i+1]){
			int temp = arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=temp;
			i=-1;
		}
	}
	printf("%d",arr[0]);
}
