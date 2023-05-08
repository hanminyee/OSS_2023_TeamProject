#include "header.h"

int SelectMenu();
void Print(library *list[], int count);
void Mreate(library *list[], int count);
void Modify(library *list[], int count);
void Delete(library *list[], int count);
void Recover(library *list[], int count);
void Search(library *list[], int count);
int LoadData(library *list[]){
    int count = 0; //파일에 몇개 데이터 있는지 리턴해야함
    FILE* fp = fopen("Library_Info.csv", "rt"); //파일 열기

    char dummy[400]; //첫줄 없애기용 더미
    fgets(dummy, 400, fp); //첫줄 없애기
    
    if(fp==NULL){ //파일이 없을 때
        printf("==>파일이 없습니다!\n");
        return 0; 
    }
    else{ //정상적으로 들어왔을 때
        while(1){
            if(feof(fp)){
                break;
            }
            else{
                
            }
        }
    }
}
void SaveData(library *list[], int count);
void Recommendation(library *list[], int count);