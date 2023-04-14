//Full Fledged Circular DLL

#include<iostream>
using namespace std ;

struct node 
{
    int data ;
    struct node *prev;
    struct node *next;
};

struct node * create(struct node *tail , int data)
{
    if(tail!=NULL)
    {
        cout<<"\nTry Using Option Of Insert...";
    }
    else
    {
        tail = (struct node *)malloc(sizeof(struct node));
        tail->prev=tail;
        tail->data=data;
        tail->next=tail;
    }
    return tail;
}

void display(struct node *tail)
{
    if(tail==NULL)
    {
        cout<<"\nEmpty List\n";
    }
    else
    {
        struct node *ptr = tail->next;
        cout<<"\n";
        do
        {
            cout<<ptr->data<<"\t";
            ptr=ptr->next;
        }while(ptr!=tail->next);
    }
}

struct node * ins_beg(struct node *tail , int data)
{
    if(tail==NULL)
    {
        cout<<"\nTry Using 1st Option for Creating...";
    }
    else
    {
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->data=data;

        struct node *ptr=tail->next;
        temp->next=ptr;
        temp->prev=tail;
        ptr->prev=temp;
        tail->next=temp;
    }
    return tail;
}

struct node * ins_last(struct node *tail , int data)
{
    if(tail==NULL)
    {
        cout<<"\nTry Using 1st Option for Creating...";
    }
    else
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        struct node *ptr=tail->next;
        temp->prev=NULL;
        temp->data=data;
        temp->next=NULL;

        temp->prev=tail;
        temp->next=tail->next;
        tail->next=temp;
        ptr->prev=temp;
        tail=tail->next;
    }
    return tail;
}

struct node * ins_pos(struct node *tail , int data , int pos)
{
    if(tail==NULL)
    {
        tail=ins_beg(tail,data);
    }
    else
    {
        struct node *ptr = tail->next;
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->prev=NULL;
        temp->data=data;
        temp->next=NULL;

        while(pos!=2)
        {
            ptr=ptr->next;
            pos--;
        }
        if(ptr==tail)
        {
            tail=ins_last(tail,data);
        }
        else
        {
            temp->prev=ptr;
            temp->next=ptr->next;
            ptr->next=temp;
            temp->next->prev=temp;
        }
    }
    return tail;
}

struct node * del_first(struct node *tail)
{
    if(tail==NULL)
    {
        cout<<"\nEmpty List.";
    }
    else if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
    }
    else
    {
        struct node *ptr = tail->next;
        
        tail->next=ptr->next;
        ptr->next->prev=tail;
        free(ptr);
        ptr=NULL;
    }
    return tail;
}

struct node * del_last(struct node *tail)
{
    if(tail==NULL)
    {
        cout<<"\nEmpty List.";
    }
    else if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
    }
    else
    {
        struct node *ptr=tail->prev;
        ptr->next=tail->next;
        tail->next->prev=ptr;
        free(tail);
        tail=ptr;
    }
    return tail ;
}

struct node * del_pos(struct node *tail , int pos)
{
    if(tail==NULL)
    {
        cout<<"\nEmpty List.";
    }
    else if(tail==tail->next)
    {
        free(tail);
        tail=NULL;
    }
    else
    {
        struct node *ptr1 , *ptr2 ;
        ptr1=tail->next;

        while(pos!=2)
        {
            ptr1=ptr1->next;
            pos--;
        }

        ptr2=ptr1->next;
        if(ptr1->next==tail)
        {
            tail=tail->prev;
        }
        ptr1->next=ptr2->next;
        ptr2->next->prev=ptr1;
        free(ptr2);
        ptr2=NULL;
        
    }
    return tail;
}

int main()
{
    struct node *tail = NULL;
    int choice , n , ch , pos;

    do 
    {
        cout<<"\n|+ Circular DLL +|"
            <<"\n1->Create."
            <<"\n2->Display."
            <<"\n3->Insert."
            <<"\n4->Delete."
            <<"\n5->Exit."
            <<"\nEnter your Choice :";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\nEnter Data :";
                cin>>n;
                tail=create(tail,n);
                cout<<"\nNode Created Successfully!!!\n";
                break;

            case 2:
                display(tail);
                cout<<"\n";
                break;

            case 3:
                do
                {
                    cout<<"\n1->Insert At Beginning."
                        <<"\n2->Insert At Last."
                        <<"\n3->Insert At Position."
                        <<"\n4->Enter Your Choice : ";
                    cin>>ch;
                    switch(ch)
                    {
                        case 1:
                            cout<<"\nEnter Data : ";
                            cin>>n;
                            tail=ins_beg(tail , n);
                            break;

                        case 2:
                            cout<<"\nEnter Data : ";
                            cin>>n;
                            tail=ins_last(tail , n);
                            break;

                        case 3:
                            cout<<"\nEnter Data : ";
                            cin>>n;
                            cout<<"\nEnter Position : ";
                            cin>>pos;
                            tail=ins_pos(tail , n , pos);
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
                    cout<<"\n1->Delete At Beginning."
                        <<"\n2->Delete At Last."
                        <<"\n3->Delete At Position."
                        <<"\n4->Enter Your Choice : ";
                    cin>>ch;
                    switch(ch)
                    {
                        case 1:
                            tail=del_first(tail);
                            cout<<"\nNode Deleted Successfully!!!\n";
                            break;

                        case 2:
                            tail=del_last(tail);
                            cout<<"\nNode Deleted Successfully!!!\n";
                            break;

                        case 3:
                            cout<<"\nEnter Position : ";
                            cin>>pos;
                            tail=del_pos(tail , pos);
                            cout<<"\nNode Deleted Successfully!!!\n";
                            break;

                        case 4:
                            break;

                        default:
                            break;
                    }
                } while (ch!=4);
                break;

            case 5:
                break;

            default:
                break;
        }
    }while(choice!=5);

    return 0 ; 
}