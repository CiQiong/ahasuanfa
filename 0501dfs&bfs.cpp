/*
//dfs
#include <cstdio>
int book[101],sum,n,e[101][101];
void dfs(int cur){//cur是当前所在的顶点编号
	int i;
	printf("%d ",cur);
	sum++;//每访问一个顶点，sum就加1
	if(sum==n) return ;//所有顶点都已经访问过则直接退出
	for(i=1;i<=n;i++){//从1号顶点到n号顶点依次尝试，看哪些顶点与当前顶点cur有边相连
		//判断当前顶点cur到顶点i是否有边，并判断顶点i是否已访问过
		if(e[cur][i]==1&&book[i]==0){
			book[i]=1;//标记顶点i已经访问过
			dfs(i);//从顶点i再出发继续遍历 
		} 
	} 
	return ;
}
int main(){
	int i,j,m,a,b;
	scanf("%d %d",&n,&m);
	//初始化二维矩阵
	for(i=1;i<n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j]=0;
			else e[i][j]=99999999;//这里假设99999999为正无穷
	//读入顶点之间的边
	for(i=1;i<=m;i++){
		scanf("%d %d",&a,&b);
		e[a][b]=1;
		e[b][a]=1;//无向图 
	} 
	//从1号城市出发
	book[1]=1;//标记1号顶点已访问
	dfs(1);//从1号顶点开始遍历
	return 0; 
}
*/
/*
输入
5 5
1 2
1 3
1 5
2 4
3 5 
输出
1 2 4 3 5 
*/

//bfs
#include <stdio.h>
int main(){
	int i,j,n,m,a,b,cur,book[101]={0},e[101][101];
	int que[10001],head,tail;
	scanf("%d %d",&n,&m);
	//初始化二维矩阵
	for(i=1;i<n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j]=0;
			else e[i][j]=99999999;//这里假设99999999为正无穷
	//读入顶点之间的边
	for(i=1;i<=m;i++){
		scanf("%d %d",&a,&b);
		e[a][b]=1;
		e[b][a]=1;//无向图 
	}
	//队列初始化
	head=1;tail=1;
	//从1号顶点出发，将1号顶点加入队列 
	que[tail]=1; 
	tail++;
	book[1]=1;//记录1号顶点已经访问
	//当队列不空的时候循环
	while(head<tail){
		cur=que[head];//当前正在访问的顶点编号
		for(i=1;i<=n;i++){//从1~n依次尝试
			//判断当前顶点cur到顶点i是否有边，并判断顶点i是否已访问过
			if(e[cur][i]==1&&book[i]==0){
				que[tail]=i;
				tail++;
				book[i]=1;//标记顶点i已经访问过
			}
			//如果tail大于n，则表明所有顶点都已经被访问过
			if(tail>n) break; 
		}
		head++;//当一个顶点扩展结束后，head++，才嫩继续扩展 
	}
	for(i=1;i<tail;i++)
		printf("%d ",que[i]);
	return 0; 
} 
/*
输入
5 5
1 2
1 3
1 5
2 4
3 5 
输出
1 2 3 5 4
*/
