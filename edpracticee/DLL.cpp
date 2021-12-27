#include "DLL.h"
#include <Windows.h>

void writeToFile2(const std::vector<char>& vector) //функция для записи вектора в отсортированный файл
{
	std::ofstream file2("2.txt", std::ios::app); //открытие файла
	copy(vector.begin(), vector.end(), std::ostream_iterator<char>(file2)); //запись вектора в файл
	file2 << std::endl; //запись переноса строки
	file2.close(); //закрытие файла
}
