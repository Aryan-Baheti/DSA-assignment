#include<iostream>
using namespace std;


//here we are using queue using linked list


struct node
{
int data;
node *next;
}*front=NULL,*rear=NULL;


void enqueue(int x)
{
  struct node *t;
  t=new node;
  

  if(t==NULL)
  {
    cout<<"Queue is full\n";
  }
  else
  {
    t->data=x;
    t->next=NULL;

    if(front==NULL)
    {
      front=rear=t;
    }
    else
    {
      rear->next=t;
      rear=t;
    }
    
  }
  
}


int dequeue()
{
  struct node *t;
  int x=-1;
  

  if(front==NULL)
  {
    cout<<"Queue is empty\n";
  }
  else
  {
    
    x=front->data;
t=front;
    front=front->next;

    delete t;
  }

  return x;
}


int isEmpty()
{
  return front==NULL;
}


void BFS(int G[][7],int start,int n)
{
  int i=start;

  int visited[7]={0};
  cout<<i<<' ';
  visited[i]=1;
  enqueue(i);

  while(!isEmpty())
    {
      i=dequeue();

      for(int j=1;j<n;j++)
        {
          if(G[i][j]==1 && visited[j]==0)
          {
            cout<<j<<' ';
            visited[j]=1;
            enqueue(j);
          }
        }
    }
}


void DFS(int G[][7],int start,int n)
{
 static int visited[7]={0};
 int j;

 if(visited[start]==0)
 {
 printf("%d ",start);
 visited[start]=1;

 for(j=1;j<n;j++)
 {
 if(G[start][j]==1 && visited[j]==0)
 DFS(G,j,n);
 }
 }
  
}

int main() 
{
  int G[7][7]={{0,0,0,0,0,0,0},
               {0,0,1,1,0,0,0},
               {0,1,0,0,1,0,0},
               {0,1,0,0,1,0,0},
               {0,0,1,1,0,1,1},
               {0,0,0,0,1,0,0},
               {0,0,0,0,1,0,0}};

  cout<<"BFS is:\n";
BFS(G,4,7);
  cout<<endl;
  cout<<"DFS is:\n";
  DFS(G,4,7);
  cout<<endl;

  return 0;
}