// g++ -o main main.cpp ; ./main

#include <iostream>

template <class T>
class Bucky
{
    T first, second;

public:
    Bucky(T a, T b)
    {
        first = a;
        second = b;
    }

    void print()
    {
        std::cout << first << " " << second << std::endl;
    }
    T bigger();
};

template <class T>
T Bucky<T>::bigger()
{
    if (first > second)
        return first;
    else
        return second;
}

// template <class T>
// class githubBucky
// {
// public:
//     githubBucky(T value)
//     {
//         this->value = value;
//     }
//     T getValue()
//     {
//         return value;
//     }

// private:
//     T value;
// };

int main()
{
    Bucky<int> bo(69, 105);
    std::cout << bo.bigger() << std::endl;

    Bucky<int> bucky(10, 20);
    bucky.print();
    std::cout << bucky.bigger() << std::endl;

    // githubBucky<int> githubBucky(10);
    // std::cout << githubBucky.getValue() << std::endl;

    return 0;
}
