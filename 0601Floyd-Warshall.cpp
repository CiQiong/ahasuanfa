#include <cstdio>
int main(){
	int e[10][10],k,i,j,n,m,t1,t2,t3;
	int inf=99999999;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j]=0;
			else e[i][j]=inf;
	for(i=1;i<=m;i++){
		scanf("%d %d %d",&t1,&t2,&t3);//t1到t2的路程是t3 
		e[t1][t2]=t3;
	}
	//核心 
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(e[i][j]>e[i][k]+e[k][j])
					e[i][j]=e[i][k]+e[k][j];
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%5d",e[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/*
输入
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12 
输出
    0    2    5    4
    9    0    3    4
    6    8    0    1
    5    7   10    0
*/ 
