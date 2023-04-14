//Addition of two Numbers using Linked List
#include<iostream>
using namespace std ; 

struct node 
{
    int data ; 
    struct node *link;
};

struct node *add_node(struct node *head , int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    temp->link=head;
    head=temp;
    return head ;
} 

struct node * create(struct node *head , int n)
{
    while(n!=0)
    {
        head = add_node(head,n%10);
        n=n/10;
    }
    return head ;
}

void display(struct node *head)
{
    if(head==NULL)
    {
        cout<<"\nNo Number.";
    }
    else 
    {
        struct node *ptr = head ;
        while(ptr!=NULL)
        {
            cout<<ptr->data;
            ptr=ptr->link;
        }
    }
}

struct node *reverse(struct node *head)
{
    struct node *current = NULL;
    struct node *next = head->link;
    head->link=NULL;

    while(next!=NULL)
    {
        current = next ;
        next=next->link;
        current->link=head;
        head = current;
    }
    return head;
}

struct node *add_num(struct node *head1 , struct node  *head2)
{
    int sum = 0 , carry = 0 ;
    struct node *head3 = NULL;
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;

    while(ptr1 || ptr2)
    {
        sum = 0;
        if(ptr1)//for avoiding errors when ptr1 becomes null  
        {
            sum+=ptr1->data;
        }
        if(ptr2)
        {
            sum+=ptr2->data;
        }
        sum+=carry;
        carry = sum/10;//extracting single digit from left side of sum
        sum = sum%10;//extracting single digit from right side of sum

        head3 = add_node(head3,sum);

        if(ptr1)
        {
            ptr1=ptr1->link;
        }
        if(ptr2)
        {
            ptr2=ptr2->link;
        }
    }
    if(carry)
    {
        head3 = add_node(head3,carry);
    }
    cout<<"\nAddition of Both Numbers is :";
    return head3 ;
}

int main()
{
    struct node *head = NULL;
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int n;
    cout<<"\nEnter Number :";
    cin>>n;
    head1 = create(head1,n);
    head1 = reverse(head1);
    cout<<"\nEnter Number :";
    cin>>n;
    head2=create(head2,n);
    head2=reverse(head2);

    head = add_num(head1 , head2);
    display(head);

    return 0;
}