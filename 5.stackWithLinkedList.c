//
// Created by Khine on 9/7/2022.
//
#include "stdio.h"
#include "stdlib.h"

struct node{
    int data;
    struct node* next;
}*top = NULL;
//top pointer points first node of the linked list

struct node *createNode(){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    return new;
}
int isEmpty(){
    if(top==NULL){
        return 1;
    }else{
        return 0;
    }
}
void push(int data){
    struct node *newNode= createNode();
    if(newNode == NULL){
        printf("Stack overflow. ");
        exit(1);
    }//malloc fun returns NULL when the requested memory can't be allocated.
    newNode->data = data;
    newNode->next = NULL;

    newNode->next = top;
    top = newNode;
}
int pop(){
    struct node *temp;
    temp = top;
    if(isEmpty()){
        printf("Stack Underflow.");
        exit(1);
    }
    int value = temp->data;
    top = top->next;
    free(temp);
    temp=NULL;
    return value;
}
int peek(){
    if(isEmpty()){
        printf("Stack Underflow.");
        exit(1);
    }
    return top->data;
}
void print(){
    struct node *temp;
    temp = top;
    if(isEmpty()){
        printf("Stack Underflow.");
        exit(1);
    }
    printf("The stack elements are: ");
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void find(int number){
    struct node *temp;
    temp = top;
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
int main(){
    int choice,data;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Find\n");
        printf("4. Print all elements of the stack\n");
        printf("5. Print the top elements of the stack\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                data = pop();
                printf("Deleted elements is %d\n",data);
                break;
            case 3:
                printf("Enter the element to find: ");
                scanf("%d",&data);
                find(data);
                break;
            case 4:
                print();
                break;
            case 5:
                peek();
                break;
            case 6:
                exit(1);
            default:
                printf("Wrong Choice\n");
                break;
        }
    }
    return 0;
}

