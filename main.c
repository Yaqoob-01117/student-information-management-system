#include<stdio.h>

#include<string.h>
#include<stdlib.h>


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
    int capacity=2;
    int count=0;
    if(count==capacity){
        capacity=capacity*2;
    }
     student_data=malloc(capacity*sizeof(struct student_information));
    int group;
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

printf("Enter acedemic year : ");
scanf("%d",&student_data->academic_year);
do{
printf("================================\n");
printf("     Academic Disciplines     \n");
printf("================================\n");

printf("1. Pre-Medical           \n");       
printf("2. Pre-Engineering       \n");            
printf("3. Computer Science\n");       
printf("4. Commerce              \n");   
printf("5. Humanities            \n");   
printf("Enter group : ");
scanf("%d",&group)  ;
switch (group)
{
case 1:
strcpy(student_data->group_name,"Pre-Medical");
 break;
 
case 2:
strcpy(student_data->group_name,"Pre-Engineering");
 break;
 
case 3:
strcpy(student_data->group_name,"Computer Science");
 break;
 
case 4:
strcpy(student_data->group_name,"Commerce ");
 break;
 
case 5:
strcpy(student_data->group_name,"Humanities");
 break;
 

default:
printf("Invalid Group! Please try again.\n");
    break;
}

}while (group>5 || group<1);


free(student_data);
}


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
