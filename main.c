#include "header.h"

int main(){
    library *lib[2000];
    for(int i = 0; i<2000; i++){
        lib[i] = (library*)malloc(sizeof(library));
    }
    printf("<<����� ������ ã�� ���α׷� L-Finder>>\n�����Ͻ÷��� �ƹ� Ű�� �����ּ���!\n");
    char dummy;
    scanf("%c", &dummy);
    getchar();
    int count = LoadData(lib);
    while(1){
        SelectMenu();
        int option;
        scanf("%d", &option);
        if(option==1){
            Print(lib, count);
        }
        else if(option==2){
            Create(lib, count);
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
            printf("���α׷��� �����մϴ�!");
            exit(0);
        }
        else{
            printf("�߸��� ��ɾ��Դϴ�! �ٽ��ѹ� Ȯ�����ּ���!\n");
            continue;
        }
    }
}
