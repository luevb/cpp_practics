#include <stdio.h>
#include <windows.h>
#include <iostream>
#include "String.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа 3\n";
    auto author = []()
        {
            cout << "Луев Борис ББСО-02-24" << endl;
        };
    author();
    String* sw = new String("Бла бла бла");
    sw->loadfile("data123.txt");
    cout << "" << endl;
    cout << *sw << endl;
    vector<string> words = sw->Chisla();
    cout << "" << endl;
    for (const auto& word : words)
        cout << word << " ";
    sw->writeResultsToFile("out123.txt", words);
}
