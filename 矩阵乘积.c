/*��Ŀһ������˻�
�����һ��Ϊ��������m n p,��ʾ֮��������������󣬵�һ������Ϊm*n�ģ��ڶ�������Ϊn*p�ġ�
֮������m��n�е�������ʾ��һ������
��֮������n��p�е�������ʾ�ڶ�������
Ҫ�������������Ļ������Ϊm��p�е�������
���������������һ���ո�񿪡���m,n,p������0С��100�������е���������ֵ��С��100��
Input:
2 3 2
1 0 2
-1 3 1
3 1
2 1
1 0

Output
5 1
4 2 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,k,m,n,p;
	int **a,**b,**c;
	printf("Input:\n");
	scanf("%d %d %d",&m,&n,&p); //�������������
	a = (int **)malloc(sizeof(int *)*m); //���붯̬����
	for (i=0; i<m; i++) 
		a[i] = (int *)malloc(sizeof(int)*n); 
	b = (int **)malloc(sizeof(int *)*n);  //���붯̬����
	for (i=0; i<n; i++) 
		b[i] = (int *)malloc(sizeof(int)*p); 
	c = (int **)malloc(sizeof(int *)*m);  //���붯̬����
	for (i=0; i<m; i++) 
		c[i] = (int *)malloc(sizeof(int)*p); 

	for(i=0;i<m;i++){ //�����һ������
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++){ //����ڶ�������
		for(j=0;j<p;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<m;i++){ //���ڴ������ľ����ʼ��
		for(j=0;j<p;j++){
			c[i][j]=0;
		}
	}
	
	for(i=0;i<m;i++){ //�������
		for(j=0;j<p;j++){
			for(k=0;k<n;k++){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}

	for(i=0;i<m;i++){ //����������
		for(j=0;j<p;j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}