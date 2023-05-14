#include "header.h"

void SelectMenu(){ //�޴� �����ֱ� �Լ�
    printf("\n----------�ɼ��� �����ϼ���----------\n");
    printf("1. ����� ��ü ������ ����\n2. ���ο� ������ �߰��ϱ�\n3. ����� ������ �����ϱ�\n4. �Ǽ��� ������ ������ �ǻ츮��\n5. ������ ���� �����ϱ�\n6. ������ ������ ��õ�ޱ�\n7. ������ ���� �����ϱ�\n8. �����ϱ�\n\n�ɼ��� ��ȣ�� �Է����ּ���!>>");
}

void Print(library *list[], int count){
    printf("****************************\n");
    printf("������ �Ϸù�ȣ  �������� �� �ڵ�  ����  �ּ� ���� �ް��� ��ȭ��ȣ");
    for(int i=0;i<count;i++){
        if(list[i]->index==-1) continue;
        printf("%2d",i+1);
        printf(" %d %s %d %s %s %s %s\n",list[i]->number,list[i]->name,list[i]->localnum,list[i]->localName,list[i]->address,list[i]->hollyday,list[i]->callnum);
    }
}
void Create(library *list[], int count) {
    printf("������..\n");
}
void Modify(library *list[], int count){
    printf("������..\n");
}
void Delete(library *list[], int count){
    printf("������..\n");
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
void SaveData(library *list[], int count){
    printf("������..\n");
}
void Recommendation(library *list[], int count){
    printf("������..\n");
}   
                   
