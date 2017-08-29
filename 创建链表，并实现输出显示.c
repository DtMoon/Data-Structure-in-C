/*实验一
创建链表，并实现输出显示。
实验输入
input the size of linklist : 4
1 5 3 9
实验输出
1 5 3 9*/

#include<stdio.h>
#include<stdlib.h>

struct node //结构定义放在需要使用的函数前面
{
	int data;
	struct node *next;
};

struct node* initlist(struct node *t) //初始化链表
{
	struct node *p;
	struct node *m;
	int n, i;
	m = t;
	printf("input the size of linklist:"); //输入链表长度
	scanf_s("%d", &n);
	for (i = 0; i<n; i++)
	{
		p = (struct node*)malloc(sizeof(struct node));
		scanf_s("%d", &p->data); //输入链表数据
		if (t->next == NULL) //用于生成链表
		{
			t->next = p;
			p->next = NULL;
			t = t->next;
		}
	}
	return m; //返回头结点
}

int listprint(struct node *L) //打印链表元素
{
	while (L)
	{
		printf("%d ", L->data);
		L = L->next;
	}
	return 0;
}

int main()
{
	struct node *ha = (struct node*)malloc(sizeof(struct node));
	ha->next = NULL; //初始化是必须的
	initlist(ha); //初始化链表
	printf("Output：\n");
	listprint(ha->next); //打印链表

	system("pause");
	return 0;
}