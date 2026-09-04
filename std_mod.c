#include "header.h"
void stud_mod(SLL *head)
{
    char choice;
    int roll;
    char name[50];
    float percentage;
    SLL *temp;
    int found = 0;
    if(head==0)
    {
        printf("Student list is empty.\n");
        return;
    }
    printf("\nEnter which record to search for modification\n");
    printf("R/r : to search a rollno\n");
    printf("N/n : to search a name\n");
    printf("P/p : percentage based\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);
    if(choice == 'r' || choice == 'R')
    {
        printf("Enter roll number:");
        scanf("%d",&roll);
        temp = head;
        while(temp)
        {
            if(temp->rollno==roll)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }
    }
    else if(choice=='n'||choice=='N')
    {
        printf("Enter name:");
        scanf("%s",name);
        temp = head;
        while(temp)
        {
            if(strcmp(temp->name,name)==0)
            {
                found=1;
                break;
            }
            temp=temp->next;
        }
    }
    else if(choice=='p'||choice=='P')
    {
        printf("Enter percentage: ");
        scanf("%f", &percentage);
        temp = head;
        while(temp)
        {
            if(temp->percentage == percentage)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }
    }
    else
    {
        printf("Invalid choice\n");
        return;
    }
    if(found == 0)
    {
       printf("Record not found\n");
        return;
    }
    printf("\nCurrent Record:\n");
    printf("Roll Number :%d\n",temp->rollno);
    printf("Name        :%s\n",temp->name);
    printf("Percentage  :%.2f\n",temp->percentage);
    printf("\nEnter new name: ");
    scanf("%s", temp->name);
    printf("Enter new percentage: ");
    scanf("%f", &temp->percentage);
    printf("Record modified successfully.\n");
}
