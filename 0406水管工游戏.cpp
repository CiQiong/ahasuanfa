/* 
#include <cstdio>
int a[51][51];//假设土地的大小不超过50*50
int book[51][51],n,m,flag=0; 
void dfs(int x,int y,int front){//x和y表示当前处理格子的坐标，front表示进水口方向
	int i;
	//判断是否到达终点（n,m+1) 
	//另外判断是否到达终点一定要放在越界判断前面
	if(x==n&&y==m+1){
		flag=1;//找到铺设方案
		return ; 
	} 
	//判断是否越界
	if(x<1||x>n||y<1||y>m) return ;
	//判断这个管道是否在路径中使用过
	if(book[x][y]==1) return ;
	book[x][y]=1;//标记使用过当前这个管道
	//当前水管是直管的情况
	if(a[x][y]==5||a[x][y]==6){
		if(front==1)//进水口在左边
			dfs(x,y+1,1);//右方进水口在左边
		if(front==2)//进水口在上边
			dfs(x+1,y,2);//下方进水口在上边
		if(front==3)//进水口在右边
			dfs(x,y-1,3);//左边进水口在右边 
		if(front==4)//进水口在左边
			dfs(x-1,y,4);//上方进水口在下边
	}
	//当前水管是弯管的情况
	if(a[x][y]>=1&&a[x][y]<=4){
		if(front==1){
			dfs(x+1,y,2);
			dfs(x-1,y,4);
		}
		if(front==2){
			dfs(x,y+1,1);
			dfs(x,y-1,3);
		}
		if(front==3){
			dfs(x-1,y,4);
			dfs(x+1,y,2);
		}
		if(front==4){
			dfs(x,y+1,1);
			dfs(x,y-1,3);
		}
	} 
	book[x][y]=0;//取消标记
	return ; 
}
int main(){
	int i,j,num=0;
	scanf("%d %d",&n,&m);
	//读入游戏地图
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	//开始搜索，从1,1开始，进水方向也是1
	dfs(1,1,1);
	//判断是否找到铺设方案
	if(flag==0)
		printf("impossible\n");
	else 
		printf("找到铺设方案\n");
	return 0; 
}
*/ 
/*
输入
5 4
5 3 5 3
1 5 3 0
2 3 5 1
6 1 1 5
1 5 5 4
输出
找到铺设方案
*/

//输出路径 
#include <cstdio>
int a[51][51];
int book[51][51],n,m,flag=0; 
struct note{//////
	int x;//横坐标////
	int y;//纵坐标////
}s[100];/////
int top=0;//////
void dfs(int x,int y,int front){
	int i;
	if(x==n&&y==m+1){
		flag=1;
		for(i=1;i<=top;i++)/////
			printf("(%d,%d) ",s[i].x,s[i].y);/////
		return ; 
	}
	if(x<1||x>n||y<1||y>m) return ;
	if(book[x][y]==1) return ;
	book[x][y]=1;
	//将当前尝试的坐标入栈
	top++;/////
	s[top].x=x;/////
	s[top].y=y;///// 
	if(a[x][y]==5||a[x][y]==6){
		if(front==1)
			dfs(x,y+1,1);
		if(front==2)
			dfs(x+1,y,2);
		if(front==3)
			dfs(x,y-1,3);
		if(front==4)
			dfs(x-1,y,4);
	}
	if(a[x][y]>=1&&a[x][y]<=4){
		if(front==1){
			dfs(x+1,y,2);
			dfs(x-1,y,4);
		}
		if(front==2){
			dfs(x,y+1,1);
			dfs(x,y-1,3);
		}
		if(front==3){
			dfs(x-1,y,4);
			dfs(x+1,y,2);
		}
		if(front==4){
			dfs(x,y+1,1);
			dfs(x,y-1,3);
		}
	} 
	book[x][y]=0;
	top--;//将当前尝试的坐标出栈////// 
	return ; 
}
int main(){
	int i,j,num=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	dfs(1,1,1);
	if(flag==0)
		printf("impossible\n");
	else 
		printf("找到铺设方案\n");
	return 0; 
}
/*
输入
5 4
5 3 5 3
1 5 3 0
2 3 5 1
6 1 1 5
1 5 5 4
输出
(1,1) (1,2) (2,2) (3,2) (3,3) (3,4) (4,4) (5,4) 找到铺设方案
*/
