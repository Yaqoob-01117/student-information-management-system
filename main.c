#include<stdio.h>
typedef struct student_information{

    int student_id;
    int roll_number;
    char full_name[100];
    char father_name[100];
    int age;
    char gender[10];
  unsigned long contact_number;
    char address[200];
    char class_name[50];
    char group_name[50];
    int academic_year;
}Student;

void Add_Student(Student* student_data) {
    
printf("Enter Student ID : ");
scanf("%d",&student_data->student_id);

printf("Enter Roll Number : ");
scanf("%d",&student_data->roll_number);

printf("Enter Full Name : ");
scanf("%s",&student_data->full_name);

printf("Enter Father Name : ");
scanf("%s",&student_data->father_name);

printf("Enter age : ");
scanf("%d",&student_data->age);

printf("Enter gender : ");
scanf("%s",&student_data->gender);

printf("Enter Contact Number : ");
scanf("%lu",&student_data->contact_number);

printf("Enter adress : ");
scanf("%s",&student_data->address);

printf("Enter class : ");
scanf("%s",&student_data->class_name);

printf("Enter group : ");
scanf("%s",&student_data->group_name);

 printf("Enter acedemic year : ");
 scanf("%d",&student_data->academic_year);

}

void view_all_students(Student student_view){
printf("------------------------------------------------------------------------------------------------------------------------\n");
printf("------------------------------------------------------------------------------------------------------------------------\n");
printf("Student ID : %d  || ",student_view.student_id);
printf("Roll No : %d  || ",student_view.roll_number);
printf("Full Name : %s  || ",student_view.full_name);
printf("father Name : %s  || ",student_view.father_name);
printf("Age : %d  || ",student_view.age);
printf("Gender : %s  || ",student_view.gender);
printf("Contact No : %lu  || ",student_view.contact_number);
printf("Adress : %s  || ",student_view.address);
printf("Class : %s  || ",student_view.class_name);
printf("Group : %s  || ",student_view.group_name);
printf("Academic year : %d  || ",student_view.academic_year);

printf("\n------------------------------------------------------------------------------------------------------------------------\n");
printf("------------------------------------------------------------------------------------------------------------------------\n");
}

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

    switch(choice) {
        case 1:
            Add_Student(&student);
            break;
        case 2:
           view_all_students(student);
            break;
        case 3:
            // Search Student
            break;
        case 4:
            // Update Student
            break;
        case 5:
            // Delete Student
            break;
        case 6:
            // Manage Marks
            break;
        case 7:
            // Calculate Result
            break;
        case 8:
            // Sort Students
            break;
        case 9:
            // Generate Reports
            break;
        case 10:
            // Save Records
            break;
        case 11:
            // Load Records
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