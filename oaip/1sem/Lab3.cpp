#include <iostream>
#include <cmath>
#include <string.h>

const double PI = 3.1415926;

const double test_a = 0.1;
const double test_b = 1.0;
const double test_h = 0.1;

double S(int n, double x);
double Y(double x);

int main()
{


    for (int i = 0; i < 10; i++)
    {
        std::cout << ++i << std::endl;
    }

    std::cout << "----------" << std::endl;

    for (int i = 0; i < 10; ++i)
    {
        std::cout << i++ << std::endl;
    }


    while (true)
    {
        double a;
        double b;
        double h;
        int n;
        int option = 0;

        std::cout << "Type '1' if you want to use test variables (a = 0.1, b = 1.0, h = 0.1): ";
        std::cin >> option;
        if (option != 1)
        {
            std::cout << "Input a: ";
            std::cin >> a;

            std::cout << "Input b: ";
            std::cin >> b;

            std::cout << "Input h: ";
            std::cin >> h;
        }
        else 
        {
            a = test_a;
            b = test_b;
            h = test_h;
        }

        std::cout << "Input n: ";
        std::cin >> n;

        double x = a;
        int header = 0;
        while (true)
        {
            double s = S(n, x);
            double y = Y(x);
            double absolute = abs(y - s);

            if (header == 0) 
            {
                printf("+===============+===============+===============+===============+\n");
                printf("| x\t\t| S(x)\t\t| Y(x)\t\t| |Y(x) - S(x)|\t|\n");
                printf("+===============+===============+===============+===============+\n");
                header = 1;
            }

            //if (round(absolute * 1000) / 1000 >= a / 100.0)
            //    continue;
            
            printf("| %.4f\t| %.4f\t| %.4f\t| %.4f \t|\n", x, s, y, absolute);

            x += h;
            x = round(x * 10000) / 10000;
            if (x > b)
            {
                printf("+===============+===============+===============+===============+\n");
                break;
            }

            printf("|---------------+---------------+---------------+---------------|\n");
        }

        std::cout << "To continue type '1': ";
        std::cin >> option;

        if (option != 1)
            break;
    }
    
    return 0;

    
}

double S(int n, double x)
{
    double sum = 0;
    for (int i = 1; i <= n; ++i) 
        sum += (pow(x, i) * cos((i * PI) / 3)) / i;

    return sum;
}

double Y(double x) 
{
    return (-1.0 / 2) * log(1 - 2 * x * cos(PI / 3) + pow(x, 2));
}