//
// Created by Khine on 9/8/2022.
//
//reverse stack with two stacks
#include "stdio.h"
#include "stdlib.h"

struct node{
    int data;
    struct node* next;
};
//top pointer points first node of the linked list

struct node *createNode(){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    return new;
}
int isEmpty(struct node *top){
    if(top==NULL){
        return 1;
    }else{
        return 0;
    }
}
void push(int data,struct node **top){
    struct node *newNode= createNode();
    if(newNode == NULL){
        printf("Stack overflow. ");
        exit(1);
    }//malloc fun returns NULL when the requested memory can't be allocated.
    newNode->data = data;
    newNode->next = NULL;

    newNode->next = *top;
    *top = newNode;
}

int pop(struct node **top){
    struct node *temp;
    if(isEmpty(top)){
        printf("Stack Underflow.");
        exit(1);
    }
    int val;
    temp = *top;
    val = temp->data;
    *top = (*top)->next;
    free(temp);
    temp=NULL;
    return val;
}
int peek(struct node **top){
    if(isEmpty(top)){
        printf("Stack Underflow.");
        exit(1);
    }
    return (*top)->data;
}
void print(struct node **top){
    struct node *temp;
    temp = *top;
    if(isEmpty(top)){
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
void find(int number,struct node **top){
    struct node **temp;
    temp = top;
    while(temp!=NULL){
        if((*temp)->data == number){
            printf("Entry Found: %d!\n\n",number);
            break;
        }
        *temp=(*temp)->next;
    }
    if(*temp==NULL){
        printf("\nYour entry is not on the list!\n\n");
        return;
    }
}
void reverse_stack(struct node **top){
    struct node *top1=NULL;
    struct node *top2=NULL;

    //Pushing onto temp stack1
    while(*top != NULL){
        push(pop(top),&top1);
    }

    //Pushing onto temp stack2
    while(top1 != NULL){
        push(pop(&top1),&top2);
    }

    //Pushing onto original stack
    while(top2 != NULL){
        push(pop(&top2),top);
    }

}
int main(){
    int choice,data;
    struct node *top=NULL;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Find\n");
        printf("4. Reverse the stack\n");
        printf("5. Print all elements of the stack\n");
        printf("6. Print the top elements of the stack\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d",&data);
                push(data,&top);
                break;
            case 2:
                data = pop(&top);
                printf("Deleted elements is %d\n",data);
                break;
            case 3:
                printf("Enter the element to find: ");
                scanf("%d",&data);
                find(data,&top);
                break;
            case 4:
                reverse_stack(&top);
                printf("Stack is reversed!");
                break;
            case 5:
                print(&top);
                break;
            case 6:
                peek(&top);
                break;
            case 7:
                exit(1);
            default:
                printf("Wrong Choice\n");
                break;
        }
    }
    return 0;
}

