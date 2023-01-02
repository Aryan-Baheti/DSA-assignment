#include<iostream>
using namespace std;

struct node
{
    int data;
   struct node *next;
}*top = NULL;


void push(int x)
{
    struct node *t;
    t=new node;

    if(t==NULL)
    {
        cout<<"stack is full"<<endl;
    }

    else
    {
       t->data=x;
       t->next=top;
       top=t;
    }
}

int pop()
{
    int x=-1;
    node *t;
    if(top==NULL)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        delete t;
    }
    return x;
}


void display()
{
    node *p;
    p=top;

    while(p!=NULL)
    {
        cout<<p->data<<"\t";
        p=p->next;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();
    cout<<endl;
    int t;
    t=pop();
    cout<<t<<endl;
  display();

}

