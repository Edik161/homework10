// Homework_10.cpp: определяет точку входа для приложения.
//

#include "homework_10.h"
#include <iostream>
#include <limits>
#include <gsl/gsl>


using namespace std;
//task1
void read(double* value) 
{
    do {
        cout << "Введите сумму в рублях (положительное число): ";
        cin >> *value; 
        if (0 > *value ) 
        {
            cout << "Ошибка! Сумма не может быть отрицательной." << "\n";
        }
    } while (0 > *value );
}
double* convert(gsl::not_null<double*> rubles) 
{
    const double Dublon = 3.14;
    *rubles = *rubles * Dublon;
    return rubles;
}
void show(gsl::not_null<double*>dubblons) 
{
    cout << "Результат конвертации: " << *dubblons << " дублонов" << "\n";
}
//task3
void read(gsl::not_null<int*> arr, int size) 
{
    srand(time(0));
    for (int i = 0; i < size; i++) 
    {
        arr.get()[i] = rand() % 100; 
    }
}
void zamena(gsl::not_null<int*> arr, int size) 
{
    for (int i = 0; i < size/2; i++) 
    {
        std::swap(arr.get()[i], arr.get()[size - 1 - i]);
    }
}
void show(gsl::not_null<int*> arr, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr.get()[i] << " ";
    }
    cout <<"\n";
}
//task4
void reads(gsl::not_null<int*> arr, int size) 
{
    cout << "Введите " << size << " элементов массива: ";
    for (int i = 0; i < size; i++) 
    {
        cin >> arr.get()[i];
    }
}

int* add(gsl::not_null<int*> arr, int& size, int val) 
{
    int* newArr = new int[size + 1];
  
    for (int i = 0; i < size; i++) 
    {
        newArr[i] = arr.get()[i];
    }
    
    newArr[size] = val;
    size++;
    
    delete[] arr;
    
    return newArr;
}
void shows(gsl::not_null<int*> arr, int size) 
{
    cout << "Массив: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr.get()[i] << " ";
    }
    cout << "\n";
}

int main()
{
	setlocale(LC_ALL, "Rus");
	/*task1
		Переводим рубли на лилипутскую валюту. 1 рубль = 3.14 дублонов.
Если пользователь ввел отрицательное значение, то просим ввести его заново.
Требуется использовать динамическую память для хранения введенного
значения.*/
	double* value = new double;
    
    read(value);
    value = convert(value); 
    show(value);    
    
    delete value;
    
    /*task2
        В одномерном динамическом массиве посчитать сумму кратных 6
чисел. Переменная для суммы должна находится в куче. Заполняем массив как
хотим. (Не забудьте очистить память)*/
    
    /*rand(time(0));
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    
    int* arr = new int[size];
    int* sum = new int(0);
    
    cout << "Массив: ";
    for (int i = 0; i < size; i++) 
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
        if (arr[i] % 6 == 0) 
        {
            *sum += arr[i];
        }
    }
    
    cout << "\nСумма элементов, кратных 6: " << *sum << "\n";
    
    delete[] arr;
    delete sum;*/
    
    /*task3
        Напишите функцию reverse, которая переворачивает одномерный
динамическом массиве.(Реализуйте функцию заполнения, переворота и вывода)*/
   
    /*int size;
    cout << "Введите размер массива: ";
    cin >> size;
    
    int *arr = new int[size];
    
    read(arr, size);
    cout << "Исходный массив: ";
    show(arr, size); 
    
    zamena(arr, size);
    cout << "Перевернутый массив: ";
    show(arr, size); 
    
    delete[] arr; */

    /*task4
        Напишите возвратную функцию добавления в конец введенного
элемента. (Дин массив)*/
     /*int size;
    cout << "Введите размер массива: ";
    cin >> size;
    
    int* arr = new int[size];
    
    reads(arr, size);
    int val;
    cout << "Введите значение для добавления: ";
    cin >> val;
    
    arr = add(arr, size, val);
    
    shows(arr, size);
    
    delete[] arr;*/

	return 0;
}
