// Here is the code for binary search without using functions and taking user defined elements

#include<stdio.h>
int main (){
    int n,i,element;
    int start,end;
    printf("Enter the number of elements of the Array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the Array in ascending order: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element you want to search: ");
    scanf("%d",&element);

    start = 0;
    end = n - 1;
    
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(arr[mid] == element){
            printf("The element you searched is found at index %d\n", mid);
            return 0;
        }
        else if(arr[mid] > element){
           end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    printf("The element is not found\n");
    return -1;
}
