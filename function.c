#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void SelectMenu(){ //�޴� �����ֱ� �Լ�
    printf("\n----------�ɼ��� �����ϼ���----------\n");
    printf("1. ����� ��ü ������ ����\n2. ���ο� ������ �߰��ϱ�\n3. ����� ������ �����ϱ�\n4. �Ǽ��� ������ ������ �ǻ츮��\n5. ������ ���� �����ϱ�\n6. ������ ������ ��õ�ޱ�\n7. ������ ���� �����ϱ�\n8. �����ϱ�\n\n�ɼ��� ��ȣ�� �Է����ּ���!>>");
}

void Print(library *list[], int count){// print �Լ�
    printf("****************************\n");
    printf("������ �Ϸù�ȣ  �������� �� �ڵ�  ����  �ּ� ���� �ް��� ��ȭ��ȣ");
    for(int i=0;i<count;i++){//�ϳ��� ����Ʈ
        if(list[i]->index==-1) continue;
        printf("%2d",i+1);// ������ �����ʹ� ǥ������ ����. 
        printf(" %d %s %d %s %s %s %s\n",list[i]->number,list[i]->name,list[i]->localnum,list[i]->localName,list[i]->address,list[i]->hollyday,list[i]->callnum);
    }
}
void Create(library *list[], int count) {
    printf("������ �Ϸù�ȣ?");
    scanf("%d",&list[count]->number);
    printf("��������?");
    getchar();
    fgets(list[count]->name,300,stdin);
    list[count]->name[(strlen(list[count]->name)-1)]='\0';
    printf("�� �ڵ�?");
    scanf("%d",&list[count]->localnum);
    printf("����?");
    getchar();
    fgets(list[count]->localName,20,stdin);
    list[count]->localName[(strlen(list[count]->localName)-1)]='\0';
    printf("�ּ�?");
    fgets(list[count]->address,1000,stdin);
    list[count]->address[(strlen(list[count]->address)-1)]='\0';
    printf("���� �ް���?");
    fgets(list[count]->hollyday,1000,stdin);
    list[count]->hollyday[(strlen(list[count]->hollyday)-1)]='\0';
    printf("��ȭ��ȣ?");
    fgets(list[count]->hollyday,1000,stdin);
    list[count]->hollyday[(strlen(list[count]->hollyday)-1)]='\0';
    printf("���� �Ϸ�!");
}
void Modify(library *list[], int count){
     int number;
    int listnum;
    printf("�Ϸù�ȣ �Է�");
    scanf("%d",&number);
    for(int i=0;i<count;i++){
        if(number==list[i]->number){
            listnum=i;
            break;
        }
    }
        printf("������ �Ϸù�ȣ?");
    scanf("%d",&list[listnum]->number);
    printf("��������?");
    getchar();
    fgets(list[listnum]->name,300,stdin);
    list[listnum]->name[(strlen(list[listnum]->name)-1)]='\0';
    printf("�� �ڵ�?");
    scanf("%d",&list[listnum]->localnum);
    printf("����?");
    getchar();
    fgets(list[listnum]->localName,20,stdin);
    list[listnum]->localName[(strlen(list[listnum]->localName)-1)]='\0';
    printf("�ּ�?");
    fgets(list[listnum]->address,1000,stdin);
    list[listnum]->address[(strlen(list[listnum]->address)-1)]='\0';
    printf("���� �ް���?");
    fgets(list[listnum]->hollyday,1000,stdin);
    list[listnum]->hollyday[(strlen(list[listnum]->hollyday)-1)]='\0';
    printf("��ȭ��ȣ?");
    scanf("%d",&list[listnum]->callnum);
    printf("���� �Ϸ�");
}
void Delete(library *list[], int count){
    printf("==> ����Ͽ��ų�, ���������� ���� �������� '�Ϸù�ȣ'�� �Է����ּ��� >> ");
    int deletenum; //������ �Ϸù�ȣ �޴� ����
    scanf("%d", &deletenum); //�ޱ�
    for(int i = 0; i<count; i++){ 
        if(list[i]->number==deletenum){ //list[i]->�Ϸù�ȣ�� deletenum�̸� list[i]->index = -1�� �����
            list[i]->index = -1;
            printf("%s�� ������ �����Ǿ����ϴ�!\n", list[i]->name);
            break;
        }
        else continue;
    }
}
void Recover(library *list[], int count){
    printf("������..\n");
}
void Search(library *list[], int count){
    printf("������..\n");
}
int LoadData(library *list[]){
    FILE* fp = fopen("Library_Info.csv", "rt"); //���� ����

    char dummy[400]; //ù�� ���ֱ�� ����
    fgets(dummy, 400, fp); //ù�� ���ֱ�
    int count = 0; //���Ͽ� � ������ �ִ��� �����ؾ���
    if(fp==NULL){ //������ ���� ��
        printf("==>������ �����ϴ�!\n");
        return 0; 
    }
    else{ //���������� ������ ��
        while(1){
            if(feof(fp)){
                printf("==>������ �ҷ��Խ��ϴ�!\n");
                break;
            }
            else{
                char val[400]; //fgets�Ѱ� ���� ����
                int tokcount = 0; //��ū �и��� ��, 0��°�� atoi�� �ٲٰ�, 1��°�� strcpy�ؾ��ϰ�... ���� ������ �����ϱ� ��
                fgets(val, 400, fp);
                char *p = strtok(val, ","); //strtok�� "," ������ �и�
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
    printf("������..\n");
}
void Recommendation(library *list[], int count){
    int num;
    num = rand()%count;
    printf("������ ��õ �������� %s�Դϴ�!\n��ġ : %s\n���� : %s\n", list[num]->name, list[num]->address, list[num]->hollyday);
}   
                   
