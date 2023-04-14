//Application of Linked List :- Polynomial Arithmetics.
//Polnomial Multiplication

#include<iostream>
#include<stdio.h>
using namespace std ;

struct node 
{
    int coeff ;
    int expo;
    struct node *link;
};

struct node * insert(struct node *head , int co , int ex)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr ;
    temp->coeff=co;
    temp->expo=ex;
    temp->link=NULL;

    if(head==NULL || ex > head->expo)//creates new or inserts to existing list
    {
        temp->link=head;
        head = temp;
    }
    else
    {
        ptr=head;
        while(ptr->link!=NULL && ptr->expo > ex)
        {
            ptr=ptr->link;
        }
        temp->link=ptr->link;
        ptr->link=temp;
    }
    return head;
}

struct node * create(struct node *head)
{
    int co , ex , i , n ;
    cout<<"\n<Enter the Polynomial>\n";
    cout<<"\nEnter the numbers of terms : ";
    cin>>n;
    
    for(i=0 ; i<n ; i++)
    {
        cout<<"\nEnter Coefficient of "<<i+1<<" term : ";
        cin>>co;
        cout<<"\nEnter Exponent of "<<i+1<<" term : ";
        cin>>ex;

        head = insert(head,co,ex);
    }
    return head;
}

void display(struct node *head)
{
    if(head==NULL)
    {
        cout<<"\nNo Polynomial found!!\n";
    }
    else
    {
        struct node *ptr = head ;
        while(ptr!=NULL)
        {
            cout<<ptr->coeff<<"x^"<<ptr->expo;
            ptr=ptr->link;
            if(ptr!=NULL)
            {
                cout<<" + ";
            }
            else
            {
                cout<<"\n";
            }
        }
        
    }
}

void poly_multi(struct node *head1 , struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;

    int res1 , res2 ;

    while(ptr1!=NULL)
    {
        ptr2=head2;//position of ptr2 is reset
        while(ptr2!=NULL)
        {
            res1 = ptr1->coeff * ptr2->coeff ; 
            res2 = ptr1->expo + ptr2->expo ; 
            head3 = insert(head3 , res1 , res2);
            ptr2=ptr2->link;
        }
        ptr1 = ptr1->link;
    }

    //Adding Like Terms
    struct node *ptr3=head3;
    struct node *ptr4=NULL;

    while(ptr3->link!=NULL)
    {
        if(ptr3->expo==ptr3->link->expo)
        {
            ptr3->coeff=ptr3->coeff + ptr3->link->coeff;
            ptr4=ptr3->link;
            ptr3->link=ptr4->link;
            free(ptr4);
            ptr4=NULL;
        }
        else
        {
            ptr3 = ptr3->link;
        }
    }

    cout<<"\nMultiplication of the Polynomials is \n";
    display(head3);
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    head1 = create(head1);
    head2 = create(head2);

    poly_multi(head1,head2);
    return 0;
}