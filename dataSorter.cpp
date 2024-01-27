#include "dataSorter.h"

/* Задача:

    Пример входного файла:
    Иванов Иван: 3515454
    Сидоров Иван: 3515422
    Сидоров Олег: 23515423
    Петров Иван: 3515455

    Программа должна выводить данные отсортированные по именам, фамилиям и
    номерам. Перед выводом, программа должна спрашивать - по какому
    параметру сортировать и ставить этот параметр в начало вывода  
*/
/* Пример:
    Для сортировки по именам введите – 1, по фамилиям введите- 2, по
    телефонам введите- 3
    
    Ввод: 1
    Вывод:
    Иван Иванов: 3515454
    Иван Сидоров: 3515422
    Иван Петров: 3515455
    Олег Сидоров: 23515423
    
    Ввод : 3
    Вывод:
    3515422: Сидоров Иван
    3515454: Иванов Иван
    3515455: Петров Иван
    23515423: Сидоров Олег
*/

dataSorter::dataSorter(){};

int dataSorter::vectorsInit(bool show){
    ptrTxt = fopen(pathTxt, "r"); 
    if (ptrTxt == NULL){
        printf("File open error.");
        return 1;
    }
    //ASCII
    // 32 пробел
    // 58 : 
    // 10 /n 
    // -1 EOF
    //? change to ':', etc. ?

    do{
    //! получаем фамилию 
        ch = fgetc(ptrTxt) ;
        for ( j = 0; j < MAXLENGTHSURNAME && ch != 32; j++){ 
            tmpSurname[j] = ch;
            ch = fgetc(ptrTxt);
        }
        tmpSurname[j++] = '\0';
        surnames.push_back(tmpSurname);
        if (show) cout << surnames.back() <<" " ;
    //! получаем имя 
        ch = fgetc(ptrTxt); 
        for (j = 0; j < MAXLENGTHNAME && ch != 58; j++){    
            tmpName[j] = ch;
            ch = fgetc(ptrTxt);
        }
        tmpName[j++] = '\0';
        names.push_back(tmpName);
        if (show) cout << names.back() <<" ";
    //! получаем телефон 
        ch = fgetc(ptrTxt); // пропускаем пробел

        ch = fgetc(ptrTxt);
        for (j = 0; j < MAXLENGTHPHONE && ch != 10 && ch != -1; j++){    
            tmpPnone[j] = ch;
            ch = fgetc(ptrTxt);
        }
        tmpPnone[j++] = '\0';
        phones.push_back(tmpPnone);
        if (show) cout << phones.back() <<endl;
    }while (ch != -1);
    fclose(ptrTxt);
    return 0;
} 

int dataSorter::menu(){
    do{
    printf( "\nChoose a type of sort \n"
            "1 - sort by name        \n"
            "2 - sort by surname     \n"
            "3 - sort by phone number\n"
            "0 - exit                \n"
            "Enter number: ");
    scanf("%d", &i);
    printf ("\n\n\n");
    if (i >= 0 && i <= 3) return i; //todo more beautiful, debug
    else printf ("\n Incorrent input. Please try again.\n");
    } while (i >= 0 && i <= 3); 
    
    return 0;
    }
void dataSorter::stepOfSort(int N, bool reverse){
    //swap phones elements
    tmp = phones[N+reverse];
    phones[N+reverse] = phones[N+(1-reverse)];
    phones[N+(1-reverse)] = tmp;

    //swap surnames elements
    tmp = surnames[N+reverse];
    surnames[N+reverse] = surnames[N+(1-reverse)];
    surnames[N+(1-reverse)] = tmp;

    //swap names elements
    tmp = names[N+reverse];
    names[N+reverse] = names[N+(1-reverse)];
    names[N+(1-reverse)] = tmp;
}
int dataSorter::makeSort(int type){ //todo enum
    if (type!=1 && type!=2 && type!=3 )
        return 1;
    moved=true;
    switch (type){  //todo refactoring
    //! Сортировка по имени
        case 1:     
            while (moved){
                moved = false;
                for (m = 0; m < names.size()-1; m++) {  
                    if (names[m]>names[m+1]){
                        stepOfSort(m, 1);
                        moved = true;
                    }
                }   
            }
            for (m = 0; m < names.size(); m++)  // вывод результата сортировки
                cout<< m+1 << ")" << names[m] <<" "<< surnames[m] << " "<< phones[m] <<endl ;             
            break;
    //! Сортировка по фамилии
        case 2:     
            while (moved){
                moved = false;
                for (m = 0; m < surnames.size()-1; m++) {  
                    if (surnames[m]>surnames[m+1]){
                        stepOfSort(m, 1);
                        moved = true;
                    }
                }   
            }
            for (m = 0; m < surnames.size(); m++)   // вывод результата сортировки
                cout<< m+1 << ")" << surnames[m] <<" "<< names[m] << " "<< phones[m] <<endl ;
            break;
    //! Сортировка по номеру телефона
        case 3:   
            while (moved){
                moved = false;
                for (m = 0; m < phones.size()-1; m++) {  
                    if (phones[m]<phones[m+1]){
                        stepOfSort(m, 1);
                        moved = true;
                    }
                }   
            }
            for (m = 0; m < phones.size(); m++) // вывод результата сортировки
                cout<< m+1 << ")" << phones[m] <<" "<< surnames[m] << " "<< names[m] <<endl ; 

            break;
    }
    return 0;
}



int main(){
    dataSorter example;     // создаем экземпляр
    example.vectorsInit(0); // получаем данные из файла, переписываем в вектора
    while (1)
        if (example.makeSort(example.menu()))   //вывод меню и сортировка по указанному признаку
        break;
    return 0;
}