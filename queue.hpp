#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "tool.hpp"

struct QueueNode
{
  QueueNode* previous;
  QueueNode* next;
  Tool* toolPtr;
};

class Queue
{
  private:
    QueueNode* head;
    int length;
  public:
    Queue();
    ~Queue();
    bool isEmpty();
    void addBack(Tool*);
    QueueNode* getHead();
    Tool* getFront();
    int getLength();
    void removeFront();
    void deleteFront();
    void printQueue();
    void advanceHead();
    void emptyTheQueue();
};

#endif
