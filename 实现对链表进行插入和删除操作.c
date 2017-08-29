/*实验二
创建一个成绩链表, 成绩数据输入以空格隔开，以负数为结束，实现对链表进行插入和删除操作。
实验输出
输入学生成绩：99 88 77 66 55 44 33 22 11 - 1
链表：99 88 77 66 55 44 33 22 11
输入一个需要插入的成绩
67
输入插入位置
3
插入后的链表：99 88 77 67 66 55 44 33 22 11
输入删除位置
4
删除后的链表：99 88 77 66 55 44 33 22 11*/

#include<stdio.h>
#include<stdlib.h>

struct node //结构定义放在需要使用的函数前面
{
	int data;
	struct node *next;
};

struct node* initlist(struct node *t) //初始化链表
{
	int tem;
	struct node *p;
	struct node *m;
	int n, i;
	m = t;
	printf("输入学生成绩：");
	while (1)
	{
		scanf_s("%d", &tem);
		if (tem > 0) //判断输入数据的正负
		{
			p = (struct node*)malloc(sizeof(struct node));
			p->data = tem;
			if (t->next == NULL) //用于生成链表
			{
				t->next = p;
				p->next = NULL; //单链表
				t = t->next;
			}
		}
		else //为负则结束
		{
			break;
		}
	}
	return m; //返回头结点
}

struct node* insert(struct node *t) //插入函数
{
	int n, i = 1, sc;
	struct node *m = t;
	printf("输入一个需要插入的成绩：\n");
	scanf_s("%d", &sc);
	printf("输入插入位置：\n");
	scanf_s("%d", &n);
	while (i < n + 1) //将m指向第n个存储数据的结点
	{
		m = m->next;
		i += 1;
	}
	struct node *p = (struct node*)malloc(sizeof(struct node));
	p->data = sc;
	p->next = m->next; //插入结点
	m->next = p;
	return t;
}

struct node* del(struct node *t) //删除函数
{
	int n, i = 1;
	struct node *m = t;
	struct node *p;
	printf("输入删除位置：\n");
	scanf_s("%d", &n);
	while (i < n) //将m指向第n-1个存储数据的结点
	{
		m = m->next;
		i += 1;
	}
	p = m->next; //将第n-1个存储数据的结点指向第n+1个
	m->next = p->next;
	return t;
}

int listprint(struct node *L) //打印链表元素
{
	while (L)
	{
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
	return 0;
}

int main()
{
	struct node *ha = (struct node*)malloc(sizeof(struct node));
	ha->next = NULL;
	initlist(ha); //初始化链表
	printf("链表：");
	listprint(ha->next); //打印链表

	insert(ha); //插入
	printf("插入后的链表：");
	listprint(ha->next); //打印链表

	del(ha); //删除
	printf("删除后的链表：");
	listprint(ha->next); //打印链表

	system("pause");
	return 0;
}