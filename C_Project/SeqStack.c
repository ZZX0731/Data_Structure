//
// Created by ZZX on 2022/12/30.
//
#include <stdio.h>
#include <stdbool.h>
#define MaxSize 50

typedef struct SeqStack{
    int Stack[MaxSize];     //存储栈的数组
    int top;                //栈顶指针
}SeqStack;

//初始化顺序栈
void Init_SeqStack(SeqStack *s){
    s->top = 0;
}

bool IsEmpty(SeqStack s){
    return s.top==0;
}

bool push(SeqStack *s,int data){
    if(s->top>=MaxSize)
        return false;
    s->Stack[s->top]=data;
    s->top++;
    return true;
}

int pop(SeqStack *s){
    if(IsEmpty(*s))
        return -1;
    s->top--;
    return s->Stack[s->top];
}

void Display(SeqStack s){
    for(int i=s.top-1;i>=0;i--)
        printf("%d  ",s.Stack[i]);
}

//进制转换10->16
void transform(int data, int n){
    SeqStack s;
    while(data!=0){
        push(&s,data%n);
        data/=n;
    }
    while(!IsEmpty(s)){
        if(s.Stack[s.top-1]>9)
            printf("%c", pop(&s)+55);
        else
            printf("%d", pop(&s));
    }

}

int main()
{
    SeqStack s;
    Init_SeqStack(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    Display(s);
    pop(&s);
    push(&s,5);
    Display(s);
    pop(&s);pop(&s);pop(&s);pop(&s);
    printf("%d", IsEmpty(s));
    printf("\n");
    transform(65535, 16);
    return 0;
}