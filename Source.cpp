//Joseph Kahale
//CS 3110.02
//Professor Huong

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <cmath>

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
	std::cout << decimal << "`" << std::endl;

	result = result + (decimal * std::pow(10, countDecimal * -1));
	std::cout << "Value: " << result << "Exp" << exponent << std::endl;

	result = result * pow(10, exponent * expSign);
	return result;
}

int main() {
	//do {
	std::string number;
	double value;
	bool maybe = false;
	do {
		std::cout << "Please enter the input or press q to quit: " << std::endl;
		std::cin >> number;
		maybe = mainState(number);
		if (maybe) {
			std::cout << "Accepted String" << std::endl;
			value = convertStringToDouble(number);
			std::cout << value << std::endl;
		}
		else {
			std::cout << "String not accepted by DFA" << std::endl;
		}
		maybe = false;
	} while (!number._Equal("q"));


}