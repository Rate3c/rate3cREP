#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void intMas1(int arr[], int size)
{
	int TO, FROM;
	cout << "Введите начало промежутка: ";
	cin >> FROM;
	cout << "Введите конец промежутка: ";
	cin >> TO;
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = FROM + rand() % (TO - FROM + 1);
	}
}
// заполнение элементов массива случайными числами
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
// swap
void showmas(int arr[], int size)
{
	cout << "Случайно сгенерированный массив: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << " " << arr[i];
	}
	cout << endl;
}			
// показать введенный массив	
void bubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
// bubble sort
void showBubble(int arr[], int size)
{
	cout << "Массив, отсортированный методом \"пузырька\": " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << " " << arr[i];
	}
	cout << endl;
}
// показать отсортированный массив
void intMas2(int arr[], int size)
{
	int TO, FROM;
	cout << "Введите начало промежутка: ";
	cin >> FROM;
	cout << "Введите конец промежутка: ";
	cin >> TO;
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = FROM + rand() % (TO - FROM + 1);
	}
}
// заполнение второго массива случайными числами
void selectionSort(int* arr, int size)
{
	int i, j, imin;
	for (i = 0; i < size - 1; i++)
	{
		imin = i; // индекс мин. значения
		for (j = i + 1; j < size; j++)
		{
			if (arr[j] > arr[imin])
			{
				imin = j;
			}
		}
		swap(arr[i], arr[imin]);
	}
}
// выборочная сортировка
void showSelectSort(int arr[], int size)
{
	cout << "Отсортированный выборочным методом массив: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << " " << arr[i];
	}
	cout << endl;
}
// показать отсортированный массив выборочным методом

int main()
{
	setlocale(LC_ALL, "rus");
	const int size = 16;
	int arr[size];
	intMas1(arr, size);
	showmas(arr, size);
	bubbleSort(arr, size);
	showBubble(arr, size);
	intMas2(arr, size);
	showmas(arr, size);
	selectionSort(arr, size);
	showSelectSort(arr, size);
	cout << endl;
	system("pause");
}
