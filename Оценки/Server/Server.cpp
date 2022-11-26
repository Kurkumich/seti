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
} persona2;

int answer=0;
long size_pred;
const int n = 4;
int mark[n];
int dolg = 0;

int main() {
    ifstream fR;
    ofstream fA;
    setlocale(LC_ALL, "rus");
    const char* nameR = "C:\\Users\\kurku\\OneDrive\\Рабочий стол\\Оценки\\Файлы\\second.bin";
    const char* nameA = "C:\\Users\\kurku\\OneDrive\\Рабочий стол\\Оценки\\Файлы\\twice.bin";

    cout << "server is working" << endl;
    fR.open(nameR, ios::binary);
    fR.seekg(0, ios::end);
    size_pred = fR.tellg();
    fR.close();
    while (true)
    {
        fR.open(nameR, ios::binary);
        fR.seekg(0, ios::end);
        while (size_pred >= fR.tellg())
        {
            Sleep(100); fR.seekg(0, ios::end);
        }
        fR.seekg(size_pred, ios::beg);
        fR.read((char*)&persona2, sizeof(persona2));
        cout << persona2.name << ", подождите Ваш запрос обрабатывается." << endl;
        size_pred = fR.tellg();
        fR.close();
        mark[0] = persona2.web;
        mark[1] = persona2.math;
        mark[2] = persona2.diff;
        mark[3] = persona2.disk;
        for (int i = 0; i < n; i++)
        {
            if (mark[i] < 3)
                dolg++;

        }
        if (dolg == 0) {
            answer = 0;
        }
        if (dolg == 1) {
            answer = 1;
        }
        if (dolg == 2) {
            answer = 2;
        }
        if (dolg == 3) {
            answer = 3;
        }
        if (dolg == 4) {
            answer = 4;
        }
        fA.open(nameA, ios::binary | ios::app);
        fA.write((char*)&answer, sizeof(answer));
        fA.close();
        for (int i = 0; i < n; i++)
        {
            mark[i] = 0;
        }
        dolg = 0;
    }
}