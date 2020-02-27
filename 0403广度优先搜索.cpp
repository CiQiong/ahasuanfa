#include <stdio.h>
struct note{
	int x;//横坐标
	int y;//纵坐标
	int f;//父亲在队列中的编号（求路径用） 
	int s;//步数 
};

int main(){
	struct note que[2501];//因为地图大小不超过50*50，因此队列扩展不会超过2500个
	int a[51][51]={0};//用来存储地图
	//定义一个用于表示走的方向的数组
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int head,tail;
	int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	//最开始的时候需要进行队列初始化，即将队列设置为空
	head=1;
	tail=1;
	//往队列插入迷宫入口坐标
	que[tail].x=startx;
	que[tail].y=starty;
	que[tail].f=0;
	que[tail].s=0; 
	tail++;
	int book[51][51]={0};//数组book用来记录哪些点已经在队列中了，
	//防止一个点被重复扩展，并全部初始化为0
	book[startx][starty]=1;
	
	flag=0;//用来标记是否到达目标点，0表示暂时还没有到达，1表示到达
	//当前队列不为空时循环
	while(head<tail){
		//枚举4个方向
		for(k=0;k<=3;k++){
			//计算下一个点的坐标
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			//判断是否越界
			if(tx<1||tx>n||ty<1||ty>m) continue;
			//判断该点是否为障碍物或者已经在路径中
			if(a[tx][ty]==0&&book[tx][ty]==0){
				//标记这个点已经走过
				//注意宽搜每个点通常情况下只入队一次，
				//和深搜不同，不需要将book数组还原
				book[tx][ty]=1;
				//插入新的点到队列中
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].f=head;//因为这个点是从head扩展来的，所以他的父亲是head 
				que[tail].s=que[head].s+1;//步数是父亲的步数+1
				tail++; 
			}
			//如果到目标点了，停止扩展，任务结束，退出循环
			if(tx==p&&ty==q){
				//注意千万不能写反
				flag=1;
				break; 
			}
		}
		if(flag==1) break;
		head++;//注意这里千万不要忘记，当一个点扩展结束后，head++才能对后面的点再进行扩展
	}	
	//打印队列中末尾最后一个点（目标点）的步数
	//注意tail只想队列尾的下一个位置，所以需要-1
	printf("%d",que[tail-1].s);
	return 0;
} 

/*
输入
5 4
0 0 1 0
0 0 0 0
0 0 1 0
0 1 0 0
0 0 0 1
1 1 4 3
输出 
7
*/
