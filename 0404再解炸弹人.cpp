/*
#include <cstdio>
struct note{
	int x;//������
	int y;//������ 
}; 
char a[20][20];//�����洢��ͼ.
int getnum(int i,int j){
	int sum,x,y;
	sum=0;//sum������������������ĵ���������������Ҫ��ʼ��Ϊ0
	//������i��j���Ƶ������±���x��y�У��Ա�֮�����������ĸ�����ͳ�ƿ�������ĵ�����
	//����ͳ�ƿ�������ĵ�����
	x=i;y=j;
	while(a[x][y]!='#'){//�ж��ǲ���ǽ���������ǽ�ͼ���
 				//�����ǰ���ǵ��ˣ�����м���
		if(a[x--][y]=='G') sum++;
		//x--�������Ǽ�������ͳ��
		//x--; 
	} 
	//����ͳ�ƿ�������ĵ�����
	x=i;y=j;
	while(a[x][y]!='#'){
		if(a[x++][y]=='G') sum++;
	} 
	//����ͳ�ƿ�������ĵ�����
	x=i;y=j;
	while(a[x][y]!='#'){
		if(a[x][y--]=='G') sum++;
	} 
	//����ͳ�ƿ�������ĵ�����
	x=i;y=j;
	while(a[x][y]!='#'){
		if(a[x][y++]=='G') sum++;
	} 
	return sum;
}
int main(){
	struct note que[401];//�����ͼ��С������20*20����˶�����չ���ᳬ��400��
	int head,tail;
	int book[20][20]={0};//����һ��������鲢ȫ����ʼ��Ϊ0
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
		//ö��4������
		for(k=0;k<=3;k++){
			//������һ���������
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			//�ж��Ƿ�Խ��
			if(tx<0||tx>n-1||ty<0||ty>m-1) continue;
			//�жϸõ��Ƿ�Ϊƽ�ػ��������߹� 
			if(a[tx][ty]=='.'&&book[tx][ty]==0){
				//���������Ѿ��߹�
				//ע�����ÿ����ͨ�������ֻ���һ�Σ�
				//�����Ѳ�ͬ������Ҫ��book���黹ԭ
				book[tx][ty]=1;
				//�����µĵ㵽������
				que[tail].x=tx;
				que[tail].y=ty;
				tail++;
				
				//ͳ�Ƶ�ǰ����չ�ĵ��������ĵ�������
				sum=getnum(tx,ty);
				//����maxֵ
				if(sum>max){
					//�����ǰ���������������������max�������max
					//����mx��my��¼��ǰ�������
					max=sum;
					mx=tx;
					my=ty;
				} 
			}
		}
		head++;//ע������ǧ��Ҫ���ǣ���һ������չ������head++���ܶԺ���ĵ��ٽ�����չ
	}	
	printf("��ը��������(%d,%d)������������%d������\n",mx,my,max);
	return 0;
}
*/
/*
����
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
���
��ը��������(7,11)������������10������
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
		//�ж��Ƿ�Χǽ�����Ѿ��߹� 
		if(a[tx][ty]=='.'&&book[tx][ty]==0){
			book[tx][ty]=1;//�����������߹� 
			dfs(tx,ty);//��ʼ������һ���� 
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
	printf("��ը��������(%d,%d)������������%d������\n",mx,my,max);
	return 0;
}
