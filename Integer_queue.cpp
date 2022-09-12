#include<bits/stdc++.h>
using namespace std;

class Queue
{
    int front,rear,capacity;
    int * arr;
    
    public:
    Queue()
    {
        front = rear = 0;
        capacity = 10;
        arr = new int [capacity];
    }

    void enqueue(int data)
    {
        if(rear==capacity)
        {
            cout<<"\nQueue Full\n";
            return;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void dequeue()
    {
        if(rear==front)
        {
            cout<<"\nQueue Empty\n";
            return;
        }
        for(int i = 0;i<rear-1;i++)
        {
            arr[i] = arr[i+1];
        }
        rear--;
    }

    void display()
    {
        if(rear==front)
        {
            cout<<"\nQueue is empty\n";
            return;
        }
        for(int i = front;i<rear;i++)
        {
            cout<<arr[i]<<"\t";
        }
        return;
    }

    int onfront()
    {
        if(front==rear)
        {
            return -1;
        }
        return arr[front];
    }

    bool empty()
    {
        return rear==front;
    }

    ~Queue()
    {
        delete [] arr;
    }
};


int main()
{
    Queue q;
    int n;
    cin>>n;
    while(n--)
    {
        int data;
        cin>>data;
        q.enqueue(data);
    }
    q.display();
}