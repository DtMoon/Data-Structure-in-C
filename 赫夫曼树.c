/*题目一：赫夫曼树
给定n个叶结点的权值，求这些结点组成的赫夫曼树的总权值。
输入共两行。
输入第一行一个整数n,表示之后会输入n个叶结点的权值。
输入第二行为n个空格想得开的整数，分别表示每个叶结点的权值。
输出为一个整数，表示n个叶结点组成的赫夫曼树的总权值。
Input:
5
1 2 3 4 5
Output
33
*/

#include <stdio.h>
#include<malloc.h>
#include <stdlib.h>

struct node { //定义结构
	int data;
	struct node *lchild;
	struct node *rchild;
};

void minmerge(struct node *a, int n) { //将权值最小的两个合并，即构造一课树连接它们
	int i;
	struct node temp, p, *temp1; //结构体
	if (n == 1) return;
	for (i = 0; i < n - 1; i++) { //冒泡排序，找到最小的，放在数组末尾位置
		if (a[i].data < a[i + 1].data) {
			temp = a[i + 1];
			a[i + 1] = a[i];
			a[i] = temp;
		}
	}
	for (i = 0; i < n - 2; i++) { //冒泡排序，找到次小的，放在数组倒数第二个位置
		if (a[i].data < a[i + 1].data) {
			temp = a[i + 1];
			a[i + 1] = a[i];
			a[i] = temp;
		}
	}
	temp1 = (struct node*)malloc(sizeof(struct node)); //用temp1保存次小者的数据
	temp1->data = a[n - 2].data;
	temp1->lchild = a[n - 2].lchild;
	temp1->rchild = a[n - 2].rchild;
	p.data = temp1->data + a[n - 1].data; //计算两者权值之和
	p.lchild = &a[n - 1]; //左子树指向最小的
	p.rchild = temp1; //右子树指向次小的
	a[n - 2] = p; //更新数组元素，将合并后的放在原来次小者的位置
	minmerge(a, n - 1); //递归操作
	return;
}

int weigh(struct node *a, int n) { //计算总体权值
	if (a->lchild == NULL && a->rchild == NULL) return a->data*n; //当结点为叶子节点时，返回data*n
	return weigh(a->lchild, n + 1) + weigh(a->rchild, n + 1); //递归调用
}

int main()
{
	int n, i, weight;
	scanf_s("%d", &n);
	struct node *a = (struct node*)malloc(sizeof(struct node)*n); //结构体数组
	for (i = 0; i < n; i++) { //结构体赋值
		scanf_s("%d", &a[i].data);
		a[i].lchild = NULL;
		a[i].rchild = NULL;
	}
	minmerge(a, n); //合并
	weight = weigh(&a[0], 0); //计算总体权值
	printf_s("%d", weight); //输出结果

	system("pause");
	return 0;
}