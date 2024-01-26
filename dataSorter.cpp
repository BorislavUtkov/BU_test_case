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


// dataSorter::dataSorter(){};

int dataSorter::vectorsInit(bool show){
    ptrTxt = fopen(pathTxt, "r"); 
    if (ptrTxt == NULL){
        printf("File open error.");
        return 1;
    }
    //! 32 пробел
    //! 58 : 
    //! 10 /n 
    //! -1 EOF
    numOfRecords=0;
    ch = fgetc(ptrTxt) ;
    do{
    //! получаем фамилию 
        for ( j = 0; j < MAXLENGTHSURNAME && ch != 32; j++){ 
            tmpSurname[j] = ch;
            ch = fgetc(ptrTxt);
        }
        tmpSurname[j++] = '\0';
        surnames.push_back(tmpSurname);
        if (show) cout << surnames.back() <<" " ;
        //===============================================================================================
        //! получаем имя 
        ch = fgetc(ptrTxt); 
        for (j = 0; j < MAXLENGTHNAME && ch != 58; j++){    
            tmpName[j] = ch;
            ch = fgetc(ptrTxt);
        }
        tmpName[j++] = '\0';
        names.push_back(tmpName);
        if (show) cout << names.back() <<" ";
        //===============================================================================================
        //! получаем телефон 
        ch = fgetc(ptrTxt); // пропускаем пробел

        ch = fgetc(ptrTxt);
        for (j = 0; j < MAXLENGTHPHONE && ch != 58 && ch != -1; j++){    
            tmpPnone[j] = ch;
            ch = fgetc(ptrTxt);
        }
        tmpPnone[j++] = '\0';
        pnones.push_back(tmpPnone);
        numOfRecords++;
        if (show) cout << pnones.back() <<endl;
    }while (ch != -1);
    fclose(ptrTxt);
    return 0;
} 
    int dataSorter::menu(){
        int i=0;
        do{
        printf( "\nChoose a type of sort \n"
                "1 - sort by name        \n"
                "2 - sort by surname     \n"
                "3 - sort by phone number\n"
                "0 - exit                \n"
                "Enter number: ");
        scanf("%d", &i);
        if (i >= 0 && i <= 3) return i; //todo
        else printf ("\n Incorrent input. Please try again.\n");
        } while (i >= 0 && i <= 3); 
        
    }
    void dataSorter::makeSort(){// сделать входной параметр определяющий признак сортировки
        vectorsInit(1);
        sortResult = new int [numOfRecords];
    }

int main(){
    dataSorter sortExample;
    sortExample.vectorsInit();
    sortExample.makeSort();
    return 0;
}