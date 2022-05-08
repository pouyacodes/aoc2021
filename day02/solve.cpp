/**
 * Part 2
*/

#include <iostream>
#include <string>

int main()
{
	int horizontal{}, depth{}, aim{};

	std::string instruction{};
	int value{};

	while (std::cin >> instruction >> value) {

		if (instruction.compare("forward") == 0) {
			horizontal += value;
			depth += value * aim;
		} else if (instruction.compare("up") == 0) {
			aim -= value;
		} else if (instruction.compare("down") == 0)
			aim += value;
	}

	std::cout << depth * horizontal << '\n';
	return 0;
}
