#include "Stack.h"

void main()
{
	setlocale(LC_ALL, "Russian");

	Stack obj1;

	char mas_P1[24] = { "([x-y-z}*[x+2y)-{z+4x)]" };

	for(char elem : mas_P1)
	{
		obj1.Push(elem);
	}

	if (obj1.Correct() == "correct")
	{
		cout << "\nРасстановка скобок верна.";
	}
	else
	{
		cout << "\nРасстановка скобок неверна.\nСтрока до первой ошибки: " << obj1.Correct();
	}

	cout << "\nСама строка: ";
	obj1.Print();
	
	


	Stack obj2;

	char mas_P2[24] = { "({x-y-z}*[x+2y]-(z+4x))" };

	for (char elem : mas_P2)
	{
		obj2.Push(elem);
	}

	if (obj2.Correct() == "correct")
	{
		cout << "\nРасстановка скобок верна.";
	}
	else
	{
		cout << "\nРасстановка скобок неверна.\nМассив до первой ошибки: " << obj2.Correct();
	}

	cout << "\nСама строка: ";
	obj2.Print();
}

