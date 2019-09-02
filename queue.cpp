/*********************************************************************
** Program name: PirateEscape
** Author: Tristan Gundel
** Date: 12/04/2018
** Description: This file is one of 19 files that together form a
**              program with the capability of running a sinle player
**              pirate themed escape room game where the user will
**              move around the board picking up items and hints to
**              use to get out of the room.
*********************************************************************/
#include "queue.hpp"
#include <iostream>

//Constructor to create an empty queue
Queue::Queue()
{
    this->head = nullptr;
    this->length = 0;
}

//Destructor to delete any allocated memory within the queue
Queue::~Queue()
{
  if (!this->isEmpty())
  {
    while (!this->isEmpty())
    {
      deleteFront();
    }
  }
}

//Function to determine whether the list is empty, or not
bool Queue::isEmpty()
{
  if (this->head == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//This function will add a new node to the back of the queue
void Queue::addBack(Tool* toolPtr)
{
  if (this->isEmpty())
  {
    this->head = new QueueNode;
    (this->head)->toolPtr = toolPtr;
    (this->head)->next = this->head;
    (this->head)->previous = this->head;
    (this->length)++;
  }
  else if (this->length < 5)
  {
    QueueNode* tempNode = this->head;
    while (tempNode->next != this->head )
    {
      tempNode = tempNode->next;
    }
    tempNode->next = new QueueNode;
    (tempNode->next)->toolPtr = toolPtr;
    (tempNode->next)->next = this->head;
    (tempNode->next)->previous = tempNode;
    (this->head)->previous = tempNode->next;
    (this->length)++;
  }
}

//This function returns the integer in the val member of the first node in queue
Tool* Queue::getFront()
{
  if (!this->isEmpty())
  {
    QueueNode* tempNode = this->head;
    return tempNode->toolPtr;
  }
  else
  {
    std::cout << "The list is empty so there is nothing to use"
              << std::endl;
    return 0;
  }
}

//Remove the node at the front of the queue
void Queue::deleteFront()
{
  if (this->isEmpty())
  {
    std::cout << "\nSorry, the queue is empty so there is nothing to remove!\n"
              << std::endl;
  }
  else
  {
    QueueNode* tempNode = this->head;
    QueueNode* prevNode = tempNode->previous;
    QueueNode* nextNode = tempNode->next;
    if (tempNode->next != this->head && prevNode != this->head)
    {
      delete tempNode->toolPtr;
      delete tempNode;
      prevNode->next = nextNode;
      this->head = nextNode;
      nextNode->previous = prevNode;
      (this->length)--;
    }
    else
    {
      delete this->head;
      this->head = nullptr;
      (this->length)--;
    }
  }
}

//Remove the node at the front of the queue
void Queue::removeFront()
{
  if (this->isEmpty())
  {
    std::cout << "\nSorry, the queue is empty so there is nothing to remove!\n"
              << std::endl;
  }
  else
  {
    QueueNode* tempNode = this->head;
    QueueNode* prevNode = tempNode->previous;
    QueueNode* nextNode = tempNode->next;
    if (tempNode->next != this->head && prevNode != this->head)
    {
      delete tempNode;
      prevNode->next = nextNode;
      this->head = nextNode;
      nextNode->previous = prevNode;
    }
    else
    {
      delete this->head;
      this->head = nullptr;
    }
  }
}

//This function will print the contents within each node of the queue once
void Queue::printQueue()
{
  if (this->isEmpty())
  {
    std::cout << "\nSorry, the queue is empty so there is nothing to print!\n"
              << std::endl;
  }
  else
  {
    int count = 1;
    QueueNode* tempNode = this->head;
    std::cout << count << ": " << (tempNode->toolPtr)->getToolName()
              << std::endl;
    while (tempNode->next != nullptr && tempNode->next != this->head)
    {
      tempNode = tempNode->next;
      std::cout << count << ": " << (tempNode->toolPtr)->getToolName()
                << std::endl;
    }
    std::cout << std::endl;
  }
}

//This function will advance the head of the of the queue
void Queue::advanceHead()
{
  this->head = (this->head)->next;
}

void Queue::emptyTheQueue()
{
  if (!this->isEmpty())
  {
    while (!this->isEmpty())
    {
      deleteFront();
    }
  }
}
