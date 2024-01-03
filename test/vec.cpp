#include <iostream>
#include "../src/MString.hpp"
#include "../src/MVector.hpp"
int main()
{
    try
    {
        /* code */
        auto vector = MVector<MString>();
        vector.right_push("hola");
        vector.left_push("jhonsina");
        std::cout << vector.get_first().to_string() << "\n";
        std::cout << vector.get_last().to_string() << "\n";

        std::cout << vector.get_range(0, 2) << "\n";
        std::cout << vector[0] << "\n";
        vector[0] = "ana";
        std::cout << vector[0] << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}