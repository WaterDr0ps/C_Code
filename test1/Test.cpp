#pragma warning(disable:6031)
#pragma warning(disable:4996)
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
 
//��������ɾ���
/*
typedef struct SListNode {
	int data;
	struct SListNode* next;
}SListNode;
//����һ���½ڵ㣬����ֵx������SListNode*��
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
//������β����x������ָ�����SListNode*���͵ĵ�ַ����ַ����)
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
//�������м�\ͷ����x
void insertSListMid(SListNode** pphead, int pos, int x) {
	SListNode* prev = NULL;
	SListNode* cur = *pphead;
	SListNode* newNode = createSListNode(x);
	int count = 2;
	while (cur != NULL) {
		//�ڵ�һ��Ԫ�ز��������½ڵ�Ϊ�µ�ͷ���
		if (pos == 1) {
			*pphead = newNode;
			newNode->next = cur;
			break;
		}
		prev = cur;
		cur = cur->next;
		if (pos == count) {
			prev->next = newNode;
			newNode->next = cur;
			break;
		}
		count++;
	}
}
//ɾ�����������һ���ڵ㣨����ָ�����SListNode*���͵ĵ�ַ����ַ����)
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
//ɾ��������posλ��Ľڵ�
void delSListMid(SListNode** pphead,int pos) {
	SListNode* prev = NULL;
	SListNode* tail = *pphead;
	int count = 2;
	while (tail != NULL) {
		if (pos == 1) {
			tail = tail->next;
			free(*pphead);
			*pphead = tail;
			break;
		}
		prev = tail;
		tail = tail->next;
		if (pos == count) {
			SListNode* cur = tail;
			tail = tail->next;
			prev->next = tail;
			free(cur);
			break;
		}
		count++;
	}
}
//����������x��λ��
void locateSList(SListNode* phead, int x) {
	int pos = 0;
	if (phead == NULL) {
		printf("����һ���ձ�\n");
		exit(1);
	}
	else {
		while (phead != NULL) {
			if (phead->data == x) {
				printf("�ҵ��ˣ�λ����:%d\n",x);
				break;
			}
			pos++;
			phead = phead->next;
		}
		printf("û���ҵ�����\n");
	}
}
//����������posλ���ֵ����ֵx������ָ�����SListNode*���͵ĵ�ַ����ַ����)
void modifySList(SListNode** pphead, int pos, int x) {
	SListNode* cur = *pphead;
	int curPos = 1;
	if (*pphead == NULL) {
		printf("����һ���ձ�\n");
		exit(1);
	}
	else {
		while (cur != NULL) {
			if (curPos == pos) {
				cur->data = x;
				break;
			}
			curPos++;
			cur = cur->next;
		}
	}
}
//��������
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
	insertSListMid(&sList, 1, 5);
	delSListMid(&sList, 1);
	printSList(sList);
}
*/

//˳���ϰ
/*
#define LSize 50;
typedef int DataType;
typedef struct SqList {
	DataType* elem;
	int length;
	int listSize;
}SqList;

void initSList(SqList* L) {
	L->length = 0;
	L->listSize = LSize;
	L->elem = (DataType*)malloc(L->listSize * sizeof(DataType));
}

void createSList(SqList* L) {
	 while(scanf("%d", &L->elem[L->length])) {
		L->length++;
		if (getchar() == '\n') {
			break;
		}
	 } 
}

void insertSList(SqList* L,int pos,int val) {
	int i;
	for (i = L->length;i >= pos - 1;i--) {
		L->elem[i+1] = L->elem[i];
		if (pos - 1 == i) {
			L->elem[i] = val;
			L->length++;
		}
	}
}

void deleteSList(SqList* L,int pos) {
	for (int i = pos-1;i < L->length;i++) {
		L->elem[i] = L->elem[i + 1];
	}
	L->length--;
}

void printSList(SqList* L) {
	for (int i = 0;i < L->length;i++) {
		printf("%d ", L->elem[i]);
	}
}

int main() {
	SqList L;
	initSList(&L);
	createSList(&L);
	deleteSList(&L, 1);
	printSList(&L);
}
*/

//��������ϰ
/*
typedef int DataType;
typedef struct SListNode {
	DataType data;
	SListNode* next;
}SListNode;

SListNode* CreateSListNode(DataType x) {
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL) {
		printf("����ʧ��\n");
		exit(1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void SListPushBack(SListNode** pphead,DataType x) {
	SListNode* newNode = CreateSListNode(x);
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

void SListInsert(SListNode** pphead, int pos, DataType x) {
	SListNode* newNode = CreateSListNode(x);
	int count = 2;
	if (*pphead == NULL) {
		*pphead = newNode;
	}
	else {
		SListNode* prev = NULL;
		SListNode* cur = *pphead;
		while (cur->next != NULL) {
			if (pos == 1) {
				*pphead = newNode;
				newNode->next = cur;
				break;
			}
			prev = cur;
			cur = cur->next;
			if(pos == count) {
				prev->next = newNode;
				newNode->next = cur;
				break;
			}
			count++;
		}
	}
}

void SListPopBack(SListNode** pphead) {
	SListNode* prev = NULL;
	SListNode* cur = *pphead;
	if (cur->next == NULL) {
		free(cur);
	}
	else {
		while (cur->next != NULL) {
			prev = cur;
			cur = cur->next;
		}
		prev->next = NULL;
		free(cur);
	}
}

void SListDelete(SListNode** pphead, int pos) {
	if (*pphead == NULL) {
		printf("�˱�Ϊ��");
		exit(1);
	}
	SListNode* prev = NULL;
	SListNode* cur = *pphead;
	int count = 2;
	
	while (cur->next != NULL) {
		prev = cur;
		cur = cur->next;
		if (pos == 1) {
			*pphead = cur;
			free(prev);
			break;
		}
		if (pos == count) {
			SListNode* del = cur;
			cur = cur->next;
			free(del);
			prev->next = cur;
			break;
		}
		count++;
	}
}

void PrintSList(SListNode* pphead) {
	SListNode* cur = pphead;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

int main() {
	SListNode* SList = NULL;
	SListPushBack(&SList, 1);
	SListPushBack(&SList, 2);
	SListPushBack(&SList, 3);
	SListDelete(&SList, 3);
	PrintSList(SList);
}
*/

//˫������ϰ
/*
#include<assert.h>
typedef int DataType;
typedef struct DListNode {
	DataType data;
	DListNode* prev;
	DListNode* next;
}DListNode;
//����һ���ڵ�
DListNode* CreateDListNode(DataType x) {
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (newNode == NULL) {
		printf("�ڵ㴴��ʧ��");
		exit(1);
	}
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
//��ʼ��ͷ���(��ͷ���Ľṹ)
DListNode* InitDList(DListNode* phead) {
	phead = CreateDListNode(-10000);
	phead->prev = phead;
	phead->next = phead;
	return phead;
}
//β��
void DListPushBack(DListNode* phead, DataType x) {
	assert(phead);
	DListNode* tail = phead->prev;
	DListNode* newNode = CreateDListNode(x);
	tail->next = newNode;
	newNode->prev = tail;
	phead->prev = newNode;
	newNode->next = phead;
}
//�м����
void DListInsert(DListNode* phead, DataType pos, DataType x) {
	DListNode* newNode = CreateDListNode(x);
	DListNode* cur = phead->next;
	int count = 2;
	while (cur->next != phead) {
		if (pos == 1) {
			phead->next = newNode;
			newNode->prev = phead;
			newNode->next = cur;
			cur->prev = newNode;
			break;
		}
		if (count == pos) {
			DListNode* tail = cur->next;
			cur->next = newNode;
			newNode->prev = cur;
			newNode->next = tail;
			tail->prev = newNode;
			break;

		}
		cur = cur->next;
		count++;
	}
}
//βɾ
void DListPopBack(DListNode* phead) {
	assert(phead);
	DListNode* del = phead->prev;
	DListNode* tail = del->prev;
	free(del);
	phead->prev = tail;
	tail->next = phead;
}
//����
void PrintDList(DListNode* phead) {
	assert(phead);
	DListNode* cur = phead->next;
	if (cur->data == -10000) {
		printf("�ձ�");
		exit(1);
	}
	while (cur != phead) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

int main() {
	DListNode* L=NULL;
	L=InitDList(L);
	DListPushBack(L, 1);
	DListPushBack(L, 2);
	DListPushBack(L, 3);
	DListInsert(L, 1, 5);
	PrintDList(L);
}
*/

#define N 50;
typedef struct SqList {
	int* elem;
	int length;
	int listSize;
}SqList;

void getArray(int arr[],int n) {
	for (int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
	}
}

void initList(SqList& L) {
	L.length = 0;
	L.listSize = N;
	L.elem = (int*)malloc(L.listSize * sizeof(int));
}

void createList(SqList& L, int arr[],int n) {
	for (int i = 0;i < n;i++) {
		L.elem[i] = arr[i];
		L.length++;
	}
}

void mergeList(SqList& A, SqList& B,SqList& C) {
	C = A;
	int i = C.length - 1, j = B.length - 1;
	while (i >= 0 && j >= 0) {
		if (C.elem[i] <= B.elem[j]) {
			if (C.elem[i + 1]==NULL)
			{
				C.elem[i + 1] = B.elem[j];
			}
			else {
				for (int k = C.length - 1; k >= i + 1; --k)
				{
					C.elem[k + 1] = C.elem[k];
				}
				C.elem[i + 1] = B.elem[j];
			}
			C.length++;
			j--;
		}
		else {
			i--;
		}
	}
}

void merge2List(SqList& A, SqList& B, SqList& C) {
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
	merge2List(La,Lb,Lc);
	printList(Lc);
	
	
}