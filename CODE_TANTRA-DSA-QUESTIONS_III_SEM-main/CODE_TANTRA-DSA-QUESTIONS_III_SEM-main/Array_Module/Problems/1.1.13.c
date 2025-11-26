#include<stdio.h>
void bubbleSort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
			else{
				continue;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(i!=n-1){
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
		else{
			continue;
		}
	}
	if(n==elements){
		bubbleSort(arr,n);
	}
	else{
		printf("-1");
	}
}