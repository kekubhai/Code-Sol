
// delete an element forom an element and decreasing the size of the array
#include <stdio.h>

int main()
{
    int n, pos, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position of the element to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos >= n || pos < 0)
    {
        printf("Invalid position\n");
        return 1;
    }

    for (i = pos-1; i < n-1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    printf("Array after deletion: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
