#include<bits/stdc++.h>
using namespace std;

#define Size 5;


 // Circular Queue implementation in C++

#define SIZE 5 /* Size of Circular Queue */


class Queue {
   private:
  int items[SIZE], front, rear;

   public:
  Queue() {
    front = -1;
    rear = -1;
  }

  bool isFull()
  {
    if( front==0 &&  rear==SIZE-1)
    {
        return true;
    }
    else if(front==(rear+1)%SIZE)
    {
        return true;
    }
    else return false;
  }

  bool isEmpty()
  {
    if(front==-1)return true;
    else return false;
  }

  void enqueue(int element)
  {
    if(isFull())
    {
        cout<<"QUEUE is full"<<endl;
    }
    else 
    {
        if(front==-1)front=0;
        rear=(rear+1) % SIZE;
        items[rear]=element;
        cout<<"Inserted"<<endl;
    }
  }
  
  void dequeue()
  {
    int element;
    
    if(isEmpty())
    {
        cout<<"Queue is Empty"<<endl;
        return ;
    }

    else{
        element=items[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%SIZE;

        }
    }
  }

  void display()
  {
    if(isEmpty())
    {
      cout<<"Queue is empty"<<endl;
      return;
    }

    int i=front;

    while(i!=rear)
    {
      cout<<items[i]<<" ";
      i=(i+1)%SIZE;

    }
    cout<<items[i]<<endl;

  }

};

int main()
{

  Queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.enqueue(6);

  q.display();

q.dequeue();
q.display();

  
}