#include <iostream>
#include <string>

double findDoubleIfConsists(std::string message);

int main()
{
    do
    {
        std::string testMessage = "jishd8.fyu2.hbdu2b33,4423+d3w2d-dw0";
        std::string message = testMessage;
        double doubleFromMessage;
        int option;

        std::cout << "Type '1' to use test message(\'jishd8.fyu2.hbdu2b33,4423+d3w2d-dw0\'): ";
        std::cin >> option;

        if (option != 1)
            std::getline(std::cin, message);

        doubleFromMessage = findDoubleIfConsists(testMessage);

        std::cout << "Your message: " << message << std::endl;
        std::cout << "founded number: " << doubleFromMessage << std::endl;
        printf("Rounded number: %.2f\n", doubleFromMessage);

        std::cout << "Type '1' to restart program: ";
        std::cin >> option;

        if (option != 1)
            break;

    } while (true);
    
    return 0;
}

double findDoubleIfConsists(std::string message)
{
    std::string resultStr;
    std::string str = message;
    bool flag = 1;

    if (str[0] == '.')
    {
        str[0] = ' ';
    }

    for (size_t i = 0; i < str.length(); ++i)
    {
        if ((int)str[i] >= 48 && (int)str[i] <= 57)
        {
            resultStr += str[i];
        }
        else if (str[i] == '.' && flag == 1)
        {
            resultStr += str[i];
            flag = 0;
        }
    }

    if (resultStr.empty())
        return 0.0;

    return atof(resultStr.c_str());
}