/* 
#include <cstdio>
int a[51][51];//�������صĴ�С������50*50
int book[51][51],n,m,flag=0; 
void dfs(int x,int y,int front){//x��y��ʾ��ǰ������ӵ����꣬front��ʾ��ˮ�ڷ���
	int i;
	//�ж��Ƿ񵽴��յ㣨n,m+1) 
	//�����ж��Ƿ񵽴��յ�һ��Ҫ����Խ���ж�ǰ��
	if(x==n&&y==m+1){
		flag=1;//�ҵ����跽��
		return ; 
	} 
	//�ж��Ƿ�Խ��
	if(x<1||x>n||y<1||y>m) return ;
	//�ж�����ܵ��Ƿ���·����ʹ�ù�
	if(book[x][y]==1) return ;
	book[x][y]=1;//���ʹ�ù���ǰ����ܵ�
	//��ǰˮ����ֱ�ܵ����
	if(a[x][y]==5||a[x][y]==6){
		if(front==1)//��ˮ�������
			dfs(x,y+1,1);//�ҷ���ˮ�������
		if(front==2)//��ˮ�����ϱ�
			dfs(x+1,y,2);//�·���ˮ�����ϱ�
		if(front==3)//��ˮ�����ұ�
			dfs(x,y-1,3);//��߽�ˮ�����ұ� 
		if(front==4)//��ˮ�������
			dfs(x-1,y,4);//�Ϸ���ˮ�����±�
	}
	//��ǰˮ������ܵ����
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
	book[x][y]=0;//ȡ�����
	return ; 
}
int main(){
	int i,j,num=0;
	scanf("%d %d",&n,&m);
	//������Ϸ��ͼ
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	//��ʼ��������1,1��ʼ����ˮ����Ҳ��1
	dfs(1,1,1);
	//�ж��Ƿ��ҵ����跽��
	if(flag==0)
		printf("impossible\n");
	else 
		printf("�ҵ����跽��\n");
	return 0; 
}
*/ 
/*
����
5 4
5 3 5 3
1 5 3 0
2 3 5 1
6 1 1 5
1 5 5 4
���
�ҵ����跽��
*/

//���·�� 
#include <cstdio>
int a[51][51];
int book[51][51],n,m,flag=0; 
struct note{//////
	int x;//������////
	int y;//������////
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
	//����ǰ���Ե�������ջ
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
	top--;//����ǰ���Ե������ջ////// 
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
		printf("�ҵ����跽��\n");
	return 0; 
}
/*
����
5 4
5 3 5 3
1 5 3 0
2 3 5 1
6 1 1 5
1 5 5 4
���
(1,1) (1,2) (2,2) (3,2) (3,3) (3,4) (4,4) (5,4) �ҵ����跽��
*/
