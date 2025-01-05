#include <stdio.h>
#include <stdlib.h>

struct QNode{
    int data;
    struct QNode* next;
};

struct Queue{
    struct QNode *front,*rear;
};

struct QNode* newNode(int data) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
};

void enqueue(struct Queue* q, int data) {
    struct QNode* temp = newNode(data);
    
    // If queue is empty, set front and rear to new node
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        printf("Enqueued %d (First element)\n", data);
        return;
    }
    
    // Add new node at the end and update rear
    q->rear->next = temp;
    q->rear = temp;
    printf("Enqueued %d\n", data);
}

int dequeue(struct Queue* q) {
    // Check if queue is empty
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    
    // Store front and move front one node ahead
    struct QNode* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    
    // If front becomes NULL, set rear as NULL too
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    printf("Dequeued %d\n", data);
    return data;
}

void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue: ");
    struct QNode* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue* q = createQueue();
    
    enqueue(q, 10);
    display(q);
    
    enqueue(q, 20);
    display(q);
    
    enqueue(q, 30);
    display(q);
    
    dequeue(q);
    display(q);
    
    dequeue(q);
    display(q);
    
    enqueue(q, 40);
    display(q);
    
    return 0;
}