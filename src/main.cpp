#include "main.hpp"

using namespace Sub1;

int main(int argc, char *argv[])
{
    std::string arg(argv[1]);
    auto c = Class(arg);
    c.execute();

    return 0;
}

