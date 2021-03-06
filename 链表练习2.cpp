#define len sizeof(point)
#include <stdio.h>
#include <stdlib.h>
typedef struct point
{
	int row;
	int col;
	struct point * next;
}point;
void create(point * p);
void output(point * p);
void delet(point *p);
void add(point * p);
void amend(point * p);
point head={0};
int main(void)
{
	create(&head);
	output(&head);
	delet(&head);
	add(&head);
	amend(&head);
	return 0;
}
void create(point * p)
{
    int row;
	int col;
	scanf("%d %d",&row,&col);
	while(row&&col)
	{
		p->next=(point *)malloc(len);
		p=p->next;
		p->col=col;
		p->row=row;
		scanf("%d %d",&row,&col);
	}
	p->next=NULL;
	printf("创建成功！\n");
	//system("pause");
	return;
}
void output(point * p)
{
	for(p=p->next;p!=NULL;p=p->next)
		printf("(%d,%d)\n",p->row,p->col);
	return;
}
void delet(point * p)
{
	int row,col;
	printf("请输入需要删除的节点：");
	scanf("%d %d",&row,&col);
	for(;p->next!=NULL;p=p->next)
	{
		if(row==p->next->row&&col==p->next->col)
		{
			point * q;
			q=p->next;
			p->next=p->next->next;
			free(q);
			if(p->next==NULL)
				break; 
		}
	}
	printf("删除成功！\n删除后结果为：\n");
	output(&head);
	return;
}
void add(point * p)
{
	int x;
	int i=0;
	int row,col;
	printf("请输入要插入到第几个点后面：");
	scanf("%d",&x);
	printf("请输入要插入的点：");
	scanf("%d %d",&row,&col);
	for(;p!=NULL;p=p->next)
	{
		if(x==i)
		{
			point * q=(point *)malloc(len);
			q->row=row;
			q->col=col;
			q->next=p->next;
			p->next=q;
		}
		i++; 
	}
	printf("插入成功！\n插入后结果为：\n");
	output(&head);
	return;
}
void amend(point * p)
{
	int x;
	int row,col;
	int i=1;
	printf("请输入需要修改第几个点：");
	scanf("%d",&x);
	for(p=p->next;p!=NULL;p=p->next)
	{
		if(x==i)
		{
			printf("请输入需要新的点：");
			scanf("%d %d",&row,&col);
			if(row&&col)
			{
				p->row=row;
				p->col=col;
			} 
		}
		i++;
	}
	printf("修改成功！\n修改之后的结果为：\n");
	output(&head);
}