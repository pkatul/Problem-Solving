#include<iostream>
#include<cstdio>

using namespace std;

#define MAX 5

typedef struct {
  int data[MAX];
  int head_index, tail_index, size;
} Queue;

// push
void enqueue(Queue *q, int item) {
  // check if queue is full or not
  if(q->size == MAX) {
    cout << "Queue is full.";
    return;
  }
  q->data[q->tail_index] = item;
  q->tail_index = (q->tail_index + 1) % MAX;
  q->size += 1;
}

// pop
int dequeue(Queue *q) {
  if(q->size == 0) {
    cout << "Queue is empty.";
    return -1;
  }
  int a = q->data[q->head_index];
  q->head_index = (q->head_index + 1) % MAX;
  q->size -= 1;

  return a;
}

int main() {
    int item;
    Queue q;
    q.head_index = q.tail_index = q.size = 0;

    enqueue(&q, 1);
    cout << "Head = " << q.head_index << ", Tail = " << q.tail_index << ", size = " << q.size << endl;

    enqueue(&q, 2);
    cout << "Head = " << q.head_index << ", Tail = " << q.tail_index << ", size = " << q.size << endl;

    enqueue(&q, 3);
    cout << "Head = " << q.head_index << ", Tail = " << q.tail_index << ", size = " << q.size << endl;

    enqueue(&q, 4);
    cout << "Head = " << q.head_index << ", Tail = " << q.tail_index << ", size = " << q.size << endl;

    enqueue(&q, 5);
    cout << "Head = " << q.head_index << ", Tail = " << q.tail_index << ", size = " << q.size << endl;

    enqueue(&q, 6);
    cout << "Head = " << q.head_index << ", Tail = " << q.tail_index << ", size = " << q.size << endl;

    enqueue(&q, 7);
    cout << "Head = " << q.head_index << ", Tail = " << q.tail_index << ", size = " << q.size << endl;

    dequeue(&q);
    cout << "Head = " << q.head_index << ", Tail = " << q.tail_index << ", size = " << q.size << endl;

    dequeue(&q);
    cout << "Head = " << q.head_index << ", Tail = " << q.tail_index << ", size = " << q.size << endl;

    enqueue(&q, 6);
    cout << "Head = " << q.head_index << ", Tail = " << q.tail_index << ", size = " << q.size << endl;

    enqueue(&q, 7);
    cout << "Head = " << q.head_index << ", Tail = " << q.tail_index << ", size = " << q.size << endl;

    return 0;
}
