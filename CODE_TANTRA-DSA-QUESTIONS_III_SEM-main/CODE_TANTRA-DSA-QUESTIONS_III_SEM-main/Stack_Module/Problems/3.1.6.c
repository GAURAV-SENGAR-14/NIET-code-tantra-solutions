#include<stdio.h>
int binarySearch(int arr[],int value,int n){
	int low=0;
	int high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(value<arr[mid]){
			high=mid-1;
		}
		else if(value>arr[mid]){
			low=mid+1;
		}
		else{
			printf("%d",mid);
			return 0;
		}
	}
	printf("Not found");
	return 0;
}
int main(){
	int n,value;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	scanf("%d",&value);
	binarySearch(arr,value,n);
	return 0;
} 
