//
// Created by Khine on 9/7/2022.
//
#include "stdlib.h"
#include "stdio.h"
//Prime Factors in desending order with stack DSA
#define MAX 50
int stack[MAX];
int top = -1;
int isFull(){
    if(top == MAX-1){
        return 1;
    }else{
        return 0;
    }
}
int isEmpty(){
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}
void push(int n){
    if(isFull()){
        printf("Stack overflow.");
        exit(1);
    }
    top++;
    stack[top] = n;
}
int pop(){
    int value;
    if(isEmpty()){
        printf("Stack Underflow. ");
        exit(1);
    }
    value = stack[top];
    top--;
    return value;
}
void prime_fact(int number){
    int i=2;
    //Push all the prime factors of a number onto stack;
    while(number!=1){
        while (number%i ==0){
            push(i);
            number=number/i;
        }
        i++;
    }

    //Pop all the prime factors from the stack and print
    printf("Prime Factors of the number in descending order are as follows: ");
    while (top!=-1){
        printf("%d ",pop());
    }

}

int main(){
    int number;
    printf("Please enter a positive number: ");
    scanf("%d",&number);

    prime_fact(number);
    return 0;
}

