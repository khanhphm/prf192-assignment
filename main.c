#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

const int MAX=10000;

typedef struct sinhVien{
    char IDStudent[10];
    char LastName[20];
    char FirtName[10];
    char Gender[5];
    int FinalPoint;
} SV;

SV listSV[MAX];

void addStudent();
void editGrade();
void editName();
void removeStudent();
void sortGrade();
void sortName();
void printAll();
void printId();
void printGrade();
void printAverage();
void saveToFile();
void readFromFile();

int main(){
    printf("      ~ MENU ~\n");
    printf(" 1. Add student\n");
    printf(" 2. Edit student grade\n");
    printf(" 3. Edit student name\n");
    printf(" 4. Remove student\n");
    printf(" 5. Sort list by grade\n");
    printf(" 6. Sort list by name\n");
    printf(" 7. Print out all of list\n");
    printf(" 8. Print out list by ID\n");
    printf(" 9. Print out list by grade\n");
    printf("10. Print out average, highest, lowest grade\n");
    printf(" Other to Exit\n");
    
    int opt;
    do{
        printf("Please Choose: ");
        scanf("%d",&opt);

        switch(opt){
            case 1:
                addStudent();
                break;
            case 2:
                editGrade();
                break;
            case 3:
                editName();
                break;
            case 4:
                removeStudent();
                break;
            case 5:
                sortGrade();
                break;
            case 6:
                sortName();
                break;
            case 7:
                printAll();
                break;
            case 8:
                printId();
                break;
            case 9:
                printGrade();
                break;
            case 10:
                printAverage();
                break;
            default:
                break;
        }

    }while(opt!=0);
}

void addStudent(){
    // Enter main part of function
}
void editGrade(){
    // Enter main part of function
}

void editName(){
    // Enter main part of function
}

void removeStudent(){
    int studentId;
    scanf("%d",studentId);
    
}


void sortGrade(){
    // Enter main part of function
}

void sortName(){
    // Enter main part of function
}

void printAll(){
    // Enter main part of function
}
void printId(){
    // Enter main part of function
}

void printGrade(){
    // Enter main part of function
}

void printAverage(){
    // Enter main part of function
}