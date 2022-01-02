#pragma warning(disable:6031)
#pragma warning(disable:4996)
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/**/
#define MAXSIZE 10
typedef char BDataType;
typedef struct BiTNode//定义树的一个节点
{
	struct BiTNode* lchild;
	struct BiTNode* rchild;
	BDataType data;
}BiTNode;

typedef BiTNode* SDataType;
typedef struct SqStack//定义栈
{
	SDataType* base;
	int maxSize;//总容量大小
	int top;//当前元素大小
}SqStack;
//栈的初始化
void initStack(SqStack* S)
{
	S->base = (SDataType*)malloc(sizeof(SDataType) * MAXSIZE);
	S->maxSize = MAXSIZE;
	S->top = 0;
}
//入栈
void pushStack(SqStack* S, SDataType e)
{
	if (S->top == S->maxSize)//空间已满，需要扩容
	{
		S->base = (SDataType*)realloc(S->base, sizeof(SDataType) * (2 * S->maxSize));
		S->maxSize = 2 * S->maxSize;
	}
	S->base[S->top] = e;
	S->top++;
}
//出栈
void popStack(SqStack* S)
{
	if (S->top == 0)
	{
		printf("栈以为空，不能出栈!!!\n");
	}
	S->top--;
}
//获取栈顶元素
SDataType topStack(SqStack* S)
{
	return S->base[S->top - 1];
}
//判断栈是否为空
int emptyStack(SqStack* S)
{
	if (S->top == 0)
	{
		return 1;
	}
	return 0;
}
//创建一个树
BiTNode* createTree(BDataType* array, int* pos)
{
	if (array[*pos] != '#')
	{
		BiTNode* newNode = (BiTNode*)malloc(sizeof(BiTNode));
		newNode->data = array[*pos];
		(*pos)++;
		newNode->lchild = createTree(array, pos);
		(*pos)++;
		newNode->rchild = createTree(array, pos);
		return newNode;
	}
	else
	{
		return NULL;
	}
}
//中序遍历
void inOrderTraversal(BiTNode* B)//中序遍历非递归
{
	printf("中序遍历: ");
	SqStack S;
	initStack(&S);
	BiTNode* cur = B;
	BiTNode* top;
	while (cur || emptyStack(&S) != 1)
	{
		while (cur)
		{
			pushStack(&S, cur);
			cur = cur->lchild;
		}
		top = topStack(&S);
		popStack(&S);
		printf("%c ", top->data);
		cur = top->rchild;
	}
	printf("\n");
}

int main()
{
	BDataType array[100];//定义一个char数组
	scanf("%s", array);
	int pos = 0;
	BiTNode* B = createTree(array, &pos);
	inOrderTraversal(B);//中序遍历
}




//实验7_字符串的匹配
/*
#include <stdio.h>
#include<string.h>
//BF算法 
int BruteForce(int pos, char S[], char T[]) {
	int i = pos;
	int j = 1;
	//设定循环终止条件，超过主串S则匹配失败，超过匹配串T则匹配成功 
	while (i <= S[0] && j <= T[0]) {
		if (S[i] == T[j]) {
			//匹配成功i和j同时前移 
			i++;
			j++;
		}
		else {
			//否则i和j要同时返回，i返回到原来的下一位，j返回到原点 
			i = i - j + 2;
			j = 1;
		}
	}
	//若j超出了字符串长度，则说明匹配成功返回i-T[0]即为pos位置 
	if (j > T[0]) {
		return i - T[0];
	}
	else {
		return 0;
	}
}

int main(int argc, char** argv) {
	char S[] = " 000000000000000000001";
	char T[] = " 00001";
	int pos;
	printf("请输入从第几位开始：");
	scanf("%d", &pos);
	T[0] = strlen(T) - 1;
	S[0] = strlen(S) - 1;
	pos = BruteForce(pos, S, T);
	if (pos != 0) {
		printf("在第%d位找到了！", pos);
	}
	else {
		printf("不存在！");
	}
	return 0;
}
*/

//实验6_循环队列
/*
#define MAXsize 7
typedef struct SqQueue {
	int* elem;
	int front;
	int tail;
}SqQueue;
//初始化队列 
void initQueue(SqQueue& Q) {
	Q.elem = (int*)malloc(MAXsize * sizeof(int));
	Q.front = 0;
	Q.tail = 0;
}
//入队列 
void enQueue(SqQueue& Q, int x) {
	//循环队列需要通过模运算实现循环效果 
	if ((Q.tail + 1) % MAXsize == Q.front) {
		printf("满队列");
		exit(1);
	}
	Q.elem[Q.tail] = x;
	//tail+1，在tail小于7时，模运算是自己本身。
	//在tail大于7时，模运算会重置到1，从而实现循环。 
	Q.tail = (Q.tail + 1) % MAXsize;
}
//出队列 
void deQueue(SqQueue& Q) {
	//tail=front为空队列，不做判断 
	if (Q.tail != Q.front) {
		Q.front = (Q.front + 1) % MAXsize;
	}
}
//打印队列 
void printQueue(SqQueue& Q) {
	//为不改变front和tail位置，用cur代替front 
	int cur = Q.front;
	//空队列打印 
	if (cur == Q.tail) {
		printf("空队列！");
		exit(1);
	}
	//循环判断cur是否到tail了，到了即为打印完成 
	while (cur != Q.tail) {
		printf("%d ", Q.elem[cur]);
		cur = (cur + 1) % MAXsize;
	}
}

int main(int argc, char** argv) {
	SqQueue Q;
	initQueue(Q);
	enQueue(Q, 7);
	enQueue(Q, 5);
	enQueue(Q, 3);
	enQueue(Q, 9);
	enQueue(Q, 2);
	enQueue(Q, 4);
	deQueue(Q);
	deQueue(Q);
	deQueue(Q);
	enQueue(Q, 15);
	enQueue(Q, 18);
	printQueue(Q);
	return 0;
}
*/

//实验5_栈的应用
/*
#define MAXsize 50
typedef struct SqSqStack {
	int* top;
	int* base;
	int SqStackSize;
}SqSqStack;
//初始化栈
void initSqStack(SqSqStack& S) {
	S.base = (int*)malloc(MAXsize * sizeof(int));
	if (!S.base) {
		printf("申请失败！");
		exit(1);
	}
	S.top = S.base;
	S.SqStackSize = MAXsize;
}
//栈是否为空
bool emptySqStack(SqSqStack& S) {
	if (S.top == S.base) {
		return true;
	}
	return false;
}
//入栈
void pushSqStack(SqSqStack& S, int e) {
	if (emptySqStack(S)) {
		*S.base = e;
		S.top++;
	}
	else if (S.top - S.base == S.SqStackSize) {
		printf("满栈了");
		exit(1);
	}
	else {
		*S.top = e;
		S.top++;
	}
}
//出栈
void popSqStack(SqSqStack& S, int& e) {
	if (S.top != S.base) {
		e = *--S.top;
	}
}
//进制转换
void conversion(SqSqStack& S, int e) {
	int n, index;
	printf("请输入要转换的数以及转换的进制数：");
	scanf("%d %d", &n,&index);
	//转换算法
	while (n) {
		pushSqStack(S, n % index);
		n = n / index;
	}
	while (!emptySqStack(S)) {
		//顺序出栈
		popSqStack(S, e);
		//判断十进制以上情况
		if (index >= 10 && e >= 10) {
			printf("%c", (char)(e + 55));
		}
		else {
			printf("%d", e);
		}
	}
	//打印后缀
	if (index == 2) printf("B");
	if (index == 8) printf("O");
	if (index == 16) printf("H");
}
int main() {
	SqSqStack S;
	int e=0;
	initSqStack(S);
	conversion(S, e);
}
*/

//实验4_链表的交换
/*
typedef struct SListBiTNode {
	int date;
	struct SListBiTNode* next;
}SListBiTNode;
//新开辟一个节点
SListBiTNode* buyBiTNode(int x) {
	SListBiTNode* newBiTNode = (SListBiTNode*)malloc(sizeof(SListBiTNode));
	if (!newBiTNode) {
		printf("节点创建失败！");
		exit(-1);
	}
	newBiTNode->date = x;
	newBiTNode->next = NULL;
	return newBiTNode;
}
//链表尾插
void SListPushBack(SListBiTNode** pphead, int x) {
	SListBiTNode* newBiTNode = buyBiTNode(x);
	if (*pphead == NULL) {
		*pphead = newBiTNode;
	}
	else {
		SListBiTNode* cur = *pphead;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = newBiTNode;
	}
}
//反转链表m位置节点
void invertSList(SListBiTNode** phead, int m, int n) {
	SListBiTNode* cur = *phead;
	SListBiTNode* pm = NULL;
	SListBiTNode* pn = NULL;
	SListBiTNode* pn_next = NULL;
	int count = 1;//用于记录链表位置
	while (cur->next != NULL) {
		if (count == m) {
			pm = cur;//当位置等于m时，用pm指针记录位置
		}
		if (count == m + n) {
			pn = cur;
			pn_next = pn->next;
		}
		cur = cur->next;
		count++;
	}
	if (m + n == 10) {
		pn = cur;
		pn_next = NULL;
	}
	if (pn && pm) {
	pn->next = *phead;//尾指针指向头
	*phead = pm->next;//pm指针下一个位置设置为头指针
	pm->next = pn_next;//pm位置为尾所以设置next为空
	}
}
//遍历链表
void printSList(SListBiTNode* phead) {
	SListBiTNode* cur = phead;
	while (cur != NULL) {
		printf("%d ", cur->date);
		cur = cur->next;
	}
	printf("\n");
}

int main() {
	SListBiTNode* L = NULL;
	for (int i = 1;i <= 10;i++) {
		SListPushBack(&L, i);
	}
	printSList(L);
	int m, n;
	printf("请输入前m个节点：\n");
	scanf("%d", &m);
	printf("请输入后n个节点：\n");
	scanf("%d", &n);
	invertSList(&L, m, n);
	printSList(L);
}
*/

//实验4_链表的合并
/*
typedef struct SListBiTNode {
	int date;
	struct SListBiTNode* next;
}SListBiTNode;
//新开辟一个节点
SListBiTNode* buyBiTNode(int x) {
	SListBiTNode* newBiTNode = (SListBiTNode*)malloc(sizeof(SListBiTNode));
	if (!newBiTNode) {
		printf("节点创建失败！");
		exit(-1);
	}
	newBiTNode->date = x;
	newBiTNode->next = NULL;
	return newBiTNode;
}
//链表尾插
void SListPushBack(SListBiTNode** pphead, int x) {
	SListBiTNode* newBiTNode = buyBiTNode(x);
	//若头指针为空，赋值。否则，照尾，赋值。
	if (*pphead == NULL) {
		*pphead = newBiTNode;
	}
	else {
		SListBiTNode* cur = *pphead;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = newBiTNode;
	}
}
//链表合并算法
void mergeSList(SListBiTNode* pa, SListBiTNode* pb, SListBiTNode** pc) {
	*pc = pa;//pc指针指向pa
	SListBiTNode* cur = *pc;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = pb;//找到表尾后链接pb
}
//遍历链表
void printSList(SListBiTNode* phead) {
	SListBiTNode* cur = phead;
	while (cur != NULL) {
		printf("%d ", cur->date);
		cur = cur->next;
	}
	printf("\n");
}

int main(int argc, char** argv) {
	SListBiTNode* La = NULL;
	SListBiTNode* Lb = NULL;
	SListBiTNode* Lc = NULL;
	for (int i = 1;i <= 5;i++) {
		SListPushBack(&La, i);
		SListPushBack(&Lb, 2 * i);
	}
	printSList(La);
	printSList(Lb);
	mergeSList(La, Lb, &Lc);
	printSList(Lc);
	return 0;
}
*/

//实验3_有序表合并加强
/*
typedef int DataType;
typedef struct SqList {
	DataType* elem;
	int length;
	int listSize;
}SqList;

void initList(SqList& L) {
	L.listSize = 50;
	L.length = 0;
	L.elem = (DataType*)malloc(L.listSize * sizeof(DataType));
}

void createList(SqList& L, int arr[],int len) {
	for (int i = 0;i < len;i++) {
		L.elem[i] = arr[i];
		L.length++;
	}

}

void insertList(SqList& L,int pos,int val) {
	for (int i = L.length;i >= pos;i--){
		L.elem[i + 1] = L.elem[i];
	}
	L.elem[pos] = val;
	L.length++;
}

void mergeList(SqList& A, SqList& B) {
	int i = 0;
	int j = 0;
	while (i < A.length && j < B.length) {
		if (B.elem[j] < A.elem[i]) {
			insertList(A, i, B.elem[j]);
			j++;
		}
		else if(B.elem[j] > A.elem[i]){
			i++;
			if (j != B.length && i == A.length) {
				for (int i = A.length;i <A.length+B.length-j;i++) {
					insertList(A, i, B.elem[j]);
					j++;
				}
			}
		}
		else {
			j++;
		}
	}
}

void mergeNewList(SqList& A, SqList& B, SqList& C) {
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < A.length && j < B.length) {
		if (B.elem[j] < A.elem[i]) {
			insertList(C, k, B.elem[j]);
			k++;
			j++;
		}
		else {
			insertList(C, k, A.elem[i]);
			i++;
			k++;
			if (j != B.length && i == A.length) { 
				for (int m = C.length;m < A.length + B.length;m++) {
					insertList(C, k, B.elem[j]);
					k++;
					j++;
				}
			}
		}
	}
}


void printList(SqList& L) {
	for(int i=0;i<L.length;i++){
		printf("%d ", L.elem[i]);
	}
	printf("\n");
}

int main() {
	int la[] = { 1,2,3,4,5 };
	int lb[] = { 2,4,6,8,10 };
	SqList La, Lb,Lc;
	initList(La);
	initList(Lb);
	initList(Lc);
	createList(La, la,5);
	createList(Lb, lb,5);
	mergeList(La, Lb);
	printList(La);
	int lB[] = { 2,6,8,9,11,15,20 };
	initList(Lb);
	createList(Lb, lB, 7);
	mergeNewList(La, Lb, Lc);
	printList(Lc);
}
*/

//实验2_改进的冒泡排序
/*
void printArray(int arr[], int len);
void bubbleSort(int arr[], int len);
int main() {
	int arr[] = { 1,6,3,4,5 };
	int arr2[] = { 1,2,3,4,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int len2 = sizeof(arr2) / sizeof(arr2[0]);
	bubbleSort(arr, len);
	printArray(arr, len);
	bubbleSort(arr2, len2);
	printArray(arr2, len2);
}

void printArray(int arr[], int len) {
	for (int i = 0;i < len;i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void bubbleSort(int arr[], int len) {
	int count = 0;
	for (int i = 0;i < len;i++) {
		for (int j = 0;j < len - i - 1;j++) {
			if (arr[j] > arr[j + 1]) {
				count++;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (count == 0) {
			printf("无需排序！\n");
			return;
		}
	}
	printf("排序成功！\n");
}
*/

//实验1_有序表合并
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
*/
