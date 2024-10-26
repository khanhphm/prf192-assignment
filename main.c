#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>



void addStudent(){

}
void editGrade(){

}

void editName(){

}

void removeStudent(){
    int studentId;
    scanf("%d",studentId);
    
}


void sortGrade(){

}

void sortName(){

}

void printAll(){

}
void printId(){

}

void printGrade(){

}

void printAverage(){

}

int main(){
    
    printf("MENU\n");
    printf(" 1. Add student\n");
    printf(" 2. Edit student grade\n");
    printf(" 3. Edit student name\n");
    printf(" 4. Remove student\n");
    printf(" 5. Sort list by grade\n");
    printf(" 6. Sort list by name\n");
    printf(" 7. Print out all of list\n");
    printf(" 8. Print out list by ID\n");
    printf(" 9. Print out list by grade\n");
    printf("10. Print out average, highest, lowest grade\n")
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
            default;

        }

    }while(opt!=0)



}