#include <iostream>
#include <bitset>
#include <cstdint>

#define MAX(a, b) (a > b ? '0' : '1')

int main()
{
    constexpr int data_len { 1000 };
    constexpr int bits_len { 12 };

    char binaries[data_len][bits_len] {};

    for (int i = 0; i < data_len; ++i)
        std::cin >> binaries[i];

    uint16_t counter[bits_len][2] {};
    for (int i = 0; i < data_len; ++i) {

        for (int j = 0; j < bits_len; ++j) {
            const int index { binaries[i][j] - '0' };
            ++counter[j][index];
        }

    }

    char gamma_binary[bits_len] {};
    for (int i = 0; i < bits_len; ++i)
        gamma_binary[i] = MAX(counter[i][0], counter[i][1]); 

    std::bitset<bits_len> gamma (gamma_binary, bits_len);
    std::bitset<bits_len> epsilon { gamma };
    epsilon.flip();

    std::cout << gamma.to_ulong() * epsilon.to_ulong() << '\n';

	return 0;
}
