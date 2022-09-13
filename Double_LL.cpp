#include<bits/stdc++.h>
using namespace std;

int size = 0;

//Node - Class
class node
{
    public:
    int data;
    node * prev;
    node * next;
    node()
    {
        prev = NULL;
        next = NULL;
    }
    node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};


//Printing Doubly Linked List in Forward and Reverse Manner
void print_DLL(node * head)
{
    cout<<"\nPrinting List in forward manner\n";
    node * temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -->  ";
        temp = temp->next;
    }
    cout<<"NULL";
    node * tail = NULL;
    temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    tail = temp;
    cout<<"\nPrinting List in backward manner\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<"  -->  ";
        temp=temp->prev;
    }
    cout<<"NULL";
    return ;
}


// Delete Front
node* delete_front(node * head)
{
    if(!head)return  NULL;
    if(!head->next){
        free(head);
        return NULL;
    }
    node * to_delete = head;
    head = head->next;
    head->prev = NULL;
    delete to_delete;
    return head;
}


//Delete End
node * delete_end(node * head)
{
    if(!head)return NULL;
    node * tail = head;
    while(tail->next)
    {
        tail=tail->next;
    }
    node * tail_prev = tail->prev;
    tail_prev->next = NULL;
    free(tail);
    return head;
}

//Delete at position

node * delete_pos(node * head,int pos)
{
    if(!head)return NULL;
    if(pos==1)
    {
        return delete_front(head);
    }
    node * temp = head;
    for(int i = 1;i<pos;i++)
    {
        temp = temp->next;
    }
    node* prev_ptr = temp->prev;
    node * next_ptr = temp->next;
    prev_ptr->next = next_ptr;
    next_ptr->prev = prev_ptr;
    free(temp);
    return head;
}

//Driver Code 
int main()
{
    node * head = NULL;
    cout<<"\nEnter Number of Nodes\n";
    int n;
    cin>>n;
    node * temp = head;
    cout<<"\nEnter Data\n";
    while(n--)
    {
        int data;
        cin>>data;
        if(temp==NULL)
        {
            head = temp = new node(data);
        }
        else
        {
            node * new_node = new node(data);
            temp->next = new_node;
            new_node->prev = temp;
            temp=temp->next;
        }
        size++;
    }
    cout<<"\nLength of the linkedlist is : "<<size<<endl;
    cout<<"\nPrinting List\n";
    print_DLL(head);
    head = delete_front(head);
    print_DLL(head);
    head = delete_end(head);
    print_DLL(head);
    cout<<"\nEnter the position you want to delete\n";
    int pos;
    cin>>pos;
    head = delete_pos(head,pos);
    if(head==NULL)
    {
        cout<<"\nList is Empty\n";
    }
    else print_DLL(head);
    cout<<"\n------------------End of Program-------------------\n";
}