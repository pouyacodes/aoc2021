#include <iostream>
#include <string>

int main()
{
	int x{}, y{}, value{};
	std::string instruction{};

	while (std::cin >> instruction >> value) {

		if (instruction.compare("forward") == 0)
			x += value;
		else if (instruction.compare("up") == 0)
			y -= value;
		else if (instruction.compare("down") == 0)
			y += value;
	}

	std::cout << x * y << '\n';
	return 0;
}
