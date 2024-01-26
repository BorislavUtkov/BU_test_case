#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class dataSorter{
private:
    FILE * ptrTxt;                        
    const char* pathTxt = "db.txt";         //! путь до файла с данными
    static const int MAXLENGTHNAME = 8;     //! максимальная длина имени 
    static const int MAXLENGTHSURNAME = 8;  //! максимальная длина фамилии
    static const int MAXLENGTHPHONE = 8;    //! максимальная длина телефона
    vector<string> names;                   //! вектор имён 
    vector<string> surnames;                //! вектор фамилий 
    vector<string> pnones;                  //! вектор телефонных номеров
    int ch;                                 //! последний полученный из файла символ
    int j;                                  //! счетчик для for'а
    int numOfRecords;                       //! количество записей в векторах
    int *sortResult;                        //! дин.массив с результатом сортировки
    char tmpPnone[MAXLENGTHPHONE + 1];      //! буфер для имени соответсвующей длины
    char tmpName[MAXLENGTHNAME + 1];        //! буфер для имени соответсвующей длины
    char tmpSurname[MAXLENGTHSURNAME + 1];  //! буфер для фамилии соответсвующей длины

public:

    /*
    @brief вывод записей отсортированных по фамилии
    */
    void sortBySurname();
    /*
    @brief вывод записей отсортированных по имени
    */
    void sortByName();
    /*
    @brief вывод записей отсортированных по телефону
    */
    void sortByPohne();
    /*
    @brief Главная функция 
    */
    void makeSort();
    /*
    @brief Вывод ткестового меню
    @return Выбранный вариант сортировки
    */
    int menu();
    /*
    @brief копирование данных файла в соответсвующие вектора
    @param show флаг для вывода считанных значений
    @return 0 - всё ок, 1 - ошибка открытия файла
    */
    int vectorsInit(bool show); 

    dataSorter();
    
};