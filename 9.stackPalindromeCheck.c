//
// Created by Khine on 9/8/2022.
//
//Palindrome is a string that we can read the same both backward and forward.
#include "stdlib.h"
#include "stdio.h"
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

void palindrome_check(char *s){
    int i=0;
    while (s[i]!='X'){
        push(s[i]);
        i++;
    }
    i++;
    while(s[i]){
        if(isEmpty() || s[i] != pop()){
            printf("Not a palindrome");
            exit(1);
        }
        i++;
    }
    if(isEmpty()){
        printf("Palidrome");
    }else{
        printf("Not a Palidrome.");
    }

}
int main(){
    char s[100];
    printf("Please enter the string: ");
    scanf("%s",s);

    palindrome_check(s);
    return 0;
}
