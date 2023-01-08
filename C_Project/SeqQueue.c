//
// Created by ZZX on 2022/12/31.
//ѭ������
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MaxSize 50

typedef struct SeqQueue{
    int Queue[MaxSize];
    int head,rear;
}SeqQueue;

//��ʼ������
void Init_SeqQueue(SeqQueue *queue){
    queue->head = queue->rear = 0;
}

//�п�
bool IsEmpty(SeqQueue queue){
    return queue.head == queue.rear;
}

//����
bool IsFull(SeqQueue queue){
    return (queue.rear+1)%MaxSize == queue.head;
}

//����
bool push(SeqQueue *queue,int data){
    if(IsFull(*queue))
        return false;
    queue->Queue[queue->rear] = data;
    queue->rear = (queue->rear+1)%MaxSize;
    return true;
}

//����
int pop(SeqQueue *queue){
    if(IsEmpty(*queue))
        return INT_MAX;
    queue->head = (queue->head+1)%MaxSize;
    return queue->Queue[queue->head];
}

void Display(SeqQueue queue){
    if(IsEmpty(queue)){
        printf("����Ϊ�ա�");
        return;
    }
    if(queue.head<queue.rear)
        for(int i=queue.head;i<queue.rear;i++)
            printf("%d  ",queue.Queue[i]);
    else{
        for(int i=queue.head;i<MaxSize;i++)
            printf("%d  ",queue.Queue[i]);
        for(int i=0;i<queue.rear;i++)
            printf("%d  ",queue.Queue[i]);
    }
}

int main()
{
    SeqQueue seqQueue;
    Init_SeqQueue(&seqQueue);
    push(&seqQueue,1);
    push(&seqQueue,2);
    push(&seqQueue,3);
    Display(seqQueue);
    printf("\n");
    pop(&seqQueue);
    push(&seqQueue,4);
    Display(seqQueue);
    printf("\n");
    pop(&seqQueue);
    push(&seqQueue,5);
    Display(seqQueue);
    return 0;
}