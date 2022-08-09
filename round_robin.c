//dynamic circular array implementation
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//structure to store the burst time and the process no.
typedef struct process
{
    int p_id;
    int burst;
}process;

struct queue
{
    int front,rear;
    int capacity;
    int size;
    process* array;
};

//create an empty queue
struct queue* createqueue(int capacity)
{
    struct queue* q=malloc(sizeof(struct queue));
    if(!q)
        return NULL;
    q->capacity=capacity;
    q->front=q->rear=-1;//sentinel value or when queue is empty
    q->size=0;
    q->array=malloc(q->capacity*sizeof(process));

    //assigning the pid to the process
    int i=0;
    for(;i<capacity;i++)
    {
        q->array[i].p_id= i+1;
    }

    if(!q->array)
        return NULL;
    return q;
}

//returns queue size
int size(struct queue* q)
{
    return q->size;
}

//returns front element of the queue
int frontelement(struct queue* q)
{
    return q->array[q->front].burst;
}

//returns the rear element of the queue
int rearelement(struct queue* q)
{
    return q->array[q->rear].burst;
}

//checks if queue is empty or not
int isempty(struct queue* q)
{
    //if the condition is true then 1 is returned else 0 is returned
    return (q->size==0);
}

//check's if the queue is full or not
int isfull(struct queue* q)
{
    return (q->size==q->capacity);
}

void resizequeue(struct queue* q)
{
    int i=0;
    int size=q->capacity;
    q->capacity=q->capacity*2;  //increase the capacity of the queue
    q->array=realloc(q->array,sizeof(int)*q->capacity);
    if(!q->array)
    {
        printf("Memory error");
        return ;
    }
    if(q->front>q->rear)
    {
        for(i=0;i<q->front;i++)
        {
            q->array[i+size]=q->array[i];
        }
        q->rear=q->rear+size;
    }
}

//adding elements in queue
void enqueue(struct queue* q,int data)
{
    if(isfull(q))
    {
        resizequeue(q);
    }
    q->rear=(q->rear+1)%q->capacity;
    q->array[q->rear].burst=data;
    if(q->front==-1)
    {
        q->front=q->rear;
    }
    q->size+=1;
    //printf("\nInside enqueue Size= %d Rear= %d Front= %d\n",q->size,q->rear,q->front);
}

//removes an element from the front of the queue
void dequeue(struct queue* q)
{
    int data=INT_MIN;//or element which does not exist in queue
    if(isempty(q))
    {
        printf("Queue is empty.\n");
        return ;
    }
    data=q->array[q->front].burst;
    if(q->front==q->rear)
    {
        q->front=q->rear=-1;
        q->size=0;
    }
    else
    {
        q->front=(q->front+1)%q->capacity;
        q->size-=1;
    }
}

void deletequeue(struct queue* q)
{
    if(!q)
    {
        if(q->array)
        {
            free(q->array);
        }
        free(q);
    }
}

int main()
{
    //initializing queue
    struct queue* q;
    
    //input the time quantum
    int quanta=0;
    printf("Enter the time quantum: ");
    scanf("%d",&quanta);
    
    //input the no. of processes
    int n_process=0;
    printf("Enter the no. of process: ");
    scanf("%d",&n_process);
    
    //creating a circular queue
    q=createqueue(n_process);
    
    //input the burst time for processes
    int i=0,burst=0;
    for(i=0;i<n_process;i++)
    {
        printf("Enter the burst time of %d process: ",i+1);
        scanf("%d",&burst);
        enqueue(q,burst);
    }

    //printing size of queue
    //printf("\nsize of queue:%d\n",size(q));

    printf("Gantt-Chart\n");

    //run the loop on ready queue till it becomes empty
    while(size(q))
    {
        int f=frontelement(q);
        //printing front element of ready queue
        //printf("front element:%d\n",f);
        //printing rear element of ready queue
        printf(" %d  ",q->array[q->front].p_id); 
        
        if(f>quanta)
        {
            //update the burst time
            f-=quanta;
            //printf("Size: %d\n",size(q));
            //dequeue the process from ready queue
            dequeue(q);
            //enqueue the process at the last
            enqueue(q,f);
            //printf("Size: %d f: %d\n",size(q),f);
        }
        else{
            //dequeue the process from ready queue
            dequeue(q);
        }
        
    }

    //removing queue
    deletequeue(q);
    return 0;
}

/*Sample Output1
Enter the time quantum: 2
Enter the no. of process: 3
Enter the burst time of 1 process: 24
Enter the burst time of 2 process: 3
Enter the burst time of 3 process: 3
Gantt-Chart
 1   2   3   1   2   3   1   1   1   1   1   1   1   1   1   1

Sample Output 2
Enter the time quantum: 3
Enter the no. of process: 3
Enter the burst time of 1 process: 24
Enter the burst time of 2 process: 3
Enter the burst time of 3 process: 3
Gantt-Chart
 1   2   3   1   1   1   1   1   1   1

Sample Output 3
Enter the time quantum: 4
Enter the no. of process: 3
Enter the burst time of 1 process: 24
Enter the burst time of 2 process: 3
Enter the burst time of 3 process: 3
Gantt-Chart
 1   2   3   1   1   1   1   1
*/