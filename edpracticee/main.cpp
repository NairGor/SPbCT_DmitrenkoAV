#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include "DLL.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>

#pragma warning(disable : 4996)
using namespace std;

int main(int argc, TCHAR* argv[])
{
    setlocale(LC_CTYPE, "ru");
    vector<char> v;
    time_t t;
    time(&t);
    cout << "Дмитренко А. В. г.500 \n";
    cout << "Дата и время: " << ctime(&t) << endl;

    cout << "Создание дочернего процесса...\n";
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    // Дочерний процесс
    TCHAR szCmdline[] = TEXT(".//ChildProcess.exe");
    if (!CreateProcess(NULL,
        szCmdline,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi)
        )
    {
        printf("CreateProcess failed (%d).\n", GetLastError());
    }
    WaitForSingleObject(pi.hProcess, INFINITE);


    string line;
    string viktor[10];
    ifstream in(".\\1.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << "\nПолучена строка:\n" << line << "\n";
        }
    }
    cout << "\n";

    in.close();

    int k = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = k; j < k + 10; j++)
        {
            viktor[i] += line[j];
        }
        sort(viktor[i].begin(), viktor[i].end());
        viktor[i][i] = 'ඞ';
        k += 10;
    }


    for (int i = 0; i < 10; i++)
    {
        cout << viktor[i] << endl;
    }
    // Анонимный канал
    
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    system("pause");

    return 0;
}