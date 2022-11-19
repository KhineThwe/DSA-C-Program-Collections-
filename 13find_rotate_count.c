#include <stdio.h>

int findRotationCount(int nums[] , int n){
    int low=0;int high = n-1;

    while(low<=high){
        //condition 1: if array is already sorted --> at index low == minimum element
        if(nums[low] <= nums[high]){
            return low;
        }
        int mid = (low+high)/2;
        //extra information
        int next = (mid + 1) % n;
        int prev = (mid - 1+n)%n;

        if(nums[mid] <= nums[next] && nums[mid] <=nums[prev]){
            return mid;
        }
        // if nums[mid…high] is sorted, and `mid` is not the minimum element,
        // then the pivot element cannot be present in nums[mid…high],
        // discard nums[mid…high] and search in the left half

        else if (nums[mid] <= nums[high]){
            high = mid -1 ;
        }//search in the left half

        else if(nums[mid]>=nums[high]){
            low = mid + 1 ;
        }
    }
    return -1;
}
int main() {
//    int nums [] = {2};
//    int nums [] = {2,5,6,8,9,10};
    int nums [] = {8,9,10,2,5,6};//original
//    int nums [] = {9,2,5};//to test for line 16
    int n = sizeof (nums)/sizeof(nums[0]);

    int count = findRotationCount(nums,n);
    printf("Array is rotated %d times",count);
    return 0;
}
