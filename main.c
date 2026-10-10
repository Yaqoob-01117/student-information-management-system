#include<stdio.h>
int main() {
int choice;

    do
    {
    printf("1. Add Student\n");
    printf("2. View All Students\n");
    printf("3. Search Student\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Manage Marks\n");
    printf("7. Calculate Result\n");
    printf("8. Sort Students\n");
    printf("9. Generate Reports\n");
    printf("10. Save Records\n");
    printf("11. Load Records\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

         switch(choice) {
        case 1:
            Add_Student(&student);
            break;
        case 2:
           view_all_students(student);
            break;
        case 3:
          
            break;
        case 4:
          
            break;
        case 5:
           
            break;
        case 6:
          
            break;
        case 7:
          
            break;
        case 8:
          
            break;
        case 9:
          
            break;
        case 10:
          
            break;
        case 11:
         
            break;
        case 0:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

        
    } while (choice != 0);

    return 0;
}
