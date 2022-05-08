/**
 * Part 2: Solve using arrays
*/

#include <iostream>

int getLargerThanPrevious(int *elements, std::size_t length)
{
	int counter{}, pre{};

    if (length > 1) pre = elements[0];

    for (int i{ 1 }; i < length; ++i) {

       	if (elements[i] > pre)
			++counter;

       pre = elements[i];
  	}

	return counter;
}


int main()
{
	constexpr std::size_t data_length { 2000 };
	int inputs[data_length] {};

	for (int i = 0; i < data_length; ++i)
		std::cin >> inputs[i];

	constexpr int group_size { 3 };
	int grouped[data_length]{};

	for (int i = 0, g = 0; i < data_length; ++i) {
		int sum { inputs[i] };

		for (int j = i + 1; j < i + group_size && j < data_length; ++j)
			sum += inputs[j];

		grouped[i] = sum;
	}

	std::cout << getLargerThanPrevious(grouped, data_length) << '\n';

	return 0;
}
