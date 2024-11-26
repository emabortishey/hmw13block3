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
	cout << mas;
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

bool Stack::Correct()
{
	for (char buff : mas)
	{
		switch (buff)
		{
		case '(':
		{
			Push(')');
			break;
		}
		case '[':
		{
			Push(']');
			break;
		}
		case '{':
		{
			Push('}');
			break;
		}

		case ')':
		{
			if (IsEmpty() || mas[top] != buff)
			{
				return false;
			}

			Pop();
			break;
		}
		case ']':
		{
			if (IsEmpty() || mas[top] != buff)
			{
				return false;
			}

			Pop();
			break;
		}
		case '}':
		{
			if (IsEmpty() || mas[top] != buff)
			{
				return false;
			}

			Pop();
			break;
		}

		}
	}

	return true;
}

void Stack::Print_Res(bool res)
{
	cout << (res == true ? "Расстановка скобок верна" : "Расстановка скобок неправильна.");
}