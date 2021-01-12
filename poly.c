#include <stdio.h>
#include <stdlib.h>
struct node{
    int exp;
    float coef;
    struct node* link;
};
void polynomialRead(struct node **head){
    int num;
    struct node *newNode,*ptr=*head;
    printf("Enter number of terms : ");
    scanf("%d",&num);
    while(num--){
        newNode=(struct node *)malloc(sizeof(struct node));
        newNode->link=NULL;
        printf("Enter coefficient : ");
        scanf("%f",&newNode->coef);
        printf("Enter exponent : ");
        scanf("%d",&newNode->exp);
        if(*head==NULL){
            *head=newNode;
            ptr=*head;
            continue;
        }
        else
            ptr->link=newNode;
        ptr=ptr->link;
    }
}
void polynomialPrint(struct node *head){
    while(head!=NULL){
        printf("%2.1fX^%d",head->coef,head->exp);
        head=head->link;
        if(head!=NULL)
            printf(" + ");
    }
    printf("\n");
}
void polynomialAdd(struct node *poly1,struct node *poly2,struct node **result){
    struct node *ptr=*result,*newNode;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->link=NULL;
    *result=ptr;
    while(poly1!=NULL&&poly2!=NULL){
        if(poly2->exp==poly1->exp){
            ptr->coef=poly1->coef+poly2->coef;
            ptr->exp=poly1->exp;
            poly1=poly1->link;
            poly2=poly2->link;
        }
        else if(poly1->exp>poly2->exp){
            ptr->coef=poly1->coef;
            ptr->exp=poly1->exp;
            poly1=poly1->link;
        }
        else{
            ptr->coef=poly2->coef;
            ptr->exp=poly2->exp;
            poly2=poly2->link;
        }
        if(poly1!=NULL&&poly2!=NULL){
            ptr->link=(struct node *)malloc(sizeof(struct node));
            ptr=ptr->link;
            ptr->link=NULL;
        }
    }
    while(poly1!=NULL){
        ptr->link=(struct node *)malloc(sizeof(struct node));
        ptr=ptr->link;
        ptr->link=NULL;
        ptr->coef=poly1->coef;
        ptr->exp=poly1->exp;
        poly1=poly1->link;
    }
    while(poly2!=NULL){
        ptr->link=(struct node *)malloc(sizeof(struct node));
        ptr=ptr->link;
        ptr->link=NULL;
        ptr->coef=poly2->coef;
        ptr->exp=poly2->exp;
        poly2=poly2->link;
    }
}
void main(){
    struct node *polynomial1=NULL,*polynomial2=NULL,*result;
    printf("Enter Polynomial One \n");
    polynomialRead(&polynomial1);
    printf("Enter Polynomial Two \n");
    polynomialRead(&polynomial2);
    printf("Polynomial One : ");
    polynomialPrint(polynomial1);
    printf("Polynomial Two : ");
    polynomialPrint(polynomial2);
    polynomialAdd(polynomial1,polynomial2,&result);
    printf("Result is : ");
    polynomialPrint(result);

}