#include <iostream>
using namespace std;


void merge(int A[],int mid,int low,int high)
{
  int i,j,k,B[100];

  i=low;
  j=mid+1;
  k=low;

  while(i<=mid && j<=high)
    {
      if(A[i]<A[j])
      {
        B[k]=A[i];
        i++;k++;
      }
      else
      {
        B[k]=A[j];
        j++;k++;
      }
    }

  while(i<=mid)
    {
      B[k]=A[i];
      i++;k++;
    }

  while(j<=high)
    {
      B[k]=A[j];
      j++;k++;
    }

  for(int i=low;i <= high;i++)
    {
      A[i]=B[i];
    }
  
}



void mergesort(int A[],int low,int high)
{
  int mid;

  if(low<high)
  {
    mid=(low+high)/2;
    mergesort(A, low, mid);
    mergesort(A, mid+1, high);
    merge(A, mid, low, high);
  }
  
}




void printarray(int *A,int n)
{
  for(int i=0;i<n;i++)
    {
      cout<<A[i]<<' ';
    }
  
  cout<<endl;
}





int main()
{
  int A[]={9,1,4,10,34,2,3};
  int n=7;
  
  mergesort(A, 0, 6);
  cout<<"merge sorted array is :\n";
  printarray(A, 7);
  cout<<endl;

  cout<<"top 5 employees are \n";

  for(int i=6;i>1;i--)
    {
      cout<<A[i]<<' ';
    }

  return 0;
}