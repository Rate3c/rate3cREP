#include <iostream>
#include <locale>
#include <iomanip>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
	const int DIM = 6, del = 3;
	setlocale(LC_ALL, "rus");
	using vec2d = vector < vector < double >>;
	double N, inpt, mul = 1.0;
	bool digit(false);
	while (!digit)
	{
		cout << "Введите целочисленный размер матрицы меньше 6: ";
		cout << "\n";
		cin >> N;
		if (N == (long long)N)				// Проверка на целочисленность 
		{
			if ((N > 0) && (N < DIM))
			{
				digit = true;
			}
			else
			{
				cout << "Неверный ввод!" << endl;
				cout << "\n";
			}
		}
		else
		{
			cout << "Неверный ввод!" << endl;
			cout << "\n";
		}
	}
	cout << "Введите элементы матрицы: ";
	cout << "\n";
	vec2d matrix(N);

	for (int rows = 0; rows < N; rows++)
	{
		for (int col = 0; col < N; col++)
		{
			cin >> inpt;
			if ((((rows + 1) + (col + 1)) % del) == 0)
			{
				mul *= inpt;
			}

			matrix[rows].push_back(inpt);
		}
	}
	double min = matrix[0][0], max = matrix[0][0];
	for (int rows = 0; rows < N; rows++)
	{
		for (int col = 0; col < N; col++)
		{
			if (matrix[rows][col] < min)
				min = matrix[rows][col];
			if (matrix[rows][col] > max)
				max = matrix[rows][col];
		}
	}
	cout << "Введенная матрица: " << endl;
	for (auto line : matrix)
	{
		for (auto element : line)
		{
			cout << setw(6) << element << " ";
		}
		cout << endl;
	}
	for (int rows = 0; rows < N; rows++)
	{
		for (int col = 0; col < N; col += 2)
		{
			for (int iter = 0; iter < N; iter++)
			{
				matrix[iter][col] = matrix[col][col];
			}
		}
	}
	cout << "ЗАДАНИЕ 1." << endl;
	cout << "Полученная матрица: " << endl;
	for (auto line : matrix)
	{
		for (auto element : line)
		{
			cout << setw(6) << element << " ";
		}
		cout << endl;
	}
	cout << "ЗАДАНИЕ 2." << endl;
	cout << "Произведение элементов, у которых i+j кратно 3:" << endl << mul << endl;
	cout << "Разность наибольшего и наименьшего элемента матрицы:" << endl << max - min << endl;
	cout << "Работу выполнил студент гр.0301 ФКТИ Нестеров Евгений (Вариант 12)." << endl;
	cout << "Hello World!";
	cout << endl;
	system("pause");
	return 0;
}