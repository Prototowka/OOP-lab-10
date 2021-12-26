#include <iostream>
#include <locale>
#include <time.h>
#include <math.h>

using namespace std;

void Zadanie1MasA(float a, float b, float dx)//Начало интервала, конец интервала, шаг
{
	int length = (b - a + 1) / dx;
	float *masA = new float[length];
	float  digit, x = a;
	int i;

		for (i = a; i < length; i++)
		{
			digit = x - 1;

			try {

				if (digit > 0)
				{
					masA[i] = log(digit);
					cout << masA[i] << endl;
				}
				else
				{
					throw exception("incorect data");
				}
			}

			catch (const exception& ex)
			{
				cout << ex.what() << endl;
				masA[i] = 0;
			}
			x += dx;
		}
}

void Zadanie1MasB(int count)
{
	int i, condition;
	srand(time(NULL));

	for (i = 0; i < count; i++)
	{
		condition = rand() % 3 + 0;
		if (condition == 0) { cout << rand() % 100 * 0 << endl; }
		if (condition == 1) { cout << rand() % 100 * 1 << endl; }
		if (condition == 2) { cout << rand() % 100 * -1 << endl; }
	}
}

void Zadanie1MasC(int count)
{
	double x;
	int y, z, i, conditionY, conditionZ, paramY, paramZ;
	srand(time(NULL));

	for (i = 0; i < count; i++)
	{
			conditionY = rand() % 3 + 0;
			if (conditionY == 0) { paramY = 0; }
			if (conditionY == 1) { paramY = -1; }
			if (conditionY == 2) { paramY = 1; }

			conditionZ = rand() % 3 + 0;
			if (conditionZ == 0) { paramZ = 0; }
			if (conditionZ == 1) { paramZ = -1; }
			if (conditionZ == 2) { paramZ = 1; }

			y = (rand() % 100) * conditionY;
			z = (rand() % 100) * conditionZ;

			try {
				if (z != 0)
				{
					x = y + (1 / z);
					cout << x << endl;
				}
				else
					throw exception("incorect data");
				}
			catch (const exception& ex)
			{
				cout << ex.what() << endl;
			}
	}
}

void Zadanie2(int count)
{
	int* systema = new int[count];
	int i, decimalNumber = 0, buf;

	srand(time(NULL));

	cout << "Случайно сгенерированное двоичное число:";
	for (i = 0; i < count; i++)
	{
		systema[i] = rand() % 2 + 0;
		cout << systema[i];
	}

	cout << endl;

	for (i = 0 ; i < count / 2; i++)
	{
		buf = systema[i];
		systema[i] = systema[count - 1 - i];
		systema[count - 1 - i] = buf;
	}

	for (i = 0; i < count; i++)
	{
		decimalNumber += systema[i] * pow(2, i);
	}
	cout<< "Промежуточное значения числа в десятичной системе:" << decimalNumber << endl;

	int chislo = 0, reverse = 0;

	while (decimalNumber !=0)
	{
		chislo += decimalNumber % 3;
		chislo *= 10;
		decimalNumber /= 3;
	}

	while (chislo)
	{
		reverse += chislo % 10;
		chislo /= 10;
		reverse *= 10;
	}
	cout << "Значение в троичной системе счисления:" << reverse << endl;
}

float FunctionZ1(float& m)
{
	try
	{
		if (m > 0 || (pow(m, 2) - 4) > 0)
		{
			float Z1 = (sqrt((m)+2 * sqrt(pow(m, 2) - 4))) / (m + sqrt(pow(m, 2) - 4) + 2);
			return Z1;
		}
		else
		{
			throw exception("Невозможно посчитать корень : отрицательное число под корнем \n");
		}
	}
	catch (const exception& ex)
	{
		cout << ex.what();
		return NULL;
	}
}

float FunctionZ2(float& m)
{
	try
	{
		float Z2;
		if (m >= 0)
		{
			Z2 = 1 / (sqrt(m + 2));
			return Z2;
		}
		else
		{
			throw exception("Невозможно получить корень : отрицательное число под знаком корня\n");
		}
	}
	catch (const exception& ex)
	{
		cout << ex.what();
		return NULL;
	}
}


int main()
{
	setlocale(LC_ALL, "ru");
	cout << "	Задние №1 MasA" << endl;
	Zadanie1MasA(0, 10, 0.5);
	cout << "	Задние №1 MasB" << endl;
	Zadanie1MasB(10);
	cout <<	"	Задние №1 MasC" << endl;
	Zadanie1MasC(10);

	cout << "Задание №2" << endl;
	int count;
	cout << "Введите кол-во символов в вашем числе" << endl;
	cin >> count;
	Zadanie2(count);

	cout << "Задание №3" << endl;
	float a, b;
	cout << "Введите значение a для функции Z1 : " << endl;
	cin >> a;
	cout << "Введите значение b для функции Z2 : " << endl;
	cin >> b;
	cout << FunctionZ1(a) << endl;
	cout << FunctionZ2(b) << endl;

	return 0;
}