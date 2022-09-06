//
// Created by Khine on 9/4/2022.
//
#include "stdio.h"
#include "stdlib.h"
struct Node{
    int data;
    struct Node *next;
};
struct Node *head;
struct Node *current;

struct Node *createNode(){
    struct Node *new = (struct Node*)malloc(sizeof (struct Node));
    return new;
}
void insertAtBegin(struct Node **head_ref,int value){
   struct Node *newNode = createNode();
   if(newNode == NULL){
       return;
   }
    if((*head_ref)->data==value){
        printf("Duplicate number are not allowed\n");
    }else{
        newNode->data = value;
        newNode->next = (*head_ref);
        (*head_ref)=newNode;
    }

}
void insertAtPos(struct Node *head,int value,int pos){
    struct Node *temp = head;
    struct Node *newNode = createNode();
    newNode->data = value;
    newNode->next=NULL;
    pos--;
    while (pos!=1){
        temp = temp->next;
        pos--;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void insertAtLast(struct Node *head,int value){
    struct Node *ptr=head;
    struct Node *newNode = createNode();
    newNode->data=value;
    newNode->next=NULL;
    while(ptr->next != NULL){
        ptr=ptr->next;
    }
    ptr->next = newNode;
}
void deleteAtBegin(){
    if(head == NULL){
        printf("List is already empty!");
    }else{
//        struct Node *temp = head;
        head = head->next;
//        free(temp);
        printf("\n\t**Element is successfully deleted!!!");
//        temp = NULL;
    }
}
void deleteAtLast(struct Node* head){
    if(head == NULL){
        printf("List is already empty");
    }else if(head->next == NULL) {
        free(head);
        head =NULL;
    }else{
        struct Node *temp = head;
        struct Node *temp2 = head;
        while(temp->next !=NULL){
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        free(temp);
        temp=NULL;

    }//one node in the list

}
void deleteAtPos(struct Node **head_ref,int pos){
    struct Node *current = *head_ref;
    struct Node *previous = *head_ref;
    if(*head_ref == NULL){
        printf("List is already empty");
    }else if(pos == 1){
        *head_ref = current->next;//fist nodes from list
//        free(current);
        current = NULL;
    }else{
        while(pos != 1){
           previous = current;
           current = current->next;
           pos--;
        }
        previous->next = current->next;
//        free(current);
        current = NULL;
    }

}
void find(struct Node* head,int number){
    struct Node *temp = head;
    int count = 0;
    while(temp!=NULL){
        if(temp->data == number){
            printf("Entry Found: %d!\n\n",number);
            break;
        }
        temp=temp->next;
    }
    if(temp==NULL){
        printf("\nYour entry is not on the list!\n\n");
        return;
    }
}

void display(struct Node* head){
    struct Node* temp = head;
    int count = 0;
    if(temp == NULL){
        printf("\n\t**Linked List is empty**\n\n");
    }else{
        printf("\n\tCurrent List:\n\t");
        while(temp != NULL){
            count++;
            printf("\n\tData: %d\t",temp->data);
            temp = temp->next;
        }
        printf("\n\tTotal Nodes: %d\n\t",count);
    }
}
int main(){
    int ch;
    head = createNode();
    head->data = 45;
    head->next = NULL;

    insertAtLast(head,98);
    insertAtLast(head,3);
    insertAtLast(head,100);

//    current = createNode();
//    current->data =98;
//    current->next=NULL;
//    head->next = current;
//
//    current = createNode();
//    current->data = 100;
//    current->next=NULL;
//
//    head->next->next = current;

    while(1){
        printf("\n\t\\t***MENU***\n\t1.Insert at the beginning\n\t2.Insert at nth position"
               "\n\t3.Insert at end\n\t4.Delete at beginning\n\t5.Delete at end\n\t"
               "6.Delete nth node\n\t7.Find\n\t8.Display\n\t");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
                printf("Enter value to be inserted: ");
                int v1;
                scanf("%d",&v1);
                insertAtBegin(&head,v1);
                break;
            case 2:
                printf("Enter value to be inserted: ");
                int v2,pos;
                scanf("%d",&v2);
                printf("Enter position to be inserted: ");
                scanf("%d",&pos);
                insertAtPos(head,v2,pos);
                break;
            case 3:
                printf("Enter value to be inserted: ");
                int v3;
                scanf("%d",&v3);
                insertAtLast(head,v3);
                break;
            case 4:
                deleteAtBegin();
                break;
            case 5:
                deleteAtLast(head);
                break;
            case 6:
                printf("Enter position to delete: ");
                int pos1;
                scanf("%d",&pos1);
                deleteAtPos(&head,pos1);
                break;
            case 7:
                printf("Insert the number to find: ");
                int x;
                scanf("%d",&x);
                find(head,x);
                break;
            case 8:
                display(head);
                break;

        }
    }
    return 0;
}
//create,delete,front,insert after,end,
//search,read,update,
// merge,split
