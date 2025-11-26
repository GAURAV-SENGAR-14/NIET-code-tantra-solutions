#include<stdio.h>
int getMax(int arr[],int n){
	int max=arr[0];
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}
int getMin(int arr[],int n){
	int min=arr[0];
	for(int i=0;i<n;i++){
		if(arr[i]<min){
			min=arr[i];
		}
	}
	return min;
}
void countingSort(int arr[],int n,int output[]){
	int max=getMax(arr,n);
	int min=getMin(arr,n);
	int count[max];
	for(int i=min;i<max+1;i++){
		count[i]=0;
	}
	for(int i=0;i<n;i++){
		count[arr[i]]++;
	}
	int index=0;
	for(int i=min;i<max+1;i++){
		if(count[i]!=0){
			for(int j=0;j<count[i];j++){
				output[index++]=i;
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int output[n];
	int elements=0;
	int arr[n];
	for(int i=0;;i++){
		scanf("%d",&arr[i]);
		elements++;
		char c=getchar();
		if(c=='\n'){
			break;
		}
	}
	if(n==elements){
		countingSort(arr,n,output);
		for(int i=0;i<n-1;i++){
			printf("%d ",output[i]);
		}
		printf("%d\n",output[n-1]);
	}
	else{
		printf("-1");
	}
}
