//Joseph Kahale
//CS 3110.02
//Professor Huong

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <cmath>
#include <stack>

int precidence(char c) {
	if (c == 'e' || c == 'E') {
		return 3;
	}
	else if (c == '/' || c == '*') {
		return 2;
	}
	else if (c == '+' || c == '-') {
		return 1;
	}
	else if (c == '.') {
		return 0;
	}
	else if (c == ' ') {
		return -2;
	}
	else {
		return -1;
	}
}

std::string postFixConverter(std::string eval) {
	std::stack<char> digi;

	std::string final;

	for (int i = 0; i < eval.length(); i++) {
		char c = eval[i];

		if ((c >= '0' && c <= '9') || precidence(c) == 0 || precidence(c) == 3) {
			final += c;
		}
		else if (c == '(') {

			digi.push('(');
		}
		else if (c == ')') {
			final += ' ';

			while (digi.top() != '(') {
				final += digi.top();
				digi.pop();
			}
			digi.pop();

		}
		else if (c == ' ' || c == 'f' || c == 'F' || c == 'd' || c == 'D') {

		}
		else {
			final += ' ';
			while (!digi.empty() && precidence(c) <= precidence(digi.top())) {
					final += digi.top();
					digi.pop();
					final += ' ';
			}

			digi.push(c);

		}
	}

	while (!digi.empty()) {
		final += ' ';

		final += digi.top();
		digi.pop();
	}

	return final;

}

int stateDigitZero(char digit) {
	if (digit == '.') {
		return 1;
	}
	else if (digit >= '0' && digit <= '9') {
		return 2;
	}

	return 3;
} 

int stateDigitOne(char digit) {
	if (digit >= '0' && digit <= '9') {
		return 4;
	}

	return 3;
}

int stateDigitTwo(char digit) {
	if (digit >= '0' && digit <= '9') {
		return 2;
	}
	else if (digit == '.') {
		return 7;
	}
	else if (digit == '_') {
		return 5;
	}
	else if (digit == 'E' || digit == 'e') {
		return 8;
	}
	else if (digit == 'F' || digit == 'f') {
		return 9;
	}
	else {
		return 3;
	}
}

int stateDigitThree(char digit) {
	return 3;
}

int stateDigitFour(char digit) {
	//accept
	if (digit == '_') {
		return (6);
	}
	else if (digit == 'E' || digit == 'e') {
		return 8;
	}
	else if (digit == 'F' || digit == 'f') {
		return 9;
	}
	else if (digit >= '0' && digit <= '9') {
		return 4;
	}

	return 3;
}

int stateDigitFive(char digit) {
	if (digit == '_') {
		return (5);
	}
	else if (digit >= '0' && digit <= '9') {
		return 2;
	}

	return 3;
}

int stateDigitSix(char digit) {
	if (digit == '_') {
		return (6);
	}
	else if (digit >= '0' && digit <= '9') {
		return 4;
	}

	return 3;
}

int stateDigitSeven(char digit){ 
	//accept
	if (digit >= '0' && digit <= '9') {
		return 4;
	}
	else if (digit == 'F' || digit == 'f') {
		return 9;
	}
	else if (digit == 'E' || digit == 'e') {
		return 8;
	}
	return 3;
}

int stateDigitEight(char digit) {
	if (digit >= '0' && digit <= '9') {
		return 11;
	}
	else if (digit == '+' || digit == '-') {
		return 10;
	}

	return 3;
}

int stateDigitNine(char digit) {

	//accept
	return 3;
}

int stateDigitTen(char digit) {
	if (digit >= '0' && digit <= '9') {
		return 11;
	}
	return 3;
}

int stateDigitEleven(char digit) {
	if (digit >= '0' && digit <= '9') {
		return 11;
	}
	else if (digit == '_') {
		return 12;
	}
	else if (digit == 'F' || digit == 'f') {
		return 9;
	}
	return 3;
}

int stateDigitTwelve(char digit) {
	if (digit >= '0' && digit <= '9') {
		return 11;
	}
	else if (digit == '_') {
		return (12);
	}

	return 3;
}

bool mainState(std::string io) {
	int state = 0;
	bool decision = false;
	for (int count = 0; count <= io.length(); count++) {
		switch (state) {
		case 0:
			state = stateDigitZero(io[count]);
			break;
		case 1:
			state = stateDigitOne(io[count]);
			break;
		case 2:
			state = stateDigitTwo(io[count]);
			break;
		case 3:
			return false;
			break;
		case 4:
			decision = true;
			state = stateDigitFour(io[count]);
			break;
		case 5:
			state = stateDigitFive(io[count]);
			break;
		case 6:
			state = stateDigitSix(io[count]);
			break;
		case 7:
			decision = true;
			state = stateDigitSeven(io[count]);
			break;
		case 8:
			state = stateDigitEight(io[count]);
			break;
		case 9:
			decision = true;
			state = stateDigitNine(io[count]);
			break;
		case 10:
			state = stateDigitTen(io[count]);
			break;
		case 11:
			decision = true;
			state = stateDigitEleven(io[count]);
			break;
		case 12:
			state = stateDigitTwelve(io[count]);
			break;
		default:
			return false;
			break;
		}
	}
	return decision;
}

double convertStringToDouble(std::string io) {
	int befCount = 0;
	int befECount = 0;
	int countDecimal = 0;
	int expSign = 1;

	double exponent = 0;
	double result = 0;
	double decimal = 0;

	for (int i = 0; i < io.length(); i++) {
		switch (io[i]) {
		case '0':
			if (befCount != -1) {
				if (befECount != -1) {
					result = result * 10 + 0;
				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 0;
				}
			}
			else if (befCount == -1) {
				if (befECount != -1) {
					decimal = decimal * 10 + 0;
					countDecimal++;
				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 0;
				}
			}
			break;
		case '1':
			if (befCount != -1) {
				if (befECount != -1) {
					result = result * 10 + 1;
					std::cout << result << "`" << std::endl;
				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 1;
				}
			}
			else if (befCount == -1) {
				if (befECount != -1) {
					decimal = decimal * 10 + 1;
					countDecimal++;
				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 1;
				}
			}
			break;
		case '2':
			if (befCount != -1) {
				if (befECount != -1) {
					result = result * 10 + 2;
					std::cout << result << "`" << std::endl;
				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 2;
				}
			}
			else if (befCount == -1) {
				if (befECount != -1) {
					decimal = decimal * 10 + 2;
					countDecimal++;

				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 2;
				}
			}
			break;
		case '3':
			if (befCount != -1) {
				if (befECount != -1) {
					result = result * 10 + 3;
					std::cout << result << "`" << std::endl;
				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 3;
				}
			}
			else if (befCount == -1) {
				if (befECount != -1) {
					decimal = decimal * 10 + 3;
					countDecimal++;

				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 3;
				}
			}
			break;
		case '4':
			if (befCount != -1) {
				if (befECount != -1) {
					result = result * 10 + 4;
				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 4;
				}
			}
			else if (befCount == -1) {
				if (befECount != -1) {
					decimal = decimal * 10 + 4;
					countDecimal++;

				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 4;
				}
			}
			break;
		case '5':
			if (befCount != -1) {
				if (befECount != -1) {
					result = result * 10 + 5;
				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 5;
				}
			}
			else if (befCount == -1) {
				if (befECount != -1) {
					decimal = decimal * 10 + 5;
					countDecimal++;

				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 5;
				}
			}
			break;
		case '6':
			if (befCount != -1) {
				if (befECount != -1) {
					result = result * 10 + 6;
				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 6;
				}
			}
			else if (befCount == -1) {
				if (befECount != -1) {
					decimal = decimal * 10 + 6;
					countDecimal++;

				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 6;
				}
			}
			break;
		case '7':
			if (befCount != -1) {
				if (befECount != -1) {
					result = result * 10 + 7;
				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 7;
				}
			}
			else if (befCount == -1) {
				if (befECount != -1) {
					decimal = decimal * 10 + 7;
					countDecimal++;

				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 7;
				}
			}
			break;
		case '8':
			if (befCount != -1) {
				if (befECount != -1) {
					result = result * 10 + 8;
				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 8;
				}
			}
			else if (befCount == -1) {
				if (befECount != -1) {
					decimal = decimal * 10 + 8;
					countDecimal++;

				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 8;
				}
			}
			break;
		case '9':
			if (befCount != -1) {
				if (befECount != -1) {
					result = result * 10 + 9;
				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 9;
				}
			}
			else if (befCount == -1) {
				if (befECount != -1) {
					decimal = decimal * 10 + 9;
					countDecimal++;

				}
				else if (befECount == -1) {
					exponent = exponent * 10 + 9;
				}
			}
			break;
		case '+':
			break;
		case '-':
			expSign = -1;
			break;
		case '_':
			break;
		case 'e':
			befECount = -1;
			break;
		case 'E':
			befECount = -1;
			break;
		case '.':
			befCount = -1;
			std::cout << result << "`" << std::endl;
			break;
		default:
			break;
		}
	}
	result = result + (decimal * std::pow(10, countDecimal * -1));
	//std::cout << "Value: " << result << "Exp" << exponent << std::endl;

	result = result * pow(10, exponent * expSign);
	return result;
}

std::vector<std::string> extractVerifyFloats(std::string posty) {
	int count = 0;
	std::vector<std::string> nums;
	while (count < posty.size()) {
		std::string temp;
		for (int i = count; i < posty.size(); i++) {
			if (precidence(posty[i]) == 3) {
				temp += posty[i];
				std::cout << std::endl << "1" << std::endl;
			}
			else if (precidence(posty[i]) == 1) {
				if (precidence(posty[i - 2]) == 3) {
					temp += posty[i];
					std::cout << std::endl << "2" << std::endl;
				}
				else if(precidence(posty[i - 4]) != 3){
					std::cout << std::endl << "3" << std::endl;
					temp += posty[i];

					nums.push_back(temp);
					count = i + 1;
					break;

				}

			}
			else if (precidence(posty[i]) == 2) {
				std::cout << std::endl << "4" << std::endl;
				temp += posty[i];
				nums.push_back(temp);
				count = i + 1;
				break;
			}
			else if (precidence(posty[i]) == 0) {
				std::cout << std::endl << "5" << std::endl;
				temp += posty[i];
			}
			else if (precidence(posty[i]) == -2) {
				if (precidence(posty[i - 1]) != 3 && precidence(posty[i - 3]) != 3) {
					std::cout << std::endl << "6" << std::endl;
					temp += posty[i];
					nums.push_back(temp);
					count = i;
					break;
				}
				else if (precidence(posty[i - 1]) == 1) {
					std::cout << std::endl << "7" << std::endl;

					count = i;
				}
			}
			//else if (precidence(posty[i + 1]) == 1) {
			//	temp += posty[i];
			//	nums.push_back(temp);
			//	count = i;
			//	break;
			//}
			else if (precidence(posty[i]) == -1) {
				std::cout << std::endl << "8" << std::endl;
				temp += posty[i];
			}
		}
		std::cout << std::endl << "Hello: " << temp << std::endl;
		count++;
	}
	for (int i = 0; i < nums.size(); i++) {
		if (mainState(nums[i]) == true) {
			std::cout << nums[i] << "is accepted." << std::endl;
		}
		else {
			std::cout << nums[i] << "is not." << std::endl;

		}
	}


	return nums;
}

double calculatePost(std::vector<std::string> one) {
	std::vector<double> num;
	double total = 0;
	for (int i = 0; i < one.size(); i++) {
		std::string temp = one[i];
		//double testy = convertStringToDouble(temp);
		//std::cout << "Number value: " << testy;
		//if (mainState(temp) == true) {
		//	std::cout << temp << "is accepted." << std::endl;
		//}
		//else {
		//	std::cout << temp << "is not." << std::endl;

		//}
		//std::cout << mainState(temp);

		//if (mainState(temp) == true) {
		//	num.push_back(testy);
		//}
		//std::cout << num.front();
		//else{
		//	double num1 = num.top();
		//	num.pop();
		//	double num2 = num.top();
		//	num.pop();

		//	if (temp == "+") {
		//		total = num2 + num1;
		//	}
		//	else if (temp == "-") {
		//		total = num2 - num1;
		//	}
		//	else if (temp == "*") {
		//		total = num2 * num1;
		//	}
		//	else {
		//		total = num2 / num1;
		//	}

		//	num.push(total);
		//}
	}
	return num.front();
}

int main() {
	std::vector<std::string> testvec;

	//do {
	std::string number = "5.0*(12.0*(1.0-1.0)+3.0)+100.0+((9.0e+1f))-8.0e-1d";
	//double value;
	//bool maybe = false;
	//do {
	//	std::cout << "Please enter the input or press q to quit: " << std::endl;
	//	std::cin >> number;
	//	maybe = mainState(number);
	//	if (maybe) {
	//		std::cout << "Accepted String" << std::endl;
	//		value = convertStringToDouble(number);
	//		std::cout << value << std::endl;
	//	}
	//	else {
	//		std::cout << "String not accepted by DFA" << std::endl;
	//	}
	//	maybe = false;
	//} while (!number._Equal("q"));

	std::string result = postFixConverter(number);
	std::cout << std::endl << result << std::endl;
	testvec = extractVerifyFloats(result);
	calculatePost(testvec);

}