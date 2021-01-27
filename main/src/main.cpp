#include <template_lib/template_lib.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
    auto result = templatelib::type(10);
    std::cout << "Type: " << result._value << std::endl;
    return 0;
}