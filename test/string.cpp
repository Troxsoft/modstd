#include "../src/MString.hpp"
#include <iostream>
int main()
{
    MString str("jjuan");

    if (str.starts_with("jjuanjjuan"))
    {
        std::cout << "verdadero\n";
    }
    else
    {
        std::cout << "falso aña\n";
    }
    if (str.ends_with("anoknnnnnnnnnnn"))
    {
        std::cout << "si\n";
    }
    else
    {
        std::cout << "no\n";
    }
    str.left_push("hola ");
    str.right_push(" adios");
    str.push(0, "123");

    std::cout << str << "\n";
    std::cout
        << "'" << str.get(str.size()) << "'"
        << "\n";
    std::cout << str.get(0, 7) << "\n";
    MString other("hola como te va");
    if (other == "hola como te va")
    {
        std::cout << "an"
                  << "\n";
    }
    other = "ano";
    if (other == "ano")
    {
        std::cout << "an"
                  << "\n";
    }
    MString hola("     hola      ");
    hola.trim_space();
    std::cout << "'" << hola << "'"
              << "\n";
    MString plo("holah");
    plo.trim("h");
    plo.right_trim("a");
    plo.left_trim("o");

    // plo.clear();
    std::cout << plo.contains("lol") << "\n";
    std::cout << plo << "\n";
    std::cout << plo.search("l") << "\n";

    MString cadena("hola-mundo-en-python-colombia-hola-mundo-en-python-colombia-hola-mundo-en-python-colombia-hola-mundo-en-python-colombia-hola-mundo-en-python-colombia-hola-mundo-en-python-colombia-hola-mundo-en-python-colombia-hola-mundo-en-python-colombia");

    std::cout << cadena.split("-") << "\n";
}