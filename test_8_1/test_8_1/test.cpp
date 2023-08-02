#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//��ʧ������
//����1�� ����ж�
int missingNumber(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i <= numsSize; i++) {
        sum += i;
    }
    for (int i = 0; i < numsSize; i++) {
        sum -= nums[i];
    }
    return sum;
}
//����2�� ���
int missingNumber2(int* nums, int numsSize) {
    int ret = 0;
    for (int i = 0; i <= numsSize; i++) {
        ret = ret ^ i;
    }
    for (int i = 0; i < numsSize; i++) {
        ret = ret ^ nums[i];
    }
    return ret;
}

// ��ת����
//����1�������ת,�ᳬʱ
void rotate1(int* nums, int numsSize, int k) {
    
    int n = numsSize;
    while (k--)
    {
        int tmp = nums[n - 1];
        for (int i = n - 1; i > 0; i--) {
            nums[i] = nums[i - 1];
        }
        nums[0] = tmp;
    }
}
//����2�����������������ת
void rotate2(int* nums, int numsSize, int k) {
    int n = numsSize;
    k %= n;
    int* tmp = (int*)malloc(n * sizeof(int));
    memcpy(tmp, nums + n - k, k * sizeof(int));
    
    memcpy(tmp + k, nums, sizeof(int) * (n - k));
    memcpy(nums, tmp, sizeof(int) * n);
    free(tmp);
    tmp = NULL;
}
//����3����������
void reverse(int* a, int left, int right) {
    while (left < right)
    {
        int tmp = a[left];
        a[left] = a[right];
        a[right] = tmp;
        left++; right--;
    }
}
void rotate3(int* nums, int numsSize, int k) {
    int n = numsSize;
    k %= n;
    reverse(nums, n - k, n - 1);
    reverse(nums, 0, n - k - 1);
    reverse(nums, 0, n - 1);
}
int main() {
    int nums[] = {1,2,3,4,5,6,7};
    rotate3(nums, 7, 3);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", nums[i]);
    }
}