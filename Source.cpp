#include "Stack.h"

void main()
{
	setlocale(LC_ALL, "Russian");

	Stack obj1;

	char mas_P[] = { "({x-y-z}*[x+2y]-(z+4x))" };

	for (int i = 0; i < 10; i++)
	{
		obj1.Push(mas_P[i]);
	}

	obj1.Print_Res(obj1.Correct());
}