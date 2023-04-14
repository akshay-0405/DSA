//Full Fledged Singly Linked List

#include<iostream>
using namespace std ;

struct st
{
    int data;
    struct st *link ; 
};

struct st * create_node(struct st *head , int data)
{
    if(head!=NULL)
    {
        cout<<"\nUse 3rd Option to Insert More Elements\n";
    }
    else
    {
        head = (struct st *)malloc(sizeof(struct st));
        head->data=data;
        head->link=NULL;
    }
    return head;
}

void add_last(struct st *head , int data)
{
    struct st *ptr , *temp;
    temp = (struct st *)malloc(sizeof(struct st));
    ptr=head;
    temp->data=data;
    temp->link=NULL;

    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;//As we have to update the link part , not ptr to temp
}

void add_beg(struct st **head , int data)
{
    struct st *temp = (struct st *)malloc(sizeof(struct st));
    temp->data=data;
    temp->link=NULL;

    temp->link=*head;
    *head=temp;
}

void add_at_pos(struct st *head , int pos , int data)
{
    struct st *ptr , *temp;
    temp = (struct st *)malloc(sizeof(struct st));
    temp->data=data;
    temp->link=NULL;

    ptr=head;

    while(pos!=2)
    {
        ptr=ptr->link;
        pos--;
    }

    temp->link=ptr->link;
    ptr->link=temp;
}

void del_first(struct st **head)
{
    if(head==NULL)
    {
        cout<<"\nEmpty Linked list";
    }
    else
    {
        struct st *temp = *head;
        *head=temp->link;
        free(temp);
        temp=NULL;
    }
}

void del_last(struct st *head)
{
    if(head==NULL)
    {
        cout<<"\nEmpty Linked list";
    }
    else
    {
        struct st *ptr1 , *ptr2;
        ptr1=ptr2=head;

        while(ptr1->link!=NULL)
        {
            ptr2=ptr1;
            ptr1=ptr1->link;
        }

        free(ptr1);
        ptr1=NULL;
        ptr2->link=NULL;
    }
}

void del_pos(struct st **head , int pos)
{
    struct st *previous = *head ;
    struct st *current = *head ;

    if(*head==NULL)
    {
        cout<<"\nLL is Empty";
    }
    else if(pos==1)
    {
        *head = current->link;
        free(current);
        current=NULL;
    }
    else
    {
        while(pos!=1)
        {
            previous=current;
            current=current->link;
            pos--;
        }

        previous->link=current->link;
        free(current);
        current=NULL;
    }
}

void del_list(struct st **head)
{
    if(*head==NULL)
    {
        cout<<"\nLL is Empty";
    }
    else
    {
        struct st *temp = *head;
        while(temp!=NULL)
        {
            temp=temp->link;
            free(*head);
            *head=temp;
        }
        if(*head==NULL)
        {
            cout<<"\nList Deleted Successfully.";
        }
    }
}

struct st * reverse(struct st *head)
{
    if(head==NULL)
    {
        cout<<"\nLL is Empty";
    }
    else
    {
        struct st *next , *prev;
        prev = next = NULL;

        while(head!=NULL)
        {
            next=head->link;
            head->link=prev;
            prev=head;
            head=next;
        }
        head = prev;
    }
    return head;
}

void count(struct st *head)
{
    int count;
    count=0;
    if(head==NULL)
    {
        cout<<"Empty List!!";
    }
    else
    {
        struct st *ptr ;
        ptr=head;
        while(ptr!=NULL)
        {
            count++;
            ptr=ptr->link;
        }
        cout<<"\nNumber of Elements in List : "<<count<<endl;
    }
}

void print(struct st *head)
{
    if(head == NULL)
    {
        cout<<"\nList Is Empty .";
    }
    else
    {
        struct st *ptr;
        ptr=head;
        while(ptr!=NULL)
        {
            cout<<ptr->data<<"\t";
            ptr=ptr->link;
        }
    }
    
}

int main()
{
    struct st *head = NULL;
    int choice,n,n1,ch,pos;

    do
    {
        cout<<"*Linked List*"
            <<"\n1->Create"
            <<"\n2->Display"
            <<"\n3->Add"
            <<"\n4->Count"
            <<"\n5->Reverse"
            <<"\n6->Delete"
            <<"\n7->Exit."<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter Data to be Added : ";
            cin>>n;
            head=create_node(head , n);
            break;

        case 2:
            print(head);
            cout<<"\n";
            break; 
        
        case 3:
            do
            {
                cout<<"\n1->Add At Beginning"
                    <<"\n2->Add At Last"
                    <<"\n3->Add At Postion"
                    <<"\n4->Exit."
                    <<"\nEnter Your Choice : ";
                cin>>ch;
                switch (ch)
                {
                case 1 :
                    cout<<"Enter Data to be Added : ";
                    cin>>n1;
                    add_beg(&head , n1);
                    break;

                case 2 :
                    cout<<"Enter Data to be Added : ";
                    cin>>n1;
                    add_last(head , n1);
                    break;

                case 3 :
                    cout<<"Enter Data to be Added : ";
                    cin>>n1;
                    cout<<"Enter Position :";
                    cin>>pos;
                    add_at_pos(head , pos , n1);
                    break;

                case 4 :
                    break;

                default:
                    break;
                }
            } while (ch!=4);
            
            cout<<"\n";
            break;
        
        case 4:
            count(head);
            break;

        case 5:
            head = reverse(head);
            cout<<"\nList Reversed Successfully";
            break;

        case 6:
            do
            {
                cout<<"\n1->Delete At Beginning"
                    <<"\n2->Delete At Last"
                    <<"\n3->Delete At Postion"
                    <<"\n4->Delete Entire List"
                    <<"\n5->Exit."
                    <<"\nEnter Your Choice : ";
                cin>>ch;
                switch (ch)
                {
                case 1 :
                    del_first(&head);
                    cout<<"\nDeleted First Element\n";
                    break;

                case 2 :
                    del_last(head);
                    cout<<"\nDeleted Last Element\n";
                    break;

                case 3 :
                    cout<<"\nEnter the Position to be deleted.";
                    cin>>pos;
                    del_pos(&head , pos);
                    cout<<"\nDeleted Last Element\n";
                    break;

                case 4 :
                    del_list(&head);
                    break;
                    
                case 5 :
                    break;
                
                default:
                    break;
                }
            } while (ch!=5);
            break;
        
        case 7:
            break;    

        default:
            break;
        }
    } while (choice!=7);
}