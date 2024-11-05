#include <iostream>
#include "vector_3d.hpp"

int main()
{
    std::cout << "hello\n";

    std::cout << "\ncreate v1 with constructor\n";
    math::Vector3D v1(1, 2, 3);
    std::cout << "print v1\n";
    v1.print();

    std::cout << "\ncreate v2 with copy constructor from v1\n";
    math::Vector3D v2(v1);
    std::cout << "print v2\n";
    v2.print();

    std::cout << "\nprint v1\n";
    v1.print();

    std::cout << "\ncreate v3 with move constructor from v1\n";
    math::Vector3D v3(std::move(v1));
    std::cout << "print v3\n";
    v3.print();

    std::cout << "\nprint v1\n";
    v1.print();

    std::cout << "\ncreate v4 with copy constructor from nullptr v1\n";
    try
    {
        math::Vector3D v4(v1);
    }
    catch(std::invalid_argument e)
    {
        std::cout << "\nExiting with exeption: " << e.what() << "\n";
    }

    std::cout << "\ncreate v5 with move constructor from nullptr v1\n";
    math::Vector3D v5(std::move(v1));
    std::cout << "print v5\n";
    v5.print();

    std::cout << "\nprint v1\n";
    v1.print();

    std::cout << "\ncreate v6 with copy assign from nullptr v2\n";
    math::Vector3D v6 = v2;
    std::cout << "print v6\n";
    v6.print();

    std::cout << "\nprint v2\n";
    v2.print();

    std::cout << "\ncreate v7 with move assign from nullptr v2\n";
    math::Vector3D v7 = std::move(v2);
    std::cout << "print v7\n";
    v7.print();

    std::cout << "\nprint v2\n";
    v2.print();

    std::cout << "\nNormalizing vector v7\n";
    auto v7_shared_ptr = std::make_shared<math::Vector3D>(std::move(v7));
    math::normalize(v7_shared_ptr);
    std::cout << "print v7_shared_ptr\n";
    v7_shared_ptr->print();
}