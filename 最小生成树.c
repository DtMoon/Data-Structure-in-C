/*�ڶ��⣺

����һ������������С��������

���룺n�У�ÿ�������������ֱ�����ڵ㣬�ӽڵ��Ȩֵ��

��������Ȩֵ�ܺ�

*/

#include<stdlib.h>
#include<stdio.h>

#define INF 65535 //���������
#define n 9 //��������

int main()
{
	int min, i, j, k, t, sum = 0;
	int arc[n][n] = { INF,10,INF,INF,INF,11,INF,INF,INF, //��ʼ���ڽӾ���
		INF,INF,18,INF,INF,INF,16,INF,12,
		INF,INF,INF,22,INF,INF,INF,INF,8,
		INF,INF,INF,INF,20,INF,24,16,21,
		INF,INF,INF,INF,INF,26,INF,7,INF,
		INF,INF,INF,INF,INF,INF,17,INF,INF,
		INF,INF,INF,INF,INF,INF,INF,19,INF,
		INF,INF,INF,INF,INF,INF,INF,INF,INF,
		INF,INF,INF,INF,INF,INF,INF,INF,INF };

	int low[n]; //������ض����ߵ�Ȩֵ
	int vex[n]; //������ض����±�

	for (j = 0; j<n; j++) { //��0���Ϊ׼����ʼ��low��vex
		low[j] = arc[0][j];
		vex[j] = 0;
	}

	for (k = 1; k<n; k++) {
		min = INF; //��ʼ��minΪ�����
		t = 0;
		for (j = 0; j<n; j++) {
			if (low[j] != 0 && low[j]<min) { //���Ȩֵ��Ϊ0��ȨֵС��min
				min = low[j]; //�õ�ǰȨֵ��Ϊmin
				t = j; //��¼��ǰȨֵ���±�
			}
		}
		printf("(%d,%d) %d\n", vex[t], t, min); //�����ǰ�������Ȩֵ��С�ı�
		sum += min; //������Ȩֵ
		low[t] = 0; //��ǰ�����Ȩֵ����Ϊ0����ʾ�˶����Ѿ��������
		for (j = 0; j<n; j++) {
			if (low[j] != 0 && arc[t][j]<low[j]) { //���±�Ϊt�Ķ������ȨֵС�ڴ�ǰ��Щ����δ������������Ȩֵ
				low[j] = arc[t][j]; //����СȨֵ����lowcost
				vex[j] = t; //���±�Ϊt�Ķ������vex
			}
		}
	}
	printf("Ȩֵ�ܺ�Ϊ�� %d", sum);

	system("pause");
	return 0;
}