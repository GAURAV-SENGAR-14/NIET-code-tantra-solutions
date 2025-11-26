#include<stdio.h>
int sparseMatrix(int r,int c,int arr[r][c]);
void printMatrix(int r,int c,int arr[r][c]);
int main(){
	int r,c;
	scanf("%d%d",&r,&c);
	int arr[r][c];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int sparseTest=sparseMatrix(r,c,arr);
	if (sparseTest==1){
		printf("True\n");
		printMatrix(r,c,arr);
	}
	else{
		printf("False");
	}
}
int sparseMatrix(int r,int c,int arr[r][c]){
	int count=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(arr[i][j]==0){
				count++;
			}
			else{
				continue;
			}
		}
	}
	if(count>(r*c/2)){
		return 1;
	}
	else{
		return 0;
	}
}
void printMatrix(int r,int c,int arr[r][c]){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if (arr[i][j]!=0){
				printf("%d %d %d\n",i,j,arr[i][j]);
			}
		}
	}
}