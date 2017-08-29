/*第二题：

给定一棵树，求其最小生成树。

输入：n行，每行三个整数，分别代表父节点，子节点和权值。

输出：输出权值总和

*/

#include<stdlib.h>
#include<stdio.h>

#define INF 65535 //定义无穷大
#define n 9 //定义结点数

int main()
{
	int min, i, j, k, t, sum = 0;
	int arc[n][n] = { INF,10,INF,INF,INF,11,INF,INF,INF, //初始化邻接矩阵
		INF,INF,18,INF,INF,INF,16,INF,12,
		INF,INF,INF,22,INF,INF,INF,INF,8,
		INF,INF,INF,INF,20,INF,24,16,21,
		INF,INF,INF,INF,INF,26,INF,7,INF,
		INF,INF,INF,INF,INF,INF,17,INF,INF,
		INF,INF,INF,INF,INF,INF,INF,19,INF,
		INF,INF,INF,INF,INF,INF,INF,INF,INF,
		INF,INF,INF,INF,INF,INF,INF,INF,INF };

	int low[n]; //保存相关顶点间边的权值
	int vex[n]; //保存相关顶点下标

	for (j = 0; j<n; j++) { //以0结点为准，初始化low和vex
		low[j] = arc[0][j];
		vex[j] = 0;
	}

	for (k = 1; k<n; k++) {
		min = INF; //初始化min为无穷大
		t = 0;
		for (j = 0; j<n; j++) {
			if (low[j] != 0 && low[j]<min) { //如果权值不为0且权值小于min
				min = low[j]; //让当前权值成为min
				t = j; //记录当前权值的下标
			}
		}
		printf("(%d,%d) %d\n", vex[t], t, min); //输出当前顶点边中权值最小的边
		sum += min; //计算总权值
		low[t] = 0; //当前顶点的权值设置为0，表示此顶点已经完成任务
		for (j = 0; j<n; j++) {
			if (low[j] != 0 && arc[t][j]<low[j]) { //若下标为t的顶点各边权值小于此前这些顶点未被加入生成树权值
				low[j] = arc[t][j]; //将较小权值存入lowcost
				vex[j] = t; //将下标为t的顶点存入vex
			}
		}
	}
	printf("权值总和为： %d", sum);

	system("pause");
	return 0;
}