/*��һ�⣺

��floyd�㷨������n���ڵ�������������·��

���룺��һ���ܹ����ٸ��ڵ㣬֮����n��n�д������������ĳ�ʼ���롣

�����n*n���󣬵õ�ÿ���ڵ�����·��

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

	for(k = 0; k < n; k ++){ //��Ϊѭ���м���k�����������һ��ѭ�� 
        for(v = 0; v < n; v ++){
            for(w = 0; w < n; w ++){
                if(D[i][j] > D[i][k] + D[k][j]){
                    D[i][j] = D[i][k] + D[k][j];    //G[i][j]�ó�����i��j�����·�� 
					P[v][w] = P[v][k]; //·�����þ����±�Ϊk�Ķ���
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