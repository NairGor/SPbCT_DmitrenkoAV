#pragma once
#include "DLL.h" // подключение созданной DLL-библиотеки
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <mutex>
#include <iterator>
#include <chrono>
#include <iomanip>
#include <fileapi.h>

namespace EduPractice {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::IO;
	using namespace System::Threading;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			DateTime datetime = DateTime::Now;
			this->label4->Text = "Дата: " + datetime.ToString(); // запись времени и даты в label 4 на форму
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;



	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: Thread^ t1;
	private: Thread^ t2; // создание потоков

	private: System::Windows::Forms::Button^ SortFileButton;
	private: System::Windows::Forms::Button^ File1CreateButton;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SortFileButton = (gcnew System::Windows::Forms::Button());
			this->File1CreateButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(19, 95);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(303, 192);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(16, 60);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Исходный файл";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(350, 60);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(188, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Отсортированный файл";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::White;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(353, 95);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(303, 192);
			this->textBox2->TabIndex = 4;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(10, 24);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(195, 20);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Дмитренко А. В. г.500";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(226, 24);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 20);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Дата:";
			// 
			// SortFileButton
			// 
			this->SortFileButton->BackColor = System::Drawing::Color::Transparent;
			this->SortFileButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SortFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SortFileButton->Location = System::Drawing::Point(418, 301);
			this->SortFileButton->Margin = System::Windows::Forms::Padding(2);
			this->SortFileButton->Name = L"SortFileButton";
			this->SortFileButton->Size = System::Drawing::Size(170, 44);
			this->SortFileButton->TabIndex = 5;
			this->SortFileButton->Text = L"Отобразить отсортированный файл и поставить аттрибут только для чтения";
			this->SortFileButton->UseVisualStyleBackColor = false;
			this->SortFileButton->Click += gcnew System::EventHandler(this, &MyForm::SortFileButton_Click);
			// 
			// File1CreateButton
			// 
			this->File1CreateButton->BackColor = System::Drawing::Color::Transparent;
			this->File1CreateButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->File1CreateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->File1CreateButton->Location = System::Drawing::Point(89, 301);
			this->File1CreateButton->Margin = System::Windows::Forms::Padding(2);
			this->File1CreateButton->Name = L"File1CreateButton";
			this->File1CreateButton->Size = System::Drawing::Size(170, 44);
			this->File1CreateButton->TabIndex = 1;
			this->File1CreateButton->Text = L"Заполнить исходный файл буквами ";
			this->File1CreateButton->UseVisualStyleBackColor = false;
			this->File1CreateButton->Click += gcnew System::EventHandler(this, &MyForm::File1CreateButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(684, 377);
			this->Controls->Add(this->SortFileButton);
			this->Controls->Add(this->File1CreateButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void File1CreateButton_Click(System::Object^ sender, System::EventArgs^ e) { // кнопка для заполнения файла 100 буквами, если это не было сделано вручную
		srand(time(NULL));
		char letters[100];
		fstream file1; // создание объекта класса fstream 
		file1.open("1.txt"); // связывание объекта класса fstream с файлом, который будет использоваться для операций ввода-вывода
		for (int i = 0; i < 100; i++)
		{
			letters[i] = (rand() % ('я' - 'а' + 1)) + 'а'; //присваиваем букве рандомное значение из алфавита
			file1 << letters[i]; // добавляем букву в файл
		}
		file1.close(); //закрываем файл

		String^ file1Path = "1.txt"; // создаем переменную для хранения пути к файлу
		try
		{
			String^ file = File::ReadAllText(file1Path, System::Text::Encoding::GetEncoding(1251)); //открываем файл
			textBox1->Text = file; //записываем содержимое файла в TextBox
		}
		catch (Exception^ e)
		{
			MessageBox::Show(this, "Файл не был открыт", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}
	}
	public: void T1() { //функция для передачи 1-му потоку
		char letter[100];
		ifstream file1;
		file1.open("1.txt");
		int k = 0;
		for (int i = 0; i < 5; i++)
		{
			std::vector<char> v; //инициализация векторов
			for (int j = k; j < k + 10; j++)
			{
				file1 >> letter[j];
				v.push_back(letter[j]);
			}
			k += 10;
			sort(v.begin(), v.end()); // сортировка вектора по алфавиту
			v[i] = 'ඞ';
			writeToFile2(v); // записываем вектор во второй файл
	 	}
		file1.close();
	}
	public: void T2() { //функция для передачи 2-му потоку
		char letter[100];
		ifstream file1;
		file1.open("1.txt");
		int k = 50;
		for (int i = 0; i < 5; i++)
		{
			std::vector<char> v; //инициализация векторов
			for (int j = k; j < k + 10; j++)
			{
				file1 >> letter[j];
				v.push_back(letter[j]);
			}
			k += 10;
			sort(v.begin(), v.end()); // сортировка вектора по алфавиту
			v[5+i] = 'ඞ';
			writeToFile2(v); // записываем вектор во второй файл
		}
		file1.close();
	}

	private: System::Void SortFileButton_Click(System::Object^ sender, System::EventArgs^ e) { //кнопка для отображения содержимого 2-го отсортированного файла (2.txt) в textbox2
		LPSTR lpFileName = "2.txt";// создаем переменную для хранения пути к файлу
		SetFileAttributesA("2.txt", FILE_ATTRIBUTE_NORMAL); // ставим стандартные атрибуты
		fstream ofs;
		ofs.open(lpFileName, ios::out | ios::trunc); // стираем содержимое файла
		ofs.close(); // закрываем поток
		t1 = gcnew Thread(gcnew ThreadStart(this, &MyForm::T1)); //создаем поток, выполняющий функцию T1
		t2 = gcnew Thread(gcnew ThreadStart(this, &MyForm::T2));
		t1->Start(); // начинаем поток
		t1->Join(); // функция для блокировки вызывающегося потока до тех пор, пока поток выполнения не завершится
		t2->Start();
		t2->Join();
		String^ file2Path = "2.txt";
		try
		{
			String^ file = File::ReadAllText(file2Path, System::Text::Encoding::GetEncoding(1251)); //открываем файл
			textBox2->Text = file; //записываем содержимое файла в TextBox
			SetFileAttributesA(lpFileName, FILE_ATTRIBUTE_READONLY);
		}
		catch (Exception^ e)
		{
			MessageBox::Show(this, "Файл не был открыт", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}