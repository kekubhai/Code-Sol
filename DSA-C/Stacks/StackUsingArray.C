

#include <stdio.h>
#define M 5

int a[M], top=-1;

void push() {
    if (top == M-1) {
        printf("Stack Overflow!\n");
    } else {
        int dd;
        printf("Enter the element: ");
        scanf("%d", &dd);
        top++;
        a[top] = dd;
    }
}

void display() {
    if (top == -1) {
        printf("Stack Empty!\n");
    } else {
        int i;
        for (i = 0; i <= top; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
    } else {
        printf("%d is deleted.\n", a[top]);
        top--;
    }
}

int main() {
    int ch;
    printf("Enter 1 to Push.\n");
    printf("Enter 2 to Pop.\n");
    printf("Enter 3 to Display.\n");
    printf("Enter 4 to Exit.\n");
    
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: 
                push();
                break;
            case 2: 
                pop();
                break;
            case 3: 
                display();
                break;
            case 4: 
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
