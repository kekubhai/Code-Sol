#include <stdio.h>
#include <stdlib.h>

struct Polynomial {
    int coeff;
    int exp;
    struct Polynomial* next;
};

struct Polynomial* createNode(int coeff, int exp) {
    struct Polynomial* newNode = (struct Polynomial*)malloc(sizeof(struct Polynomial));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct Polynomial** poly, int coeff, int exp) {
    struct Polynomial* newNode = createNode(coeff, exp);
    if (*poly == NULL) {
        *poly = newNode;
        return;
    }
    struct Polynomial* temp = *poly;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void addPolynomials(struct Polynomial* poly1, struct Polynomial* poly2, struct Polynomial** result) {
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            appendNode(result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            appendNode(result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            appendNode(result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        appendNode(result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        appendNode(result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
}

void displayPolynomial(struct Polynomial* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Polynomial *poly1 = NULL, *poly2 = NULL, *result = NULL;

    appendNode(&poly1, 5, 2);
    appendNode(&poly1, 4, 1);
    appendNode(&poly1, 2, 0);

    appendNode(&poly2, 5, 1);
    appendNode(&poly2, 5, 0);

    addPolynomials(poly1, poly2, &result);

    printf("Sum of the polynomials: ");
    displayPolynomial(result);

    return 0;
}
