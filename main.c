#include<stdio.h>
int main() {
int choice;
Student student;
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
        
    } while (choice != 0);

    return 0;
}
