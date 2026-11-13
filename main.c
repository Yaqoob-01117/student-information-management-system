#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct student_information{

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
    struct Student_marks{
        float subject1;
        float subject2;
        float subject3;
        float subject4;
        float subject5;
        float subject6;
        float subject7;
    }SMarks;
   
}Student;

int studentcounting(Student *students){
    int count=0;
    FILE *fp=fopen("Student_data.txt","r");
    if(fp==NULL){
       
        return 0;
    }

    while (fscanf(fp,"%d",&students->roll_number)==1)
    {
       
        while(fgetc(fp)!='\n');
        if (fgets(students->full_name, sizeof(students->full_name), fp) == NULL) break;
        students->full_name[strcspn(students->full_name,"\n")]='\0';
        
        if (fgets(students->father_name, sizeof(students->father_name), fp) == NULL) break;
        students->father_name[strcspn(students->father_name,"\n")]='\0';

        if (fgets(students->class_name, sizeof(students->class_name), fp) == NULL) break;
        students->class_name[strcspn(students->class_name,"\n")]='\0';

        if (fgets(students->group_name, sizeof(students->group_name), fp) == NULL) break;
        students->group_name[strcspn(students->group_name,"\n")]='\0';

        if (fgets(students->academic_year, sizeof(students->academic_year), fp) == NULL) break;
         students->academic_year[strcspn(students->academic_year,"\n")]='\0';

        if (fscanf(fp, "%d", &students->age) != 1) break;
        while(fgetc(fp)=='\n');
        
        if (fgets(students->gender, sizeof(students->gender), fp) == NULL) break;
        students->gender[strcspn(students->gender,"\n")]='\0';

        if (fgets(students->contact_number, sizeof(students->contact_number), fp) == NULL) break;
        students->contact_number[strcspn(students->contact_number,"\n")]='\0';

        if (fgets(students->address, sizeof(students->address), fp) == NULL) break;
        students->address[strcspn(students->address,"\n")]='\0';

        count++;
    
}
return count;
}
void Add_Student(Student *student_data,int *capacity,int *count,int *added) {
  int T_students=0;
    if(*count==*capacity){
        *capacity=*capacity*2;
        Student *temp=realloc(student_data,(*capacity)*sizeof(struct student_information));
   if(temp==NULL){
    printf("Memory Reallocation failed!\n");
    return;
   }
   
    }
     FILE *pf=fopen("Student_data.txt","a");
    if(pf==NULL){
        printf("File creating failed!\n");
        return;
    }
    int group;
    int class;
    int gender;

printf("Enter Roll Number : ");
scanf("%d",&student_data[*count].roll_number);

while(getchar()!='\n');
printf("Enter Full Name : ");
fgets(student_data[*count].full_name,sizeof(student_data[*count].full_name),stdin);
student_data[*count].full_name[strcspn(student_data[*count].full_name,"\n")]='\0';

printf("Enter Father Name : ");
fgets(student_data[*count].father_name,sizeof(student_data[*count].father_name),stdin);
student_data[*count].father_name[strcspn(student_data[*count].father_name,"\n")]='\0';

printf("Enter age : ");
scanf("%d",&student_data[*count].age);
do{
 printf("================================\n");
printf("     Genders     \n");
printf("================================\n");
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
student_data[*count].contact_number[strcspn(student_data[*count].contact_number,"\n")]='\0';

printf("Enter adress : ");
fgets(student_data[*count].address,sizeof(student_data[*count].address),stdin);
student_data[*count].address[strcspn(student_data[*count].address,"\n")]='\0';
do{
    printf("================================\n");
printf("     Classes     \n");
printf("================================\n");
printf("1. 11th\n");
printf("2. 12th\n");
printf("Enter class : ");
scanf("%d",&class);
switch (class)
{
case 1:
    strcpy(student_data[*count].class_name,"11th");
    break;
    case 2:
   strcpy(student_data[*count].class_name,"12th");
default:
    break;
}

}while(class>2 || class<1);

while(getchar()!='\n');
printf("Enter acedemic year : ");
fgets(student_data[*count].academic_year,sizeof(student_data[*count].academic_year),stdin);
student_data[*count].academic_year[strcspn(student_data[*count].academic_year,"\n")]='\0';

do{
printf("================================\n");
printf("     Academic Disciplines     \n");
printf("================================\n");

printf("1. Pre-Medical           \n");       
printf("2. Pre-Engineering       \n");            
printf("3. Computer(th+pr) Scien [Total Marks:100]ce\n");       
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
strcpy(student_data[*count].group_name,"Computer(th+pr) Scien [Total Marks:100]ce");
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



fprintf(pf, "%d\n",student_data[*count].roll_number);
fprintf(pf, "%s\n",student_data[*count].full_name);
fprintf(pf, "%s\n",student_data[*count].father_name);
fprintf(pf, "%s\n",student_data[*count].class_name);
fprintf(pf, "%s\n",student_data[*count].group_name);
fprintf(pf, "%s\n",student_data[*count].academic_year);
fprintf(pf, "%d\n",student_data[*count].age);
fprintf(pf, "%s\n",student_data[*count].gender);
fprintf(pf, "%s\n",student_data[*count].contact_number);
fprintf(pf, "%s\n",student_data[*count].address);
(*count)=(*count)+1;
fclose(pf);

added++;
}

void view_all_students(Student *student_view,int count){
      FILE *fp=fopen("Student_data.txt","r");
    if(fp==NULL){
        printf("File creating failed!\n");
        return;
    }
    
   
    for(int i=0;i<count;i++){


fscanf(fp, "%d", &student_view[i].roll_number);

while(fgetc(fp)!='\n');
fgets(student_view[i].full_name, sizeof(student_view[i].full_name), fp);
student_view[i].full_name[strcspn(student_view[i].full_name,"\n")]='\0';

fgets(student_view[i].father_name, sizeof(student_view[i].father_name), fp);
student_view[i].father_name[strcspn(student_view[i].father_name,"\n")]='\0';

fgets(student_view[i].class_name, sizeof(student_view[i].class_name), fp);
student_view[i].class_name[strcspn(student_view[i].class_name,"\n")]='\0';

fgets(student_view[i].group_name, sizeof(student_view[i].group_name), fp);
student_view[i].group_name[strcspn(student_view[i].group_name,"\n")]='\0';

fgets(student_view[i].academic_year,sizeof(student_view[i].academic_year),fp);
student_view[i].academic_year[strcspn(student_view[i].academic_year,"\n")]='\0';


fscanf(fp, "%d", &student_view[i].age);

while(fgetc(fp)!='\n');
fgets(student_view[i].gender, sizeof(student_view[i].gender), fp);
student_view[i].gender[strcspn(student_view[i].gender,"\n")]='\0';


fgets(student_view[i].contact_number, sizeof(student_view[i].contact_number), fp);
student_view[i].contact_number[strcspn(student_view[i].contact_number,"\n")]='\0';


fgets(student_view[i].address, sizeof(student_view[i].address), fp);
student_view[i].address[strcspn(student_view[i].address,"\n")]='\0';



printf("                ========== STUDENT %d ========== \n",i+1);
printf("------------------------------------------------------------------------------------\n");
printf("Roll No       : %d  \n",student_view[i].roll_number);
printf("Full Name     : %s  \n",student_view[i].full_name);
printf("father Name   : %s  \n",student_view[i].father_name);
printf("------------------------------------------------------------------------------------\n");

printf("Class : %-15s || ",student_view[i].class_name);
printf("Group : %-15s || ",student_view[i].group_name);
printf("Academic year : %-15s || \n",student_view[i].academic_year);
printf("------------------------------------------------------------------------------------\n");

printf("Age : %-5d || ",student_view[i].age);
printf("Gender : %-10s || ",student_view[i].gender);
printf("Contact No : %-10s ||\n",student_view[i].contact_number);
printf("------------------------------------------------------------------------------------\n");

printf("Adress : %-15s\n",student_view[i].address);
printf("------------------------------------------------------------------------------------\n\n");

    }


     }

void student_marks(Student *StudentMarks,int count){
    FILE *pf=fopen("Smarks.txt","a");
    if(pf==NULL){
        printf("file creating failed.\n");
        return;
    }
       FILE *fp=fopen("Student_data.txt","r");
    if(fp==NULL){
        printf("File creating failed!\n");
        return;
    }
    int choice;
    int subject7=0;
    int Roll_number;

    printf("Enter Student Roll number : ");
    scanf("%d",&Roll_number);

    do{
printf("1. Add Student Marks\n");
printf("2. Update Student Marks\n");
printf("3. View Student Marks\n");
printf("4. Calculate Student Result\n");
printf("0. Back to Main Menu\n");
printf("Enter choice : ");
scanf("%d",&choice);

switch (choice)
{
case 1:
   for(int i=0;i<count;i++){

    fscanf(fp,"%d",&StudentMarks[i].roll_number);
    
        while(fgetc(fp)!='\n');
        if (fgets(StudentMarks[i].full_name, sizeof(StudentMarks[i].full_name), fp) == NULL) break;
        StudentMarks[i].full_name[strcspn(StudentMarks[i].full_name,"\n")]='\0';
        
        if (fgets(StudentMarks[i].father_name, sizeof(StudentMarks[i].father_name), fp) == NULL) break;
        StudentMarks[i].father_name[strcspn(StudentMarks[i].father_name,"\n")]='\0';

        if (fgets(StudentMarks[i].class_name, sizeof(StudentMarks[i].class_name), fp) == NULL) break;
       StudentMarks[i].class_name[strcspn(StudentMarks[i].class_name,"\n")]='\0';

        if (fgets(StudentMarks[i].group_name, sizeof(StudentMarks[i].group_name), fp) == NULL) break;
        StudentMarks[i].group_name[strcspn(StudentMarks[i].group_name,"\n")]='\0';

        if (fgets(StudentMarks[i].academic_year, sizeof(StudentMarks[i].academic_year), fp)== NULL) break;
         StudentMarks[i].academic_year[strcspn(StudentMarks[i].academic_year,"\n")]='\0';

        if (fscanf(fp, "%d", &StudentMarks[i].age) != 1) break;
        while(fgetc(fp)=='\n');
        
        if (fgets(StudentMarks[i].gender, sizeof(StudentMarks[i].gender), fp) == NULL) break;
        StudentMarks[i].gender[strcspn(StudentMarks[i].gender,"\n")]='\0';

        if (fgets(StudentMarks[i].contact_number, sizeof(StudentMarks[i].contact_number), fp) == NULL) break;
        StudentMarks[i].contact_number[strcspn(StudentMarks[i].contact_number,"\n")]='\0';

        if (fgets(StudentMarks[i].address, sizeof(StudentMarks[i].address), fp) == NULL) break;
        StudentMarks[i].address[strcspn(StudentMarks[i].address,"\n")]='\0';

  if(StudentMarks[i].roll_number==Roll_number){

    while(getc(fp)=='\n');
    fgets(StudentMarks[i].full_name,sizeof(StudentMarks->full_name),fp);
    StudentMarks[i].full_name[strcspn(StudentMarks[i].full_name,"\n")]='\0';
    fgets(StudentMarks[i].father_name,sizeof(StudentMarks[i].father_name),fp);
    StudentMarks[i].father_name[strcspn(StudentMarks[i].father_name,"\n")]='\0';
    fgets(StudentMarks[i].class_name,sizeof(StudentMarks[i].class_name),fp);
    StudentMarks[i].class_name[strcspn(StudentMarks[i].class_name,"\n")]='\0';
    fgets(StudentMarks[i].group_name,sizeof(StudentMarks[i].group_name),fp);
    StudentMarks[i].group_name[strcspn(StudentMarks[i].group_name,"\n")]='\0';

    
    printf("                ========== STUDENT %d ========== \n",i+1);
printf("------------------------------------------------------------------------------------\n");
printf("Roll No       : %d  \n",StudentMarks[i].roll_number);
printf("Full Name     : %s  \n",StudentMarks[i].full_name);
printf("Class   : %s  \n",StudentMarks[i].class_name);
printf("Group Name : %s \n",StudentMarks[i].group_name);
printf("------------------------------------------------------------------------------------\n");



if(strcmp(StudentMarks[i].group_name,"Pre-Medical")==0){
    if(strcmp(StudentMarks[i].class_name,"11th")==0){
printf("Enter English Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject1);

printf("Enter Urdu Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject2);


printf("Enter Islamiat Marks [Total Marks:50]: ");
scanf("%d",&StudentMarks[i].SMarks.subject3);


printf("Enter Physics(th+pr) Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject4);


printf("Enter Chemistry(th+pr) Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject5);


printf("Enter Botany(th+pr) Marks [Total Marks:48]: ");
scanf("%d",&StudentMarks[i].SMarks.subject6);


printf("Enter Zoology(th+pr) Marks [Total Marks:52]: ");
scanf("%d",&StudentMarks[i].SMarks.subject7);
subject7++;

    }
    else if(strcmp(StudentMarks[i].class_name,"12th")==0){

printf("Enter English Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject1);

printf("Enter Urdu Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject2);


printf("Enter Pakistan Study Marks [Total Marks:50]: ");
scanf("%d",&StudentMarks[i].SMarks.subject3);


printf("Enter Physics(th+pr) Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject4);


printf("Enter Chemistry(th+pr) Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject5);


printf("Enter Botany(th+pr) Marks [Total Marks:48]: ");
scanf("%d",&StudentMarks[i].SMarks.subject6);


printf("Enter Zoology(th+pr) Marks [Total Marks:52]: ");
scanf("%d",&StudentMarks[i].SMarks.subject7);
subject7++;
    }

}

 

if(strcpy(StudentMarks[i].group_name,"Pre-Engineering")==0){
    if(strcmp(StudentMarks[i].class_name,"11th")==0){

printf("Enter English Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject1);

printf("Enter Urdu Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject2);


printf("Enter Islamiat Marks [Total Marks:50]: ");
scanf("%d",&StudentMarks[i].SMarks.subject3);


printf("Enter Physics(th+pr) Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject4);


printf("Enter Chemistry(th+pr) Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject5);


printf("Enter Math Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject6);



    }
    else if(strcmp(StudentMarks[i].class_name,"12th")==0){

printf("Enter English Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject1);

printf("Enter urdu Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject2);


printf("Enter Pakistan Study Marks [Total Marks:50]: ");
scanf("%d",&StudentMarks[i].SMarks.subject3);


printf("Enter Physics(th+pr) Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject4);


printf("Enter Chemistry(th+pr) Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject5);


printf("Enter Math Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject6);


    }

}

 

if(strcpy(StudentMarks[i].group_name,"Computer(th+pr) Scien [Total Marks:100]ce")==0){
    if(strcmp(StudentMarks[i].class_name,"11th")==0){
       
printf("Enter English Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject1);

printf("Enter Urdu Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject2);


printf("Enter Islamiat Marks [Total Marks:50]: ");
scanf("%d",&StudentMarks[i].SMarks.subject3);


printf("Enter Physics(th+pr) Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject4);


printf("Enter Computer(th+pr) Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject5);


printf("Enter Math Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject6);

    }
    else if(strcmp(StudentMarks[i].class_name,"12th")==0){
printf("Enter English Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject1);

printf("Enter Urdu Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject2);


printf("Enter Pakistan Study Marks [Total Marks:50]: ");
scanf("%d",&StudentMarks[i].SMarks.subject3);


printf("Enter Physics(th+pr) Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject4);


printf("Enter Computer(th+pr) Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject5);


printf("Enter Math Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject6);

    }

}

 

if(strcpy(StudentMarks[i].group_name,"Commerce ")==0){
    if(strcmp(StudentMarks[i].class_name,"11th")==0){
printf("Enter English Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject1);

printf("Enter Urdu Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject2);

printf("Enter Islamiat Marks [Total Marks:50]: ");
scanf("%d",&StudentMarks[i].SMarks.subject3);

printf("Enter Principles of Commerce Marks [Total Marks:75]: ");
scanf("%d",&StudentMarks[i].SMarks.subject4);

printf("Enter Accounting Marks[Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject5);

printf("Enter Principles of Economics Marks[Total Marks:75]: ");
scanf("%d",&StudentMarks[i].SMarks.subject6);

printf("Enter Business Mathematics Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject7);
subject7++;
    }
    else if(strcmp(StudentMarks[i].class_name,"12th")==0){
printf("Enter English Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject1);

printf("Enter Urdu Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject2);

printf("Enter Pakistan Study Marks [Total Marks:50]: ");
scanf("%d",&StudentMarks[i].SMarks.subject3);

printf("Enter Principles of Commerce Marks [Total Marks:75]: ");
scanf("%d",&StudentMarks[i].SMarks.subject4);

printf("Enter Accounting Marks[Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject5);

printf("Enter Principles of Economics Marks[Total Marks:75]: ");
scanf("%d",&StudentMarks[i].SMarks.subject6);

printf("Enter Business Mathematics Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject7);
subject7++;
    }

}
 
 

if(strcpy(StudentMarks[i].group_name,"Humanities")==0){
    if(strcmp(StudentMarks[i].class_name,"11th")==0){
        printf("Enter English Marks [Total Marks:100]: ");
        scanf("%d",&StudentMarks[i].SMarks.subject1);

printf("Enter Urdu Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject2);

printf("Enter Islamiat Marks [Total Marks:50]: ");
scanf("%d",&StudentMarks[i].SMarks.subject3);

printf("Enter Civics Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject4);

printf("Enter Education Marks[Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject5);

printf("Enter Economics Marks [Total marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject6);

    }
    else if(strcmp(StudentMarks[i].class_name,"12th")==0){
 printf("Enter English Marks [Total Marks:100]: ");
        scanf("%d",&StudentMarks[i].SMarks.subject1);

printf("Enter Urdu Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject2);

printf("Enter Islamiat Marks [Total Marks:50]: ");
scanf("%d",&StudentMarks[i].SMarks.subject3);

printf("Enter Civics Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject4);

printf("Enter Education Marks[Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject5);

printf("Enter Economics Marks [Total Marks:100]: ");
scanf("%d",&StudentMarks[i].SMarks.subject6);

    }


}

 


fprintf(pf,"%d",StudentMarks[i].SMarks.subject1);
fprintf(pf,"%d",StudentMarks[i].SMarks.subject2);
fprintf(pf,"%d",StudentMarks[i].SMarks.subject3);
fprintf(pf,"%d",StudentMarks[i].SMarks.subject4);
fprintf(pf,"%d",StudentMarks[i].SMarks.subject5);
fprintf(pf,"%d",StudentMarks[i].SMarks.subject6);
if(subject7){
fprintf(pf,"%d",StudentMarks[i].SMarks.subject7);
}

  }


}

   



    break;
    case 2:

    break;
    case 3:

    break;
    case 4:

    break;

    case 0:
return;
    break;


default:
printf("Entered choice is wrong.Please try again!\n");
    break;
}

    }while(choice!=0);
    if(choice==0){
        return;
    }





}


int main() {
int choice;
int added=0;
int count=0;
int capacity=2;
Student *student=malloc(capacity*sizeof(Student));
 
    if(student==NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }
    count=studentcounting(student);
    printf("Total students : %d\n",count);
    do
    {
    printf("1. Add Student\n");
    printf("2. View All Students\n");
    printf("3. Search Student\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Manage Marks & Results\n");
    printf("7. Sort Students\n");
    printf("8. Generate Reports\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:

        printf("       ========== ADD NEW STUDENT ==========\n");
            Add_Student(student,&capacity,&count,&added);
            added=0;
            
            break;
        case 2:
        printf("            ========== VIEW ALL STUDENTS ==========\n");
           view_all_students(student,count);
            break;
        case 3:
          printf("        ========== SEARCH STUDENT RECORD ==========\n");
            break;
        case 4:
        printf("          ========== UPDATE STUDENT RECORD ==========\n");
          
            break;
        case 5:
           printf("          ========== DELETE STUDENT RECORD ==========\n");

            break;
        case 6:
          printf("          ========== MANAGE STUDENT MARKS ==========\n");
         student_marks(student,count);
            break;
        
        case 7:
          printf("         ========== SORT STUDENT RECORDS ==========\n");

            break;
        case 8:
          printf("         ========== GENERATE STUDENT REPORTS ==========\n");

            break;
        
        case 0:
        printf("         ========== EXIT SYSTEM ==========\n");
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    } while (choice != 0);

    if(added){
free(student);
    }
    return 0;
}
