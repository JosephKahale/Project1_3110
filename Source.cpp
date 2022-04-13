//Joseph Kahale
//CS 3110.02
//Professor Huong

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>

//double parseDtoS(std::string) {
//
//	std::map<std::string, int> lang;
//	lang.insert(std::pair<std::string, int>("0", 0));
//	lang.insert(std::pair<std::string, int>("1", 1));
//	lang.insert(std::pair<std::string, int>("2", 2));
//	lang.insert(std::pair<std::string, int>("3", 3));
//	lang.insert(std::pair<std::string, int>("4", 4));
//	lang.insert(std::pair<std::string, int>("5", 5));
//	lang.insert(std::pair<std::string, int>("6", 6));
//	lang.insert(std::pair<std::string, int>("7", 7));
//	lang.insert(std::pair<std::string, int>("8", 8));
//	lang.insert(std::pair<std::string, int>("9", 9));
//	lang.insert(std::pair<std::string, int>("e", 10));
//	lang.insert(std::pair<std::string, int>("E", 10));
//	lang.insert(std::pair<std::string, int>(".", 11));
//
//
//}

int main() {
	int count = 0;
	std::string number;
	std::cout << "Please enter the input: " << std::endl;
	std::cin >> number;
	std::vector<char> one;

	//double nums;
	//nums = parseDtoS(number);

	for (int i = 0; i < number.length(); i++) {
		switch (number[i])
		{
		case '0':
			one.push_back('0');
			count++;
			break;

		case '1':
			one.push_back('1');
			count++;
			break;

		case '2':
			one.push_back('2');
			count++;
			break;

		case '3':
			one.push_back('3');
			count++;
			break;

		case '4':
			one.push_back('4');
			count++;
			break;

		case '5':
			one.push_back('5');
			count++;
			break;

		case '6':
			one.push_back('6');
			count++;
			break;

		case '7':
			one.push_back('7');
			count++;
			break;
			
		case '8':
			one.push_back('8');
			count++;
			break;

		case '9':
			one.push_back('9');
			count++;
			break;

		case '.':
			one.push_back('.');
			count++;
			break;

		case 'f':
			one.push_back('f');
			count++;
			break;

		case 'F':
			one.push_back('F');
			count++;
			break;

		case 'e':
			one.push_back('e');
			count++;
			break;

		case 'E':
			one.push_back('E');
			count++;
			break;

		default:

			break;
		}
	}

	//for (int i = 1; i < number.length(); i++) {
	//	one.push_back(number.substr(i - 1, i));
	//	std::cout << one[i] << std::endl;
	//}

}