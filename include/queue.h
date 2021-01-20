#ifdef ARRAY_BASED_QUEUE

#define QueueEntry int
#define MAXQUEUE 100

typedef struct queue
{
    int Front;
    int Rear;
    int Size;
    QueueEntry entry [MAXQUEUE];
}Queue;
void CreatQueue(Queue &q);
void Appand(QueueEntry e,Queue &q);
void Serve(QueueEntry &e,Queue &q);
int QueueEmpty(Queue &q);
int QueueFull(Queue &q);
int QueueSize(Queue &q);
void ClearQueue(Queue &q);
void TraverseQueue(Queue &q,void(&f)(QueueEntry));


#else
#include <cstdlib>
#define QueueEntry int
typedef struct queuenode
{
    QueueEntry entry;
    struct queuenode *next;
}QueueNode;
typedef struct queue
{
    QueueNode *Front;
    QueueNode *Rear;
    int Size;
}Queue;
void CreatQueue (Queue &q);
void Append(QueueEntry e,Queue &q);
void Serve(QueueEntry &e,Queue &q);
int QueueEmpty (Queue &q);
int QueueFull(Queue &q);
int QueueSize(Queue &q);
void ClearQueue(Queue &q);
void TraverseQueue(Queue &q,void (&f)(QueueEntry));
#endif
