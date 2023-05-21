#include "header.h"

int main(){
    library *lib[4000];
    for(int i = 0; i<4000; i++){
        lib[i] = (library*)malloc(sizeof(library));
    }
    printf("<<서울시 도서관 찾기 프로그램 L-Finder>>\n시작하시려면 아무 키나 눌러주세요!\n");
    char dummy;
    scanf("%c", &dummy);
    getchar();
    int count = LoadData(lib);
    while(1){
        SelectMenu();
        int option;
        scanf("%d", &option);
        if(option==0){
            Search(lib, count);
        }
        else if(option==1){
            Print(lib, count);
        }
        else if(option==2){
            Create(lib, count);
            count++;
        }
        else if(option==3){
            Delete(lib, count);
        }
        else if(option==4){
            Recover(lib, count);
        }
        else if(option==5){
            Modify(lib, count);
        }
        else if(option==6){
            Recommendation(lib, count);
        }
        else if(option==7){
            SaveData(lib, count);
        }
        else if(option==8){
            printf("프로그램을 종료합니다!");
            exit(0);
        }
        else{
            printf("잘못된 명령어입니다! 다시한번 확인해주세요!\n");
            continue;
        }
    }
}
