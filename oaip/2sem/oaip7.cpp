//Написать и отладить программу поиска всех корней функции f(x) на отрезке[a, b].
//Метод нахождения корня оформить в виде отдельной функции.
// Вид функции f(x)	а	b	Заданный метод
//  sin(x)^2-x/5-1  –4	0	Метод секущих

#include <iostream>
#include <cmath>

using namespace std;

double foo(double x)
{
	return pow(sin(x), 2) - x / 5 - 1;
}

void meth_sec(double x1, double x2, double E)
{
    float xm, x0, c;
    if (foo(x1) * foo(x2) < 0) {
        do {
            x0 = x2 - (foo(x2) * (x2 - x1)) / (foo(x2) - foo(x1));
            c = foo(x1) * foo(x0);
            x1 = x2;
            x2 = x0;
            if (c == 0)
                break;
            xm = x2 - (foo(x2) * (x2 - x1)) / (foo(x2) - foo(x1));
        } while (fabs(xm - x0) >= E); 
        cout << "Корень уравнения = " << x0 << endl;
    }
    else
        cout << "Нет корня на данном отрезке!" << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
    double a, b, eps = 0.01, h=0.01;
    cout << "Введите начало отрезка:";
    cin >> a;
    double x = a;
    cout << "Ввелите конец отрезка:";
    cin >> b;
    while (x <= b)
    {
        if(foo(x)*foo(x+h)<0)
        meth_sec(x, x+h, eps);
        x += h;
    }
}