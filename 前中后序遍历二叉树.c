/*实验一

C语言实现 前序、中序、后序遍历二叉树

输入为：AB#C##D##(输入一个按前（先）序遍历的二叉树的遍历结果，如果遍历到孩子为空时，则用#号代替)

如：AB##C##是以A为根，B为左，C为右的二叉树

AB###是A为根，B为左的二叉树

A#B##是A为根，B为右的二叉树

样例：

输入为：

AB#C##D##

输出为：

前序遍历左子树 A B C D

中序遍历左子树 B C A D

后序遍历左子树 C B D A

*/

#include<stdlib.h>
#include<stdio.h>

typedef struct BiTNode { //定义树结构
	char data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void CreateBiTree(BiTree *T) { //生成树的函数
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#') *T = NULL; //当前值为'#'，说明是空结点
	else {
		*T = (BiTNode*)malloc(sizeof(BiTNode)); //当前值不为'#',申请新内存存储该值
		(*T)->lchild = NULL; //左孩子初始化为空
		(*T)->rchild = NULL; //右孩子初始化为空
		(*T)->data = ch; //存储当前值
		CreateBiTree(&((*T)->lchild)); //建立左子树
		CreateBiTree(&((*T)->rchild)); //建立右子树
	}
	return;
}

void Preorder(BiTree T) //前序遍历
{
	if (T) //当前结点不空
	{
		printf("%c ", T->data); //输出结点值
		Preorder(T->lchild); //递归左子树
		Preorder(T->rchild); //递归右子树
	}
	return;
}

void Inorder(BiTree T) //中序遍历
{
	if (T) //当前结点不空
	{
		Inorder(T->lchild); //递归左子树
		printf("%c ", T->data); //输出结点值
		Inorder(T->rchild); //递归右子树
	}
	return;
}

void Postorder(BiTree T) //后序遍历
{
	if (T) //当前结点不空
	{
		Postorder(T->lchild); //递归左子树
		Postorder(T->rchild); //递归右子树
		printf("%c ", T->data); //输出结点值
	}
	return;
}

void main()
{
	BiTree T = NULL;
	CreateBiTree(&T); //生成一棵树
	printf("前序遍历：");
	Preorder(T);
	printf("\n");
	printf("中序遍历：");
	Inorder(T);
	printf("\n");
	printf("后序遍历：");
	Postorder(T);

	system("pause");
	return;
}