#pragma warning(disable:6031)
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//comlpex ������������
/*
struct complex {
	double realpart;
	double imagpart;
};
void InitComplex(complex &C, double x, double y) {//��ʼ�����츴��
	C.realpart = x;
	C.imagpart = y;
}
double GetReal(complex C) {
	return C.realpart;
}
double GetImag(complex C) {
	return C.imagpart;
}
complex add(complex C1, complex C2) {//�����ӷ�
	complex Sum;
	Sum.realpart = C1.realpart + C2.realpart;
	Sum.imagpart = C1.imagpart + C2.imagpart;
	return Sum;
}
complex sub(complex C1, complex C2) {//��������
	complex Sum;
	Sum.realpart = C1.realpart - C2.realpart;
	Sum.imagpart = C1.imagpart - C2.imagpart;
	return Sum;
}
complex mul(complex C1, complex C2) {//�����˷�
	complex Sum;
	Sum.realpart = (C1.realpart * C2.realpart - C1.imagpart * C2.imagpart);
	Sum.imagpart = (C1.imagpart * C2.realpart + C1.realpart * C2.imagpart);
	return Sum;
}
complex div(complex C1, complex C2) {//��������
	complex Sum;
	Sum.realpart = (C1.realpart * C2.realpart + C1.imagpart * C2.imagpart) / (C2.realpart * C2.realpart + C2.imagpart * C2.imagpart);
	Sum.imagpart = (C1.imagpart * C2.realpart - C1.realpart * C2.imagpart) / (C2.realpart * C2.realpart + C2.imagpart * C2.imagpart);
	return Sum;
}
int main() {
	complex C1, C2, C_add,C_sub,C_mul,C_div;double X1, X2, Y1, Y2;//X1��Y1��C1��ʵ���鲿��X2,Y2��C2��ʵ���鲿
	printf("������C1��ʵ�����鲿��");
	scanf("%lf%lf", &X1, &Y1);//����C1����
	printf("������C2��ʵ�����鲿��");
	scanf("%lf%lf", &X2, &Y2);//����C2����
	InitComplex(C1, X1, Y1);//��ʼ����ֵ����ʵ��X1�鲿Y1��ֵ��complex���C1
	InitComplex(C2, X2, Y2);//��ʼ����ֵ����ʵ��X2�鲿Y2��ֵ��complex���C2
	C_add = add(C1, C2);
	C_sub = sub(C1, C2);
	C_mul = mul(C1, C2);
	C_div = div(C1, C2);
	printf("���������ĺ���:%lf+%lfi\n",GetReal(C_add),GetImag(C_add));//����ʵ�����鲿�����
	printf("���������Ĳ���:%lf+%lfi\n", GetReal(C_sub), GetImag(C_sub));
	printf("���������Ļ���:%lf+%lfi\n", GetReal(C_mul), GetImag(C_mul));
	printf("��������������:%lf+%lfi\n", GetReal(C_div), GetImag(C_div));
} 
*/

//ð������
/*
int main() {
	int arr[10];
	printf("�����������:");
	for (int i = 1;i <= 5;i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1;i <= 5;i++) {
		for (int j = 1;j <= 5-i;j++) {
			if (arr[j] < arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	for (int i = 1;i <= 5;i++) {
		printf("%d ", arr[i]);
	}
}
*/

//ѡ������
/*
int main() {
	int arr[10];
	printf("�������������");
	for (int i = 1;i <= 5;i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1;i <= 5;i++) {
		int min = i;//min����С��λ�õı�־
		for (int j = i + 1;j <= 5;j++) {
			if (arr[j] < arr[min]) {
				min = j;//���jλ�õ�����iλ�õ���С�����¸���min��־
			}
		}
		if (min != i) {//���������������min��־����Сֵ��i���и���
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
	printf("���������ǣ�");
	for (int i = 1;i <= 5;i++) {
		printf("%d", arr[i]);
	}
}
*/

//���Ա���ɾ���
/*
typedef struct  {
	int* elem;//�洢�ռ��ַ
	int length;//��ǰ����
	int listsize;//��ǰ����Ĵ洢����
}SqList;
void InitList(SqList& L) {
	L.elem = (int*)malloc(50*sizeof(int));//��ʼ������50��int�ռ�
	L.length = 0;
	L.listsize = 50;
}
void CreateList(SqList& L) {
	for (int i = 0;i < 6;i++) {
		scanf("%d", &L.elem[i]);
		L.length++;
	}
}
void PrintList(SqList& L) {
	for (int i = 0;i < L.length;i++) {
		printf("%d ", L.elem[i]);
	}
	printf("\n��ǰ��:%d��Ԫ��\n", L.length);
}
void InsertList(SqList& L) {
	int n, input;
	printf("�ڵڼ�λ������ʲô����\n");
	scanf("%d%d", &n, &input);
	for (int i = L.length;i >= n;i--) {
		L.elem[i] = L.elem[i - 1];
	}
	L.elem[n - 1] = input;
	L.length++;
}
void DeleteList(SqList& L) {
	int n,i;
	printf("ɾ���ڼ�λ����\n");
	scanf("%d", &n);
	for (i = n - 1;i < L.length-1;i++) {
		L.elem[i] = L.elem[i + 1];
	}
	L.length--;
}
void LocationList(SqList& L,int number) {
	int i;
	for (i = 0;i < L.length;i++) {
		if (L.elem[i] == number) { 	
			printf("�ڵ�%dλ", i + 1); 
			break;
		}
	}
	if (i == L.length) printf("0");
}
void ModifyList(SqList& L, int n, int number) {
	L.elem[n - 1] = number;
}
int main() {
	SqList L;
	InitList(L);
	CreateList(L);
	ModifyList(L, 4,10); 
	PrintList(L);
}
*/

//���Ա�������ϰ
/*
typedef struct {
	int* elem;
	int length;
	int listSize;
}SqList;
//���鸳ֵ
void initArray(int arr[], int n) {
	for (int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
	}
}
//��ʼ�����Ա�
void initList(SqList& L) {
	L.length = 0;
	L.listSize = 50;
	L.elem = (int*)malloc(L.listSize * sizeof(int));
}
//�����Ա������е�ֵ
void createList(SqList& L,int arr[], int n) {
	for (int i = 0;i < n;i++) {
		L.elem[i]=arr[i];
		L.length++;
	}
}
//�õ�����i��ֵ
int getList(SqList& L, int i) {
	return L.elem[i - 1];
}
//��ӡ���Ա�
void printList(SqList& L) {
	for (int i = 0;i < L.length;i++) {
		printf("%d ", L.elem[i]);
	}
}
//���Ա����ֵ���ҳ���+1
void insertList(SqList& L,int n,int input) {
	for (int i = L.length;i >= n;i--) {
		L.elem[i] = L.elem[i - 1];
	}
	L.elem[n] = input;
	L.length++;
}
//�÷������½�C��=A��-B��
void getNewList_Sub(SqList& A,SqList& B,SqList& C){
	for (int i = 0;i < A.length;i++) {
		C.elem[i] = A.elem[i] - B.elem[i];
		C.length++;
	}
}
//�÷����ǽ�B����A����,��A��B���Ϊ����
void listBtoA(SqList& A, SqList& B) {
	int i = 0;
	int increment = 0;//���ڼ�¼A�����ӳ���ʱ������
	int flag = 0;
	while (flag!=5) {
		if (B.elem[i] < A.elem[i+increment]) {
			insertList(A, i+increment, B.elem[i]);
			flag++;
			increment++;
		}else{
			insertList(A, i + 1+increment, B.elem[i]);
			flag++;
			increment++;
		}
		i++;
	}
}
int main() {
	SqList ListA, ListB, ListC;
	int A[5], B[5];
	initArray(A, 5);initArray(B, 5);
	initList(ListA);initList(ListB);initList(ListC);
	createList(ListA, A, 5);createList(ListB, B, 5);
	getNewList_Sub(ListA, ListB, ListC);
	printList(ListC);
	listBtoA(ListA, ListB);
	printList(ListA);
}
*/

//����nums������0��n��������������������ȱ��һ����������дȱʧ����������O(n)ʱ�������
/*
int main() {
	int nums[] = { 3,0,5,1,2 };
	int arr[6];
	int numsSize = sizeof(nums) / sizeof(int);
	for (int i = 0;i <= numsSize;i++) {
		arr[i] = i;
	}
	int a = 0;
	for (int i = 0;i < numsSize;i++) {
		a = a ^ nums[i];
	}
	for (int i = 0;i <= numsSize;i++) {
		a = a ^ arr[i];
	}
	printf("%d\n", a);
}
*/
 


typedef struct SListNode {
	int data;
	struct SListNode* next;
}SListNode;

SListNode* createSListNode(int x) {
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL) {
		printf("����ʧ��");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void insertSListBack(SListNode** pphead, int x) {
	SListNode* newNode = createSListNode(x);
	if (*pphead == NULL) {
		*pphead = newNode;
	}
	else {
		SListNode* cur = *pphead;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

void delSListBack(SListNode** pphead) {
	SListNode* cur = *pphead;
	SListNode* bef=*pphead;
	if (*pphead == NULL) {
		printf("���ǿձ�");
		exit(1);
	}else {
		while (true) {
			if (cur->next != NULL) {
				bef = cur;
				cur = cur->next;
			}else{
				free(cur);
				bef->next = NULL;
				break;
			}
		}

	}
}

void printSList(SListNode* phead) {
	SListNode* cur = phead;
	while (cur != NULL) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

int main() {
	SListNode* sList = NULL;
	insertSListBack(&sList, 1);
	insertSListBack(&sList, 2);
	insertSListBack(&sList, 3);
	printSList(sList);
	delSListBack(&sList);
	printSList(sList);
}

