#include "header.h"

int SelectMenu();
void Print(library *list[], int count);
void Mreate(library *list[], int count);
void Modify(library *list[], int count);
void Delete(library *list[], int count);
void Recover(library *list[], int count);
void Search(library *list[], int count);
int LoadData(library *list[]){
    FILE* fp = fopen("Library_Info.csv", "rt"); //파일 열기

    char dummy[400]; //첫줄 없애기용 더미
    fgets(dummy, 400, fp); //첫줄 없애기
    int count = 0; //파일에 몇개 데이터 있는지 리턴해야함
    if(fp==NULL){ //파일이 없을 때
        printf("==>파일이 없습니다!\n");
        return 0; 
    }
    else{ //정상적으로 들어왔을 때
        while(1){
            if(feof(fp)){
                printf("==>파일을 불러왔습니다!\n");
                break;
            }
            else{
                char val[400]; //fgets한거 담기는 변수
                int tokcount = 0; //토큰 분리할 때, 0번째는 atoi로 바꾸고, 1번째는 strcpy해야하고... 여러 변수가 있으니까 씀
                fgets(val, 400, fp);
                char *p = strtok(val, ","); //strtok로 "," 나오면 분리
                while(p!=NULL){
                    if(tokcount==0){
                        list[count]->index = count;
                        int num = atoi(p);
                        list[count]->number = num;
                        //printf("%d ", list[count]->number);
                        //printf("dkdkdk");
                        tokcount++;
                    }
                    else if(tokcount==1){
                        strcpy(list[count]->name, p);
                        //printf("%s ", list[count]->name);
                        tokcount++;
                    }
                    else if(tokcount==2){
                        int num = atoi(p);
                        list[count]->localnum = num;
                        //printf("%d ", list[count]->localnum);
                        tokcount++;
                    }
                    else if(tokcount==3){
                        strcpy(list[count]->localName, p);
                        //printf("%s ", list[count]->localName);
                        tokcount++;
                    }
                    else if(tokcount==4){
                        strcpy(list[count]->address, p);
                        //printf("%s ", list[count]->address);
                        tokcount++;
                    }
                    else if(tokcount==5){
                        strcpy(list[count]->hollyday, p);
                        //printf("%s ", list[count]->hollyday);
                        tokcount++;
                    }
                    else if(tokcount==6){
                        strcpy(list[count]->callnum, p);
                        //printf("%s\n", list[count]->callnum);
                        tokcount++;
                    }
                    //printf("%s", p);
                    p = strtok(NULL, ",");
                }
                count++;
                //printf("\n%d\n", count);
            }
        }
    }
}
void SaveData(library *list[], int count);
void Recommendation(library *list[], int count);
