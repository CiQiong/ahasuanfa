/*
//������� 
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
	//����һ����������
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	//����n��m���Լ�С�߽�������� 
	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	//�����ͼ
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	//���г�ʼ��
	head=1;
	tail=1;
	//�������в��뽵�����ʼ����
	que[tail].x=startx;
	que[tail].y=starty;
	tail++;
	book[startx][starty]=1;
	sum=1;
	//�����в���ʱѭ��
	while(head<tail){
		//ö��4������
		for(k=0;k<=3;k++){
			//������һ��������
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			//�ж��Ƿ�Խ��
			if(tx<1||tx>n||ty<1||ty>m) continue;
			//�����½����û���߹�
			if(a[tx][ty]>0&&book[tx][ty]==0){
				sum++;
				//ÿ����ֻ���һ�Σ�������Ҫ���������Ѿ��߹�
				book[tx][ty]=1;
				//������չ�ĵ�������
				que[tail].x=tx;
				que[tail].y=ty;
				tail++; 
			}
		}
		head++;//ע������ǧ��Ҫ����,
		//��һ������չ������head++���ܶԺ���ĵ��ٽ�����չ 
	}
	//����������Ĵ�С
	printf("%d\n",sum);
	return 0; 
}
*/
/*
���� 
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
��� 
38 
*/ 


/*
//������� 
#include <cstdio>
int a[51][51];
int book[51][51],n,m,sum;
void dfs(int x,int y){
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int k,tx,ty;
	for(k=0;k<=3;k++){
		//������һ��������
		tx=x+next[k][0];
		ty=y+next[k][1];
		//�ж��Ƿ�Խ��
		if(tx<1||tx>n||ty<1||ty>m) continue;
		//�����½����û���߹�
		if(a[tx][ty]>0&&book[tx][ty]==0){
			sum++;
			book[tx][ty]=1;
			dfs(tx,ty);//��ʼ������һ���� 
		}
	}
	return ; 
} 
int main(){
	int i,j,startx,starty;
	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	//�����ͼ
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	book[startx][starty]=1;
	sum=1;
	//�ӽ���λ�ÿ�ʼ 
	dfs(startx,starty);
	//����������Ĵ�С
	printf("%d\n",sum);
	return 0; 
}
*/


/*
//Ⱦɫ
#include <cstdio>
int a[51][51];
int book[51][51],n,m,sum;
void dfs(int x,int y,int color){//,int color
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int k,tx,ty;
	a[x][y]=color;//��a[x][y]������ӽ���Ⱦɫ 
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
	//����Ѿ�Ⱦɫ��ĵ�ͼ
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("%3d",a[i][j]);//%3d�е�3��c�����еĳ��� 
		}
		printf("\n");
	}
	return 0; 
} 
*/
/*
���� 
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
��� 
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

//������С��Ⱦɫ����С������
//��һ��ͼ�ж�����ͼ�ĸ�����Floodfill��ˮ��䷨/������䷨ 
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
	//�����ͼ 
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	//��ÿһ������0�ĵ㳢�Խ���dfsȾɫ
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j]>0){
				num--;//С����ҪȾ����ɫ�ı��
				//ÿ����һ��С��ӦȾ�Բ�ͬ����ɫ,���Ҫ-1
				book[i][j]=1;
				dfs(i,j,num); 
			}
		}
	}
	//����Ѿ�Ⱦɫ��ĵ�ͼ
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("%3d",a[i][j]);//%3d�е�3��c�����еĳ��� 
		}
		printf("\n");
	}
	//���С���ĸ���
	printf("��%d��С��\n",-num); 
	return 0; 
}
/*
���� 
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
���
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
��4��С��
*/
