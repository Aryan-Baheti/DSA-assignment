#include <iostream>
using namespace std;

struct node {
  int data;
  node *next;
};

class single_linked {
  node *head = NULL;

public:
  void insert_at_beginning();
  void display_list();
  void insert_at_end();
  void insert_at_position();
  void delete_first();
  void delete_last();
  void delete_at_position();
};

void single_linked ::insert_at_beginning() {
  node *newnode;
  newnode = new node();
  cout << "\nEnter the data of the node\n";
  int n;
  cin >> n;
  newnode->data = n;
  newnode->next = head;
  head = newnode;
}

void single_linked ::insert_at_end() {
  node *newnode;
  newnode = new node();
  cout << "\nEnter the data of the node\n";
  int n;
  cin >> n;
  newnode->data = n;
  newnode->next = NULL;

  if (head == NULL) {
    head = newnode;

  } else {
    node *temp;
    temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newnode;
  }
}

void single_linked ::delete_first() { head = head->next; }

void single_linked ::delete_last() {
  if (head != NULL) {
    node *temp;
    node *temp1;
    temp = head->next;
    temp1 = head;

    while (temp->next != NULL) {
      temp1 = temp;
      temp = temp->next;
    }
    delete temp;
    temp1->next = NULL;
  } else
    cout << "\n You haven't entered any element\n";
}

void single_linked ::insert_at_position() {
  node *temp;
  int count = 0;
  cout << "\nEnter at which position you have to enter\n";
  int n;
  cin >> n;
  temp = head;
  while (temp != NULL) {
    temp = temp->next;
    count++;
  }
  if (n > count) {
    cout << "\nYou cannot add element at " << n << "! as only"
         << "count"
         << "elements are in the list" << endl;
  } else if (n == 1) {
    insert_at_beginning();
  } else {
    node *newnode;
    node *prenode;
    newnode = new node();
    cout << "\n enter data part of node\n";
    int p;
    cin >> p;
    newnode->data = p;
    node *temp = head;

    for (int i = 0; i < n - 2; i++) {
      // prenode=temp;
      temp = temp->next;
    }

    /*prenode= temp->next;
       temp->next = newnode;
       newnode->next=prenode;*/

    newnode->next = temp->next;
    temp->next = newnode;
  }
}

void single_linked ::delete_at_position() {
  node *temp;
  int count = 0;
  temp = head;

  while (temp != NULL) {
    temp = temp->next;
    count++;
  }
  int n;
  cout << "\n enter at which position you want to delete element\n";
  
  cin >> n;

  if (n > count) {
    cout << "you cannot delete element at " << n << "! as only" << count
         << "elements are in the list\n";
  } else {
    temp = head;
    for (int i = 0; i < n - 2; i++) {
      temp = temp->next;
    }
    temp->next = temp->next->next;
    /* node *temp1;
     temp1=temp;
       temp=head
       for(int i=0;i<n-1;i++)
       {
               temp=temp->next;
        }
        temp=temp1; */
  }
}

void single_linked ::display_list() {
  node *temp;
  temp = head;
  while (temp != NULL) {
    cout << temp->data << "\t";
    temp = temp->next;
  }
}

int main() {
  single_linked s;
  int p = 0;

  while (p != -1) {
    cout << "\n Enter 1 to insert node at beginning\n";
    cout << "\n Enter 2 to insert node at end\n";
    cout << "\n Enter 3 to delete node at beginning\n";
    cout << "\n Enter 4 to insert node at end\n";
    cout << "\n Enter 5 to insert node at position\n";
    cout << "\n Enter 6 to delete node at position\n";
    cout << "\n Enter 7 to display\n";
    cout << "\n Enter 8 to exit\n";

    int n;
    cin >> n;

    switch (n) {
    case 1:

      s.insert_at_beginning();
      break;

    case 2:
      s.insert_at_end();
      break;

    case 3:
      s.delete_first();
      break;

    case 4:
      s.insert_at_end();
      break;

    case 5:
      s.insert_at_position();
      break;

    case 6:
      s.delete_at_position();
      break;

    case 7:
      s.display_list();
      break;

    case 8:
      exit(0);
      break;

    default:
      cout << "enter appropiate choice" << endl;
      break;
    }
  }

  return 0;
}
