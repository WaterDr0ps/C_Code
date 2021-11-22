#pragma warning(disable:6031)
#pragma warning(disable:4996)
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void printArray(int arr[], int len);
void bubbleSort(int arr[], int len);
int main() {
	int arr[] = { 1,5,3,4,2 };
	bool flag = true;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0;i < len-1;i++) {
		if (arr[i] > arr[i + 1]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		printf("��������");
		exit(0);
	}
	else {
		bubbleSort(arr, len);
		printf("�������\n");
		printArray(arr,len);
	}
}

void printArray(int arr[], int len) {
	for (int i = 0;i < len;i++) {
		printf("%d ", arr[i]);
	}
}

void bubbleSort(int arr[], int len) {
	for (int i = 0;i < len;i++) {
		for (int j = 0;j < len - i - 1;j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


//����DNA���ƥ��
/*
#include<string.h>
#include<iostream>
using namespace std;
bool BruteForce(char* S, char* T) {
	int i = 0;
	int j = 0;
	while (i < strlen(S) && j < strlen(T)) {
		if (S[i] == T[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (i > strlen(T)) {
		return true;
	}
	else {
		return false;
	}
}
//��T�е�һ���ַ��ŵ����һλ
char* turn(char* T) {
	char* temp = T;
	char head[2] = { temp[0] };//������ҪԤ��'\0'�Ŀռ�
	strcpy(T, temp + 1);
	strcat(T, head);
	return T;
}

bool judegVirus(char* S, char* T) {
		for (int i = 0;i < strlen(T);i++) {
			if (i != 0) {
				strcpy(T, turn(T));
			}
			if (BruteForce(S, T)) {
				return true;
			}
		}
		return false;
}

int main() {
	char Virus[100];
	char DNA[200];
	scanf("%s %s", Virus, DNA);
	if (judegVirus(DNA, Virus)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
*/

//KMP�㷨
/*
#include<string.h>
void getNext(char T[],int next[]) {
	int i = 1;
	int j = 0;
	next[1] = 0;
	while (i < T[0]) {
		if (j == 0 || T[i] == T[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j]; 
		}
	}
}

int KMP(char S[], char T[], int next[]) {
	int i = 1;
	int j = 1;
	while (i <= S[0] && j <= T[0]) {
		if (j == 0 || S[i] == T[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (i > T[0]&&S[i]==T[j]) {
		return i - T[0];
	}
	else {
		return 0;
	}
}

int main() {
	char S[] = " abcdefge";
	char T[] = " fged";
	S[0] = strlen(S) - 1;
	T[0] = strlen(T) - 1;
	int next[20];
	getNext(T,next);
	printf("%d", KMP(S, T, next));
}

*/

//BF�㷨
/*
#include<string.h>
int BruteForce(char S[],char T[]) {
	int i = 1;
	int j = 1;
	while (i <= S[0] && j <= T[0]) {
		if (S[i] == T[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 2;
			j = 1;
		}
	}
	if (i > T[0]) {
		return i - T[0];
	}
	else {
		return 0;
	}
 }

int main() {
	char S[] = " abcdefge";
	char T[] = " cde";
	S[0] = strlen(S) - 1;
	T[0] = strlen(T) - 1;
	printf("%d", BruteForce(S,T));
}
*/

//����(������)
/*
typedef int DataType;
typedef struct QNode {
	DataType data;
	QNode* next;
}QNode;
//front��tail����QNode��ָ����������ڿ���ͷɾβ�������
typedef struct LinkNode {
	QNode* front;
	QNode* tail;
}LinkNode;

void initQNode(LinkNode& Q) {
	Q.front = Q.tail = NULL;
}

QNode* buyNode(DataType x) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode) {
		newNode->data = x;
		newNode->next = NULL;
	}
	return newNode;
}

void enQueue(LinkNode& Q,DataType x) {
	QNode* newNode = buyNode(x);
	if (!Q.front) {
		Q.front = Q.tail = newNode;
	}
	else {
		Q.tail->next = newNode;
		Q.tail = newNode;
	}
}

void deQueue(LinkNode& Q) {
	if (Q.front) {
		QNode* cur = Q.front;
		Q.front = Q.front->next;
		free(cur);
	}
	
}

void printNode(LinkNode& Q) {
	if (!Q.front) {
		printf("�ն���");
		exit(1);
	}
	while (Q.front) {
		printf("%d\n", Q.front->data);
		Q.front = Q.front->next;
	}
}

int main() {
	LinkNode Q;
	initQNode(Q);
	enQueue(Q, 1);
	enQueue(Q, 2);
	enQueue(Q, 3);
	enQueue(Q, 4);
	deQueue(Q);
	printNode(Q);
}

*/

//����(ѭ��˳�����)
/*
#define MAX_SIZE 6
typedef int DataType;
typedef struct SqQueue {
	DataType* elem;
	int front;
	int tail;
}SqQueue;

void initQueue(SqQueue& Q) {
	Q.elem = (DataType*)malloc(MAX_SIZE * sizeof(DataType));
	Q.front = 0;
	Q.tail = 0;
}
//�������˷�һ���洢��Ԫ���ж������е������Ҳ��������һ��flag��length���ж�
void enQueue(SqQueue& Q, DataType x) {
	if ((Q.tail + 1) % MAX_SIZE == Q.front) {
		printf("������");
		exit(1);
	}
	Q.elem[Q.tail] = x;
	Q.tail = (Q.tail + 1) % MAX_SIZE;
}

void deQueue(SqQueue& Q) {
	if (Q.front != Q.tail) {
		Q.front = (Q.front + 1) % MAX_SIZE;
	}
}
//���ض���Ԫ�ظ�����ע��tail������frontǰҲ������front�󣬹���ģmod����
int QueueLength(SqQueue& Q) {
	return((Q.tail - Q.front + MAX_SIZE) % MAX_SIZE);
}

void printQueue(SqQueue& Q) {
	int cur = Q.front;
	if (cur == Q.tail) {
		printf("�ն���");
		exit(1);
	}
	while (cur != Q.tail) {
		printf("%d\n", Q.elem[cur]);
		cur = (cur + 1) % MAX_SIZE;
	}
}

int main() {
	SqQueue Q;
	initQueue(Q);
	enQueue(Q, 1);
	enQueue(Q, 2);
	enQueue(Q, 3);
	deQueue(Q);
	enQueue(Q, 4);
	enQueue(Q, 5);
	enQueue(Q, 6);
	printQueue(Q); 
}
*/

//ջ�Ĳ���(��ջ)
/*
typedef int DataType;
typedef struct LStack {
	DataType data;
	LStack* next;
}LStack;

void pushStack(LStack** S,DataType x) {
	LStack* P = (LStack*)malloc(sizeof(LStack));
	if (P != NULL) {
		P->data = x;
		P->next = *S;
		*S = P;
	}
}

void popStack(LStack** S) {
	if (S!=NULL) {
		LStack* P = *S;
		*S = (*S)->next;
		free(P);
	}
}

void printStack(LStack* S) {
	while (S != NULL) {
		printf("%d ", S->data);
		S = S->next;
	}

}

int main() {
	LStack* S = NULL;
	pushStack(&S, 1);
	pushStack(&S, 2);
	pushStack(&S, 3);
	pushStack(&S, 4);
	popStack(&S);
	printStack(S);
}
*/

//ջ�Ĳ���(˳��ջ)
/*
typedef int DataType;
#define MAX_SIZE 50
typedef struct SqStack {
	DataType* top;
	DataType* base;
	int stackSize;
}SqStack;

void initSqStack(SqStack& S) {
	S.base = (DataType*)malloc(MAX_SIZE*sizeof(DataType));
	if (!S.base) {
		printf("����ʧ��");
		exit(1);
	}
	S.top = S.base;
	S.stackSize = MAX_SIZE;
}

void pushStack(SqStack& S,DataType x) {
	if (S.top == S.base) {
		*S.base = x;
		S.top++;
	}
	else if (S.top - S.base == S.stackSize) {
		printf("��ջ��");
		exit(1);
	}
	else {
		*S.top = x;
		S.top++;
	}
}

void popStack(SqStack& S) {
	if (S.top != S.base) {
		S.top--;
	}
}

void printStack(SqStack& S) {
	if (S.top == S.base) {
		printf("��ջ");
		exit(1);
	}
	while (S.top != S.base) {
		printf("%d ", *S.base);
		S.base++;
	}
}

int main() {
	SqStack S;
	initSqStack(S);
	pushStack(S, 2);
	popStack(S);
	printStack(S);
}
 */

//�����ĺϲ�(����ʵ��)
/*
#include<assert.h>
typedef int DataType;
typedef struct SListNode {
	DataType data;
	SListNode* next;
}SListNode;

SListNode* initList() {
	SListNode* phead = (SListNode*)malloc(sizeof(SListNode));
	if (!phead) {
		printf("ͷ��㴴��ʧ��");
		exit(1);
	}
	phead->data = 0;
	phead->next = NULL;
	return phead;
}

SListNode* createSListNode(DataType x) {
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (!newNode) {
		printf("�½ڵ㴴��ʧ��");
		exit(1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
//��do..whileʵ���ûس��Ϳ��Կ�����������Ľ���
void estaBlishSList(SListNode** pphead) {
	assert(*pphead);
	DataType x;
	SListNode* cur = *pphead;
	do {
		scanf("%d", &x);
		SListNode* newNode = createSListNode(x);
		if (cur->next == NULL) {
			cur->next= newNode;
		}else{
			while (cur->next != NULL) {
				cur = cur->next;
			}
			cur->next = newNode;
		}
	} while (getchar() != '\n');
}
//�ϲ�
void mergeSList(SListNode* La, SListNode* Lb, SListNode* Lc) {
	SListNode* pa = La->next;
	SListNode* pb = Lb->next;
	SListNode* pc = Lc;
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
}

void printSList(SListNode* phead) {
	SListNode* cur = phead->next;
	while (cur!= NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

int main() {
	SListNode* La = initList();
	SListNode* Lb = initList();
	SListNode* Lc = initList();
	estaBlishSList(&La);
	estaBlishSList(&Lb);
	mergeSList(La, Lb, Lc);
	printSList(Lc);
}
*/

//�����ĺϲ�(˳���ʵ��)
/*
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
//�÷�����AԪ��ȫ����ֵ��C���ٽ�B�е�Ԫ�ش�ͷ���αȽϲ���C��
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
			if (i == C.length && j != B.length) {
				for (int k = C.length;k < B.length + A.length;k++) {
					C.elem[k] = B.elem[j];
					C.length++;
					j++;
				}
			}
		}
	}
}
//�÷�����A��ֵ��C���ٽ�B��Ԫ��ֱ��β����C�У��ٽ�C������
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

