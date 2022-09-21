//
// Created by Khine on 9/21/2022.
//
#include "stdio.h"

int binarySearchRecur(int data[],int toSearch,int low,int high){

    if(high>=low)
    {
        int mid = low + (high - low) / 2;
        if (data[mid] == toSearch)
            return mid;

        if (data[mid] < toSearch)
            return binarySearchRecur(data, toSearch, mid + 1, high);

        return binarySearchRecur(data, toSearch, low, mid - 1);
    }

    return -1;
}
int main(){
    int data[] = {10,20,30,40,50,60};

    int size = sizeof(data)/sizeof(data[0]);

    int toSearch;
    printf("Enter Data To Find: ");
    scanf("%d",&toSearch);

    int result = binarySearchRecur(data,toSearch,0,size-1);
    if(result == -1){
        printf("Data Not Found: %d",toSearch);
    }else{
        printf("Data Found: %d",toSearch);
    }

    return 0;
}

