//
// Created by ZZX on 2022/12/30.
//
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

//节点结构体
struct LNode {
    int data;
    struct LNode *next;
};
//链表结构体
typedef struct LinkList{
    struct LNode head;
    int length;
}LinkList;

//初始化链表
void Init_LinkList(LinkList *l){
    l->head.next=NULL;
    l->length = 0;
}

//判空
bool IsEmpty(LinkList l){
    return l.length==0;
}

//取值
int GetElem(LinkList l,int site){
    if(site<=0||site>l.length)
        return INT_MAX;
    struct LNode *p=&l.head;
    for(int i=0;i<site;i++)
        p=p->next;
    return p->data;
}

//查找
int LocateElem(LinkList l,int data){
    int site=1;
    struct LNode *p=l.head.next;
    while(p!=NULL){
        if(p->data!=data){
            site++;
            p=p->next;
        }
        else{
            return site;
        }
    }
    return -1;
}

//插入
bool Insert(LinkList *l,int data,int site){
    if(site<=0||site>l->length+1)
        return false;
    struct LNode *p=&l->head,*q;
    for(int i=1;i<site;i++)
        p=p->next;
    q = malloc(sizeof(struct LNode));
    q->data = data;
    q->next = p->next;
    p->next = q;
    l->length++;
    return true;
}

//删除
bool Delete(LinkList *l,int site){
    if(site<=0||site>l->length)
        return false;
    struct LNode *p=&l->head,*q;
    for(int i=1;i<site;i++)
        p=p->next;
    q=p->next;
    p->next=q->next;
    free(q);
    l->length--;
    return true;
}

//遍历
void Display(LinkList l){
    struct LNode *p = l.head.next;
    while(p!=NULL){
        printf("%d  ",p->data);
        p=p->next;
    }
}

int main()
{
    LinkList l;
    Init_LinkList(&l);
    Insert(&l,100,1);
    Insert(&l,200,2);
    Insert(&l,300,2);
    Insert(&l,400,2);
    Display(l);
    Delete(&l,4);
    Display(l);
    printf("%d\t", GetElem(l,2));
    printf("%d\t", LocateElem(l,400));
    Delete(&l,1);Delete(&l,1);Delete(&l,1);
    printf("%d", IsEmpty(l));
    return 0;
}
