#include "header.h" 
#include<stdio.h> 
int main() 
{ 
    SLL *head = NULL; 
    char choice; 
    stud_load(&head); 
 
    while(1) 
    { 
        printf("STUDENT RECORD MENU\n"); 
        printf("a/A : add new record\n"); 
        printf("d/D : delete a record\n"); 
        printf("s/S : show the list\n"); 
        printf("m/M : modify a record\n"); 
        printf("v/V : save\n"); 
        printf("e/E : exit\n"); 
        printf("t/T : sort the list\n"); 
        printf("l/L : delete all the records\n"); 
        printf("r/R : reverse the list\n"); 
        printf("Enter your choice: "); 
        scanf(" %c", &choice); 
        switch(choice) 
        { 
            case 'a': 
            case 'A': 
                stud_add(&head); 
                break; 
 
            case 'd': 
            case 'D': 
                stud_del(&head); 
                break; 
 
            case 's': 
            case 'S': 
                stud_show(head); 
                break; 
 
            case 'm': 
            case 'M': 
                stud_mod(head); 
                break; 
 
            case 'v': 
            case 'V': 
                stud_save(head); 
                break; 
 
            case 'e': 
            case 'E': 
            { 
                char ch; 
 
                printf("\nEnter\n"); 
                printf("S/s : save and exit\n"); 
                printf("E/e : exit without saving\n"); 
                printf("Enter choice: "); 
                scanf(" %c", &ch); 
 
                if(ch == 's' || ch == 'S') 
                { 
                    stud_save(head); 
                    stud_delete_all(&head); 
                    printf("Saved and exited.\n"); 
                   return 0;
                } 
                else if(ch == 'e' || ch == 'E') 
                { 
                    stud_delete_all(&head); 
                    printf("Exited without saving.\n"); 
                    return 0;
                } 
                else 
                { 
                    printf("Invalid choice.\n"); 
                } 
 
                break; 
            } 
 
            case 't': 
            case 'T': 
                stud_sort(head); 
                break; 
 
            case 'l': 
            case 'L': 
                stud_delete_all(&head); 
                printf("All records deleted.\n"); 
                break; 
 
            case 'r': 
            case 'R': 
                stud_reverse(&head); 
                printf("List reversed successfully.\n"); 
                break; 
 
            default: 
                printf("Invalid choice.\n"); 
        }
} 
    return 0; 

} 
