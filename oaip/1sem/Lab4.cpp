#include <iostream>
#include <cmath>

double fRand(double fMin, double fMax);

int main()
{
    srand(time(0));

    while (true) 
    {
        int n;
        int option;
        int errorInCondition = 0;
        double randMin = -10.0;
        double randMax = 10.0;
        double sum = 0.0;
        double* arr;

        do
        {
            if (errorInCondition != 0)
                std::cout << "Error in input! Value must be 0 < n < 21" << std::endl;

            std::cout << "Input n: ";
            std::cin >> n;
            ++errorInCondition;

            if (n > 0 && n <= 20)
                break;
        } while (true);

        arr = new double[n];

        std::cout << "Type '1' if you want to use random numbers: ";
        std::cin >> option;

        for (int i = 0; i < n; ++i)
        {
            if (option != 1)
            {
                std::cout << "a[" << i + 1 << "] = ";
                std::cin >> arr[i];
            }
            else
            {
                arr[i] = fRand(randMin, randMax);
            }
        }

        std::cout << "Array: ";
        for (int i = 0; i < n; ++i)
        {
            if (n - i == 1)
            {
                std::cout << arr[i] << ".\n";
                break;
            }

            std::cout << arr[i] << ", ";
        }

        double firstNum;
        bool firstGEZero = false;
        bool canSum = false;
        for (int i = 0; i < n; ++i)
        {
            sum += arr[i];
            if (i == 0)
            {
                firstNum = arr[i];
                if (firstNum >= 0)
                    firstGEZero = true;

                continue;
            }

            if ((arr[i] < 0 && firstGEZero) || (arr[i] > 0 && !firstGEZero))
            {
                canSum = true;
                break;
            }
        }

        if (canSum)
        {
            printf("Sum = %.2f\n", sum);
        }
        else
        {
            printf("Sum cannot be calculated for this array\n");
        }

        std::cout << "Type '1' to restart program: ";
        std::cin >> option;

        if (option != 1)
            break;
    }

    return 0;
}

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}