/* 
//ָ��1 
#include<stdio.h>
int main(){
	int a=10;
	int *p;//����һ��ָ��p 
	p=&a;//ָ��p��ȡ����a�ĵ�ַ
	printf("%d",*p);//���ָ��p��ָ����ڴ��е�ֵ
	getchar();getchar();
	return 0; 
}
*/

/*
//ָ��2 
#include <stdio.h>
#include <stdlib.h>
int main(){
	int *p;//����һ��ָ��p
	p=(int *)malloc(sizeof(int));//ָ��p��ȡ��̬������ڴ�ռ��ַ
	*p=10;//��ָ��p��ָ����ڴ�ռ��д���10
	printf("%d",*p);//���ָ��p��ָ����ڴ��е�ֵ
	getchar();getchar();
	return 0; 
} 
*/

/*
//����������̬�� 
#include <stdio.h>
#include <stdlib.h> 
//����һ���ṹ������ʾ����Ľ������ 
struct node{
	int data;
	struct node *next;
}; 

int main(){
	struct node *head,*p,*q,*t;
	int i,n,a;
	scanf("%d",&n);
	head=NULL;//ͷָ���ʼΪ��
	for(i=1;i<=n;i++){//ѭ������n����
		scanf("%d",&a);
		//��̬����һ���ռ䣬�������һ���ڵ㣬������ʱָ��pָ��������
		p=(struct node *)malloc(sizeof(struct node));
		p->data=a;//�����ݴ洢����ǰ����data����
		p->next=NULL;//���õ�ǰ���ĺ��ָ��ָ��գ�Ҳ���ǵ�ǰ������һ�����Ϊ��
		if(head==NULL)
			head=p;//������ǵ�һ�������Ľ�㣬��ͷָ��ָ��������
		else
			q->next=p;//������ǵ�һ�������Ľ�㣬����һ�����ĺ��ָ��ָ��ǰ���
		q=p;//ָ��qҲָ��ǰ��� 
	}
	//��������е�������
	t=head;
	while(t!=NULL){
		printf("%d ",t->data);
		t=t->next;//������һ����� 
	} 
	return 0;
}
*/
/*
����
9
2 3 5 8 9 10 18 26 32
���
2 3 5 8 9 10 18 26 32
*/ 


//�������ݵ����� 
#include <stdio.h>
#include <stdlib.h> 
//����һ���ṹ������ʾ����Ľ������ 
struct node{
	int data;
	struct node *next;
}; 

int main(){
	struct node *head,*p,*q,*t;
	int i,n,a;
	scanf("%d",&n);
	head=NULL;//ͷָ���ʼΪ��
	for(i=1;i<=n;i++){//ѭ������n����
		scanf("%d",&a);
		//��̬����һ���ռ䣬�������һ���ڵ㣬������ʱָ��pָ��������
		p=(struct node *)malloc(sizeof(struct node));
		p->data=a;//�����ݴ洢����ǰ����data����
		p->next=NULL;//���õ�ǰ���ĺ��ָ��ָ��գ�Ҳ���ǵ�ǰ������һ�����Ϊ��
		if(head==NULL)
			head=p;//������ǵ�һ�������Ľ�㣬��ͷָ��ָ��������
		else
			q->next=p;//������ǵ�һ�������Ľ�㣬����һ�����ĺ��ָ��ָ��ǰ���
		q=p;//ָ��qҲָ��ǰ��� 
	}
	
	//���벿��
	scanf("%d",&a);//������������
	t=head;//������ͷ����ʼ����
	while(t!=NULL){//��û�е��������β��ʱ��ѭ��
		if(t->next->data>a){//�����ǰ�����һ������ֵ���ڴ�����������������뵽�м�������������ڵ�
			p=(struct node *)malloc(sizeof(struct node));//��̬����һ���ռ䣬��������������
			p->data=a;
			p->next=t->next;//�����ڵ�ĺ��ָ��ָ��ǰ���ĺ��ָ����ָ��Ľ�� 
			t->next=p;//��ǰ���ĺ��ָ��ָ�������ڵ�
			break;//��������˳�ѭ��
		} 
		t=t->next;//������һ����� 
	} 
	
	//��������е�������
	t=head;
	while(t!=NULL){
		printf("%d ",t->data);
		t=t->next;//������һ����� 
	} 
	return 0;
}

/*
����
9
2 3 5 8 9 10 18 26 32
6
���
2 3 5 6 8 9 10 18 26 32
*/ 
