#include "Stack.h"

Stack::Stack() : top{ EMPTY } {}

void Stack::Clear()
{
	top = EMPTY;
}

bool Stack::IsEmpty()
{
	return top == EMPTY;
}

bool Stack::IsFull()
{
	return top == FULL;
}

int Stack::GetCount()
{
	return top + 1;
}

void Stack::Push(char c)
{
	if (!IsFull())
	{
		mas[++top] = c;
	}
}

void Stack::Print()
{
	// как я прочитала, энд л (догадываюсь что означает эндлайн)
	// выводить строку без мусорного значения, я дописала его ведь
	// при прошлых тестах выводился ъвост из мусора
	cout << mas << endl;
}

char Stack::Pop()
{
	if (!IsEmpty())
	{
		return mas[top--];
	}
	else
	{
		return 0;
	}
}

// (полное обьяснение алгоритма описано в ридми файле)

string Stack::Correct()
{
	// массив содержащий закрывающиеся скобочки для проверки
	char* buff_mass = new char[FULL];
	// строка (mas till uncorrect) которая содержит строку стека до первой ошибки
	string mas_till_unc;
	// строка которая содержит значение возвращаемое в случае правильного выполнения программы
	// ( я пыталась возвращать 0, нуллптр и константную строку, но не выходило, поэтому
	// расточительствую память как могу
	string correct = "correct";
	// счётчик 1 для массива со скобками, а второй для возвращаемого в случае неправильной расстановке
	int count = 0, count_for_unc = 0;

	for (char buff : mas)
	{
		mas_till_unc.push_back(buff);
		switch (buff)
		{
		case '(':
		{
			buff_mass[++count] = ')';
			break;
		}
		case '[':
		{
			buff_mass[++count] = ']';
			break;
		}
		case '{':
		{
			buff_mass[++count] = '}';
			break;
		}

		case ')':
		{
			if (buff_mass[count] != buff)
			{
				cout << "\nРасстановка скобок неверна.\nМассив до первой ошибки: " << mas_till_unc;
				return mas_till_unc;
			}

			count--;
			break;
		}
		case ']':
		{
			if (buff_mass[count] != buff)
			{
				return mas_till_unc;
			}

			count--;
			break;
		}
		case '}':
		{
			if (buff_mass[count] != buff)
			{
				return mas_till_unc;
			}

			count--;
			break;
		}

		}
	}

	return correct;
}