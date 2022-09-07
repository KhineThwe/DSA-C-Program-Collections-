//
// Created by Khine on 9/7/2022.
//
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#define MAX 10
int stack_arr[MAX];
int first = -1;
int isEmpty(){
    if(first == -1){
        return 1;
    }else{
        return 0;
    }
}//stack empty or stack underflow//first keeps track of first inserted element

int isFull(){
    if(first == MAX - 1){
        return 1;
    }else{
        return 0;
    }
}
void push(int data){
    int i;
    if(isFull()){
        printf("Stack is Overflow\n");
        exit(1);
    }else{
        first+=1;
        for(i=first;i>0;i--){
            stack_arr[i]=stack_arr[i-1];
        }
        stack_arr[0]=data;
    }
}
int peek(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack_arr[0];
}
void print(){
    int i;
    if(first==-1){
        printf("Stack underflow\n");
        exit(1);
    }
    for(i=0;i<=first;i++){
        printf("%d\n",stack_arr[i]);
    }
    printf("\n");
}
int pop(){
    int i,value;
    if(isEmpty()){
        printf("Stack is underflow\n");
        exit(1);
    }else{
        value = stack_arr[0];
        for(i=0;i<first;i++){
            stack_arr[i]=stack_arr[i+1];
        }
        first-=1;
        return value;
    }
}

int main(){
    int choice,data;
    while(1){
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element\n");
        printf("4. Print all the elements of the stack\n");
        printf("5. Quit\n");
        printf("Please enter your choice.\n");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                data = pop();
                printf("Deleted element is %d\n",data);
                break;
            case 3:
                printf("The topmost element of the stack is %d\n",peek());
                break;
            case 4:
                print();
                break;
            case 5:
                exit(1);
            default:
                printf("Wrong Choice\n");
        }
    }
    return 0;
}
