#pragma warning(disable:6031)
#pragma warning(disable:4996)
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define LSize 50;
typedef struct SqList {
	int* elem;
	int length;
	int listSize;
}SqList;

void getArray(int arr[], int n) {
	for (int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
	}
}

void initList(SqList& L) {
	L.length = 0;
	L.listSize = LSize;
	L.elem = (int*)malloc(L.listSize * sizeof(int));
}

void createList(SqList& L, int arr[], int n) {
	for (int i = 0;i < n;i++) {
		L.elem[i] = arr[i];
		L.length++;
	}
}
//该方法将A元素全部赋值给C，再将B中的元素从头依次比较插入C中
void mergeListFront(SqList& A, SqList& B, SqList& C) {
	C = A;
	int i = 0, j = 0;
	while (i < C.length && j < B.length) {
		if (C.elem[i] >= B.elem[j]) {
			for (int k = C.length - 1;k >= i;k--) {
				C.elem[k + 1] = C.elem[k];
			}
			C.elem[i] = B.elem[j];
			C.length++;
			j++;
		}
		else {
			i++;
			if (i == C.length&&j!=B.length) {
				for (int k = C.length;k < B.length+A.length;k++) {
					C.elem[k] = B.elem[j];
					C.length++;
					j++;
				}
			}
		}
	}
}

//该方法将A赋值给C，再将B中元素直接尾插入C中，再将C中排序
void mergeListSort(SqList& A, SqList& B, SqList& C) {
	C = A;
	int j = 0;
	for (int i = C.length;i < A.length + B.length;i++) {
		C.elem[i] = B.elem[j];
		j++;
		C.length++;
	}
	for (int i = 0;i < C.length;i++) {
		for (int j = 0;j < C.length - 1 - i;j++) {
			if (C.elem[j] > C.elem[j + 1]) {
				int temp = C.elem[j];
				C.elem[j] = C.elem[j + 1];
				C.elem[j + 1] = temp;
			}
		}
	}
}

void printList(SqList& L) {
	for (int i = 0;i < L.length;i++) {
		printf("%d ", L.elem[i]);
	}
}

int main() {
	SqList La, Lb, Lc;initList(La);initList(Lb);initList(Lc);
	int la[5], lb[5];
	getArray(la, 5);
	getArray(lb, 5);
	createList(La, la, 5);
	createList(Lb, lb, 5);
	mergeListFront(La, Lb, Lc);
	printList(Lc);


}

