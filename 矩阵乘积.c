/*题目一：矩阵乘积
输入第一行为三个整数m n p,表示之后会输入两个矩阵，第一个矩阵为m*n的，第二个矩阵为n*p的。
之后输入m行n列的整数表示第一个矩阵。
再之后输入n行p列的整数表示第二个矩阵。
要求输出两个矩阵的积，输出为m行p列的整数。
输入输出的数都用一个空格格开。（m,n,p均大于0小于100，矩阵中的整数绝对值均小于100）
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
	scanf("%d %d %d",&m,&n,&p); //输入矩阵行列数
	a = (int **)malloc(sizeof(int *)*m); //申请动态数组
	for (i=0; i<m; i++) 
		a[i] = (int *)malloc(sizeof(int)*n); 
	b = (int **)malloc(sizeof(int *)*n);  //申请动态数组
	for (i=0; i<n; i++) 
		b[i] = (int *)malloc(sizeof(int)*p); 
	c = (int **)malloc(sizeof(int *)*m);  //申请动态数组
	for (i=0; i<m; i++) 
		c[i] = (int *)malloc(sizeof(int)*p); 

	for(i=0;i<m;i++){ //输入第一个矩阵
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++){ //输入第二个矩阵
		for(j=0;j<p;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<m;i++){ //用于储存结果的矩阵初始化
		for(j=0;j<p;j++){
			c[i][j]=0;
		}
	}
	
	for(i=0;i<m;i++){ //矩阵相乘
		for(j=0;j<p;j++){
			for(k=0;k<n;k++){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}

	for(i=0;i<m;i++){ //输出结果矩阵
		for(j=0;j<p;j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}