#include "header.h"
void stud_save(SLL *ptr)
{
    FILE *fp;
    fp = fopen("student.dat", "w");
    if(fp==0)
    {
        printf("no records found\n");
        return;
    }
    while(ptr)
    {
        fprintf(fp, "%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
         ptr=ptr->next;
    }
    fclose(fp);
    printf("Student records saved successfully.\n");
}
void stud_load(SLL **ptr)
{
    FILE *fp;
    SLL *newnode;
    SLL *last=0;
    fp = fopen("student.dat", "r");
    if(fp==0)
    {
        return;
    }
    while(1)
    {
        newnode = malloc(sizeof(SLL));
        if(fscanf(fp, "%d %s %f",&newnode->rollno,newnode->name,&newnode->percentage) != 3)
        {
            free(newnode);
            break;
        }
        newnode->next=0;
        if(*ptr==0)
        {
            *ptr=newnode;
            last=newnode;
        }
        else
        {
            last->next=newnode;
            last=newnode;
        }
    }
    fclose(fp);
}
void stud_delete_all(SLL **ptr)
{
    SLL *temp;
    while(*ptr!=NULL)
    {
        temp=*ptr;
        *ptr=(*ptr)->next;
        free(temp);
    }
}
void stud_sort(SLL *head)
{
    SLL *i,*j;
    int temp_roll;
    float temp_percentage;
    char temp_name[50];
    char choice;
    if(head==0)
    {
        printf("Student list is empty.\n");
        return;
    }
    printf("\nEnter\n");
    printf("N/n : sort with name\n");
    printf("P/p : sort with percentage\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);
    if(choice=='n'||choice=='N')
    {
        for(i=head;i!=0;i=i->next)
        {
            for(j=i->next;j!=0;j=j->next)
            {
                if(strcmp(i->name,j->name) > 0)
                {
                    temp_roll = i->rollno;
                    i->rollno = j->rollno;
                    j->rollno = temp_roll;

                    temp_percentage = i->percentage;
                    i->percentage = j->percentage;
                    j->percentage = temp_percentage;

                    strcpy(temp_name, i->name);
                    strcpy(i->name, j->name);
                    strcpy(j->name, temp_name);
                }
            }
        }

        printf("List sorted by name.\n");
    }
    else if(choice=='p'||choice=='P')
    {
        for(i=head;i!=0;i=i->next)
        {
            for(j=i->next;j!=0;j=j->next)
            {
                if(i->percentage < j->percentage)
                {
                    temp_roll = i->rollno;
                    i->rollno = j->rollno;
                    j->rollno = temp_roll;

                    temp_percentage = i->percentage;
                    i->percentage = j->percentage;
                    j->percentage = temp_percentage;

                    strcpy(temp_name, i->name);
                    strcpy(i->name, j->name);
                    strcpy(j->name, temp_name);
                }
            }
        }
        printf("List sorted by percentage.\n");
    }
    else
    {
        printf("Invalid choice.\n");
    }
}
void stud_reverse(SLL **ptr)
{
    SLL *prev=0,*current = *ptr,*next;
    while(current!=0)
    {
        next=current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *ptr = prev;
}
