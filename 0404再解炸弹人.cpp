/*
#include <cstdio>
struct note{
	int x;//横坐标
	int y;//纵坐标 
}; 
char a[20][20];//用来存储地图.
int getnum(int i,int j){
	int sum,x,y;
	sum=0;//sum用来计数（可以消灭的敌人数），所以需要初始化为0
	//将坐标i，j复制到两个新变量x，y中，以便之后上下左右四个方向统计可以消灭的敌人数
	//向上统计可以消灭的敌人数
	x=i;y=j;
	while(a[x][y]!='#'){//判断是不是墙，如果不是墙就继续
 				//如果当前点是敌人，则进行计数
		if(a[x--][y]=='G') sum++;
		//x--的作用是继续向上统计
		//x--; 
	} 
	//向下统计可以消灭的敌人数
	x=i;y=j;
	while(a[x][y]!='#'){
		if(a[x++][y]=='G') sum++;
	} 
	//向左统计可以消灭的敌人数
	x=i;y=j;
	while(a[x][y]!='#'){
		if(a[x][y--]=='G') sum++;
	} 
	//向右统计可以消灭的敌人数
	x=i;y=j;
	while(a[x][y]!='#'){
		if(a[x][y++]=='G') sum++;
	} 
	return sum;
}
int main(){
	struct note que[401];//假设地图大小不超过20*20，因此队列扩展不会超过400个
	int head,tail;
	int book[20][20]={0};//定义一个标记数组并全部初始化为0
	int i,j,k,sum,max=0,mx,my,n,m,startx,starty,tx,ty;
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	for(i=0;i<=n-1;i++)
		scanf("%s",&a[i]);
	head=1;
	tail=1;
	que[tail].x=startx;
	que[tail].y=starty;
	tail++;
	book[startx][starty]=1;
	max=getnum(startx,starty);
	mx=startx;
	my=starty;
	while(head<tail){
		//枚举4个方向
		for(k=0;k<=3;k++){
			//计算下一个点的坐标
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			//判断是否越界
			if(tx<0||tx>n-1||ty<0||ty>m-1) continue;
			//判断该点是否为平地或者曾经走过 
			if(a[tx][ty]=='.'&&book[tx][ty]==0){
				//标记这个点已经走过
				//注意宽搜每个点通常情况下只入队一次，
				//和深搜不同，不需要将book数组还原
				book[tx][ty]=1;
				//插入新的点到队列中
				que[tail].x=tx;
				que[tail].y=ty;
				tail++;
				
				//统计当前新扩展的点可以消灭的敌人总数
				sum=getnum(tx,ty);
				//更新max值
				if(sum>max){
					//如果当前点所能消灭敌人总数大于max，则更新max
					//并用mx和my记录当前点的坐标
					max=sum;
					mx=tx;
					my=ty;
				} 
			}
		}
		head++;//注意这里千万不要忘记，当一个点扩展结束后，head++才能对后面的点再进行扩展
	}	
	printf("将炸弹放置在(%d,%d)，最多可以消灭%d个敌人\n",mx,my,max);
	return 0;
}
*/
/*
输入
13 13 3 3
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.#.#
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
输出
将炸弹放置在(7,11)，最多可以消灭10个敌人
*/  



#include <cstdio>
char a[20][20];
int book[20][20],max,mx,my,n,m;
int getnum(int i,int j){
	int sum,x,y;
	sum=0;
	x=i;y=j;
	while(a[x][y]!='#'){
		if(a[x--][y]=='G') sum++;
	} 
	x=i;y=j;
	while(a[x][y]!='#'){
		if(a[x++][y]=='G') sum++;
	}
	x=i;y=j;
	while(a[x][y]!='#'){
		if(a[x][y--]=='G') sum++;
	}
	x=i;y=j;
	while(a[x][y]!='#'){
		if(a[x][y++]=='G') sum++;
	} 
	return sum;
}
void dfs(int x,int y){
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int k,sum,tx,ty;
	sum=getnum(x,y);
	if(sum>max){
		max=sum;
		mx=x;
		my=y;
	}
	for(k=0;k<=3;k++){
		tx=x+next[k][0];
		ty=y+next[k][1];
		if(tx<0||tx>n-1||ty<0||ty>m-1) continue;
		//判断是否围墙或者已经走过 
		if(a[tx][ty]=='.'&&book[tx][ty]==0){
			book[tx][ty]=1;//标记这个点已走过 
			dfs(tx,ty);//开始尝试下一个点 
		} 
	}
	return;
}
int main(){
	int i,startx,starty;
	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	for(i=0;i<=n-1;i++)
		scanf("%s",&a[i]);
	book[startx][starty]=1;
	max=getnum(startx,starty);
	mx=startx;
	my=starty;
	dfs(startx,starty);
	printf("将炸弹放置在(%d,%d)，最多可以消灭%d个敌人\n",mx,my,max);
	return 0;
}
