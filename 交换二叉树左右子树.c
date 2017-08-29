/*实验二

将二叉树所有节点的左右子节点互换

输入：一个按先序遍历的二叉树的遍历结果，如果遍历到孩子为空时，则用#号代替。

如：AB##C##是以A为根，B为左，C为右的

AB###是A为根，B为左的二叉树

A#B##是A为根，B为右的二叉树

输出：输出为先序遍历的结果

AC##B##

A#B##

AB###
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

void exchange(BiTree *T) //交换左右子节点函数
{
	BiTree p;
	if (!(*T)) return; //递归结束条件
	else {
		p = (BiTNode*)malloc(sizeof(BiTNode)); //申请内存
		p = (*T)->rchild; //存储右孩子地址
		(*T)->rchild = (*T)->lchild; //右孩子地址变为左孩子地址
		(*T)->lchild = p; //左孩子地址变为右孩子地址
		exchange(&(*T)->lchild); //对左子树递归
		exchange(&(*T)->rchild); //对右子树递归
	}
	return;
}

void Preorder(BiTree T) //前序遍历
{
	if (T) //当前结点不空
	{
		printf("%c", T->data); //输出结点值
		Preorder(T->lchild); //递归左子树
		Preorder(T->rchild); //递归右子树
	}
	else printf("#");
	return;
}

void main()
{
	BiTree T = NULL;
	CreateBiTree(&T); //生成一棵树
	exchange(&T); //交换左右子结点
	printf("前序遍历：");
	Preorder(T); //前序遍历输出
	printf("\n");

	system("pause");
	return;
}