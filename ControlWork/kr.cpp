#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>


using namespace std;
string DOW(int);
void show_menu();



class Time_Table
{
private:
	struct Patient
	{
		int day;
		string name;
		int time;
		int polis;
		Patient* next;
		Patient* prev;
	};
	Patient* Head;
	Patient* Tail;


public:
	Time_Table() { Head = Tail = NULL; };
	bool Head_chker() { if (Head == NULL) return 1; else return 0; }
	~Time_Table();
	void show_day();
	void push(int, string, int, int);
	void pop(int, string, int, int);
	bool Repeat_Checker(int);
	void File_Save(ofstream&);
	void File_Read(ifstream&, Time_Table&);

};

bool Time_Table::Repeat_Checker(int i)
{
	Patient* temp = Head;
	while (temp != NULL)
	{
		if (temp->time == i) return 0;
		temp = temp->next;
	}
	return 1;
}

Time_Table::~Time_Table()
{
	while (Head)
	{
		Tail = Head->next;
		delete Head;
		Head = Tail;
	}
}

void Time_Table::push(int D, string N, int T, int P)
{
	Patient* person = new Patient;
	
	person->day = D;
	person->name = N;
	person->time = T;
	person->polis = P;

	if (Head == NULL)
	{
		person->prev = NULL;
		person->next = NULL;
		Head = Tail = person;
		cout << "Запись успешно добавлена!" << endl;
	}
	else
	{
		if (Repeat_Checker(person->time))
		{
			Patient* temp = Head;
			bool flag = true;
			bool checker = person->time == temp->time;

			if (person->time < temp->time)
			{
				Head->prev = person;
				person->next = Head;
				person->prev = NULL;
				Head = person;
			}
			else
			{
				while (flag)
				{
					if (temp->next == NULL)
					{
						person->prev = temp;
						person->next = NULL;
						temp->next = person;
						Tail = person;
						flag = 0;
					}
					else
					{
						temp = temp->next;

						if (person->time < temp->time)
						{
							person->next = temp;
							person->prev = temp->prev;
							temp->prev->next = person;
							temp->prev = person;
							flag = 0;
						}

					}
				}
			}
			cout << " Запись успешно добавлена!" << endl;
		}
		else cout << "Запись не может быть осущствлена. Время занято." << endl;
	}
}

void Time_Table::pop(int D, string N, int T, int P)
{
	if (Head == NULL) cout << "Список пуст. Удаление невозможно." << endl;
	else
	{
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = NULL;
		}
		else
		{
			bool flag = true;
			Patient* temp = Head;
			while (flag)
			{
				if (D == temp->day && N == temp->name && temp->time == T && temp->polis == P)
				{
					if (temp == Head)
					{
						temp->next->prev = NULL;
						Head = temp->next;
						delete temp;
						flag = false;
					}
					else
					{
						if (temp == Tail)
						{
							temp->prev->next = NULL;
							Tail = temp->prev;
							delete temp;
							flag = false;
						}
						else
						{
							temp->prev->next = temp->next;
							temp->next->prev = temp->prev;
							delete temp;
							flag = false;
						}
					}
				}
				else temp = temp->next;
			}
		}
		cout << "Удаление прошло успешно" << endl;
	}

}

void File_Read(ifstream& f, Time_Table* W)
{
	string name, blank;
	int day, time_pass, polis;
	if (!f)
	{
		cout << "Ошибка открытия файла." << endl;
	}
	else
	{

		while (!f.eof())
		{
			f >> name;
			f >> day;
			f >> time_pass;
			f >> polis;

			W[day - 1].push(day, name, time_pass, polis);
		}
		cout << "Файл был успешно считан.";
		cout << blank;
	}
}

void Time_Table::show_day()
{
	Patient* temp = Head;
	while (temp != NULL)
	{
		cout << endl << "Фамилия пациента: " << temp->name << endl;
		cout << "Время приема: " << temp->time << ":00" << endl ;
		cout << "Полис: " << temp->polis << endl << endl;
		temp = temp->next;
	}
}

void Time_Table::File_Save(ofstream& f)
{
	Patient* temp = Head;
	while (temp != NULL)
	{
		f << endl << "Фамилия пациента: " << temp->name << endl;
		f << "Время приема: " << temp->time << ":00" << endl ;
		f << "Полис: " << temp->polis << endl << endl;
		temp = temp->next;
	}
}
int main()
{
	setlocale(LC_ALL, "RU");

	Time_Table RJD1, RJD2, RJD3, RJD4, RJD5, RJD6, RJD7;
	Time_Table week[7] = { RJD1, RJD2, RJD3, RJD4, RJD5, RJD6, RJD7 };

	string name;
	int time_pass;
	int k, day, polis;

	show_menu();
	cout << endl << "Введите пункт меню. " << endl;
	k = _getch();
	cout << endl;

	while (k != 'Q')
	{
		switch (k)
		{
		case '1':
		{
			ifstream r("input.txt");
			File_Read(r, week);
			r.close();


		}; break;

		case '2':
		{

			for (int i = 0; i < 7; i++)
			{
				cout << "-----------------------" << DOW(i + 1) << "------------------------" << endl;
				if (week[i].Head_chker())
					cout << "Записей на сегодня нет!" << endl;
				else
					week[i].show_day();
				cout << "------------------------------------------------------" << endl;
			}

		}; break;


		case '3':
		{
			cout << endl << "Введите день: ";
			cin >> day;
			cout << "-------------" << DOW(day) << "---------" << endl;

			if (week[day - 1].Head_chker())
				cout << "Записей на сегодня нет" << endl;
			else
				week[day - 1].show_day();

		}; break;


		case '4':
		{
			cout << "Введите фамилию: ";
			cin >> name;
			cout << "Введите день приема: ";
			cin >> day;
			cout << "Введите время приема: ";
			cin >> time_pass;
			cout << "Введите полис пациента: ";
			cin >> polis;

			week[day - 1].push(day, name, time_pass, polis);
		}; break;

		case '5':
		{

			cout << "Удаление записи" << endl;
			cout << "Введите фамилию пациента, удаляемого из списка: ";
			cin >> name;
			cout << "Введите назначенный день приема: ";
			cin >> day;
			cout << "Введите время приема: ";
			cin >> time_pass;
			cout << "Введите полис пациента: ";
			cin >> polis;
			week[day - 1].pop(day, name, time_pass, polis);
		}; break;


		case '6':
		{
			ofstream f("output.txt");
			for (int i = 0; i < 5; i++)
			{
				f << "-----------------------" << DOW(i + 1) << "------------------------" << endl;
				if (week[i].Head_chker())
					f << "Записей на сегодня нет!" << endl;
				else
					week[i].File_Save(f);
				f << "------------------------------------------------------" << endl;
			}

			f.close();
			cout << "Расписание успешно сохранено в файл!" << endl;
		}; break;

		default:
		{
			cout << "Простите, данной цифры в меню нет. Попробуйте ещё раз.";
		}; break;
		};

		cout << endl << "Введите пункт меню." << endl;
		k = _getch();
		cout << endl;
	}

	return 0;
}

string DOW(int D)
{
	switch (D)
	{
	case 1: return "Понедельник"; break;
	case 2: return "Вторник"; break;
	case 3: return "Среда"; break;
	case 4: return "Четверг"; break;
	case 5: return "Пятница"; break;
	case 6: return "Суббота"; break;
	case 7: return "Воскресенье"; break;
	default: return "Такого дня недели нет.";
	}
}

void show_menu()
{
	cout << "Работа расписания пациентов:" << endl;
	cout << endl;
	cout << "1. Формирование расписания с файла." << endl;
	cout << "2. Показать расписание на неделю." << endl;
	cout << "3. Показать расписание конкретного дня." << endl;
	cout << "4. Добавить запись." << endl;
	cout << "5. Удалить запись." << endl;
	cout << "6. Сохранить расписание в файл." << endl;
}