/*ʵ��һ

C����ʵ�� ǰ�����򡢺������������

����Ϊ��AB#C##D##(����һ����ǰ���ȣ�������Ķ������ı���������������������Ϊ��ʱ������#�Ŵ���)

�磺AB##C##����AΪ����BΪ��CΪ�ҵĶ�����

AB###��AΪ����BΪ��Ķ�����

A#B##��AΪ����BΪ�ҵĶ�����

������

����Ϊ��

AB#C##D##

���Ϊ��

ǰ����������� A B C D

������������� B C A D

������������� C B D A

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

void Preorder(BiTree T) //ǰ�����
{
	if (T) //��ǰ��㲻��
	{
		printf("%c ", T->data); //������ֵ
		Preorder(T->lchild); //�ݹ�������
		Preorder(T->rchild); //�ݹ�������
	}
	return;
}

void Inorder(BiTree T) //�������
{
	if (T) //��ǰ��㲻��
	{
		Inorder(T->lchild); //�ݹ�������
		printf("%c ", T->data); //������ֵ
		Inorder(T->rchild); //�ݹ�������
	}
	return;
}

void Postorder(BiTree T) //�������
{
	if (T) //��ǰ��㲻��
	{
		Postorder(T->lchild); //�ݹ�������
		Postorder(T->rchild); //�ݹ�������
		printf("%c ", T->data); //������ֵ
	}
	return;
}

void main()
{
	BiTree T = NULL;
	CreateBiTree(&T); //����һ����
	printf("ǰ�������");
	Preorder(T);
	printf("\n");
	printf("���������");
	Inorder(T);
	printf("\n");
	printf("���������");
	Postorder(T);

	system("pause");
	return;
}