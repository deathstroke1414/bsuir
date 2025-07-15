#include <iostream>

double recursiveSqrt(double a);
double recursiveSqrt(double a, int n);

int main()
{
    int option;
    int errorCondition = 0;
    double a;

    while (true)
    {
        do
        {
            if (errorCondition != 0)
                std::cout << "Input error! Value must be positive!\n";

            std::cout << "Input a: ";
            std::cin >> a;

            if (a < 0) 
            {
                ++errorCondition;
                continue;
            }

            break;
        } while (true);

        printf("Sqrt(a) = %.2f\n", sqrt(a));
        printf("RecSqrt(a) = %.2f\n", recursiveSqrt(a));

        std::cout << "Type '1' to restart program: ";
        std::cin >> option;

        if (option != 1)
            break;
    }

    return 0;
}

double recursiveSqrt(double a)
{
    return recursiveSqrt(a, a);
}

double recursiveSqrt(double a, int n)
{
    if (n > 0)
    {
        double prevVal = recursiveSqrt(a, n - 1);
        return 0.5 * (prevVal + a / prevVal);
    }
    else
    {
        return 0.5 * (1 + a);
    }
}