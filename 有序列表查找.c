/*
题目一：有序列表查找
给定n个有序整数和t组查询，输出每次查询的结果。
输入共4行。
输入第一行一个整数n,表示之后会输入n个有序的整数。
输入第二行为n个空格想得开的整数，分别表示整数。
输入第三行一个整数t,表示之后会输入t个查询。
输入第四行为t个空格想得开的整数，分别每次查询的结果，如果找到输出在原序列中的位置，如果没找到输出"N"。

输出为t行整数，表示每次查询的结果。
Input:
10
1 2 3 4 5 6 7 8 9 10
4
3 5 1 11
Output
2
4
0
N
*/

#include<stdlib.h>
#include<stdio.h>

int Bisearch(int *a, int n, int p) //折半查找
{
	int low = 0, high = n - 1, mid, i;
	while (low <= high)
	{
		mid = (low + high) / 2; //折半
		if (a[mid]>p) high = mid - 1; //若中值比查找值大，最高下标调整为中位下标减1
		else if (a[mid]<p) low = mid + 1; //若中值比查找值小，最低下标调整为中位下标加1
		else return mid; //若相等，说明mid即为查找到的位置
	}
	return -1;
}

void main()
{
	int n, i, num, pos;
	int *a, *b;
	printf("Input:\n");
	scanf_s("%d", &n); //输入序列元素个数
	a = (int*)malloc(sizeof(int)*n); //动态分配
	for (i = 0; i<n; i++)
	{
		scanf_s("%d", &a[i]); //输入序列元素
	}
	scanf_s("%d", &num); //输入要查找的元素个数
	b = (int *)malloc(sizeof(int)*num);
	for (i = 0; i<num; i++) scanf_s("%d", &b[i]); //输入要查找的元素
	printf("Output:\n");
	for (i = 0; i<num; i++)
	{
		pos = Bisearch(a, n, b[i]); //折半查找
		if (pos == -1) printf("N\n"); //没找到，输出N
		else printf("%d\n", pos); //找到，输出位置
	}

	system("pause");
	return;
}