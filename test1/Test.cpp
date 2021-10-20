#pragma warning(disable:6031)
#pragma warning(disable:4996)
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//comlpex 复数四则运算
/*
struct complex {
	double realpart;
	double imagpart;
};
void InitComplex(complex &C, double x, double y) {//初始化构造复数
	C.realpart = x;
	C.imagpart = y;
}
double GetReal(complex C) {
	return C.realpart;
}
double GetImag(complex C) {
	return C.imagpart;
}
complex add(complex C1, complex C2) {//复数加法
	complex Sum;
	Sum.realpart = C1.realpart + C2.realpart;
	Sum.imagpart = C1.imagpart + C2.imagpart;
	return Sum;
}
complex sub(complex C1, complex C2) {//复数减法
	complex Sum;
	Sum.realpart = C1.realpart - C2.realpart;
	Sum.imagpart = C1.imagpart - C2.imagpart;
	return Sum;
}
complex mul(complex C1, complex C2) {//复数乘法
	complex Sum;
	Sum.realpart = (C1.realpart * C2.realpart - C1.imagpart * C2.imagpart);
	Sum.imagpart = (C1.imagpart * C2.realpart + C1.realpart * C2.imagpart);
	return Sum;
}
complex div(complex C1, complex C2) {//复数除法
	complex Sum;
	Sum.realpart = (C1.realpart * C2.realpart + C1.imagpart * C2.imagpart) / (C2.realpart * C2.realpart + C2.imagpart * C2.imagpart);
	Sum.imagpart = (C1.imagpart * C2.realpart - C1.realpart * C2.imagpart) / (C2.realpart * C2.realpart + C2.imagpart * C2.imagpart);
	return Sum;
}
int main() {
	complex C1, C2, C_add,C_sub,C_mul,C_div;double X1, X2, Y1, Y2;//X1，Y1是C1的实部虚部，X2,Y2是C2的实部虚部
	printf("请输入C1的实部和虚部：");
	scanf("%lf%lf", &X1, &Y1);//接收C1数据
	printf("请输入C2的实部和虚部：");
	scanf("%lf%lf", &X2, &Y2);//接收C2数据
	InitComplex(C1, X1, Y1);//初始化赋值，将实部X1虚部Y1赋值给complex类的C1
	InitComplex(C2, X2, Y2);//初始化赋值，将实部X2虚部Y2赋值给complex类的C2
	C_add = add(C1, C2);
	C_sub = sub(C1, C2);
	C_mul = mul(C1, C2);
	C_div = div(C1, C2);
	printf("两个复数的和是:%lf+%lfi\n",GetReal(C_add),GetImag(C_add));//调用实部和虚部并输出
	printf("两个复数的差是:%lf+%lfi\n", GetReal(C_sub), GetImag(C_sub));
	printf("两个复数的积是:%lf+%lfi\n", GetReal(C_mul), GetImag(C_mul));
	printf("两个复数的商是:%lf+%lfi\n", GetReal(C_div), GetImag(C_div));
} 
*/

//冒泡排序
/*
int main() {
	int arr[10];
	printf("请输入五个数:");
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

//选择排序
/*
int main() {
	int arr[10];
	printf("请输入五个数：");
	for (int i = 1;i <= 5;i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1;i <= 5;i++) {
		int min = i;//min是最小数位置的标志
		for (int j = i + 1;j <= 5;j++) {
			if (arr[j] < arr[min]) {
				min = j;//如果j位置的数比i位置的数小，重新赋予min标志
			}
		}
		if (min != i) {//如果发生交换，则将min标志的最小值与i进行更换
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
	printf("排序后的数是：");
	for (int i = 1;i <= 5;i++) {
		printf("%d", arr[i]);
	}
}
*/

//线性表增删查改
/*
typedef struct  {
	int* elem;//存储空间基址
	int length;//当前长度
	int listsize;//当前分配的存储容量
}SqList;
void InitList(SqList& L) {
	L.elem = (int*)malloc(50*sizeof(int));//初始化开辟50个int空间
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
	printf("\n当前有:%d个元素\n", L.length);
}
void InsertList(SqList& L) {
	int n, input;
	printf("在第几位数插入什么数？\n");
	scanf("%d%d", &n, &input);
	for (int i = L.length;i >= n;i--) {
		L.elem[i] = L.elem[i - 1];
	}
	L.elem[n - 1] = input;
	L.length++;
}
void DeleteList(SqList& L) {
	int n,i;
	printf("删除第几位数？\n");
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
			printf("在第%d位", i + 1); 
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

//线性表两个练习
/*
typedef struct {
	int* elem;
	int length;
	int listSize;
}SqList;
//数组赋值
void initArray(int arr[], int n) {
	for (int i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
	}
}
//初始化线性表
void initList(SqList& L) {
	L.length = 0;
	L.listSize = 50;
	L.elem = (int*)malloc(L.listSize * sizeof(int));
}
//给线性表赋数组中的值
void createList(SqList& L,int arr[], int n) {
	for (int i = 0;i < n;i++) {
		L.elem[i]=arr[i];
		L.length++;
	}
}
//得到表中i的值
int getList(SqList& L, int i) {
	return L.elem[i - 1];
}
//打印线性表
void printList(SqList& L) {
	for (int i = 0;i < L.length;i++) {
		printf("%d ", L.elem[i]);
	}
}
//线性表插入值，且长度+1
void insertList(SqList& L,int n,int input) {
	for (int i = L.length;i >= n;i--) {
		L.elem[i] = L.elem[i - 1];
	}
	L.elem[n] = input;
	L.length++;
}
//该方法是新建C表=A表-B表
void getNewList_Sub(SqList& A,SqList& B,SqList& C){
	for (int i = 0;i < A.length;i++) {
		C.elem[i] = A.elem[i] - B.elem[i];
		C.length++;
	}
}
//该方法是将B表并到A表中,且A，B表均为升序
void listBtoA(SqList& A, SqList& B) {
	int i = 0;
	int increment = 0;//用于记录A表增加长度时的增量
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

//数组nums包含从0到n的所有整数，但是其中缺了一个。请代码编写缺失的整数。在O(n)时间内完成
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
 
//单链表增删查改
/*
typedef struct SListNode {
	int data;
	struct SListNode* next;
}SListNode;
//开辟一个新节点，并赋值x，返回SListNode*型
SListNode* createSListNode(int x) {
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL) {
		printf("申请失败");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
//在链表尾插入x（二级指针接收SListNode*类型的地址，地址传递)
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
//在链表中间\头插入x
void insertSListMid(SListNode** pphead, int pos, int x) {
	SListNode* prev = NULL;
	SListNode* cur = *pphead;
	SListNode* newNode = createSListNode(x);
	int count = 2;
	while (cur != NULL) {
		//在第一个元素插的情况，新节点为新的头结点
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
//删除链表中最后一个节点（二级指针接收SListNode*类型的地址，地址传递)
void delSListBack(SListNode** pphead) {
	SListNode* cur = *pphead;
	SListNode* bef=*pphead;
	if (*pphead == NULL) {
		printf("这是空表");
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
//删除链表中pos位序的节点
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
//查找链表中x的位序
void locateSList(SListNode* phead, int x) {
	int pos = 0;
	if (phead == NULL) {
		printf("这是一个空表\n");
		exit(1);
	}
	else {
		while (phead != NULL) {
			if (phead->data == x) {
				printf("找到了，位序是:%d\n",x);
				break;
			}
			pos++;
			phead = phead->next;
		}
		printf("没有找到该数\n");
	}
}
//更改链表中pos位序的值，赋值x（二级指针接收SListNode*类型的地址，地址传递)
void modifySList(SListNode** pphead, int pos, int x) {
	SListNode* cur = *pphead;
	int curPos = 1;
	if (*pphead == NULL) {
		printf("这是一个空表\n");
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
//遍历数组
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

//顺序表复习
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

//单链表练习
/*
typedef int DataType;
typedef struct SListNode {
	DataType data;
	SListNode* next;
}SListNode;

SListNode* CreateSListNode(DataType x) {
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL) {
		printf("申请失败\n");
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
		printf("此表为空");
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

//双链表练习
/*
#include<assert.h>
typedef int DataType;
typedef struct DListNode {
	DataType data;
	DListNode* prev;
	DListNode* next;
}DListNode;
//创建一个节点
DListNode* CreateDListNode(DataType x) {
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (newNode == NULL) {
		printf("节点创建失败");
		exit(1);
	}
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
//初始化头结点(带头结点的结构)
DListNode* InitDList(DListNode* phead) {
	phead = CreateDListNode(-10000);
	phead->prev = phead;
	phead->next = phead;
	return phead;
}
//尾插
void DListPushBack(DListNode* phead, DataType x) {
	assert(phead);
	DListNode* tail = phead->prev;
	DListNode* newNode = CreateDListNode(x);
	tail->next = newNode;
	newNode->prev = tail;
	phead->prev = newNode;
	newNode->next = phead;
}
//中间插入
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
//尾删
void DListPopBack(DListNode* phead) {
	assert(phead);
	DListNode* del = phead->prev;
	DListNode* tail = del->prev;
	free(del);
	phead->prev = tail;
	tail->next = phead;
}
//遍历
void PrintDList(DListNode* phead) {
	assert(phead);
	DListNode* cur = phead->next;
	if (cur->data == -10000) {
		printf("空表");
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