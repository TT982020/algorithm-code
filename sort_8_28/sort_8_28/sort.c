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

void Swap(int* p1, int* p2) {
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SelectSort(int* a, int n) {
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin; i <= end; i++) {
			
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] >= a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}
void AdjustDown(int* a, int n, int parent) {
	int child = parent * 2 + 1;
	//升序建大堆
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n) {
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		//建大堆
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}

}

int PartSort(int* a, int left, int right) {
	int keyi = left;

	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);
	return left;
}

int PartSort2(int* a, int left, int right) {
	int key = a[left];
	int hole = left;

	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

int PartSort3(int* a, int left, int right) {
	int keyi = left;
	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi]) {
			prev++;
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[prev], &a[keyi]);
	keyi = prev;
	return keyi;
}

void QuickSort(int* a, int begin, int end) {
	if (begin >= end)
	{
		return;
	}
	int partition = PartSort3(a, begin, end);
	QuickSort(a, begin, partition - 1);
	QuickSort(a, partition + 1, end);
}