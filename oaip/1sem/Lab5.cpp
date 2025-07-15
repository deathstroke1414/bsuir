#include <iostream>

double fRand(double fMin, double fMax);

int main()
{
	srand(time(0));
	while (true)
	{
		int n;
		int m;
		int option;
		int errorCondition = 0;
		double randMin = -10.0;
		double randMax = 10.0;
		double** arr;

		do
		{
			if (errorCondition != 0)
				std::cout << "Input error! N & M must be positive numbers!\n";

			std::cout << "Input n: ";
			std::cin >> n;

			std::cout << "Input m: ";
			std::cin >> m;

			if (n > 0 && m > 0)
				break;

			++errorCondition;
		} while (true);

		arr = new double* [n];
		for (int i = 0; i < n; ++i)
			arr[i] = new double[m];

		std::cout << "Type '1' if you want to use random numbers: ";
		std::cin >> option;

		std::cout << "Old array\n";

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (option != 1)
				{
					std::cout << "a[" << i + 1 << "][" << j + 1 << "] = ";
					std::cin >> arr[i][j];
				}
				else
				{
					arr[i][j] = fRand(randMin, randMax);
				}

				printf("%.2f\t", arr[i][j]);
			}

			std::cout << std::endl;
		}

		int i = 0;
		while (i < n - 1)
		{
			double* buffRow = arr[i];

			if (arr[i][0] > arr[i + 1][0])
			{
				arr[i] = arr[i + 1];
				arr[i + 1] = buffRow;
				i = 0;
			}
			else
			{
				++i;
			}
		}

		std::cout << "New array\n";

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				printf("%.2f\t", arr[i][j]);

			std::cout << std::endl;
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