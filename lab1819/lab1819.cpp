#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdalign>
#include <ctime>
#include <random>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
int main()
{
	//Русификатор
	setlocale(LC_ALL, "RU");

	//Создание файла
	string file_in, word_in, word_fn;
	ofstream file;
	file.open("test.txt", ios::out | ios::app);
	if (!file)
	{
		cout << "ОШИБКА!!!: Невозможно открыть файл для записи данных";
		cin.sync(); cin.get(); return 1;
	}

	//Ввод слов в файл
	file << "tik" << endl << "tok" << endl << "john" << endl << "flashlight" << endl << "trojan" << endl;

	file.close();
	ifstream file2;
	file2.open("test.txt", ios::in);
	if (!file)
	{
		cout << "ОШИБКА!!!: Невозможно открыть файл для записи данных";
		cin.sync(); cin.get(); return 2;
	}

	//Ввод пользователем слова для поиска
	cout << "Введите слово: ";
	cin >> word_fn;
	
	while (file2 >> word_in)
		if (word_in == word_fn)
		{
			cout << "Слово '" << word_fn << "' найдено\n";
		}
	if (word_in != word_fn)
	{
		cout << "Слово '" << word_fn << "' не найдено\n";
	}

	system("PAUSE");
	file2.close();
	return 0;
}