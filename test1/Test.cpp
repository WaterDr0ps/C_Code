#pragma warning(disable:6031)
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

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