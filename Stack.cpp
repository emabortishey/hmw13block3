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

string Stack::Correct()
{
	char* buff_mass = new char[FULL];
	string mas_till_unc;
	string correct = "correct";
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