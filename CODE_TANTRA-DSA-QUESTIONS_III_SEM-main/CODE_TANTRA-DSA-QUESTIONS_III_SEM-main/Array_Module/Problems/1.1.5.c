#include<stdio.h>
int main(){
	int n,k;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	scanf("%d",&k);
	int count=0;
	for(int i=0;i<n;i++){
		if (arr[i]==k){
			count++;
		}
	}
	printf("%d\n",count);
}