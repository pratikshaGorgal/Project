#include<stdio.h>
#include<stdlib.h>
#pragma pack(1)
struct node
{
    int data;
    struct node*next;
    struct node*prev;

};
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE First,PPNODE Last,int No)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=No;
    newn->next=NULL;
    if((*First==NULL) &&(*Last==NULL))
    {
        *First=*Last=newn;
        (*Last)->next=*First; 
    }
    else
    {
        newn->next=*First;
        *First=newn;
        (*Last)->next=*First;
        }

}
void InsertLast(PPNODE First,PPNODE Last,int No)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=No;
    newn->next=NULL;
    if((*First==NULL) &&(*Last==NULL))
    {
        *First=*Last=newn;
        (*Last)->next=*First;

    }
    else
    {
        (*Last)->next=newn;
        *Last=newn;
        (*Last)->next=*First;

    }
}
void DeleteFirst(PPNODE First,PPNODE Last)
{
    if((*First==NULL) &&(*Last==NULL))
    {
        return;
    }
    else if(*First==*Last)
    {
        free(*First);
        *First=NULL;
        *Last=NULL;

    }
    else
    {
        *First=(*First)->next;
        free((*Last)->next);
        (*Last)->next=*First;

        
    }
}
void DeleteLast(PPNODE First,PPNODE Last)
{  PNODE temp=*First;
    if((*First==NULL) &&(*Last==NULL))
    {
        return;
    }
    else if(*First==*Last)
    {
        free(*First);
        *First=NULL;
        *Last=NULL;

    }
    else
    {
        while(temp->next!=*Last)
        {
            temp=temp->next;

        }
        free(temp->next);
        *Last=temp;
        (*Last)->next=*First;
    }

}
void InsertAtPos(PPNODE First,PPNODE Last,int No,int iPos)
{
    PNODE temp=*First;
    int iCnt=0;
    int NodeCnt= Count(*First, *Last);
    if((iPos<1)||(iPos>NodeCnt+1))
    {
        printf("Invalid Position\n");

    }
    if(iPos==1)
    {
        InsertFirst(First,Last,No);

    }
    else if(iPos==NodeCnt+1)
    {
        InsertLast(First,Last,No);
    }
    else
    {
        PNODE newn=NULL;
        newn=(PNODE)malloc(sizeof(NODE));
        newn->data=No;
        newn->next=NULL;
        for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;



    }
}
void DeleteAtPos(PPNODE First,PPNODE Last,int iPos)
{
    PNODE temp1=*First;
    PNODE temp2=NULL;
    int iCnt=0;
    int NodeCnt= 0;
    NodeCnt=Count(*First,*Last);
    if((iPos<1)||(iPos>NodeCnt))
    {
        printf("Invalid Position\n");

    }
    if(iPos==1)
    {
        DeleteFirst(First,Last);

    }
    else if(iPos==NodeCnt)
    {
        DeleteLast(First,Last);
    }
    else
    {
        for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        free(temp2);
    }
}


void Display(PNODE First,PNODE Last)
{
    printf("Elements of link list are:\n");
    do
    {
        printf("| %d |->",First->data);
        First=First->next;
        
    }while(First!=Last->next);
    printf("\n");


}
int Count(PNODE First,PNODE Last)
{
    int iCnt=0;
    do
    {
        iCnt++;
        First=First->next;
    }while(First!=Last->next);
    return iCnt;
}

void InsertFirst1(PPNODE First,PPNODE Last,int No)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;
    if(*First==NULL && *Last==NULL)
    {
        *First=newn;
        *Last=newn;
    }
    else
    {
        newn->next=*First;
        (*First)->prev=newn;
        *First=newn;
    }
    (*First)->prev=*Last;
    (*Last)->next=*First;

}
void InsertLast1(PPNODE First,PPNODE Last,int No)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;
    if(*First==NULL && *Last==NULL)
    {
        printf("Link List is empty\n");
        return;
    }
    else
    {
        newn->prev=*Last;
        (*Last)->next=newn;
        *Last=newn;
    }
    (*Last)->next=*First;
    (*First)->prev=*Last;

}
void DeleteFirst1(PPNODE First,PPNODE Last)
{
    PNODE temp=*First;
    if((*First==NULL) &&(*Last==NULL))
    {
        return;
    }
    else if ((*First==*Last))
        
    {
        free(*First);
        *First=NULL;
        *Last=NULL;

    }
    else{
        *First=(*First)->next;
        free((*Last)->next);
        }
        (*First)->prev=*Last;
        (*Last)->next=*First;
        
        
}
void DeleteLast1(PPNODE First,PPNODE Last)
{
    PNODE temp=*First;
    if(*First==NULL && *Last==NULL)
    {
        return;
    }
    else if(*First==*Last)
    {
        free(*First);
        *First=NULL;
        *Last=NULL;
    }
    else
    {
       *Last=(*Last)->prev;
       free((*Last)->next);
       (*Last)->next=*First;
       (*First)->prev=*Last;

    }
}
void InsertAtPos1(PPNODE First,PPNODE Last,int No,int iPos )
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));
    int iCnt=0;
    PNODE temp=*First;
    int NodeCnt=Count(*First,*Last);
    if((iPos<1) ||(iPos>NodeCnt+1))
    {
        printf("Invalid Position..\n");
    }
    if(iPos==1)
    {
        InsertFirst(First,Last,No);

    }
    else if(iPos==NodeCnt+1)
    {
        InsertLast(First,Last,No);
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
void DeleteAtPos1(PPNODE First,PPNODE Last,int iPos)
{
    int iCnt=0;
    int NodeCnt=Count(*First, *Last);
    if((iPos<1) ||(iPos>NodeCnt))
    {
        printf("Invalid Position..\n");
        return;
    }
    if(iPos==1)
    {
        DeleteFirst(First,Last);

    }
    else if(iPos==NodeCnt)
    {
       DeleteLast(First,Last);
    }
    else
    {
        PNODE temp=*First;
        for(iCnt=0;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        free(temp->next->prev);
        temp->next->prev=temp;
    }

}
void Display1(PNODE First,PNODE Last)
{
    if(First==NULL && Last==NULL)
    {
        printf("Link List is empty\n");
        return;
    }
   do
   {
    printf("| %d |<=>",First->data);
    First=First->next;
   }while(First!=Last->next);
   printf("\n");
}
int Count1(PNODE First,PNODE Last)
{
    int iCnt=0;
    if(First==NULL && Last==NULL)
    {
         printf("Link List is empty\n");
         return iCnt;
    }
    do
    {
        iCnt++;
        First=First->next;

    }while(First!=Last->next);
    return iCnt;
}
void InsertFirst3(PPNODE First,PPNODE Last,int No)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;
    if(*First==NULL && *Last==NULL)
    {
        *First=newn;
        *Last=newn;
    }
    else
    {
        newn->next=*First;
        (*First)->prev=newn;
        *First=newn;
    }
    (*First)->prev=*Last;
    (*Last)->next=*First;

}
void InsertLast3(PPNODE First,PPNODE Last,int No)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=No;
    newn->next=NULL;
    newn->prev=NULL;
    if(*First==NULL && *Last==NULL)
    {
        printf("Link List is empty\n");
        return;
    }
    else
    {
        newn->prev=*Last;
        (*Last)->next=newn;
        *Last=newn;
    }
    (*Last)->next=*First;
    (*First)->prev=*Last;

}
void DeleteFirst3(PPNODE First,PPNODE Last)
{
    PNODE temp=*First;
    if((*First==NULL) &&(*Last==NULL))
    {
        return;
    }
    else if ((*First==*Last))
        
    {
        free(*First);
        *First=NULL;
        *Last=NULL;

    }
    else{
        *First=(*First)->next;
        free((*Last)->next);
        }
        (*First)->prev=*Last;
        (*Last)->next=*First;
        
        
}
void DeleteLast3(PPNODE First,PPNODE Last)
{
    PNODE temp=*First;
    if(*First==NULL && *Last==NULL)
    {
        return;
    }
    else if(*First==*Last)
    {
        free(*First);
        *First=NULL;
        *Last=NULL;
    }
    else
    {
       *Last=(*Last)->prev;
       free((*Last)->next);
       (*Last)->next=*First;
       (*First)->prev=*Last;

    }
}
void InsertAtPos3(PPNODE First,PPNODE Last,int No,int iPos )
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));
    int iCnt=0;
    PNODE temp=*First;
    int NodeCnt=Count(*First,*Last);
    if((iPos<1) ||(iPos>NodeCnt+1))
    {
        printf("Invalid Position..\n");
    }
    if(iPos==1)
    {
        InsertFirst(First,Last,No);

    }
    else if(iPos==NodeCnt+1)
    {
        InsertLast(First,Last,No);
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
void DeleteAtPos3(PPNODE First,PPNODE Last,int iPos)
{
    int iCnt=0;
    int NodeCnt=Count(*First, *Last);
    if((iPos<1) ||(iPos>NodeCnt))
    {
        printf("Invalid Position..\n");
        return;
    }
    if(iPos==1)
    {
        DeleteFirst(First,Last);

    }
    else if(iPos==NodeCnt)
    {
       DeleteLast(First,Last);
    }
    else
    {
        PNODE temp=*First;
        for(iCnt=0;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        free(temp->next->prev);
        temp->next->prev=temp;
    }

}
void Display3(PNODE First,PNODE Last)
{
    if(First==NULL && Last==NULL)
    {
        printf("Link List is empty\n");
        return;
    }
   do
   {
    printf("| %d |<=>",First->data);
    First=First->next;
   }while(First!=Last->next);
   printf("\n");
}
int Count3(PNODE First,PNODE Last)
{
    int iCnt=0;
    if(First==NULL && Last==NULL)
    {
         printf("Link List is empty\n");
         return iCnt;
    }
    do
    {
        iCnt++;
        First=First->next;

    }while(First!=Last->next);
    return iCnt;
}

int main()
{
    PNODE Head=NULL;
    PNODE Tail=NULL;
    int iRet=0;

    printf("-----------------------------------------------------------------------------\n");
    printf("Singly Linaer..\n");
    InsertFirst(&Head,&Tail,51);
    InsertFirst(&Head,&Tail,21);
    InsertFirst(&Head,&Tail,11);
    Display(Head,Tail);
    iRet=Count(Head,Tail);
    printf("No of link list are:%d\n",iRet);

    InsertLast(&Head,&Tail,81);
    InsertLast(&Head,&Tail,71);
    Display(Head,Tail);
    iRet=Count(Head,Tail);
    printf("No of link list are:%d\n",iRet);

    InsertAtPos(&Head,&Tail,31,3);
    Display(Head,Tail);
    iRet=Count(Head,Tail);
    printf("No of link list are:%d\n",iRet);

    DeleteAtPos(&Head,&Tail,3);
     Display(Head,Tail);
    iRet=Count(Head,Tail);
    printf("No of link list are:%d\n",iRet);


    DeleteFirst(&Head,&Tail);
    Display(Head,Tail);
    iRet=Count(Head,Tail);
    printf("No of link list are:%d\n",iRet);

    DeleteLast(&Head,&Tail);
    Display(Head,Tail);
    iRet=Count(Head,Tail);
    printf("No of link list are:%d\n",iRet);

    printf("-----------------------------------------------------------------------------------\n");
    printf("Doubly Linear link List:\n");
    printf("-----------------------------------------------------------------------------------\n");

    InsertFirst1(&Head,&Tail,91);
    InsertFirst1(&Head,&Tail,81);
    InsertFirst1(&Head,&Tail,71);
    Display1(Head,Tail);
    iRet=Count1(Head,Tail);
    printf("Number of link List are:%d\n",iRet);

    InsertLast1(&Head,&Tail,101);
    InsertLast1(&Head,&Tail,121);
    InsertLast1(&Head,&Tail,111);
     Display1(Head,Tail);
    iRet=Count1(Head,Tail);
    printf("Number of link List are:%d\n",iRet);

    InsertAtPos1(&Head,&Tail,131,3);
     Display1(Head,Tail);
    iRet=Count1(Head,Tail);
    printf("Number of link List are:%d\n",iRet);

    DeleteAtPos1(&Head,&Tail,3);
    Display1(Head,Tail);
    iRet=Count1(Head,Tail);
    printf("Number of link List are:%d\n",iRet);


    DeleteFirst1(&Head,&Tail);
    Display1(Head,Tail);
    iRet=Count1(Head,Tail);
    printf("Number of link List are:%d\n",iRet);
    DeleteLast1(&Head,&Tail);
     Display1(Head,Tail);
    iRet=Count1(Head,Tail);
    printf("Number of link List are:%d\n",iRet);


  printf("-----------------------------------------------------------------------------------\n");
  printf("Doubly Circular..\n");
  printf("-------------------------------------------------------------------------------------\n");

    InsertFirst3(&Head,&Tail,51);
    InsertFirst3(&Head,&Tail,21);
    InsertFirst3(&Head,&Tail,11);
    Display3(Head,Tail);
    iRet=Count3(Head,Tail);
    printf("Number of link List are:%d\n",iRet);

    InsertLast3(&Head,&Tail,101);
    InsertLast3(&Head,&Tail,121);
    InsertLast3(&Head,&Tail,111);
     Display3(Head,Tail);
    iRet=Count3(Head,Tail);
    printf("Number of link List are:%d\n",iRet);

    InsertAtPos3(&Head,&Tail,131,3);
     Display3(Head,Tail);
    iRet=Count3(Head,Tail);
    printf("Number of link List are:%d\n",iRet);

    DeleteAtPos3(&Head,&Tail,3);
    Display3(Head,Tail);
    iRet=Count3(Head,Tail);
    printf("Number of link List are:%d\n",iRet);


    DeleteFirst3(&Head,&Tail);
    Display3(Head,Tail);
    iRet=Count3(Head,Tail);
    printf("Number of link List are:%d\n",iRet);
    DeleteLast3(&Head,&Tail);
     Display3(Head,Tail);
    iRet=Count3(Head,Tail);
    printf("Number of link List are:%d\n",iRet);
   
   return 0;
}




