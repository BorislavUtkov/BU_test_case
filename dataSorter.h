#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class dataSorter{
private:
    const char* pathTxt = "db.txt";         //! путь до файла с данными
    static const int MAXLENGTHNAME = 8;     //! максимальная длина имени 
    static const int MAXLENGTHSURNAME = 8;  //! максимальная длина фамилии
    static const int MAXLENGTHPHONE = 8;    //! максимальная длина телефона
    vector<string> names;                   //! вектор имён 
    vector<string> surnames;                //! вектор фамилий 
    vector<string> pnones;                  //! вектор телефонных номеров
    int ch;                                 //! последний полученный из файла символ
    int j;                                  //! счетчик для for'а
    char tmpPnone[MAXLENGTHPHONE +1];       //! буфер для имени соответсвующей длины
    char tmpName[MAXLENGTHNAME +1];         //! буфер для имени соответсвующей длины
    char tmpSurname[MAXLENGTHSURNAME +1];   //! буфер для фамилии соответсвующей длины

public:

    /*
    @brief копирование данных файла в соответсвующие вектора
    @return 0 - всё ок, 1 - ошибка открытия файла
    */
    int vectorsInit(bool show); 
    /*
    @brief Отсортировать записи по фамилии
    */
    void sortBySurname();
    /*
    @brief Отсортировать записи по Имени
    */
    void sortByName();
    /*
    @brief Отсортировать записи по телефону
    */
    void sortByPohne();
    /*
    @brief Главная функция включающая в себя всю логику
    */
    void makeSort();
    /*
    @brief Вывод ткестового меню
    @return Выбранный вариант сортировки
    */
    int menu();
    dataSorter();
    ~dataSorter();
};

dataSorter::dataSorter()
{
}

dataSorter::~dataSorter()
{
}
