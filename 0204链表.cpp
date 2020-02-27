/* 
//指针1 
#include<stdio.h>
int main(){
	int a=10;
	int *p;//定义一个指针p 
	p=&a;//指针p获取变量a的地址
	printf("%d",*p);//输出指针p所指向的内存中的值
	getchar();getchar();
	return 0; 
}
*/

/*
//指针2 
#include <stdio.h>
#include <stdlib.h>
int main(){
	int *p;//定义一个指针p
	p=(int *)malloc(sizeof(int));//指针p获取动态分配的内存空间地址
	*p=10;//向指针p所指向的内存空间中存入10
	printf("%d",*p);//输出指针p所指向的内存中的值
	getchar();getchar();
	return 0; 
} 
*/

/*
//创建量表（动态） 
#include <stdio.h>
#include <stdlib.h> 
//创建一个结构体来表示链表的结点类型 
struct node{
	int data;
	struct node *next;
}; 

int main(){
	struct node *head,*p,*q,*t;
	int i,n,a;
	scanf("%d",&n);
	head=NULL;//头指针初始为空
	for(i=1;i<=n;i++){//循环读入n个数
		scanf("%d",&a);
		//动态申请一个空间，用来存放一个节点，并用临时指针p指向这个结点
		p=(struct node *)malloc(sizeof(struct node));
		p->data=a;//将数据存储到当前结点的data域中
		p->next=NULL;//设置当前结点的后继指针指向空，也就是当前结点的下一个结点为空
		if(head==NULL)
			head=p;//如果这是第一个创建的结点，则将头指针指向这个结点
		else
			q->next=p;//如果不是第一个创建的结点，则将上一个结点的后继指针指向当前结点
		q=p;//指针q也指向当前结点 
	}
	//输出链表中的所有数
	t=head;
	while(t!=NULL){
		printf("%d ",t->data);
		t=t->next;//继续下一个结点 
	} 
	return 0;
}
*/
/*
输入
9
2 3 5 8 9 10 18 26 32
输出
2 3 5 8 9 10 18 26 32
*/ 


//插入数据到链表 
#include <stdio.h>
#include <stdlib.h> 
//创建一个结构体来表示链表的结点类型 
struct node{
	int data;
	struct node *next;
}; 

int main(){
	struct node *head,*p,*q,*t;
	int i,n,a;
	scanf("%d",&n);
	head=NULL;//头指针初始为空
	for(i=1;i<=n;i++){//循环读入n个数
		scanf("%d",&a);
		//动态申请一个空间，用来存放一个节点，并用临时指针p指向这个结点
		p=(struct node *)malloc(sizeof(struct node));
		p->data=a;//将数据存储到当前结点的data域中
		p->next=NULL;//设置当前结点的后继指针指向空，也就是当前结点的下一个结点为空
		if(head==NULL)
			head=p;//如果这是第一个创建的结点，则将头指针指向这个结点
		else
			q->next=p;//如果不是第一个创建的结点，则将上一个结点的后继指针指向当前结点
		q=p;//指针q也指向当前结点 
	}
	
	//插入部分
	scanf("%d",&a);//读入待插入的数
	t=head;//从链表头部开始遍历
	while(t!=NULL){//当没有到达链表结尾的时候循环
		if(t->next->data>a){//如果当前结点下一个结点的值大于待插入的数，将数插入到中间用来存放新增节点
			p=(struct node *)malloc(sizeof(struct node));//动态申请一个空间，用来存放新增结点
			p->data=a;
			p->next=t->next;//新增节点的后继指针指向当前结点的后继指针所指向的结点 
			t->next=p;//当前结点的后继指针指向新增节点
			break;//插入完毕退出循环
		} 
		t=t->next;//继续下一个结点 
	} 
	
	//输出链表中的所有数
	t=head;
	while(t!=NULL){
		printf("%d ",t->data);
		t=t->next;//继续下一个结点 
	} 
	return 0;
}

/*
输入
9
2 3 5 8 9 10 18 26 32
6
输出
2 3 5 6 8 9 10 18 26 32
*/ 
