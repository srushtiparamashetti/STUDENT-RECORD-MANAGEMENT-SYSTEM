#include "header.h"
void stud_show(SLL *ptr)
{
    if(ptr==0)
    {
        printf("\nStudent list is empty.\n");
        return;
    }
    printf("\n");
    printf("STUDENT RECORDS\n");
    printf("%-10s %-15s %-10s\n","ROLL NO", "NAME", "PERCENTAGE");
    while(ptr)
    {
    printf("%-10d %-15s %-10.2f\n",ptr->rollno,ptr->name,ptr->percentage);
        ptr=ptr->next;
    }
}
