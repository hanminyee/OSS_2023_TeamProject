#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void SelectMenu(){ //메뉴 보여주기 함수
    printf("\n----------옵션을 선택하세요----------\n");
    printf("0. 서울 시내 도서관 검색하기\n1. 서울시 전체 도서관 보기\n2. 새로운 도서관 추가하기\n3. 사라진 도서관 삭제하기\n4. 실수로 삭제한 도서관 되살리기\n5. 도서관 정보 수정하기\n6. 오늘의 도서관 추천받기\n7. 도서관 정보 저장하기\n8. 종료하기\n\n옵션의 번호를 입력해주세요!>>");
}

void Print(library *list[], int count){// print 함수
    printf("****************************\n");
    printf("도서관 일련번호  도서관명 구 코드  구명  주소 정기 휴관일 전화번호\n");
    for(int i=0;i<count;i++){//하나씩 프린트
        if(list[i]->index==-1) continue;
        printf("%2d",i+1);// 삭제된 데이터는 표시하지 않음. 
        printf(" %d %s %d %s %s %s %s\n",list[i]->number,list[i]->name,list[i]->localnum,list[i]->localName,list[i]->address,list[i]->hollyday,list[i]->callnum);
    }
}
void Create(library *list[], int count) { // 새로운 list 추가 함수
    printf("도서관 일련번호?");
    scanf("%d",&list[count]->number);
    printf("도서관명? ");
    getchar();
    fgets(list[count]->name,300,stdin);
    list[count]->name[(strlen(list[count]->name)-1)]='\0';
    printf("구 코드? ");
    scanf("%d",&list[count]->localnum);
    printf("구명? ");
    getchar();
    fgets(list[count]->localName,20,stdin);
    list[count]->localName[(strlen(list[count]->localName)-1)]='\0';
    printf("주소? ");
    fgets(list[count]->address,1000,stdin);
    list[count]->address[(strlen(list[count]->address)-1)]='\0
    printf("정기 휴관일?");
    fgets(list[count]->hollyday,1000,stdin);
    list[count]->hollyday[(strlen(list[count]->hollyday)-1)]='\0';
    printf("전화번호?");
    fgets(list[count]->callnum,1000,stdin);
    list[count]->callnum[(strlen(list[count]->callnum)-1)]='\0';
    printf("생성 완료!");// 생성 완료 메시지 출력
}
void Modify(library *list[], int count){
     int number;//받을 일련번호
    int listnum;// 받은 일련번호와 일치하는 도서관 일련번호의 index
    printf("일련번호 입력");
    scanf("%d",&number); // 일련 번호 입력 받기
    for(int i=0;i<count;i++){//입련 받은 일련 번호와 일치하는 것 찾기
        if(number==list[i]->number){
            listnum=i;
            break;
        }
    }
    printf("%s 수정\n",list[listnum]->name);
    // 일치하는 도서관 수정
    printf("도서관 일련번호?");
    scanf("%d",&list[listnum]->number);
    printf("도서관명? ");
    getchar();
    fgets(list[listnum]->name,300,stdin);
    list[listnum]->name[(strlen(list[listnum]->name)-1)]='\0';
    printf("구 코드? ");
    scanf("%d",&list[listnum]->localnum);
    printf("구명? ");
    getchar();
    fgets(list[listnum]->localName,20,stdin);
    list[listnum]->localName[(strlen(list[listnum]->localName)-1)]='\0';
    printf("주소? ");
    fgets(list[listnum]->address,1000,stdin);
    list[listnum]->address[(strlen(list[listnum]->address)-1)]='\0';
    printf("정기 휴관일? ");
    fgets(list[listnum]->hollyday,1000,stdin);
    list[listnum]->hollyday[(strlen(list[listnum]->hollyday)-1)]='\0
    printf("전화번호?");
    fgets(list[count]->callnum,1000,stdin);
    list[count]->callnum[(strlen(list[count]->callnum)-1)]='\0';
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
void Recover(library *list[], int count){// 복구 함수
    int number;  // 복구할 도서관의 일련번호 받기
    printf("삭제된 도서관:\n"); // 삭제된 도서관들 출력
    printf("****************************\n");
    for(int i=0;i<count;i++){
        if(list[i]->index==-1){
            printf("%2d",i+1);
        printf(" %d %s %d %s %s %s %s\n",list[i]->number,list[i]->name,list[i]->localnum,list[i]->localName,list[i]->address,list[i]->hollyday,list[i]->callnum);
        }
    }
    printf("복구할 도서관의 일련번호 입력 : ");
    scanf("%d",&number);
    for(int i=0;i<count;i++){
        if(number==list[i]->number){ // 일련번호 일치하는 도서관 복구
            list[i]->index=i;
            printf("%s 복구 성공!\n",list[i]->name);
            printf("%s의 정보가 복구되었습니다!\n", list[i]->name);
            break;
        }
    }
}
void Search(library *list[], int count){// 검색 함수
    getchar();
    char name[100];// 검색할 도서관 이름
    printf("검색할 도서관 이름 입력 : ");
        fgets(name,20,stdin);
    name[(strlen(name)-1)]='\0';
    printf("****************************\n");
    for(int i=0;i<count;i++){// 같거나, 검색된 이름이 포함된 도서관이 있으면 출력
        if(strstr(list[i]->name,name)!=NULL){
        printf("%2d",i+1);
        printf(" %d %s %d %s %s %s %s\n",list[i]->number,list[i]->name,list[i]->localnum,list[i]->localName,list[i]->address,list[i]->hollyday,list[i]->callnum);
        return;
        }
    }
    printf("검색하신 도서관을 찾을 수 없습니다. 이름을 다시한번 확인해주세요!\n");
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
                        list[count]->callnum[(strlen(list[count]->callnum)-1)]='\0';
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
void SaveData(library *list[], int count){// 파일 저장 함수
     FILE *fi;
    fi = fopen("Library_Info.csv", "w");
    fprintf(fi, "도서관 일련번호,도서관명,구 코드,구명,주소,정기 휴관일,전화번호\n");
    for(int i=0;i<count;i++){// 삭제된것 제외 파일 저장
        if(list[i]->index== -1) continue;
        if(i==count-1) {
            fprintf(fi,"%d,%s,%d,%s,%s,%s,%s",list[i]->number,list[i]->name,list[i]->localnum,list[i]->localName,list[i]->address,list[i]->hollyday,list[i]->callnum);
            return;
        }
        fprintf(fi,"%d,%s,%d,%s,%s,%s,%s\n",list[i]->number,list[i]->name,list[i]->localnum,list[i]->localName,list[i]->address,list[i]->hollyday,list[i]->callnum);
    }
    printf("!저장되었습니다!\n");
fclose(fi);
printf("저장 완료!");
}
void Recommendation(library *list[], int count){
    int num;
    num = rand()%count;
    printf("오늘의 추천 도서관은 %s입니다!\n위치 : %s\n휴일 : %s\n", list[num]->name, list[num]->address, list[num]->hollyday);
}   
                   
