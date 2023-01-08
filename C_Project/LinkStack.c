//
// Created by ZZX on 2022/12/30.
//
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode;

typedef struct LinkStack{
    LNode *top;
}LinkStack;

void Init_LinkList(LinkStack *l){
    l->top=NULL;
}

bool push(LinkStack *l,int data){
    LNode *q;
    q = malloc(sizeof(LNode));
    q->next = l->top;
    q->data = data;
    l->top = q;
    return true;
}

int pop(LinkStack *l){
    if(l->top==NULL)
        return -1;
    LNode *p=l->top;
    l->top = p->next;
    int e = p->data;
    free(p);
    return e;
}

void Display(LinkStack l){
    LNode *q = l.top;
    while(q!=NULL){
        printf("%d  ",q->data);
        q=q->next;
    }
}

int main()
{
    LinkStack l;
    Init_LinkList(&l);
    push(&l,1);
    push(&l,2);
    push(&l,3);
    Display(l);
    pop(&l);
    push(&l,4);
    Display(l);
    return 0;
}