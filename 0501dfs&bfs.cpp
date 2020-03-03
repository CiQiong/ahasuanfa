/*
//dfs
#include <cstdio>
int book[101],sum,n,e[101][101];
void dfs(int cur){//cur�ǵ�ǰ���ڵĶ�����
	int i;
	printf("%d ",cur);
	sum++;//ÿ����һ�����㣬sum�ͼ�1
	if(sum==n) return ;//���ж��㶼�Ѿ����ʹ���ֱ���˳�
	for(i=1;i<=n;i++){//��1�Ŷ��㵽n�Ŷ������γ��ԣ�����Щ�����뵱ǰ����cur�б�����
		//�жϵ�ǰ����cur������i�Ƿ��бߣ����ж϶���i�Ƿ��ѷ��ʹ�
		if(e[cur][i]==1&&book[i]==0){
			book[i]=1;//��Ƕ���i�Ѿ����ʹ�
			dfs(i);//�Ӷ���i�ٳ����������� 
		} 
	} 
	return ;
}
int main(){
	int i,j,m,a,b;
	scanf("%d %d",&n,&m);
	//��ʼ����ά����
	for(i=1;i<n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j]=0;
			else e[i][j]=99999999;//�������99999999Ϊ������
	//���붥��֮��ı�
	for(i=1;i<=m;i++){
		scanf("%d %d",&a,&b);
		e[a][b]=1;
		e[b][a]=1;//����ͼ 
	} 
	//��1�ų��г���
	book[1]=1;//���1�Ŷ����ѷ���
	dfs(1);//��1�Ŷ��㿪ʼ����
	return 0; 
}
*/
/*
����
5 5
1 2
1 3
1 5
2 4
3 5 
���
1 2 4 3 5 
*/

//bfs
#include <stdio.h>
int main(){
	int i,j,n,m,a,b,cur,book[101]={0},e[101][101];
	int que[10001],head,tail;
	scanf("%d %d",&n,&m);
	//��ʼ����ά����
	for(i=1;i<n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j]=0;
			else e[i][j]=99999999;//�������99999999Ϊ������
	//���붥��֮��ı�
	for(i=1;i<=m;i++){
		scanf("%d %d",&a,&b);
		e[a][b]=1;
		e[b][a]=1;//����ͼ 
	}
	//���г�ʼ��
	head=1;tail=1;
	//��1�Ŷ����������1�Ŷ��������� 
	que[tail]=1; 
	tail++;
	book[1]=1;//��¼1�Ŷ����Ѿ�����
	//�����в��յ�ʱ��ѭ��
	while(head<tail){
		cur=que[head];//��ǰ���ڷ��ʵĶ�����
		for(i=1;i<=n;i++){//��1~n���γ���
			//�жϵ�ǰ����cur������i�Ƿ��бߣ����ж϶���i�Ƿ��ѷ��ʹ�
			if(e[cur][i]==1&&book[i]==0){
				que[tail]=i;
				tail++;
				book[i]=1;//��Ƕ���i�Ѿ����ʹ�
			}
			//���tail����n����������ж��㶼�Ѿ������ʹ�
			if(tail>n) break; 
		}
		head++;//��һ��������չ������head++�����ۼ�����չ 
	}
	for(i=1;i<tail;i++)
		printf("%d ",que[i]);
	return 0; 
} 
/*
����
5 5
1 2
1 3
1 5
2 4
3 5 
���
1 2 3 5 4
*/
