#include "header.h"
void delete_by_roll(SLL **ptr, int roll)
{
    if(*ptr==0)
  {
     printf("no record found\n");
     return;
    }
    SLL *temp=*ptr,*prev;
    while(temp)
    {
        if(temp->rollno==roll)
        {
            if(temp==*ptr)
                *ptr=temp->next;
            else
                prev->next=temp->next;
            free(temp);
            printf("Record deleted successfully\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Roll number not found\n");
}
void delete_by_name(SLL **ptr, char name[])
{
  if(*ptr==0)
  {
     printf("no record found\n");
     return;
    }
    SLL *temp=*ptr,*prev;
    while(temp)
    {
        if(strcmp(temp->name,name)==0)
        {
            if(temp==*ptr)
                *ptr=temp->next;
            else
                prev->next=temp->next;
            free(temp);
            printf("Record deleted successfully\n");
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    printf("Name not found\n");
}
void delete_by_percentage(SLL **ptr, float percentage)
{
  if(*ptr==0)
  {
     printf("no record found\n");
     return;
    }
    SLL *temp=*ptr,*prev;
    while(temp)
    {
        if(temp->percentage==percentage)
        {
            if(temp==*ptr)
                *ptr=temp->next;
            else
                prev->next=temp->next;
            free(temp);
            printf("Record deleted successfully\n");
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    printf("Percentage not found\n");
}
void stud_del(SLL **ptr)
{
    char choice;
    int roll;
    char name[50];
    float percentage;
    printf("\n");
    printf("R/r : Delete by Roll Number\n");
    printf("N/n : Delete by Name\n");
    printf("P/p : Delete by Percentage\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);
    switch(choice)
    {
        case 'R':
        case 'r':
            printf("Enter roll number: ");
            scanf("%d", &roll);
            delete_by_roll(ptr, roll);
            break;
	case 'N':
        case 'n':
            printf("Enter name: ");
            scanf("%s", name);
            delete_by_name(ptr, name);
            break;
        case 'P':
        case 'p':
            printf("Enter percentage: ");
            scanf("%f", &percentage);
            delete_by_percentage(ptr,percentage);
            break;
        default:
            printf("Invalid choice\n");
    }

}
