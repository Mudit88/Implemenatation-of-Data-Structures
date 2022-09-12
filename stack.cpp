#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Stack
{
    int size = 0;
    int capacity = 10;
    T * arr = new T [capacity];
    public:
    Stack()
    {
        cout<<"Stack is being created "<<endl;
    }
    int Length()
    {
        return size;
    }
    int max_capacity()
    {
        return capacity;
    }
    void push(T data)
    {
        if(size==capacity)
        {
            cout<<"Overflow"<<endl;
            return;
        }
        size++;
        arr[size-1] = data;
    }
    void pop()
    {
        if(size==0)
        {
            cout<<"Underflow"<<endl;
        }
        size--;
    }
    int top()
    {
        if(!size)return -1;
        return arr[size-1];
    }
    bool empty()
    {
        return size==0;
    }
};
int main()
{
    Stack<int> s;
    int n;
    cin>>n;
    while(n--)
    {
        int data;
        cin>>data;
        s.push(data);
    }
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}