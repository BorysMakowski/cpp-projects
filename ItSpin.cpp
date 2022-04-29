#include <iostream>
#include <thread>
int main()
{
    //PROGRAMOWANIE TO MOJA PASJA
    int g[4] = { 92,124,45,47 };
    int i(0);
    long long m = pow(2, 34);
    while ((ceil(log2(m)) == floor(log2(m)))) {
        std::cout << (char)*(g + (i % 4));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "\r";
        i = (i == INT_MAX) ? 0 : ++i;
    }
}


