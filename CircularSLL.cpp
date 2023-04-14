//Full Fledged Circular SLL

#include<iostream>

using namespace std ;

struct node 
{
    int data;
    struct node *next;
};

struct node * create(struct node *tail , int data)
{
    if(tail!=NULL)
    {
        cout<<"\nTry Option 3 Below ...";
    }
    else
    {
        tail = (struct node *)malloc(sizeof(struct node));
        tail->data=data;
        tail->next=tail;
    }
    return tail;
}

void print(struct node *tail)
{
    if(tail==NULL)
    {
        cout<<"\nEmpty List...";
    }
    else
    {
        struct node *ptr=tail->next;
        //do loop helps to execute first then check condition    
        do
        {
            cout<<ptr->data<<"\t";
            ptr=ptr->next;
        } while (ptr!=tail->next);
        
    }
}

void ins_beg(struct node *tail , int data)
{
    struct node *temp ;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    temp->next=tail->next;
    tail->next=temp;
    
}

struct node * ins_last(struct node *tail , int data)
{
    if(tail==NULL)
    {
        cout<<"\nEmpty List...";
    }
    else
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data=data;
        temp->next=NULL;

        temp->next=tail->next;
        tail->next=temp;
        tail=tail->next;
    }
    return tail;
}

struct node * ins_pos(struct node *tail , int data , int pos)
{
    struct node *temp , *ptr;
    ptr = tail->next;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    if(pos==1)
    {
        ins_beg(tail,data);
    }
    else
    {
        while(pos!=2)
        {
            ptr=ptr->next;
            pos--;
        }
        temp->next=ptr->next;
        ptr->next=temp;
        if(ptr==tail)
        {
            tail=tail->next;
        }
    }
    return tail;
}

void del_beg(struct node *tail)
{
    if(tail==NULL)
    {
        cout<<"\nList Empty.\n";
    }
    else
    {
        struct node *ptr = tail->next;
        tail->next=ptr->next;
        free(ptr);
        ptr=NULL;
    }
}

struct node * del_last(struct node *tail)
{
    if(tail==NULL)
    {
        cout<<"\nList Empty.\n";
    }
    else
    {
        struct node *ptr = tail->next;

        while(ptr->next!=tail)
        {
            ptr=ptr->next;
        }

        ptr->next=tail->next;
        free(tail);
        tail=ptr;
    }
    return tail;
}

struct node * del_pos(struct node *tail , int pos)
{
    if(tail==NULL)
    {
        cout<<"\nList Empty.\n";
    }
    else if(pos==1)
    {
        del_beg(tail);
    }
    else
    {
        struct node *ptr1,*ptr2;
        ptr1=tail->next;
        ptr2=ptr1->next;
        while(pos!=2)
        {
            ptr1=ptr2;
            ptr2=ptr2->next;
            pos--;
        }
        if(ptr2==tail)
        {
            tail=del_last(tail);
        }
        else
        {
            ptr1->next=ptr2->next;
            free(ptr2);
            ptr2=NULL;
        }
    }
    return tail;
}

int count(struct node *tail)
{
    if(tail==NULL)
    {
        cout<<"\nList Empty.\n";
        return 0;
    }
    else
    {
        struct node *ptr = tail->next;
        int count = 0 ;
        while(ptr!=tail)
        {
            count++;
            ptr=ptr->next;
        }
        count++;
        return count;
    }
}

int Search(struct node *tail , int find)
{
    if(tail==NULL)
    {
        return -2;
    }
    else
    {   
        struct node *ptr = tail->next;
        int index=0;
        do
        {
            if(ptr->data==find)
            {
                return index;
            }
            index++;
            ptr=ptr->next;
        } while (ptr!=tail->next);
        return -1;
    }
}

int main()
{
    struct node *tail=NULL;
    int choice , ch , n , pos , find , index;

    do
    {
        cout<<"\n| Circular SLL |"
            <<"\n1->Create"
            <<"\n2->Display"
            <<"\n3->Insert"
            <<"\n4->Count"
            <<"\n5->Search"
            <<"\n6->Delete"
            <<"\n7->Exit"
            <<"\nEnter Your Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\nEnter Data :";
                cin>>n;
                tail=create(tail,n);
                break;
            case 2:
                cout<<"\n";
                print(tail);
                cout<<"\n";
                break;
            case 3:
                do
                {
                    cout<<"\n1->Insert At Beginning."
                        <<"\n2->Insert At Last."
                        <<"\n3->Insert At Position."
                        <<"\n4->Exit"
                        <<"\nEnter Your Choice : ";
                    cin>>ch;
                    switch (ch)
                    {
                        case 1:
                            cout<<"\nEnter Data :";
                            cin>>n;
                            ins_beg(tail , n);
                            cout<<"\nNode Inserted Successfully.\n";
                            break;
                        case 2:
                            cout<<"\nEnter Data :";
                            cin>>n;
                            tail=ins_last(tail,n);
                            cout<<"\nNode Inserted Successfully.\n";
                            break;
                        case 3:
                            cout<<"\nEnter Data :";
                            cin>>n;
                            cout<<"\nEnter Position :";
                            cin>>pos;
                            tail=ins_pos(tail , n , pos);
                            cout<<"\nNode Inserted Successfully.\n";
                            break;
                        case 4:
                            break;

                        default:
                            break;
                    }
                } while (ch!=4);
                
                break;
            case 4:
                cout<<"\nNumber of Elements in List : "<<count(tail)<<"\n";
                break;

            case 5 :
                cout<<"\nEnter Element To Be Searched : ";
                cin>>find;
                index=Search(tail , find);
                if(index==-1)
                {
                    cout<<"\nElement Not Found.\n";
                }
                else if(index==-2)
                {
                    cout<<"\nEmpty List\n";
                }
                else
                {
                    cout<<"\nElement Found At Index : "<<index<<"\n";
                }
                break;    

            case 6:
                do
                {
                    cout<<"\n1->Delete At Beginning."
                        <<"\n2->Delete At Last."
                        <<"\n3->Delete At Position."
                        <<"\n4->Exit"
                        <<"\nEnter Your Choice : ";
                    cin>>ch;
                    switch (ch)
                    {
                        case 1:
                            del_beg(tail);
                            cout<<"\nNode Deleted Successfully.\n";
                            break;
                        case 2:
                            tail=del_last(tail);
                            cout<<"\nNode Deleted Successfully.\n";
                            break;
                        case 3:
                            cout<<"\nEnter Position :";
                            cin>>pos;
                            tail=del_pos(tail , pos);
                            cout<<"\nNode Deleted Successfully.\n";
                            break;
                        case 4:
                            break;
                        default:
                            break;
                    }
                } while (ch!=4);
                break;
            case 7:
                break;
            
            default:
                break;
        }
    } while (choice != 7);
    return 0;
}