// write a c program to implememt the stack ADT using an array

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int Q[SIZE];
int front = -1;
int r = -1;

void enqueue();
void dequeue();
void display();
int main()
{
    int choice;
    while (1)
    {
        printf("1.Enqueue Operation \n");
        printf("1.Dequeue Operation \n");
        printf("1.Display Operation \n");
        printf("4.Exit \n");
        printf("Enter your choice : \n");
        scanf("%d",choice);
        switch (choice)
        {
        case 1:enqueue();
            break;
         case 2:dequeue();
            break;
             case 3:display();
            break;
             case 4:exit(0);
        default:
           printf("Invalid Choice");
        }
    }
return 0;
}
void enqueue(){

}

void dequeue(){

}
void display(){

}