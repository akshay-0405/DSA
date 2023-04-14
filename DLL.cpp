//Full Fledged Doubly Linked List

#include<iostream>
using namespace std ;

struct node  
{
    struct node *prev ;
    int data ;
    struct node *next ;
};

struct node * create(struct node *head , int data)
{
    if(head!=NULL)
    {
        cout<<"\nTry Inserting Elements Option\n";
    }
    else
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->prev=NULL;
        head->data=data;
        head->next=NULL;
        cout<<"\nInserted Successfully.\n";

    }
    return head;
}

struct node * insert_beg(struct node *head , int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    temp->next=head;
    temp->prev=NULL;
    head->prev=temp;
    head=temp;
    return head ;
}

void insert_last(struct node *head , int data)
{
    struct node *temp , *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    ptr=head;
    while(ptr->next!=NULL)//Checking Link part of node for updation
    {
        ptr=ptr->next;
    }
    temp->prev=ptr;
    ptr->next=temp;
}

void insert_pos(struct node *head , int pos , int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    struct node *ptr1 , *ptr2;
    ptr1=ptr2=head;

    //As we want to change the prev and next parts of both nodes so
    //alleast 1 traversing step required ,i.e, pos!=1 cond.
    while(pos!=1) 
    {
        ptr2=ptr2->next;
        pos--;
    }

    if(ptr2==NULL)
    {   
        insert_last(head,data);
    }
    else
    {
        ptr1=ptr2->prev;
        temp->prev=ptr1->next;
        temp->next=ptr2;
        ptr1->next=temp;
        ptr2->prev=temp;
    }
}

struct node * del_beg(struct node *head)
{
    if(head==NULL)
    {
        cout<<"\nEmpty DLL.\n";
        return head;
    }
    else
    {
        head=head->next;
        free(head->prev);
        head->prev=NULL;
        return head;
    }
}

struct node * del_last(struct node *head)
{
    if(head==NULL)
    {
        cout<<"\nEmpty DLL.\n";
        return head;
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return head;
    }
    else 
    {
        struct node *ptr1 , *ptr2;
        ptr2=head;
        while(ptr2->next!=NULL)
        {
            ptr2=ptr2->next;
        }

        ptr1=ptr2->prev;
        free(ptr2);
        ptr2=NULL;
        ptr1->next=NULL;
        return head;
    }
}

struct node * del_pos(struct node *head , int pos)
{
    if(head==NULL)
    {
        cout<<"\nEmpty DLL.\n";
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node *ptr1,*ptr2;
        ptr1=ptr2=head;

        while(pos!=1)//
        {
            ptr2=ptr2->next;
            pos--;
        }
        ptr1=ptr2->prev;
        ptr1->next=ptr2->next;
        ptr2->next->prev=ptr1;
        free(ptr2);
        ptr2=NULL;
    }
    return head;
}

struct node * reverse(struct node *head)
{
    struct node *ptr1 , *ptr2;
    ptr1=head;
    ptr2=head->next;
    
    ptr1->next=NULL;
    ptr1->prev=ptr2;

    while(ptr2!=NULL)
    {
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }

    head=ptr1;
    return head;
}

void display(struct node *head)
{
    if(head==NULL)
    {
        cout<<"\nList is Empty.\n";
    }
    else 
    {
        struct node *ptr = head;
        cout<<"\n";
        while(ptr!=NULL)
        {
            cout<<ptr->data<<"\t";
            ptr=ptr->next;
        }
        cout<<"\n";
    }
}

int main()
{
    struct node *head = NULL ;
    int choice , n , ch , pos;

    do
    {
        cout<<"\n* Operations Of DLL :"
            <<"\n1->Create"
            <<"\n2->Display"
            <<"\n3->Insert"
            <<"\n4->Delete"
            <<"\n5->Reverse"
            <<"\n6->Exit"
            <<"\nEnter Your Choice :";
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"\nEnter Data to be Inserted :";
                cin>>n;
                head = create(head , n);
                break;

            case 2:
                display(head);
                break;
            
            case 3:
                do
                {
                    cout<<"\n1->Insert at Beginning."
                        <<"\n2->Insert at Position."
                        <<"\n3->Insert at Last."
                        <<"\n4->Exit."
                        <<"\nEnter your Choice :";
                    cin>>ch;
                    switch (ch)
                    {
                        case 1:
                            cout<<"\nEnter Data to be Inserted :";
                            cin>>n;
                            head = insert_beg(head , n);
                            cout<<"\nInserted Successfully.\n";
                            break;

                        case 2:
                            cout<<"\nEnter Data to be Inserted :";
                            cin>>n;
                            cout<<"\nEnter the Position : ";
                            cin>>pos;
                            insert_pos(head , pos , n);
                            cout<<"\nInserted Successfully.\n";
                            break;

                        case 3:
                            cout<<"\nEnter Data to be Inserted :";
                            cin>>n;
                            insert_last(head , n);
                            cout<<"\nInserted Successfully.\n";
                            break;

                        case 4:
                            break;

                        default:
                            break;
                    }
                } while (ch!=4);
                
                break;

            case 4:
                do
                {
                    cout<<"\n1->Delete at Beginning."
                        <<"\n2->Delete at Position."
                        <<"\n3->Delete at Last."
                        <<"\n4->Exit."
                        <<"\nEnter your Choice :";
                    cin>>ch;
                    switch (ch)
                    {
                    case 1:
                        head = del_beg(head);
                        cout<<"\nDeleted Node Successfully.\n";
                        break;
                    case 2:
                        cout<<"\nEnter the Position : ";
                        cin>>pos;
                        head = del_pos(head,pos);
                        cout<<"\nDeleted Node Successfully.\n";
                        break;
                    case 3:
                        head = del_last(head);
                        cout<<"\nDeleted Node Successfully.\n";
                        break;
                    case 4:
                        cout<<"\nDeleted Node Successfully.\n";
                        break;
                    
                    default:
                        break;
                    }
                } while (ch!=4);
                break;

            case 5:
                head = reverse(head);
                cout<<"\nList Reversed.\n";
                break;

            case 6 :
                break;
        
            default:
                break;
        }

    } while (choice != 6);
    
    return 0;
}

