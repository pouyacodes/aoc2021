/**
 * Solve with Vectors
*/

#include <iostream>
#include <vector>
#include <numeric>

#define DEBUG 0

int getLargerThanPrevious(int *elements, std::size_t length)
{
	int counter{}, pre{};
	if (length > 1)
		pre = elements[0];

	for (int i{ 1 }; i < length; ++i) {
		if (elements[i] > pre)
			++counter;
		pre = elements[i];
	}

	return counter;
}

#if DEBUG

std::ostream& operator<<(std::ostream& stream, const std::vector<int>& buffer) {
	constexpr int width { 5 };

	stream << '[';

	for (int i{}; i < buffer.size(); ++i) {
		stream << buffer[i] << (i + 1 == buffer.size() ? "" : ", ");
		if (width > 0 && (i + 1) % width == 0)
			stream << '\n';
	}

 	stream << ']' << '\n';

	return stream;
}

#endif

int main()
{
	std::vector<int> inputs{};
	int cur{};
	while (std::cin >> cur)
		inputs.push_back(cur);


	std::vector<int> grouped{};
	for (int i{}; i < inputs.size(); ++i) {
		int sum{ inputs[i] };

		for (int j = i + 1; j < i + 3 && j < inputs.size(); ++j)
			sum += inputs[j];

		grouped.push_back(sum);
	}


	std::cout << getLargerThanPrevious(grouped.data(), grouped.size()) << '\n';

	return 0;
}
