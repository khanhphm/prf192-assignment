#include<stdio.h>

void addStudent(){

}

int main(){
    
    printf("MENU\n");
    printf("1. Add student\n");
    printf("2. Edit student\n");
    printf("3. Remove student\n");
    printf("4. Exit\n");

    
    int opt;
    do{
        scanf("%d",&opt);

        switch(opt){
            case 1:
                addStudent();
                break;
            default;

        }

    }while(opt!=0)



}