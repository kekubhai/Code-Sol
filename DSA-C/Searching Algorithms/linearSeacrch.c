//Element searching using  Linear search
#include<stdio.h>
int main (){
    int n,element,i;
    printf("Enter the number of Elements in the Array");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elments in the array");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element you want to Search");
    scanf("%d",&element);
    for(i=0;i<n;i++){
        if(arr[i]==element){
            printf("The searched Element %d is found at  index :%d ", element,i);
            break;
        }else {
            printf("Searching ....");
        }
    }
    return 0;
}