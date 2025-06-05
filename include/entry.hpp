#include <iostream>

// @brief A simple example class that prints a member's value.
struct example_t
{
    // @brief A method to print the value of the member variable.
    void print( ) const
    {
        std::cout << "Value: " << value << std::endl;
    }

    float value { 5.4f }; ///< A float variable initialized to 5.4.
};