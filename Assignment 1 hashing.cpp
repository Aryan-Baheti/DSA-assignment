
#include<iostream>
#include<cstring>
using namespace std;
struct Employee
{
int id;
string name;
int key;
};

class Hashtable
{
Employee Table[10];

public:
void deletion()
{
int x,i;
cout<<"Enter id to be deleted"<<endl;
cin>>x;
for(i=0;i<10;i++)
{
if(x==Table[i].id)
{
Table[i].id= -1;
Table[i].key= -1;
Table[i].name=" ";
}
}


}

void searching()
{
int iKey,j;
cout<<"Enter the id to be searched "<<endl;
cin>>iKey;

for(j=0;j<10;j++)
{
if(iKey==Table[j].id)
{
cout<<"Employee found at index "<<j<<endl;
}
}
}

int hashfunction(int key)
{
return key % 10;
}

Hashtable() //Constructor
{
for(int i=0;i<10;i++)
{
Table[i].id= -1;
Table[i].key= -1;
Table[i].name=" ";
}
}

void insertion()
{
int id,flag=0;
string name;
cout<<"Enter Employee Id "<<endl;
cin>>id;
cout<<"Enter Employee Name "<<endl;
cin>>name;

int index = hashfunction(id);

int c=index;

while(Table[index].key!= -1 && flag==10)
{
index = (index +1)%10;
flag++;
}

Table[index].id = id;
Table[index].name = name;
Table[index].key = c;
 }
void display()
{
cout<<"Key  Id  Name "<<endl;

int j=0;
for (j=0;j<10;j++)
{
cout<<" "<<j<<"   "<< Table[j].id <<"  "<<Table[j].name<<endl;
}
}
};

int main()
{
int ch,end;

Hashtable obj1;
do
{
    cout<<endl;
    cout<<"1.Insert Data"<<endl;
cout<<"2.Delete Data"<<endl;
cout<<"3.Search Data"<<endl;
cout<<"4.View Table"<<endl;

cin>>ch;
switch(ch)
{
case 1 :
obj1.insertion();
break;

case 2 :
obj1.deletion();
break;

case 3 :
obj1.searching();
break;

case 4 :
obj1.display();
break;

default :
cout<<"Invalid Input"<<endl;
}

cout<<"Do you want to continue?? (0 = No, 1= Yes )";
cin>>end;
}while(end==1);
return 0;
}
