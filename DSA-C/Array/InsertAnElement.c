/// insert an element at given position in an array and changing the sze of the array.
// If you want to insert without changing the size remove the "n++" at line 30
#include <stdio.h>
int main()
{
    int n, pos, i, element;
    printf("Enter the number of elementts in the array");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements in the array");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        /* code */
    }
    printf("Enter the position where you want to insert the element");
    scanf("%d", &pos);
    printf("Enter the element you want to insert");
    scanf("%d", &element);
    if (pos > n || pos < 0)
    {
        printf("Invalid response");
        return 1;
    }
    for (i = n - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = element;
    n++;
    printf("Array after insertion will look like:");
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        /* code */
    }
    printf("\n");
    return 0;
}