#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int number; //일련번호
    int index; //삭제용 인덱스,  그냥 어레이 번호랑 같음
    char callnum[20]; //전화번호
    char name[300]; //도서관 이름
    int localnum; //구 코드
    char localName[20]; //구 이름
    char address[1000]; //도서관 주소
    char hollyday[300]; //도서관 휴일
}library;

int SelectMenu();
void Print(library *list[], int count); // 프린트 함수
void Mreate(library *list[], int count); //정보 추가 함수
void Modify(library *list[], int count); // 정보 수정 함수
void Delete(library *list[], int count);
void Recover(library *list[], int count); // 정보 복수 함수
void Search(library *list[], int count); //정보 검색 함수
int LoadData(library *list[]); 
void SaveData(library *list[], int count);  // 파일 저장 함수
void Recommendation(library *list[], int count);
