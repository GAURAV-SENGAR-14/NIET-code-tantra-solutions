#include<stdio.h>
void shellSort(int arr[],int n);
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	int elements=0;
	for(int i=0;;i++){
		scanf("%d",&arr[i]);
		elements++;
		char c=getchar();
		if(c=='\n'){
			break;
		}
	}
	if(n==elements){
		shellSort(arr,n);
		int i;
		for(i=0;i<n-1;i++){
			printf("%d ",arr[i]);
		}
		printf("%d",arr[i]);
	}
	else{
		printf("-1");
	}
}
void shellSort(int arr[],int n){
	for(int gap=n/2;gap>0;gap/=2){
		for(int i=gap;i<n;i++){
			int temp=arr[i];
			int j;
			for(j=i;j>=gap && arr[j-gap]>temp;j-=gap){
				arr[j]=arr[j-gap];
			}
			arr[j]=temp;
		}
	}
}