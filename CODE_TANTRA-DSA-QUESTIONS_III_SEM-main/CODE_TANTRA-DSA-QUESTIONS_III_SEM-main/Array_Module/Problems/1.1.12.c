#include<stdio.h>
void selectionSort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		int index=i;
		int small=arr[index];
		for(int j=i+1;j<n;j++){
			if (arr[j]<small){
				small=arr[j];
				index=j;
			}
		}
		int temp=arr[index];
		arr[index]=arr[i];
		arr[i]=temp;
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
	elements=0;
	for(int i=0;;i++){
		scanf("%d",&arr[i]);
		elements++;
		char c;
		scanf("%c",&c);
		if(c=='\n'){
			break;
		}
	}
	if (n==elements){
		selectionSort(arr,n);
	}
	else{
		printf("-1");
	}
}