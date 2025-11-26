#include<stdio.h>
int sparseMatrix(int r,int c,int arr[r][c]){
	int zero=0;
	int nonzero=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if (arr[i][j]==0){
				zero++;
			}
			else{
				nonzero++;
			}
		}
	}
	if(zero==(r*c)){
		return -1;
	}
	else if (zero>nonzero){
		return 1;
	}
	else{
		return -1;
	}
}
void printmatrix(int r,int c,int arr[r][c]){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if (arr[i][j]==0){
				continue;
			}
			else{
				printf("%d %d %d\n",i,j,arr[i][j]);
			}
		}
	}
}
int main(){
	int r,c;
	scanf("%d%d",&r,&c);
	int arr[r][c];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int sparseCheck=sparseMatrix(r,c,arr);
	if (sparseCheck==1){
		printmatrix(r,c,arr);
	}
	else{
		printf("-1");
	}
}