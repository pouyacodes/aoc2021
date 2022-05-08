/**
 * Part 1
*/

#include <iostream>

int main()
{
	int counter{}, pre{}, cur{};
	std::cin >> pre;

	while (std::cin >> cur) {

		if (cur > pre)
			++counter;

		pre = cur;
	}

	std::cout << counter << '\n';

	return 0;
}
