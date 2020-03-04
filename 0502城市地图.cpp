#include <stdio.h>
int min=999999999,book[101],n,e[101][101];
void dfs(int cur,int dis){
	int j;
	if(dis>min) return;
	if(cur==n){
		if(dis<min) min=dis;
		return ;
	}
	for(j=1;j<=n;j++){
		if(e[cur][j]!=999999999&&book[j]==0){
			book[j]=1;
			dfs(j,dis+e[cur][j]);
			book[j]=0;
		}
	}
	return ;
} 
int main(){
	int i,j,m,a,b,c;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j]=0;
			else e[i][j]=999999999;
	for(i=1;i<=m;i++){
		scanf("%d %d %d",&a,&b,&c);
		e[a][b]=c;
	}
	book[1]=1;
	dfs(1,0);
	printf("%d",min);
	return 0;
}
/*
ÊäÈë
5 8
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3
Êä³ö
9
*/ 
