/*
program to code a message using Golomb coding
input: tunable parameter M, string containing hex nums 1-f
*/
#include <iostream>
#include <vector>

bool isPowerOf2(int m)
{
    if (m == 0)
        return false;

    return (ceil(log2(m)) == floor(log2(m)));
}
std::vector <char> unaryCode(int in)
{
    std::vector <char> output;
    for (int j = 0; j < in; j++)
        output.push_back('1');
    output.push_back('0');
    return output;
}
std::vector <char> binaryCode(int in, int len)
{
    std::vector <char> output;
    output.resize(len);

    int temp = in;
    for (int j = 0; j < len; j++)
    {
        output[(len - 1) - j] = char(temp % 2) + '0';
        temp /= 2;
    }

    for (char i : output)
        std::cout << i;
    std::cout << std::endl;

    return output;
}
std::string input;
std::vector <char> prefix;
std::vector <char> suffix;
std::vector <char> output;
int symbol = 1;
int koddekod, m, num, r, k, b, n;
int main()
{
    std::cout << "kodowanie golomba" << std::endl;
    std::cout << "podaj rzad m:" << std::endl;
    std::cin >> m;
    std::cout << "podaj ciag znakow:" << std::endl;
    std::cin >> input;

    for (int i = 0; i < input.length(); i++)//kod unarny
    {
        if (input[i] == 'a')
            num = 10;
        if (input[i] == 'b')
            num = 11;
        if (input[i] == 'c')
            num = 12;
        if (input[i] == 'd')
            num = 13;
        if (input[i] == 'e')
            num = 14;
        if (input[i] == 'f')
            num = 15;
        if (input[i] != 'a' && input[i] != 'b' && input[i] != 'c' && input[i] != 'd' && input[i] != 'e' && input[i] != 'f')
            num = (int)input[i] - '0';

        if (m == 1)
            output = unaryCode(num);

        else if (isPowerOf2(m))
        {

            prefix = unaryCode(std::floor(num / m));
            r = num - (std::floor(num / m) * m);
            k = log2(m);
            suffix = binaryCode(r, k);

            output = prefix;
            output.push_back('|');
            for (char i : suffix)
                output.push_back(i);
        }
        else
        {
            n = std::floor(num / m);
            prefix = unaryCode(std::floor(n));
            b = std::ceil(log2(m));
            r = num - (n * m);

            if (r < (pow(2, b) - m))
                suffix = binaryCode(r, b - 1);
            else
                suffix = binaryCode((r + pow(2, b) - m), b);

            output = prefix;
            output.push_back('|');
            for (char i : suffix)
                output.push_back(i);
        }
        for (char i : output)
            std::cout << i;
        std::cout << std::endl;
    }
}


