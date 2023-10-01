#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::cout << argc << '\n';
    for (int i = 0; i < argc; ++i)
        std::cout << i << ": " << argv[i] << '\n';
}
