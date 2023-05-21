#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void SelectMenu(){ //메뉴 보여주기 함수
    printf("\n----------옵션을 선택하세요----------\n");
    printf("1. 서울시 전체 도서관 보기\n2. 새로운 도서관 추가하기\n3. 사라진 도서관 삭제하기\n4. 실수로 삭제한 도서관 되살리기\n5. 도서관 정보 수정하기\n6. 오늘의 도서관 추천받기\n7. 도서관 정보 저장하기\n8. 종료하기\n\n옵션의 번호를 입력해주세요!>>");
}

void Print(library *list[], int count){// print 함수
    printf("****************************\n");
    printf("도서관 일련번호  도서관명 구 코드  구명  주소 정기 휴관일 전화번호");
    for(int i=0;i<count;i++){//하나씩 프린트
        if(list[i]->index==-1) continue;
        printf("%2d",i+1);// 삭제된 데이터는 표시하지 않음. 
        printf(" %d %s %d %s %s %s %s\n",list[i]->number,list[i]->name,list[i]->localnum,list[i]->localName,list[i]->address,list[i]->hollyday,list[i]->callnum);
    }
}
void Create(library *list[], int count) {
    printf("도서관 일련번호?");
    scanf("%d",&list[count]->number);
    printf("도서관명?");
    getchar();
    fgets(list[count]->name,300,stdin);
    list[count]->name[(strlen(list[count]->name)-1)]='\0';
    printf("구 코드?");
    scanf("%d",&list[count]->localnum);
    printf("구명?");
    getchar();
    fgets(list[count]->localName,20,stdin);
    list[count]->localName[(strlen(list[count]->localName)-1)]='\0';
    printf("주소?");
    fgets(list[count]->address,1000,stdin);
    list[count]->address[(strlen(list[count]->address)-1)]='\0';
    printf("정기 휴관일?");
    fgets(list[count]->hollyday,1000,stdin);
    list[count]->hollyday[(strlen(list[count]->hollyday)-1)]='\0';
    printf("전화번호?");
    fgets(list[count]->hollyday,1000,stdin);
    list[count]->hollyday[(strlen(list[count]->hollyday)-1)]='\0';
    printf("생성 완료!");
}
void Modify(library *list[], int count){
     int number;
    int listnum;
    printf("일련번호 입력");
    scanf("%d",&number);
    for(int i=0;i<count;i++){
        if(number==list[i]->number){
            listnum=i;
            break;
        }
    }
        printf("도서관 일련번호?");
    scanf("%d",&list[listnum]->number);
    printf("도서관명?");
    getchar();
    fgets(list[listnum]->name,300,stdin);
    list[listnum]->name[(strlen(list[listnum]->name)-1)]='\0';
    printf("구 코드?");
    scanf("%d",&list[listnum]->localnum);
    printf("구명?");
    getchar();
    fgets(list[listnum]->localName,20,stdin);
    list[listnum]->localName[(strlen(list[listnum]->localName)-1)]='\0';
    printf("주소?");
    fgets(list[listnum]->address,1000,stdin);
    list[listnum]->address[(strlen(list[listnum]->address)-1)]='\0';
    printf("정기 휴관일?");
    fgets(list[listnum]->hollyday,1000,stdin);
    list[listnum]->hollyday[(strlen(list[listnum]->hollyday)-1)]='\0';
    printf("전화번호?");
    scanf("%d",&list[listnum]->callnum);
    printf("수정 완료");
}
void Delete(library *list[], int count){
    printf("==> 폐업하였거나, 영업중이지 않은 도서관의 '일련번호'를 입력해주세요 >> ");
    int deletenum; //삭제할 일련번호 받는 변수
    scanf("%d", &deletenum); //받기
    for(int i = 0; i<count; i++){ 
        if(list[i]->number==deletenum){ //list[i]->일련번호가 deletenum이면 list[i]->index = -1로 만들기
            list[i]->index = -1;
            printf("%s의 정보가 삭제되었습니다!\n", list[i]->name);
            break;
        }
        else continue;
    }
}
void Recover(library *list[], int count){
    printf("구현중..\n");
}
void Search(library *list[], int count){
    printf("구현중..\n");
}
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
                    list[count]->index = count;
                    if(tokcount==0){
                        int num = atoi(p);
                        list[count]->number = num;
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
            }
        }
    }
    return count;
}
void SaveData(library *list[], int count){
    printf("구현중..\n");
}
void Recommendation(library *list[], int count){
    int num;
    num = rand()%count;
    printf("오늘의 추천 도서관은 %s입니다!\n위치 : %s\n휴일 : %s\n", list[num]->name, list[num]->address, list[num]->hollyday);
}   
                   
