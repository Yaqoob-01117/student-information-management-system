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
    char contact_number[30];
    char address[200];
    char class_name[50];
    char group_name[50];
    char academic_year[50];
   
}Student;

void Add_Student(Student *student_data,int *capacity,int *count) {
  
    if(student_data==NULL){
        printf("Memory allocation failed!\n");
        return;
    }
    if(*count==*capacity){
        *capacity=*capacity*2;
        student_data=realloc(student_data,(*capacity)*sizeof(struct student_information));
    }
     FILE *pf=fopen("Student_data.txt","a");
    if(pf==NULL){
        printf("File creating failed!\n");
        return;
    }
    int group;
    int gender;
printf("Enter Student ID : ");
scanf("%d",&student_data[*count].student_id);


printf("Enter Roll Number : ");
scanf("%d",&student_data[*count].roll_number);

while(getchar()!='\n');
printf("Enter Full Name : ");
fgets(student_data[*count].full_name,sizeof(student_data[*count].full_name),stdin);


printf("Enter Father Name : ");
fgets(student_data[*count].father_name,sizeof(student_data[*count].father_name),stdin);

printf("Enter age : ");
scanf("%d",&student_data[*count].age);
do{
printf("\nGenders: \n");
printf("1.Male\n");
printf("2.Female\n");
printf("3.Other\n");
printf("Enter gender : ");
scanf("%d",&gender);
switch (gender)
{
case 1:
    strcpy(student_data[*count].gender,"Male");
    break;

    case 2:
    strcpy(student_data[*count].gender,"Female");
    break;

    case 3:
    strcpy(student_data[*count].gender,"Other");
    break;
default:
printf("Invalid Gender! Please try again.");
    break;
}
}while (gender>3 || gender<1);



while(getchar()!='\n');
printf("Enter Contact Number : ");
fgets(student_data[*count].contact_number,sizeof(student_data[*count].contact_number),stdin);


printf("Enter adress : ");
fgets(student_data[*count].address,sizeof(student_data[*count].address),stdin);

printf("Enter class : ");
fgets(student_data[*count].class_name,sizeof(student_data[*count].class_name),stdin);


printf("Enter acedemic year : ");
fgets(student_data[*count].academic_year,sizeof(student_data[*count].academic_year),stdin);
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
scanf("%d",&group);
switch (group)
{
case 1:
strcpy(student_data[*count].group_name,"Pre-Medical");
 break;
 
case 2:
strcpy(student_data[*count].group_name,"Pre-Engineering");
 break;
 
case 3:
strcpy(student_data[*count].group_name,"Computer Science");
 break;
 
case 4:
strcpy(student_data[*count].group_name,"Commerce ");
 break;
 
case 5:
strcpy(student_data[*count].group_name,"Humanities");
 break;
 

default:
printf("Invalid Group! Please try again.\n");
    break;
}

}while (group>5 || group<1);

fprintf(pf,"------------------------------------------------------------------------------------------------------------------------\n");
fprintf(pf,"------------------------------------------------------------------------------------------------------------------------\n");
fprintf(pf,"Student ID : %d  || ",student_data[*count].student_id);
fprintf(pf,"Roll No : %d  || ",student_data[*count].roll_number);
fprintf(pf,"Full Name : %s  || ",student_data[*count].full_name);
fprintf(pf,"father Name : %s  || ",student_data[*count].father_name);
fprintf(pf,"Age : %d  || ",student_data[*count].age);
fprintf(pf,"Gender : %s  || ",student_data[*count].gender);
fprintf(pf,"Contact No : %s  || ",student_data[*count].contact_number);
fprintf(pf,"Adress : %s  || ",student_data[*count].address);
fprintf(pf,"Class : %s  || ",student_data[*count].class_name);
fprintf(pf,"Group : %s  || ",student_data[*count].group_name);
fprintf(pf,"Academic year : %s  || ",student_data[*count].academic_year);

fprintf(pf,"\n------------------------------------------------------------------------------------------------------------------------\n");
fprintf(pf,"------------------------------------------------------------------------------------------------------------------------\n");
(*count)=(*count)+1;
fprintf(pf,"Total Student : %d",(*count));
fclose(pf);


}

void view_all_students(Student *student_view,int count){
    for(int i=0;i<count;i++){
printf("------------------------------------------------------------------------------------------------------------------------\n");
printf("------------------------------------------------------------------------------------------------------------------------\n");
printf("Student ID : %d  || ",student_view[i].student_id);
printf("Roll No : %d  || ",student_view[i].roll_number);
printf("Full Name : %s  || ",student_view[i].full_name);
printf("father Name : %s  || ",student_view[i].father_name);
printf("Age : %d  || ",student_view[i].age);
printf("Gender : %s  || ",student_view[i].gender);
printf("Contact No : %s  || ",student_view[i].contact_number);
printf("Adress : %s  || ",student_view[i].address);
printf("Class : %s  || ",student_view[i].class_name);
printf("Group : %s  || ",student_view[i].group_name);
printf("Academic year : %d  || ",student_view[i].academic_year);

printf("\n------------------------------------------------------------------------------------------------------------------------\n");
printf("------------------------------------------------------------------------------------------------------------------------\n");

    }
}

int main() {
int choice;
int count=0;
int capacity=2;
Student *student=malloc(capacity*sizeof(Student));
 
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
            Add_Student(student,&capacity,&count);
            break;
        case 2:
        printf("Total student : %d \n",count);
           view_all_students(student,count);
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

    
free(student);
    return 0;
}
