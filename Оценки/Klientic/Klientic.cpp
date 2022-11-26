#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

struct Person {
    char name[25];
    int web;
    int math;
    int diff;
    int disk;
} persona;

void main() {
    setlocale(LC_ALL, "rus");
    const char* nameR = "C:\\Users\\kurku\\OneDrive\\Рабочий стол\\Оценки\\Файлы\\second.bin";
    const char* nameA = "C:\\Users\\kurku\\OneDrive\\Рабочий стол\\Оценки\\Файлы\\twice.bin";
    ofstream fR;
    ifstream fA;
    long pred_size;
    int answer = 0;
    while (true)
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        cout << "Введите Ваше имя и оценки по 4 экзаменам: Web, Математический анализ, Дифференциальные уравнения и Дискретная математика:" << endl;
        cin >> persona.name >> persona.web >> persona.math >> persona.diff >> persona.disk;
        cout << "Ответ для пользователя: " << persona.name << endl;
        fR.open(nameR, ios::app | ios::binary);
        fR.write((char*)&persona, sizeof(persona));
        fR.close();

        fA.open(nameA, ios::binary);
        if (!fA.is_open())
            cout << "ERROR" << endl;
        else
        {
            fA.seekg(0, ios::end);
            pred_size = fA.tellg();
            while (pred_size >= fA.tellg())
            {
                Sleep(100);
                fA.seekg(0, ios::end);
            }
            fA.seekg(pred_size, ios::beg);
            fA.read((char*)&answer, sizeof(answer));
            fA.close();
        }
        switch (answer) {
        case 0: {cout << "Вы сдали сессию, поздравляем! " << endl << endl; break; }
        case 1: {cout << "К сожалению, Вы не сдали сессию( Кол-во долгов: 1! " << endl << endl; break; }
        case 2: {cout << "К сожалению, Вы не сдали сессию( Кол-во долгов: 2! " << endl << endl; break; }
        case 3: {cout << "К сожалению, Вы не сдали сессию( Кол-во долгов: 3! " << endl << endl; break; }
        case 4: {cout << "К сожалению, Вы не сдали сессию( Кол-во долгов: 4! " << endl << endl; break; }
        }
    }
}