/*ʵ���

�����������нڵ�������ӽڵ㻥��

���룺һ������������Ķ������ı���������������������Ϊ��ʱ������#�Ŵ��档

�磺AB##C##����AΪ����BΪ��CΪ�ҵ�

AB###��AΪ����BΪ��Ķ�����

A#B##��AΪ����BΪ�ҵĶ�����

��������Ϊ��������Ľ��

AC##B##

A#B##

AB###
*/

#include<stdlib.h>
#include<stdio.h>

typedef struct BiTNode { //�������ṹ
	char data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void CreateBiTree(BiTree *T) { //�������ĺ���
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#') *T = NULL; //��ǰֵΪ'#'��˵���ǿս��
	else {
		*T = (BiTNode*)malloc(sizeof(BiTNode)); //��ǰֵ��Ϊ'#',�������ڴ�洢��ֵ
		(*T)->lchild = NULL; //���ӳ�ʼ��Ϊ��
		(*T)->rchild = NULL; //�Һ��ӳ�ʼ��Ϊ��
		(*T)->data = ch; //�洢��ǰֵ
		CreateBiTree(&((*T)->lchild)); //����������
		CreateBiTree(&((*T)->rchild)); //����������
	}
	return;
}

void exchange(BiTree *T) //���������ӽڵ㺯��
{
	BiTree p;
	if (!(*T)) return; //�ݹ��������
	else {
		p = (BiTNode*)malloc(sizeof(BiTNode)); //�����ڴ�
		p = (*T)->rchild; //�洢�Һ��ӵ�ַ
		(*T)->rchild = (*T)->lchild; //�Һ��ӵ�ַ��Ϊ���ӵ�ַ
		(*T)->lchild = p; //���ӵ�ַ��Ϊ�Һ��ӵ�ַ
		exchange(&(*T)->lchild); //���������ݹ�
		exchange(&(*T)->rchild); //���������ݹ�
	}
	return;
}

void Preorder(BiTree T) //ǰ�����
{
	if (T) //��ǰ��㲻��
	{
		printf("%c", T->data); //������ֵ
		Preorder(T->lchild); //�ݹ�������
		Preorder(T->rchild); //�ݹ�������
	}
	else printf("#");
	return;
}

void main()
{
	BiTree T = NULL;
	CreateBiTree(&T); //����һ����
	exchange(&T); //���������ӽ��
	printf("ǰ�������");
	Preorder(T); //ǰ��������
	printf("\n");

	system("pause");
	return;
}