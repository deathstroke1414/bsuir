/*8. Для книг, хранящихся в библиотеке, задаются: номер книги, автор, название, 
год издания, издательство и количество страниц. 
Вывести список книг с фамилиями авторов в алфавитном порядке,
изданных после заданного года. Ключ: автор.*/

#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;
struct books
{
    
    int number;
    char title[50];
    char author[30];
    int year;
    int pages;
}*arr,*mas;
int read(struct books *arr,int n)
{
    ifstream file("books.txt");
    if (file.is_open())
        for (int i = 0; i < n; i++)
        {
            file >> arr[i].number;
            file >> arr[i].title;
            file >> arr[i].author;
            file >> arr[i].year;
            file >> arr[i].pages;
        }
    else
    {
        cout << "Файл не открыт!\n\n" << endl;
        return -1;
    }
    return 0;
}
int straightsort(struct books* arr,struct books* mas, int n)
{
    cout << endl << "Книги, выпущенные после заданного года, и их авторы в алфавитном порядке:" << endl;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(arr[i].author, arr[j].author) > 0)
            {
                mas[0] = arr[i];
                arr[i] = arr[j];
                arr[j] = mas[0];
            }
    return 0;
}
int quicksort(struct books* arr, struct books* mas, int n)
{
    cout << endl << "Книги, выпущенные после заданного года, и их авторы в алфавитном порядке:" << endl;
    int i = 0;
    int j = n - 1;
     char* x = arr[(0 + n) / 2].author;
    while (i <= j) {
        while (strcmp(arr[i].author,x) < 0)  i++;
        while (strcmp(arr[j].author, x) > 0)  j--;
        if (i <= j) {
            mas[0] = arr[i];
            arr[i] = arr[j];
            arr[j] = mas[0];
            i++; 		j--;
        }
    }
    
    return 0;
}
int linefinder(struct books* arr, int n, int year)
{
    int kod = 0;
    for (int i = 0; i < n; i++)
        if (arr[i].year >= year)
        {
            kod = 1;
            cout << arr[i].title << " " << arr[i].author << endl;

        }
    if (kod == 0)
        return -1;
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, year;
    cout << "Количество рассматриваемых книг(<11):";
    cin >> n;
    if (n>10)
    {
        cout << "Ошибка!" << endl;
        return main();
    }
    arr = new books[n];
    mas = new books[n];
    read(arr,n);
    cout << "Все имеющиеся книги:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i].number << " " << arr[i].title << " " << arr[i].author << " " << arr[i].year << " " << arr[i].pages << endl;
    cout << "Введите год начала издания:";
    cin >> year;
    int vibor;
    cout << "Выберите способ сортировки: 1 - прямой выбор, 2 - QuickSort " << endl;
    cin >> vibor;
    switch (vibor)
    {
    case 1:
    {
        straightsort(arr, mas, n);
        break;
    }
    case 2:
    {
        quicksort(arr, mas, n);
        break;
    }
    default:
    {
        break;
        return -1;
    }
    }
    linefinder(arr, n, year);
    delete[]arr;
    delete[]mas;
}
