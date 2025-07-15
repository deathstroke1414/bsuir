#include <iostream>
#include <string>
#include <fstream>

std::string encryptMessage(std::string message);
std::string decryptMessage(std::string message);
bool saveMessageToFile(std::string message, std::string filePath);
std::string readMessageFromFile(std::string filePath);

int main()
{
	setlocale(LC_ALL, "ru");

	do
	{
		const std::string filePath = ".\\MyMessageFile.txt";
		std::string testMessage = "съешьте еще этих мягких французских булок да выпейте чаю";
		std::string message = testMessage;
		std::string readedMessage;
		int option;

		std::cout << "Type '1' to use test message (\'съешьте еще этих мягких французских булок да выпейте чаю\'): ";
		std::cin >> option;

		if (option != 1)
			std::getline(std::cin, message);

		std::string encryptedMessage = encryptMessage(testMessage);
		saveMessageToFile(encryptedMessage, filePath);
		readedMessage = readMessageFromFile(filePath);

		std::cout << "Message: " << testMessage << std::endl;
		std::cout << "Encrypted message: " << encryptedMessage << std::endl;
		std::cout << "Message in file: " << readedMessage << std::endl;
		std::cout << "DecryptedMessage: " << decryptMessage(readedMessage) << std::endl;

		std::cout << "Type '1' to restart program: ";
		std::cin >> option;

		if (option != 1)
			break;
	} while (true);

	return 0;
}

std::string encryptMessage(std::string message)
{
	std::string pattern = "уеыаоэяиюё";
	std::string encryptedMessage = "";

	for (int i = 0; i < message.size(); ++i)
	{
		encryptedMessage.push_back(message[i]);
		for (int j = 0; j < pattern.size(); ++j)
		{
			if (message[i] == pattern[j])
			{
				encryptedMessage.push_back('с');
				break;
			}
		}
	}

	return encryptedMessage;
}

std::string decryptMessage(std::string message)
{
	std::string pattern = "уеыаоэяиюё";
	std::string decryptedMessage = "";
	bool isCryptedSegment = false;

	for (int i = 0; i < message.size(); ++i)
	{
		if (isCryptedSegment)
		{
			isCryptedSegment = false;
			continue;
		}

		decryptedMessage.push_back(message[i]);

		for (int j = 0; j < pattern.size(); ++j)
		{
			if (message[i] == pattern[j] && message[i + 1] == 'с')
			{
				isCryptedSegment = true;
			}
		}
	}

	return decryptedMessage;
}

bool saveMessageToFile(std::string message, std::string filePath)
{
	std::ofstream out(filePath);

	if (!out.is_open())
		return false;

	out << message << std::endl;
	return true;
}

std::string readMessageFromFile(std::string filePath)
{
	std::string rawData;
	std::ifstream in(filePath);

	if (!in.is_open())
		return "Error while reading file!";

	std::getline(in, rawData);
	return rawData;
}