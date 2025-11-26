#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxArrSize 100000


int fibonacciNumbers(int N, int *resultsArr) {
	resultsArr[0]=0;
	resultsArr[1]=1;
	int count=2;
	for(int i=2;resultsArr[i-1]<=N;i++){
		resultsArr[i]=resultsArr[i-1]+resultsArr[i-2];
		count++;
	}
	return count-1;
}

void printArrayElements(int *resultsArr, int resultsArrLength) {
	int index;
	for(index = 0; index < resultsArrLength - 1; index++) {
		printf("%d,", resultsArr[index]);
 	}
	printf("%d\n", resultsArr[index]);
}

int main(int argc, char *argv[]) {
	int N = atoi(argv[1]);
	int resultsArr[MaxArrSize];
	int resultsArrLength = fibonacciNumbers(N, resultsArr);
	printArrayElements(resultsArr, resultsArrLength);
	return 0;
}