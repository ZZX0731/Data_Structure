#include <stdio.h>
#include <stdbool.h>
#define MaxSize 50

//顺序表的结构体
typedef struct SeqList{
    int elem[MaxSize];
    int length;
}SeqList;

//初始化顺序表
void Init_SeqList(SeqList *s){
    s->length=0;
}

//判空
bool IsEmpty(SeqList s){
    return s.length==0;
}

//取值
int GetElem(SeqList s,int site){
    if(site<0||site>=s.length)
        return -1;
    else{
        return s.elem[site];
    }
}

//查找
int LocateElem(SeqList s, int data){
    for(int i=0;i<s.length;i++)
        if(s.elem[i]==data)
            return i;
    return -1;
}

//删除
bool Delete(SeqList *s,int site){
    if(site<0||site>=s->length)
        return false;
    else{
        for(int i=site;i<s->length;i++)
            s->elem[i]=s->elem[i+1];
        s->length--;
    }
    return true;
}

//插入
bool Insert(SeqList *s, int data, int site){
    if(site<0||site>s->length)
        return false;
    else{
        for(int i=s->length;i>=site;i--)
            s->elem[i+1]=s->elem[i];
        s->elem[site]=data;
        s->length++;
    }
    return true;
}

//遍历
void Display(SeqList s){
    for(int i=0;i<s.length;i++){
        printf("%d  ",s.elem[i]);
    }
}

int main()
{
    SeqList s;
    Init_SeqList(&s);
    Insert(&s,100,0);
    Insert(&s,200,1);
    Insert(&s,300,2);
    Insert(&s,400,2);
    Display(s);
    IsEmpty(s);
    printf("\n%d\n", GetElem(s,2));
    printf("%d\n", LocateElem(s, 300));
    Delete(&s,2);
    Display(s);
}