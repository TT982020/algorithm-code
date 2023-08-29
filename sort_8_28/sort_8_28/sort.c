#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"
#include <stdbool.h>
void PrintArray(int* a, int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n) {
	for (int i = 1; i < n; i++) {
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void InsertSort1(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		int tmp = a[i + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
//���Զ�����ѭ�������Ż�
	//for (int j = 0; j < gap; j++)
	//{
	//	//i<n-gap ʹ��tmp��Խ��
	//	for (int i = j; i < n - gap; i += gap)  //ѭ��gap��
	//	{
	//		int end = i;
	//		int tmp = a[end + gap];
	//		while (end >= 0)                    //ÿ�����ݲ�������
	//		{
	//			if (tmp < a[end])
	//			{
	//				a[end + gap] = a[end];
	//				end -= gap;
	//			}
	//			else {
	//				break;
	//			}
	//		}
	//		a[end + gap] = tmp;
	//	}
	//}
void ShellSort(int* a, int n) {
	// 1��gap > 1 Ԥ����
	// 2��gap == 1 ֱ�Ӳ�������
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;  //���������3������Ų������ȥ�� +1���Ա�֤���һ��gapΪ1��
		//gap = gap / 2;   //��2Ԥ�ŵĸ��࣬��Ϊ�Ÿ���Σ�/3������ٵ�1��Ԥ�ŵĸ���
		//i<n-gap ʹ��tmp��Խ��
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void BubbleSort(int* a, int n) {
	for (int i = 0; i < n-1; i++)
	{
		bool flag = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j]>a[j+1])
			{
				flag = true;
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
		if (!flag) break;
	}
}