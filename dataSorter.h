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
    vector<string> phones;                  //! вектор телефонных номеров 
    string tmp;                             //! временная переменная хранящяя промежуточное значение при сортировке
    int ch;                                 //! последний полученный из файла символ
    int j;                                  //! счетчик для for'а
    int i;                                  //! счетчик для for'а, буфер для вводимого числа
    size_t m;                               //! счетчик для for'а
    char tmpPnone[MAXLENGTHPHONE + 1];      //! буфер для имени соответсвующей длины
    char tmpName[MAXLENGTHNAME + 1];        //! буфер для имени соответсвующей длины
    char tmpSurname[MAXLENGTHSURNAME + 1];  //! буфер для фамилии соответсвующей длины
    bool moved;                             //! флаг смены элементов для функции сортировки
protected:
    /*
    @brief меняет местами соседние элементы вектора в каждом из векторов
    @para N позиция переставляемого элемента
    @para reverse 1 - по убыванию, 0 - по возрастанию
    */
    void stepOfSort(int N, bool reverse);
public:
    /*
    @brief вывод записей как они отсортированы на текущий момент
    */
    void showVectors();
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
    void sortByPhone();
    /*
    @brief Вывод отсортированных данных
    @param type по какому признаку сортировка (1-имя, 2-фамилия, 3-телефон)
    */
    int makeSort(int type);
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