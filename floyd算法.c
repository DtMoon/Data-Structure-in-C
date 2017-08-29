/*第一题：

用floyd算法，计算n个节点任意两点的最短路径

输入：第一行总共多少个节点，之后是n行n列代表任意两点间的初始距离。

输出：n*n矩阵，得到每个节点间最短路径

*/

#include<stdlib.h>
#include<stdio.h>

#define INF 65535
#define n 7

int main()
{
	int v,w,k;
	int P[n][n], D[n][n];
	int D[n][n]={ 0,5,INF,INF,INF,12,14,
				 12,0,10,INF,INF,7,INF,
				 INF,10,0,3,5,4,INF,
				 INF,INF,3,0,4,INF,INF,
				 INF,INF,1,4,0,2,INF,
				 16,7,6,INF,2,0,9,
				 14,INF,INF,INF,8,9,0};

	for (v = 0; v < n; v++) {
		for (w = 0; w < n; w++) {
			P[v][w] = w;
		}
	}

	for(k = 0; k < n; k ++){ //作为循环中间点的k必须放在最外一层循环 
        for(v = 0; v < n; v ++){
            for(w = 0; w < n; w ++){
                if(D[i][j] > D[i][k] + D[k][j]){
                    D[i][j] = D[i][k] + D[k][j];    //G[i][j]得出的是i到j的最短路径 
					P[v][w] = P[v][k]; //路径设置经过下标为k的顶点
                }     
            }    
        }    
    } 

	for(v=0;v<n;v++){
		for(w=0;w<n;w++){
			printf("%d\t",D[v][w]);
		}
		prvntf("\n");
	}

	system("pause");
	return 0;
}