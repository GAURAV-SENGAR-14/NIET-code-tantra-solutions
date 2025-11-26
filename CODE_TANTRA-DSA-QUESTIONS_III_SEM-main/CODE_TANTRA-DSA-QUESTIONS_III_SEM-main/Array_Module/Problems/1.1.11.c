#include<stdio.h>
int position(int arr[],int n,int value){
	int lower_bound=0;
	int upper_bound=n-1;
	while (lower_bound<=upper_bound){
		int middle_point=(lower_bound+upper_bound)/2;
		if (value>arr[middle_point]){
			lower_bound=middle_point+1;
		}
		else if(value<arr[middle_point]){
			upper_bound=middle_point-1;
		}
		else{
			return middle_point;
		}
	}
	return -1;
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int value;
	scanf("%d",&value);
	int index;
	index=position(arr,n,value);
	printf("%d",index);
	
}