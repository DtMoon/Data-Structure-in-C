#include<stdio.h>
#include<stdlib.h>
void sort(int *a, int left, int right) {
	int stack[30]; //定义栈用来存储排序范围
	int top = 0;
	int i = left, j = right;
	int key = a[i];
	if (left >= right) //如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了
	{
		return;
	}
	while (1) {
		while (i < j) { //该循环为快速排序
			while (i < j&&a[j] >= key) {
				j--; //向前寻找
			}
			a[i] = a[j]; //从j开始向前搜索，即由后开始向前搜索(j--)，找到第一个小于key的a[j]，令a[i]=a[j]
			while (i < j&&a[i] <= key) {
				i++; //向后寻找
			}
			a[j] = a[i]; //从i开始向后搜索，即由前开始向后搜索(i++)，找到第一个大于key的a[i]，令a[j]=a[i]
		}
		a[i] = key; //a[i]左边的数全小于等于key，a[j]右边的数全大于等于key

		if (i - 1 != left && i != left) { //当i-1=left或i=left时，i左边数组不需要进行排序了
			stack[top++] = left; //用栈存储i左边数组进行快速排序的范围
			stack[top++] = i - 1;
		}
		if (i + 1 != right && i != right) { //当i+1=right或i=right时，i右边数组不需要进行排序了
			stack[top++] = i + 1; //用栈存储i右边数组进行快速排序的范围
			stack[top++] = right;
		}
		if (top == 0) break; //当栈空时，排序完成，跳出循环
		j = stack[--top]; //出栈下次排序的最高下标
		right = j;
		i = stack[--top]; //出栈下次排序的最低下标
		left = i;
		key = a[i];
	}
	return;
}

void main() {
	int a[] = { 6,3,1,5,4,7,9,8,0,2 };
	int left = 0;
	int right = 9;
	int i;
	sort(a, left, right);
	for (i = 0; i < 8; i++) { //打印排好序的数组
		printf("%d", a[i]);
	}

	system("pause");
	return;
}