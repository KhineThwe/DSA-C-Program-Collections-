//
// Created by Khine on 9/6/2022.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int count = 0;
struct node{
    struct node *prev;
    int ssn;
    long int phNo;
    float sal;
    char name[20],dept[20],desg[20];
    struct node *next;
}*h,*temp,*temp1,*temp2,*temp4;
struct node *head;
struct node *createNode(){
    struct node *new = (struct node*)malloc(sizeof (struct node));
    return new;
}
void create(){
    int ssn;
    long int phNo;
    float sal;
    char name[20],dept[20],desg[20];
    temp =createNode();
    temp->prev = NULL;
    temp->next = NULL;
    printf("\n enter ssn, name, department, designation, salary "
           "and phNo of employee:\n");
    scanf("%d %s %s %s %f %ld",&ssn, name, dept, desg,&sal, &phNo);
    temp->ssn = ssn;
    strcpy(temp->name,name);
    strcpy(temp->dept,dept);
    strcpy(temp->desg,desg);
    temp->sal = sal;
    temp->phNo = phNo;
    count++;
}
void insertbeg(){
    if(h == NULL){
        create();
        h = temp;
        temp1 =h;
    }else{
        create();
        temp->next = h;
        h->prev = temp;
        h=temp;
    }
}
void insertend(){
    if(h == NULL){
        create();
        h=temp;
        temp1=h;
    }else{
        create();
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}
void deletebeg(){
   struct node *temp;
   temp = h;
   if(temp == NULL){
       printf("List is empty\n");
       return;
   }
   if(temp->next == NULL){
       printf("%d %s %s %s %f %ld\n",
              temp->ssn, temp->name,
              temp->dept, temp->desg,
              temp->sal, temp->phNo);
       free(temp);
       h = NULL;
   }else{
       h = h->next;
       h->prev = NULL;
       printf("%d %s %s %s %f %ld\n",
              temp->ssn, temp->name,
              temp->dept, temp->desg,
              temp->sal, temp->phNo);
       free(temp);
   }
   count--;
}
void deleteend(){
    struct node* temp;
    temp = h;
    if (temp == NULL) {
        printf("list is empty\n");
        return;
    }
    if (temp->next == NULL) {
        printf("%d %s %s %s %f %ld\n",
               temp->ssn, temp->name,
               temp->dept, temp->desg,
               temp->sal, temp->phNo);
        free(temp);
        h = NULL;
    }else{
        temp = temp1;
        temp2 = temp1->prev;
        temp2->next =NULL;
        free(temp);
        temp1 = temp2;
    }
    count--;
}
void displaybeg(){
    temp2 = h;
    if (temp2 == NULL) {
        printf("\n list is empty\n");
        return;
    }
    printf("\n linked list elements "
           "from beginning:\n");
    while (temp2 != NULL) {
        printf("%d %s %s %s %f %ld\n",
               temp2->ssn, temp2->name,
               temp2->dept, temp2->desg,
               temp2->sal, temp2->phNo);
        temp2 = temp2->next;
    }

    // Print the count
    printf("number of employees=%d", count);
}
void employerDetails(){
    int ch,n,i;
    h = NULL;
    temp = temp1 = NULL;
    printf("--------Menu------------\n");
    printf("\n 1.Create a DLL of n emp");
    printf("\n 2.Display from beginning");
    printf("\n 3.Insert at end");
    printf("\n 4.Delete at end");
    printf("\n 5.Insert at beginning");
    printf("\n 6.Delete at beginning");
    printf("\n 7.To show DLL as queue");
    printf("\n 8.Exit\n");
    printf("----------------------\n");
    while(1){
        printf("\n Enter choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("\n Enter number of employees:");
                scanf("%d", &n);
                for(int i=0;i<n;i++){
                    insertend();
                }
                break;
            case 2:
                displaybeg();
                break;
            case 3:
                insertend();
                break;
            case 4:
                deleteend();
                break;
            case 5:
                insertbeg(&head);
                break;
            case 6:
                deletebeg();
                break;
            case 7:
                printf(
                        "\n to show DLL as queue"
                        " \n1.perform insert and"
                        " deletion operation by "
                        "calling insertbeg() and "
                        "deleteend() respectively\n "
                        "\t OR \n 2.perform insert "
                        "and delete operations by"
                        "calling  insertend() and "
                        "deletebeg() respectively\n");
                break;
            case 8:
                exit(0);
            default:
                printf("wrong choice\n");

        }
    }

}
int main(){
    employerDetails();
    return 0;
}
