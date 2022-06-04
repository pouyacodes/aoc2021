#include <iostream>
#include <vector>
#include <utility>
#include <bitset>

namespace constants
{
	constexpr std::size_t bits_len { 12 };
	constexpr std::size_t data_lines { 1000 };
}

using BinaryNumber = std::bitset<constants::bits_len>;

namespace Solution
{
	typedef bool (*ComparisonFunction)(const int& lhs, const int& rhs);
	typedef unsigned long ulong;
	constexpr inline bool maxBit(const int& lhs, const int& rhs);
	constexpr inline bool minBit(const int& lhs, const int& rhs);

	class Rate
	{
		const std::vector<BinaryNumber>& _binaries;
		const ComparisonFunction _func;
		const std::size_t _bits_len;

		public:
			Rate(const std::vector<BinaryNumber>& binaries, ComparisonFunction func, 
							std::size_t bits_len = constants::bits_len) : _binaries(binaries), _func(func), _bits_len(bits_len) {};
			ulong getRate();
		private:
			std::pair<int, int> getRepetition(const std::vector<BinaryNumber>& binaries, std::size_t pos);
	};

	ulong Rate::getRate()
	{
		std::vector<BinaryNumber> matches{ _binaries };
		for (int i = _bits_len - 1; matches.size() > 1 && i >= 0; --i) {
			const auto [lhs, rhs] = getRepetition(matches, i);
			const bool target = _func(lhs, rhs);

			std::vector<BinaryNumber> filtered{};
			for (const auto& binary: matches)
				if (binary[i] == target)
					filtered.push_back(binary);

			matches = filtered;
		}

		return matches.size() > 0 ? matches[0].to_ulong() : 0;
	}

	std::pair<int, int> Rate::getRepetition(const std::vector<BinaryNumber>& binaries, std::size_t pos)
	{
		int counters[2] = {};

		for (const auto& binary: binaries) {
			const bool index { binary[pos] };
			++counters[index];
		}

		return std::make_pair(counters[0], counters[1]);
	}

	constexpr inline bool maxBit(const int& lhs, const int& rhs) 
	{
		return lhs == rhs ? true : lhs < rhs;
	}

	constexpr inline bool minBit(const int& lhs, const int& rhs)
	{
		return lhs == rhs ? false : lhs > rhs;
	}

}

int main()
{
	
	std::vector<BinaryNumber> binaries{};

	for (int i = 0; i < constants::data_lines; ++i) {
		BinaryNumber current{};
		std::cin >> current;
		binaries.push_back(current);
	}

	const Solution::ulong oxygen 	= Solution::Rate(binaries, Solution::maxBit).getRate();
	const Solution::ulong CO2 		= Solution::Rate(binaries, Solution::minBit).getRate();

	std::cout << oxygen * CO2 << '\n';

	return 0;
}
