/* 
#include <cstdio>
int main(){
	int q[102]={6,3,1,7,5,8,9,2,4};
	int i,head,tail;
	//��ʼ������
	head=0;
	tail=9;//�����Ѿ���9��Ԫ���ˣ�tailָ���β�����һ��λ��
	while(head<tail){//�����в��յ�ʱ��ִ��ѭ��
		//��ӡ���ײ������׳���
		printf("%d ",q[head]);
		head++;
		//�Ƚ��¶��׵�����ӵ���β
		q[tail]=q[head];
		tail++;
		//�Ƚ��¶��׳���  
		head++;  
		////printf("%d ",q[head++]);
		////q[tail++]=q[head++];
	} 
	getchar();getchar();
	return 0;
}
*/ 

#include <cstdio>
struct queue{
	int data[100];//���е����壬�����洢����
	int head;//����
	int tail;//��β 
}; 
int main(){
	struct queue q;
	int i;
	//��ʼ������
	q.head=1;
	q.tail=1;
	for(i=1;i<=9;i++)
		//��������в���9����
		scanf("%d",&q.data[q.tail++]); 
	while(q.head<q.tail){//�����в�Ϊ�յ�ʱ��ִ��ѭ��
		//��ӡ���ײ������׳���
		printf("%d ",q.data[q.head++]);
		//�Ƚ��¶��׵�����ӵ���β���ٽ����׳���
		q.data[q.tail++]=q.data[q.head++]; 
	}
	getchar();getchar();
	return 0;
}

/*
���� 
6 3 1 7 5 8 9 2 4
��� 
6 1 5 9 4 7 2 8 3
*/
