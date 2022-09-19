//
// Created by Khine on 9/19/2022.
//
#include "stdlib.h"
#include "stdio.h"

int binarySearch(int data[],int toFind,int low,int high){//return 1 or -1(not found)
    while(low<=high){
       int mid =(high-low)/2+low;

       if(data[mid]  == toFind){
           return mid;
       }else if(data[mid] < toFind){
           low = mid+1;
       }else{
           high = mid-1;
       }
    }
    return -1;
}
int main(){
    int toFind=0;
    int data[10] = {1,2,3,4,5,6,7,8,9,10};

    printf("Enter data to find: ");
    scanf("%d",&toFind);

    int dataSize = sizeof(data)/sizeof(data[0]);

    int result = binarySearch(data,toFind,0,dataSize-1);

    if(result == -1){
        printf("Data not found");
    }else{
        printf("Data found");
    }
    return 0;
}


