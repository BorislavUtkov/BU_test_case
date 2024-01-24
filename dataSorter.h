#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class dataSorter{
private:
    static const int MAXLENGTHNAME = 8;     //! максимальная длина имени 
    static const int MAXLENGTHSURNAME = 8;  //! максимальная длина фамилии
    static const int MAXLENGTHPHONE = 8;    //! максимальная длина телефона
    const char* pathTxt = "db.txt";         //! путь до файла с данными
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
    void makeSort();
    dataSorter();
    ~dataSorter();
};

dataSorter::dataSorter()
{
}

dataSorter::~dataSorter()
{
}
