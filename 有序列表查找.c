/*
��Ŀһ�������б����
����n������������t���ѯ�����ÿ�β�ѯ�Ľ����
���빲4�С�
�����һ��һ������n,��ʾ֮�������n�������������
����ڶ���Ϊn���ո���ÿ����������ֱ��ʾ������
���������һ������t,��ʾ֮�������t����ѯ��
���������Ϊt���ո���ÿ����������ֱ�ÿ�β�ѯ�Ľ��������ҵ������ԭ�����е�λ�ã����û�ҵ����"N"��

���Ϊt����������ʾÿ�β�ѯ�Ľ����
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

int Bisearch(int *a, int n, int p) //�۰����
{
	int low = 0, high = n - 1, mid, i;
	while (low <= high)
	{
		mid = (low + high) / 2; //�۰�
		if (a[mid]>p) high = mid - 1; //����ֵ�Ȳ���ֵ������±����Ϊ��λ�±��1
		else if (a[mid]<p) low = mid + 1; //����ֵ�Ȳ���ֵС������±����Ϊ��λ�±��1
		else return mid; //����ȣ�˵��mid��Ϊ���ҵ���λ��
	}
	return -1;
}

void main()
{
	int n, i, num, pos;
	int *a, *b;
	printf("Input:\n");
	scanf_s("%d", &n); //��������Ԫ�ظ���
	a = (int*)malloc(sizeof(int)*n); //��̬����
	for (i = 0; i<n; i++)
	{
		scanf_s("%d", &a[i]); //��������Ԫ��
	}
	scanf_s("%d", &num); //����Ҫ���ҵ�Ԫ�ظ���
	b = (int *)malloc(sizeof(int)*num);
	for (i = 0; i<num; i++) scanf_s("%d", &b[i]); //����Ҫ���ҵ�Ԫ��
	printf("Output:\n");
	for (i = 0; i<num; i++)
	{
		pos = Bisearch(a, n, b[i]); //�۰����
		if (pos == -1) printf("N\n"); //û�ҵ������N
		else printf("%d\n", pos); //�ҵ������λ��
	}

	system("pause");
	return;
}