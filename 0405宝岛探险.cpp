/*
//广度优先 
#include <cstdio>
struct node{
	int x,y;
};
int main(){
	struct node que[2501];
	int head,tail;
	int a[51][51];
	int book[51][51]={0};
	int i,j,k,sum,max=0,mx,my,n,m,startx,starty,tx,ty;
	//定义一个方向数组
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	//读入n行m列以及小哼降落的坐标 
	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	//读入地图
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	//队列初始化
	head=1;
	tail=1;
	//往队列中插入降落的起始坐标
	que[tail].x=startx;
	que[tail].y=starty;
	tail++;
	book[startx][starty]=1;
	sum=1;
	//当队列不空时循环
	while(head<tail){
		//枚举4个方向
		for(k=0;k<=3;k++){
			//计算下一步的坐标
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			//判断是否越界
			if(tx<1||tx>n||ty<1||ty>m) continue;
			//如果是陆地且没有走过
			if(a[tx][ty]>0&&book[tx][ty]==0){
				sum++;
				//每个点只入队一次，所以需要标记这个点已经走过
				book[tx][ty]=1;
				//将新扩展的点加入队列
				que[tail].x=tx;
				que[tail].y=ty;
				tail++; 
			}
		}
		head++;//注意这里千万不要忘记,
		//当一个点扩展结束后，head++才能对后面的点再进行扩展 
	}
	//最后输出岛屿的大小
	printf("%d\n",sum);
	return 0; 
}
*/
/*
输入 
10 10 6 8 
1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 1 0
输出 
38 
*/ 


/*
//深度优先 
#include <cstdio>
int a[51][51];
int book[51][51],n,m,sum;
void dfs(int x,int y){
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int k,tx,ty;
	for(k=0;k<=3;k++){
		//计算下一步的坐标
		tx=x+next[k][0];
		ty=y+next[k][1];
		//判断是否越界
		if(tx<1||tx>n||ty<1||ty>m) continue;
		//如果是陆地且没有走过
		if(a[tx][ty]>0&&book[tx][ty]==0){
			sum++;
			book[tx][ty]=1;
			dfs(tx,ty);//开始尝试下一个点 
		}
	}
	return ; 
} 
int main(){
	int i,j,startx,starty;
	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	//读入地图
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	book[startx][starty]=1;
	sum=1;
	//从降落位置开始 
	dfs(startx,starty);
	//最后输出岛屿的大小
	printf("%d\n",sum);
	return 0; 
}
*/


/*
//染色
#include <cstdio>
int a[51][51];
int book[51][51],n,m,sum;
void dfs(int x,int y,int color){//,int color
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int k,tx,ty;
	a[x][y]=color;//对a[x][y]这个格子进行染色 
	for(k=0;k<=3;k++){
		tx=x+next[k][0];
		ty=y+next[k][1];
		if(tx<1||tx>n||ty<1||ty>m) continue;
		if(a[tx][ty]>0&&book[tx][ty]==0){
			sum++;
			book[tx][ty]=1;
			dfs(tx,ty,color);//,color
		}
	}
	return ; 
} 
int main(){
	int i,j,startx,starty;
	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	book[startx][starty]=1;
	sum=1;
	dfs(startx,starty,-1);//,-1
	printf("%d\n",sum);
	//输出已经染色后的地图
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("%3d",a[i][j]);//%3d中的3是c语言中的场宽 
		}
		printf("\n");
	}
	return 0; 
} 
*/
/*
输入 
10 10 6 8 
1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 1 0
输出 
38
  1  2  1  0  0  0  0  0  2  3
  3  0  2  0 -1 -1 -1  0  1  2
  4  0  1  0 -1 -1 -1 -1  0  1
  3  2  0  0  0 -1 -1 -1  0  0
  0  0  0  0  0  0 -1 -1 -1  0
  0 -1 -1 -1  0 -1 -1 -1 -1  0
  0 -1 -1 -1 -1 -1 -1 -1 -1  0
  0  0 -1 -1 -1 -1 -1 -1  0  0
  0  0  0 -1 -1 -1 -1  0  1  2
  0  0  0  0  0  0  0  0  1  0
*/

//给各个小岛染色并求小岛个数
//求一个图中独立子图的个数，Floodfill漫水填充法/种子填充法 
#include <cstdio>
int a[51][51];
int book[51][51],n,m,sum;
void dfs(int x,int y,int color){
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int k,tx,ty;
	a[x][y]=color;
	for(k=0;k<=3;k++){
		tx=x+next[k][0];
		ty=y+next[k][1];
		if(tx<1||tx>n||ty<1||ty>m) continue;
		if(a[tx][ty]>0&&book[tx][ty]==0){
			sum++;
			book[tx][ty]=1;
			dfs(tx,ty,color);
		}
	}
	return ; 
}
int main(){
	int i,j,num=0;
	scanf("%d %d",&n,&m);
	//读入地图 
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	//对每一个大于0的点尝试进行dfs染色
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j]>0){
				num--;//小岛需要染的颜色的编号
				//每发现一个小岛应染以不同的颜色,因此要-1
				book[i][j]=1;
				dfs(i,j,num); 
			}
		}
	}
	//输出已经染色后的地图
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("%3d",a[i][j]);//%3d中的3是c语言中的场宽 
		}
		printf("\n");
	}
	//输出小岛的个数
	printf("有%d个小岛\n",-num); 
	return 0; 
}
/*
输入 
10 10
1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 1 0
输出
 -1 -1 -1  0  0  0  0  0 -2 -2
 -1  0 -1  0 -3 -3 -3  0 -2 -2
 -1  0 -1  0 -3 -3 -3 -3  0 -2
 -1 -1  0  0  0 -3 -3 -3  0  0
  0  0  0  0  0  0 -3 -3 -3  0
  0 -3 -3 -3  0 -3 -3 -3 -3  0
  0 -3 -3 -3 -3 -3 -3 -3 -3  0
  0  0 -3 -3 -3 -3 -3 -3  0  0
  0  0  0 -3 -3 -3 -3  0 -4 -4
  0  0  0  0  0  0  0  0 -4  0
有4个小岛
*/
