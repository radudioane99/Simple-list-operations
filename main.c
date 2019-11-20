#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct nod
{
    char nume[30];
    int key;
    struct nod *next;
};

struct nod *head = NULL;
struct nod *ptr=NULL;

void printlist()
{
    struct nod *ptr=head;
    int i=1;
    if(head!=NULL)
    {
     printf("The list is : \n");
     while(ptr != NULL)
     {
        printf(" \n The element number :");
        printf("%d",i);
        printf("\n The key value :");
        printf("%d",ptr->key);
        printf("\n The name value :");
        printf("%s",ptr->nume);
        printf("\n \n");
        ptr=ptr->next;
        i++;
     }
    }
    else {printf("The list is empty!!!");}
}

void insertfirst()
{

    /// new node
   struct nod *link = (struct nod*) malloc(sizeof(struct nod));
    /// new node data input
   printf("Give the key: \n");
   scanf("%d",&link->key);
   printf("Give the name: \n");
   scanf("%s",link->nume);

    /// inserting the element

   // point next the old header
   link->next = head;
   // set the new head (global declared)
   head=link;


}

void insertlast()
{
    if(head!=NULL)
    {
        ///the new element
    struct nod *link = (struct nod*) malloc(sizeof(struct nod));
    ///the data needed
    printf("\n Give the key :");
    scanf("%d",&link->key);
    printf("\n Give the name:");
    scanf("%s",link->nume);
    ///traverse the list to the last element
    struct nod *p;
    struct nod *current;
    for (current=head;current!=NULL;current=current->next)
    {
        p=current;
    }
    ///inserting the new element
    p->next=link;
    link->next=NULL;
    }
    else {printf("The list is empty!!! \n");}
}
void deletefirst()
{
    if(head->next != NULL)
    {
       /// save reference to first link in order to free the memory
       struct nod *templink = (struct nod *)malloc(sizeof(struct nod));
       templink->next=head;
       /// deleting the first element
       head=head->next;

       /// free the memory
       free(templink->next);
       free(templink);
    }
    else {head=NULL;}



}
bool isempty()
{
    /// is the list empty
    if (head==NULL) return 1;
    else return 0;
}
int length()
{
    /// traverse the list and count the elements
    int len=0;
    struct nod *current;
    for(current=head;current!=NULL;current=current->next)
    {
        len++;
    }
    return len;
}
///Finds an element of a given key
struct nod* findkey(int key)
{
    ///Start from the beginning
    struct nod *current = head;

    ///Check if the list is empty
    if (isempty()==1) return NULL;
    else
    {
      for (current=head;current!=NULL;current=current->next)
      {
         if (current->key == key) return current;
      }
      return NULL;
    }
};
void insertbeforekey(int key)
{
    struct nod *current;
    current=head;
    ///Construct the new node
    struct nod *link = (struct nod*)malloc(sizeof(struct nod));
    ///the data needed
    printf("\n Give the key of the new element :");
    scanf("%d",&link->key);
    printf("\n Give the name of the new element:");
    scanf("%s",link->nume);
    ///Traverse the list until the element before the key element
    while (current->next->key !=key)
    {
        current=current->next;
    }
    ///insert process
    link->next=current->next;
    current->next=link;


}
void insertafterkey (int key)
{
    ///construct the new node
    struct nod *link = (struct nod*)malloc(sizeof(struct nod));
    ///The data needed
    printf("Give the key of the new element \n");
    scanf("%d",&link->key);
    printf("Give the name of the new element \n");
    scanf("%s",link->nume);
    ///Traverse the list
    struct nod *current;
    current=head;
    while (current->key!=key)
    {
        current=current->next;
    }
    ///The insertion process
    link->next=current->next;
    current->next=link;



}
void deletekey(int key)
{

   //start from the first link
   struct nod* current = head;
   struct nod* previous = NULL;

   //if list is empty
   if(head == NULL) {
      return ;
   }

   //navigate through list
   while(current->key != key) {

      //if it is last node
      if(current->next == NULL) {
         return ;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }

   free(current);

}
int main()
{
    int op = 0;
    printf("\n                   LISTE SIMPLU INLANTUITE                \n");
    while (op!=9)
    {
         printf("MENU:  \n\n");
         printf("1.PRINT \n");
         printf("2.INSERT FIRST \n");
         printf("3.INSERT LAST \n");
         printf("4.DELETE FIRST \n");
         printf("5.LIST LENGTH \n");
         printf("6.INSERT BEFORE KEY \n");
         printf("7.INSERT AFTER KEY \n");
         printf("8.DELETE THE ELEMENT WITH KEY \n");
         printf("9.EXIT \n");

         printf("Give operation :");
         scanf("%d",&op);
        switch (op)
        {
          case 1 : {printlist();break;}
          case 2 : {insertfirst();break;}
          case 3 : {insertlast();break;}
          case 4 : {deletefirst();break;}
          case 5 : {printf("\n THE LIST LENGTH IS %d",length());}
          case 6 : {int key;
                    printf("\n Give the key of the element before you want to insert :");
                    scanf ("%d",&key);
                    insertbeforekey(key);
                    break;
                   }
          case 7 : {
                    int key;
                    printf("\n Give the key of the element after you want to insert :");
                    scanf ("%d",&key);
                    insertafterkey(key);
                    break;
                   }
          case 8 : { int key;
                     printf("\n Give the key of the element you want to delete :");
                     scanf ("%d",&key);
                     deletekey(key);
                     break;
                   }

          case 9 : {return 0;}
          default : {printf("\n\n Wrong command!!! \n\n");}
        }

        printf("\n\n");

    }

    return 0;
}
