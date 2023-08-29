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
//可以对三重循环进行优化
	//for (int j = 0; j < gap; j++)
	//{
	//	//i<n-gap 使得tmp不越界
	//	for (int i = j; i < n - gap; i += gap)  //循环gap组
	//	{
	//		int end = i;
	//		int tmp = a[end + gap];
	//		while (end >= 0)                    //每组数据插入排序
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
	// 1、gap > 1 预排序
	// 2、gap == 1 直接插入排序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;  //最大的数最多3步可以挪到后面去。 +1可以保证最后一趟gap为1。
		//gap = gap / 2;   //除2预排的更多，因为排更多次，/3更快减少到1，预排的更少
		//i<n-gap 使得tmp不越界
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