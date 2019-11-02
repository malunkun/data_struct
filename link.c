/*************************************************************************
  > File Name: link.c
  > Author: malunkun
  > Mail: 209446860@qq.com
  > Created Time: 2019-11-01 21:54:03
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node createlist(int num)//创建无头链表
{
    struct node head;
    struct node *p = NULL;
    p = &head;
    p->data = num;
    p->next = NULL;
    return head;
}

void insert_head(struct node *head,int num)//链表头插法
{
    struct node *node,*p;
    p = head->next;
    head->next = (struct node *)malloc(sizeof(struct node));
    node = head->next;
    node->next = p;
    node->data = num;
}

void insert_tail(struct node *head,int num)//
{
    struct node *node,*p;
    while(1)
    {
        if(NULL == head->next)
        {
            head->next = (struct node *)malloc(sizeof(struct node));
            node = head->next;
            node->next = NULL;
            node->data = num;
            break;
        }
        head = head->next;
    }
}

void printlist(struct node *head)//打印链表
{
    int counter = 1;
    while(1)
    {
        printf("NO.%d:%d\n",counter,head->data);
        counter++;
        head = head->next;
        if(head == NULL)
            break;
    }
}

void freelist(struct node *head)
{
    while(1)
    {
        free(head->next);
        head = head->next;
        if(NULL == head)
            break;
    }
}
int main()
{
    struct node head;
    head = createlist(55);
    insert_head(&head,23);
    insert_head(&head,22);
    insert_tail(&head,66);
    insert_tail(&head,200);
    printlist(&head);
    freelist(&head);
    return 0;
}

