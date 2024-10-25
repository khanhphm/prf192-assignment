#include<stdio.h>

struct sinhVien{
    char maSV[10];
    char hoSV[20];
    char tenSV[20];
    char gioiTinh[10];
    double diemSV;
};
void addStudent(){

}
void deleteStuden(){

    
}


void removeStudent(){
    int studentId;
    scanf("%d",studentId);
    
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
            default:
                break;

        }

    }while(opt!=0);
}