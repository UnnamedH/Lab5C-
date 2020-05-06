#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Adress {
    int index;
    string Country;
    string Region;
    string District;
    string Town;
    string Street;
    string House;
    string Flat;
};

struct CarOwner {
    string FIO;
    int telephone;
    Adress adress;
    string mark;
    int numberCar;
    int numberPassport;
};

void EasyLevel(CarOwner *carOwners, const int* k) {
    fstream on("E:\\Struct.txt", ios::out | ios::in | ios::trunc);
    CarOwner carOwner;
    carOwners[0].FIO = "Зубенко Михаил Петрович";
    carOwners[1].FIO = "Зеленский Владимир Александрович";
    carOwners[0].mark = "Тойота";
    carOwners[1].mark = "ВАЗ";
    for (int i = 0; i < *k; i++) {
        on << carOwners[i].FIO << "," << carOwners[i].mark << ";" <<"\n";
    }
    on.seekp(0, ios::beg);
    CarOwner* buffer = new CarOwner[*k];
    for (size_t i = 0; i < *k; i++) {
        on >> buffer[i].FIO >> buffer[i].mark;
        if (carOwners[i].mark == "ВАЗ") {
            getline(on, buffer[i].mark, ';');
            cout << "\n" << buffer[i].mark << " ";
        }
    }
    on.close();
   
}

int main()
{
    setlocale(LC_ALL,"");
    int k = 2; 
    CarOwner* carOwners = new CarOwner[k]; 
    EasyLevel(carOwners,&k);// Выводит данные владельца автомобиля "ВАЗ" 
    MediumLevel();
}


