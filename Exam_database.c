#include <stdio.h>
#include <string.h>

// Initialize required variables here
int i = 0;
int n = 0;
float tdays = 1;
float elg_attend = 75.0;
char pay = 'P';
int j, option;

// Strucute for student details
struct student_details
{
    char name[20];
    char branch[5];
    int rno;
    char fees;
    float days;
    float attend;
} s[50];

// Add Function decalration here
void add(struct student_details s[]);
void printStudents(struct student_details s[]);
void eligibility();
void eligibility_check(struct student_details s[]);
void eligibility_update();
void delete_record(struct student_details s[]);

//I am defining this function which uses switch statements. This executes the functions choosen by the client.
void execution()
{
    printf("\n");
    printf("\nEnter 1 .Displaying the eligibility criteria.");
    printf("\nEnter 2 .Check the number of eligible students.");
    printf("\nEnter 3 .Reset the eligibilty criteria.");
    printf("\nEnter 4 .To delete the record of student/students.");
    printf("\nEnter 5 .To print the details of all students.");
    printf("\nEnter 0 to exit from the Database.");

    //rishabh add another condition here regarding the room number alloted to a student.

    //I am considering a variable option which i have defined at the beginning of this code .

    printf("\nEnter your option: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        eligibility();
        execution();
        break;

    case 2:
        eligibility_check(s);
        execution();
        break;

    case 3:
        eligibility_update();
        execution();
        break;

    case 4:
        delete_record(s);
        execution();
        break;

    case 5:
        printStudents(s);
        execution();
        break;

        //after adding the room_allotment function , upadate it here.

    case 0:
        break;

    default:
        printf("\nEnter a number only from 0 to 6");
        execution();
    }
}

// Function to add student records
void add(struct student_details s[50])
{
    printf("\n");
    printf("Enter the total number of working days\n");
    scanf("%f", &tdays);

    printf("Enter the number of students\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Student number %d \n", (i + 1));

        printf("Enter the name of student \n");
        scanf("%s", &s[i].name);

        printf("Enter branch of the student \n");
        scanf("%s", &s[i].branch);

        printf("Enter the last three digits of roll number \n");
        scanf("%d", &s[i].rno);

        printf("Enter the fee status of the student\n");
        printf("Enter 'P' for paid or 'N' for not paid or 'H' for partially paid \n");
        fflush(stdin);
        scanf("%c", &s[i].fees);

        printf("Enter number of days the student was present \n");
        scanf("%f", &s[i].days);

        s[i].attend = (s[i].days / tdays) * 100;

        printf("Students attendance percentage = %0.2f \n", s[i].attend);
        printf("\n");
    }
}

// Function to print student details
void printStudents(struct student_details s[])
{
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Name of student %s \n", s[i].name);
        printf("Student branch %s \n", s[i].branch);
        printf("Student fees status = %c \n", s[i].fees);
        printf("Number of days present = %f \n", s[i].days);
        printf("Student attendance = %f \n", s[i].attend);
        printf("\n");
    }
}
//eligibility set
void eligibility()
{
    printf("\n");
    printf("Eligibility Critera:\n");
    printf("1.The candidate must require minimum  %0.1f percent of attendance.\n", elg_attend);

    switch (pay)
    {

    case 'P':
        printf("\n2.The candidate must pay the full fees inorder to be eligible for the exam.");
        break;

    case 'H':
        printf("\n2.The candidate must pay atleast half the fees inorder to be eligible for the exam.");
        break;

    case 'N':
        printf("\n2.The candidate need not pay the fees inorder to be eligible for the exam.");
        break;

    default:
        printf("\nInvalid Entry");
        break;
    }
}
//eligibility check
void eligibility_check(struct student_details s[])
{
    printf("\n");
    for (i = 0; i < n; i++)
    {
        if (s[i].attend >= elg_attend)
        {
            if (s[i].fees == pay)
            {
                printf("\n%s is eligible to write the exam.", s[i].name);
            }
        }
        else
        {
            printf("\n%s is not eligible to write the exam.", s[i].name);
        }
    }
}

//eligibility edit
void eligibility_update()
{
    printf("\n");
    printf("Updating Eligibility Criteria\n");
    printf("1.Attendance :  Previous:%0.2f", elg_attend);
    printf("\nEnter the current eligible attendance percentage: ");
    scanf("%f", &elg_attend);
    //printf("Updated:%0.2f",elg_attend);
    printf("\n2.Fee :  Previous:%c ", pay);
    printf("\nEnter the current eligible fee status: ");
    printf("\n'P'-Fully paid fees. \n'H'-Partially paid fees. \n'N'-No fees paid.\n");
    fflush(stdin);
    scanf("%c", &pay);
    //printf("Updated:%c",pay);
    printf("\nThe Eligibility Criteria has been Updated Succesfully!.");
}

//Function to delete student record
void delete_record(struct student_details s[])
{
    printf("\n");
    int m;

    printf("\nEnter the roll number of student which you want to delete: ");
    scanf("%d", &m);

    //now i am iterating over the students records to delete

    for (i = 0; i < n; i++)
    {
        if (s[i].rno == (m))
        {
            //now i am replacing the ith index by i+1

            for (j = i; j < n; j++)
            {
                strcpy(s[j].name, s[j + 1].name);
                s[j].rno = s[j + 1].rno;
                s[j].fees = s[j + 1].fees;
                strcpy(s[j].branch, s[j + 1].branch);
                s[j].days = s[j + 1].days;
                s[j].attend = s[j + 1].attend;
            }
            printf("\nStudent's record has been deleted Succesfully!.");
        }
    }
}

int main()
{
    printf("\nWelcome to Exam Management Database!");

    printf("\nEnter 0 to exit.");
    printf("\nEnter 1 to add student record into the database.");

    printf("\nPlease choose your option.\n");

    scanf("%d", &option);

    switch (option)
    {
    case 0:
        break;

    case 1:
        add(s);
        execution();
        break;

    default:
        printf("\nPlease enter either 0 or 1");
    }
    return 0;
}
