#include <iostream>
#include <vector>
using namespace std;


int partition(vector<int>& arr, int left, int right) {
	int tmp = arr[left];
	int dest = left-1, cur = left;
	while (cur <= right)
	{
		if (arr[cur] <= tmp) {
			swap(arr[++dest], arr[cur]);
			cur++;
		}
		else {
			cur++;
		}
	}
	swap(arr[dest], arr[left]);
	return dest;
}

void quicksort(vector<int>& v, int left, int right) {
	if (left >= right)
	{
		return;
	}
	
	int p = partition(v, left, right);
	quicksort(v, left, p - 1);
	quicksort(v, p + 1, right);

}

void delval(vector<int>& v, int val) {
	int dest = -1, cur = 0;
	while (cur < v.size())
	{
		if (v[cur] != val) {
			v[++dest] = v[cur];
			cur++;
		}
		else {
			cur++;
		}
	}

}
void duplicateZeros(vector<int>& arr) {
	/*int i = 0, j = -1;
	while (j < (int)arr.size() - 1) {
		if (arr[i] != 0) {
			j++;
		}
		else {
			j += 2;
		}
		i++;
	}
	i--;*/
	int i = 0, j = -1;
	while (i < arr.size())
	{
		if (arr[i] != 0) {
			i++;
			j++;
		}
		else {
			j += 2;
			if (j >= arr.size() - 1) {
				break;
			}
			i++;
		}
	}
	if (j > arr.size() - 1) {
		j--;
		arr[j] = arr[i];
		j--; i--;
	}
	while (i >= 0) {
		if (arr[i] != 0) {
			arr[j] = arr[i];
			j--; i--;
		}
		else {
			arr[j] = arr[j - 1] = 0;
			j -= 2;
			i--;
		}
	}
}
int main() {
	vector<int> v = { 3,4,2,1,8,5,6,0,3 };
	quicksort(v, 0, v.size() - 1);
	for (auto e : v) {
		cout << e << endl;
	}
	cout << endl;
	delval(v, 3);
	for (auto e : v) {
		cout << e << endl;
	}
	v = { 0,0,0,0,0,0,0 };
	duplicateZeros(v);

}