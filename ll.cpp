#include <iostream>

using namespace std;

class node
{
public:
  int data;
  node *next=NULL;
  node(int d=0)
  {
    data =d;
  }
};
void st(node **start)
{
  node *n,*temp=*start;
  cout<<"enter data to be entered at start: ";
  int d;
  cin>>d;
  n=new node(d);
  n->next=temp->next;
  temp->next=n;
  temp=n;
}
void end(node **start)
{
  node *n,*temp=*start;
  cout<<"\n enter the data  to be entered at the end: ";
  int d;
  cin>>d;
  n=new node(d);
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=n;
  n->next=NULL;
}
void display(node **point)
{
  node *start=*point;
  node *temp=start->next;
  cout<<"HEAD->";
  while(temp->next!=NULL)
  {
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  cout<<"NULL";
}
void reverse(node **point)
{
  node *temp1=*point;
  temp1=temp1->next;
  node *temp2= temp1->next;
  node *temp3= temp2->next;
  temp1->next=NULL;
  temp2->next=temp1;
  temp1=temp3->next;
  temp3->next=temp2;
  temp2=temp1->next;


  while(temp1->next!=NULL)
  {
    temp1->next=temp3;
    temp3=temp2->next;
    temp2->next=temp1;
    temp1=temp3->next;
    temp3->next=temp2;
    temp2=temp1->next;

  }

}
void insert(node **point)
{
  node *start=*point;
  node *n;
  cout<<"enter the data to be entered: ";
  int t;
  cin>>t;
  cout<<"enter the place to be entered: ";
  int pl;
  cin>>pl;
  n=new node(t);
  for(int i=0;i<pl-1;i++)
  {
    start=start->next;
  }
  n->next=start->next;
  start->next=n;

}
void del(node **point)
{
  node *temp=*point;
  cout<<"\n enter the place of node to be deleted: ";
  int t;
  cin>>t;
  node *temp1;
  for(int i=0;i<t-1;i++)
  {
    temp=temp->next;
  }
  temp1=temp->next;
  temp->next=temp1->next;
  delete temp1;
}
int main()
{
  node *start=new node();
  int choice=0;
  while(choice!=6)
  {
  cout<<"ENTER YOUR CHOICE: \n";
  cout<<"1)ADD AT START\n2)ADD AT END\n3)ADD ANYWHERE\n4)DELETE\n5)DISPLAY\n6)EXIT\7)REVERSEn";
  cin>>choice;
  switch(choice) {
    case 1:
    {
      st(&start);
      break;
    }
    case 2:
    {
      end(&start);
      break;
    }
    case 3:
    {
      insert(&start);
      break;
    }
    case 4:
    {
      del(&start);
    }
    case 5:
    {
      display(&start);
      break
    }
    case 7:
    {
      reverse(&start);
      break;
    }
    case 6:
    {
      break;
    }
    default :
    {
      cout<<"WRONG CHOICE";
      break;
    }
  }
}
  }
