#include<iostream>
#include<stdlib.h>

using namespace std;
template<class T>
struct node
{
    T data;
    struct node *next;
    struct node*prev;

};


template<class T>
class SinglyLL
{
    public:
    struct node<T>*First;
    int iCount;
    SinglyLL();
    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No,T iPos);
    void DeleteAtPos(T iPos);
    void DeleteFirst();
    void DeleteLast();
    void Display();


};

template<class T>
SinglyLL<T>::SinglyLL()
{
    First=NULL;
    iCount=0;
}

template<class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct node<T>* newn=new node<T>;
    newn->data=No;
    newn->next=NULL;
    if(First==NULL)
    {
        First=newn;
        iCount++;

    }
    else
    {
        newn->next=First;
        First=newn;
        iCount++;
    }
}

template<class T>
void SinglyLL<T>::InsertLast(T No)
{
     struct node<T>*newn=new node<T>;
     struct node<T>*temp=First;
    newn->data=No;
    newn->next=NULL;
    if(First==NULL)
    {
        First=newn;
        iCount++;

    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        iCount++;


}

}

template<class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements of link list are:"<<"\n";
    struct node<T>*temp=First;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"NULL"<<"\n";
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
    if(First==NULL)
    {
        return;

    }
    else if(First->next==NULL)
    {
        delete(First);
        First=NULL;
        iCount--;

    }
    else
    {
        struct node<T>* temp=First;
        First=First->next;
        delete temp;
        iCount--;


    }

}

template<class T>
void SinglyLL<T>::DeleteLast()
{
    if(First==NULL)
    {
        return;

    }
    else if(First->next==NULL)
    {
        delete(First);
        First=NULL;
        iCount--;

    }
    else
    {
    struct node<T>* temp=First;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;

}
}

template<class T>
void SinglyLL<T>:: InsertAtPos(T No,T iPos)
{
    struct node<T>* newn=new node<T>;
    struct node<T>* temp=First;
    newn->data=No;
    newn->next=NULL;
    if((iPos<1)||(iPos>iCount+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if(iPos==1)
    {
        InsertFirst(No);
    }
    else if(iPos==iCount+1)
    {
        InsertLast(No);
    }
    else
    {
    int iCnt=0;
    for(iCnt=1;iCnt<iPos-1;iCnt++)
    {
        temp=temp->next;
    }
    newn->next=temp->next;
    temp->next=newn;

    iCount++;

    }
}

template<class T>
void SinglyLL<T>::DeleteAtPos(T iPos)
{
    if((iPos<1)||(iPos>iCount))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==iCount)
    {
        DeleteLast();
    }
    else
    {
    int iCnt=0;
    struct node<T>* temp=First;
    struct node<T>* temp2=NULL;
    for(iCnt=1;iCnt<iPos-1;iCnt++)
    {
        temp=temp->next;
    }
    temp2=temp->next;
    temp->next=temp2->next;
    delete temp2;

    }


}


template<class T>
class SinglyCL
{
    public:
        struct node<T>* First;
        struct node<T>* Last;

        SinglyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, T ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(T ipos);

        void Display();
        int Count();
};

template<class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;

}
template<class T>
void SinglyCL<T>::InsertFirst(T no)
{
    struct node<T>* newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        newn->next = First;
        First = newn;
        (Last)->next = First;
    }
}
template<class T>
void SinglyCL<T>::InsertLast(T no)
{
    struct node<T> *newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        (Last) -> next = newn;
        Last = newn;
        (Last)->next = First;
    }
}
template<class T>
void SinglyCL<T>::Display()
{
    struct node<T>*temp = First;

    cout<<"Elements of Linked list are : "<<"\n";

    do
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"\n";
}
template<class T>
int SinglyCL<T>::Count()
{
    struct node<T>*temp = First;

    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);
    return iCnt;
}
template<class T>
void SinglyCL<T>::DeleteFirst()
{
struct node<T>* temp = First;

    if((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node in LL
    {
        //free(*First);
        delete First;

        First = NULL;
        Last = NULL;
    }
    else    // If LL contains more than 1 node
    {
        First = (First)->next;
        //free(temp);
        delete temp;

        (Last) ->next = First;
    }
}
template<class T>
void SinglyCL<T>::DeleteLast()
{
    struct node<T>*temp = First;

    if((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node in LL
    { 
        delete First;

        First = NULL;
        Last = NULL;
    }
    else    // If LL contains more than 1 node
    {
        while(temp->next != (Last))
        {
            temp = temp -> next;
        }

        delete temp->next;

        Last = temp; 
        (Last) ->next = First;
    }
}
template<class T>
void SinglyCL<T>::InsertAtPos(T no, T ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct node<T>* newn = NULL;
    struct node<T>* temp = First;

    if((ipos < 1) || (ipos > iNodeCnt + 1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new node<T>;

        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}
template<class T>
void SinglyCL<T>::DeleteAtPos(T ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct node<T>* temp1 = First;
    struct node<T>* temp2 = NULL;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }   
        temp2 = temp1 ->next;

        temp1->next = temp2->next;
        delete temp2;
    }
}
template<class T>
class DoublyLinear
{
    public:
    struct node<T>*First;
    int iCount;
    DoublyLinear();
    void InsertFirst(T No);
    void InsertLast(T No);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(T No,T iPos);
    void DeleteAtPos(T iPos);
    void Display();


};
template<class T>
DoublyLinear<T>::DoublyLinear()
{
    First=NULL;
    iCount=0;
}
template<class T>
void DoublyLinear<T>::InsertFirst(T No)
{
    struct node<T>* newn=new node<T>;
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;
    if(First==NULL)
    {
        First=newn;
        iCount++;

    }
    else
    {
        newn->next=First;
        First->prev=newn;
        First=newn;
        iCount++;

    }
}
template<class T>
void DoublyLinear<T>::InsertLast(T No)
{
    struct node<T>* newn=new node<T>;
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;
    if(First==NULL)
    {
        First=newn;
        iCount++;

    }
    else
    {
    struct node<T>* temp=First;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newn;
    newn->prev=temp;
    iCount++;
    }



}
template<class T>
void  DoublyLinear<T>::DeleteFirst()
{
    if(First==NULL)
    {
    return ;
    }
    else if(First->next==NULL)
    {
        free(First);
        First=NULL;

    }
    else
    {
        First=First->next;
        free(First->prev);
        (First)->prev=NULL;

    }
}
template<class T>
void  DoublyLinear<T>::DeleteLast()
{
    if(First==NULL)
    {
    return ;
    }
    else if(First->next==NULL)
    {
        free(First);
        First=NULL;

    }
    else
    {
    struct node<T>* temp=First;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);

    temp->next=NULL;


}
}
template<class T>
void  DoublyLinear<T>::InsertAtPos(T No,T iPos)
{
    struct node<T>* temp=First;
    struct node<T>* newn=new node<T>;
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;
    if((iPos<1)||(iPos>iCount+1))
    {
        cout<<"INVALID POSITION"<<"\n";
        return;
    }
    if(iPos==1)
    {
        InsertFirst(No);
    }
    else if(iPos==iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        int iCnt=0;
        for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
        

    }

}
template<class T>
void  DoublyLinear<T>::DeleteAtPos(T iPos)
{
    
    if((iPos<1)||(iPos>iCount))
    {
        cout<<"INVALID POSITION"<<"\n";
        return;
    }
    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==iCount)
    {
        DeleteLast();
    }
    else
    {
        struct node<T>* temp=First;
        struct node<T>*temp2=NULL;

        int iCnt=0;
        for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        temp2=temp->next;
        temp->next=temp2->next;
        temp->next->prev=temp;
        free(temp2);
    }
}
template<class T>
void DoublyLinear<T>:: Display()
{
    struct node<T>* temp=First;
    cout<<"Elements of link list are:"<<"\n";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";

        temp=temp->next;

    }
    cout<<"NULL"<<"\n";
}
template<class T>
class DoublyC
{
    public:
    struct node<T>* First;
    struct node<T>* Last;
    DoublyC();
    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No,T iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(T iPos);
    void Display();
    int Count();
};
template<class T>
DoublyC<T>::DoublyC()
{
    First=NULL;
    Last=NULL;
}
template<class T>
void DoublyC<T>:: InsertFirst(T No)
{
    struct node<T>* newn=NULL;
    newn=new node<T>;
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;
    if(First==NULL && Last==NULL)
    {
        First=newn;
        Last=newn;
    }
    else
    {
        newn->next=First;
        (First)->prev=newn;
        First=newn;
    }
    (First)->prev=Last;
    (Last)->next=First;

}
template<class T>
void DoublyC<T>::InsertLast(T No)
{
    struct node<T>* newn=NULL;
    newn=new node<T>;
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;
    if(First==NULL && Last==NULL)
    {
        cout<<"Link List is empty"<<"\n";
        return;
    }
    else
    {
        newn->prev=Last;
        (Last)->next=newn;
        Last=newn;
    }
    (Last)->next=First;
    (First)->prev=Last;

}
template<class T>
void DoublyC<T>:: DeleteFirst()
{
    struct node<T>* temp=First;
    if((First==NULL) &&(Last==NULL))
    {
        return ;
    }
    else if ((First==Last))
        
    {
        free(First);
        First=NULL;
        Last=NULL;

    }
    else{
        First=(First)->next;
        free((Last)->next);
        }
        (First)->prev=Last;
        (Last)->next=First;
        
        
}
template<class T>
void DoublyC<T>:: DeleteLast()
{
    struct node<T>* temp=First;
    if(First==NULL && Last==NULL)
    {
        return;
    }
    else if(First==Last)
    {
        free(First);
        First=NULL;
        Last=NULL;
    }
    else
    {
       Last=(Last)->prev;
       free((Last)->next);
       (Last)->next=First;
       (First)->prev=Last;

    }
}
template<class T>
void DoublyC<T>::InsertAtPos(T No,T iPos )
{
    struct node<T>*newn=new node<T>;
    int iCnt=0;
    struct node<T>* temp=First;
    int NodeCnt=Count();
    if((iPos<1) ||(iPos>NodeCnt+1))
    {
        cout<<"Invalid Position.."<<"\n";
    }
    if(iPos==1)
    {
        InsertFirst(No);

    }
    else if(iPos==NodeCnt+1)
    {
        InsertLast(No);
    }
    else
    {
        newn->data=No;
        newn->next=NULL;
        newn->prev=NULL;
        for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        newn->prev=temp;
        temp->next=newn;

    }

}
template<class T>
void DoublyC<T>:: DeleteAtPos(T iPos)
{
    int iCnt=0;
    struct node<T>*temp=First;
    int NodeCnt=Count();
    if((iPos<1) ||(iPos>NodeCnt))
    {
        cout<<"Invalid Position.."<<"\n";
        return;
    }
    if(iPos==1)
    {
        DeleteFirst();

    }
    else if(iPos==NodeCnt)
    {
       DeleteLast();
    }
    else
    {
        struct node<T>*temp=First;
        for(iCnt=0;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        free(temp->next->prev);
        temp->next->prev=temp;
    }

}
template<class T>
void DoublyC<T>::Display()
{
    struct node<T>*temp=First;
    if(First==NULL && Last==NULL)
    {
    cout<<"Link List is empty"<<"\n";
        return;
    }
   do
   {
    cout<<"|"<<temp->data<<"|<=>";
    temp=temp->next;
   }while(temp!=Last->next);
   cout<<"\n";
}
template<class T>
int DoublyC<T>::Count()
{
    int iCnt=0;
    struct node<T>* temp=First;

    if(First==NULL && Last==NULL)
    {
         return iCnt;
    }
    do
    {
        iCnt++;
        temp=temp->next;

    }while(temp!=(Last)->next);
    return iCnt;
}





int main()
{

SinglyLL<int>obj1;
obj1.InsertFirst(101);
obj1.InsertFirst(111);

obj1.InsertFirst(121);
obj1.InsertFirst(131);
obj1.Display();
cout<<"Number o link list are:"<<obj1.iCount<<"\n";


obj1.InsertLast(151);
obj1.InsertLast(171);

obj1.InsertLast(181);
obj1.Display();
cout<<"Number o link list are:"<<obj1.iCount<<"\n";

obj1.InsertAtPos(200,4);
obj1.Display();
cout<<"Number o link list are:"<<obj1.iCount<<"\n";

obj1.DeleteAtPos(4);
obj1.Display();
cout<<"Number o link list are:"<<obj1.iCount<<"\n";


obj1.DeleteFirst();
obj1.Display();
cout<<"Number o link list are:"<<obj1.iCount<<"\n";

obj1.DeleteLast();
obj1.Display();
cout<<"Number o link list are:"<<obj1.iCount<<"\n";

    SinglyCL<int>obj;
 int iRet = 0;
   
    
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    
     obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
     obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";


    obj.InsertAtPos(105,5);
     obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";


    

    obj.DeleteAtPos(5);
    obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";


   
    obj.DeleteFirst();
     obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    DoublyLinear<int> dobj2;
    dobj2.InsertFirst(111);
    dobj2.InsertFirst(121);
    dobj2.InsertFirst(141);
    dobj2.Display();
    cout<<"Number of node are:"<<dobj2.iCount<<"\n";

    dobj2.InsertLast(151);
     dobj2.Display();
    cout<<"Number of node are:"<<dobj2.iCount<<"\n";


    dobj2.InsertAtPos(101,3);
     dobj2.Display();
    cout<<"Number of node are:"<<dobj2.iCount<<"\n";

    dobj2.DeleteAtPos(3);
     dobj2.Display();
    cout<<"Number of node are:"<<dobj2.iCount<<"\n";

    
    dobj2.DeleteFirst();
     dobj2.Display();
    cout<<"Number of node are:"<<dobj2.iCount<<"\n";

    dobj2.DeleteLast();
     dobj2.Display();
    cout<<"Number of node are:"<<dobj2.iCount<<"\n";
    

    cout<<"------------------------------------------------------------------------"<<"\n";
    cout<<"SECOND NUMBER OF LINKLIST:"<<"\n";
    DoublyLinear<int> dobj1;
    dobj1.InsertFirst(111);
    dobj1.InsertFirst(121);
    dobj1.InsertFirst(141);
    dobj1.Display();
    cout<<"Number of node are:"<<dobj1.iCount<<"\n";

    dobj1.InsertLast(151);
     dobj1.Display();
    cout<<"Number of node are:"<<dobj1.iCount<<"\n";


    dobj1.InsertAtPos(101,3);
     dobj1.Display();
    cout<<"Number of node are:"<<dobj1.iCount<<"\n";

    dobj1.DeleteAtPos(3);
     dobj1.Display();
    cout<<"Number of node are:"<<dobj1.iCount<<"\n";

    
    dobj1.DeleteFirst();
     dobj1.Display();
    cout<<"Number of node are:"<<dobj1.iCount<<"\n";

    dobj1.DeleteLast();
     dobj1.Display();
    cout<<"Number of node are:"<<dobj1.iCount<<"\n";

     DoublyC<int> dobj;


    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    dobj.Display();
iRet=dobj.Count();
    cout<<"Number of link List are:"<<iRet<<"\n";

    dobj.InsertLast(101);
    dobj.InsertLast(121);
    dobj.InsertLast(111);
     dobj.Display();
     iRet=dobj.Count();
   cout<<"Number of link List are:"<<iRet<<"\n";

    dobj.InsertAtPos(131,3);
    dobj.Display();
    iRet=dobj.Count();
    cout<<"Number of link List are:"<<iRet<<"\n";

    dobj.DeleteAtPos(3);
    dobj.Display();
    iRet=dobj.Count();
   cout<<"Number of link List are:"<<iRet<<"\n";


    dobj.DeleteFirst();
    dobj.Display();
 iRet=dobj.Count();
    cout<<"Number of link List are:"<<iRet<<"\n";
     dobj.DeleteLast();
     dobj.Display();
iRet=dobj.Count();
   cout<<"Number of link List are:"<<iRet<<"\n";
     return 0;

}
    



