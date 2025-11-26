#include<stdio.h>
void insertionSort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		int element=arr[i+1];
		int j=i;
		while(j>=0 && element<arr[j]){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=element;
	}
	for(int i=0;i<n;i++){
		if (i!=n-1){
			printf("%d ",arr[i]);
		}
		else{
			printf("%d",arr[i]);
		}
	}
}
int main(){
	int n,elements;
	scanf("%d",&n);
	int arr[n];
	char c;
	elements=0;
	for(int i=0;c!='\n';i++){
		scanf("%d",&arr[i]);
		elements++;
		c=getchar();
	}
	if(n==elements){
		insertionSort(arr,n);
	}
	else{
		printf("-1");
	}
}