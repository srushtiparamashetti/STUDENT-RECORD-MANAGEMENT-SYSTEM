#include "header.h"
void stud_add(SLL **ptr)
{
    SLL *newnode,*temp;
    int roll = 1,found;
    while(1)
    {
        found = 0;
        temp = *ptr;
        while(temp != NULL)
        {
            if(temp->rollno == roll)
            {
                found = 1;
                break;
            }

            temp = temp->next;
        }

        if(found == 0)
            break;

        roll++;
    }
    newnode = malloc(sizeof(SLL));
    newnode->rollno = roll;
    printf("Enter student name: ");
    scanf("%s", newnode->name);
    printf("Enter student percentage");
    scanf("%f",&newnode->percentage);
    newnode->next = NULL;

    if(*ptr == NULL)
    {
        *ptr = newnode;
    }
    else
    {
        temp = *ptr;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("\nStudent added successfully.\n");
    printf("Assigned Roll Number = %d\n", newnode->rollno);
}
