#ifdef  ARRAY_BASED_QUEUE
#include "../include/queue.h"

void CreatQueue(Queue *pq)
{
    pq->Front=0;
    pq->Rear=-1;
    pq->Size=0;
}
void Appand(QueueEntry e,Queue *pq)
{
    pq->Rear=(pq->Rear+1)%MAXQUEUE;
    pq->entry[pq->Rear]=e;
    pq->Size++;
}
void Serve(QueueEntry *pe,Queue* pq)
{
     *pe=pq->entry[pq->Front];
     pq->Front=(pq->Front+1)%MAXQUEUE;
     pq->Size--;
}
int QueueEmpty(Queue *pq)
{
    return !pq->Size;
}
int QueueFull(Queue* pq)
{
    return (pq->Size==MAXQUEUE);
}
int QueueSize(Queue *pq)
{
    return pq->Size;
}
void ClearQueue(Queue *pq)
{
    pq->Front=0;
    pq->Rear=-1;
    pq->Size=0;
}
void TraverseQueue(Queue *pq,void(*pf)(QueueEntry))
{
    int pos,s;
    for(pos=pq->Front,s=0;s<pq->Size;s++)
    {
        (*pf)(pq->entry[pos]);
        pos=(pos+1)%MAXQUEUE;
    }
}
#else
#include "../include/queue.h"

void CreatQueue (Queue *pq)
{
    pq->Front=NULL;
    pq->Rear=NULL;
    pq->Size=0;
}
void Append(QueueEntry e,Queue* pq)
{
    QueueNode *pn=(QueueNode*)  (sizeof(QueueNode));
    pn->next=NULL;
    pn->entry=e;
    if(!pq->Rear)
        pq->Front=pn;
    else
        pq->Rear->next=pn;
    pq->Rear=pn;
    pq->Size++;
}
void Serve(QueueEntry *pe,Queue *pq)
{
    QueueNode*pn=pq->Front;
    *pe=pn->entry;
    pq->Front=pn->next;
    free (pn);
    if(!pq->Front)
        pq->Rear=NULL;
    pq->Size--;
}
int QueueEmpty (Queue *pq)
{
    return !pq->Front;
}
int QueueFull(Queue *pq)
{
    return 0;
}
int QueueSize(Queue *pq)
{
    return pq->Size;
}
void ClearQueue(Queue *pq)
{
   while(pq->Front)
   {
       pq->Rear=pq->Front->next;
       free(pq->Front);
       pq->Front=pq->Rear;
   }
   pq->Size=0;
}
void TraverseQueue(Queue* pq,void (*pf)(QueueEntry))
{
   for (QueueNode *pn=pq->Front;pn;pn=pn->next)
        (*pf)(pn->entry);

}
#endif
