#include<stdio.h>
#include<stdlib.h>
void Arrange(int a[], int n) {
	int i = 0, j = n-1;
	int left = i, right = j;
	int key = 0;
	int temp;
	while (i < j) { //该循环执行完毕后，i的左侧全小于等于0，i的右侧全大于等于0
		while (i < j&&a[j] >= key) { //从后向前查找第一个小于key的数
			j--; //向前寻找
		}
		while (i < j&&a[i] <= key) { //从前向后找第一个大于key的数
			i++; //向后寻找
		}
		temp = a[i]; //交换这两个数
		a[i] = a[j];
		a[j] = temp;
	}

	while (left <= i) { //将i左侧的0后移
		if (a[left] == 0) {
			a[left] = a[i];
			a[i] = 0;
			i--;
		}
		left++;
	}
	while (right >= j) { //将j右侧的0前移
		if (a[right] == 0) {
			a[right] = a[++j];
			a[j] = 0;
		}
		right--;
	}

	return;
}

void main() {
	int a[] = { 0,3,6,1,-1,0,-4,7,-5,8,0,2 };
	int n = 12;
	int i;
	Arrange(a, n);

	for (i = 0; i < n; i++) { //打印排好序的数组
		printf("%d", a[i]);
	}

	system("pause");
	return;
}