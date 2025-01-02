/* ---- TRANSPOSE ---- */

#include "../includes/matrix.hpp"
#include "../includes/vector.hpp"

int main()
{
    try
    {
        {
            Matrix<double> u = { {1., 0.}, {0., 1.} };
            std::cout << "Before transposition :\n"<< u << std::endl;
            std::cout << "After transposition :\n"<< u.transpose() << std::endl;
        }
        std::cout << std::endl;
        {
            Matrix<double> u = { {2., -5., 0.}, {4., 3., 7.}, {-2., 3., 4.} };
            std::cout << "Before transposition :\n"<< u << std::endl;
            std::cout << "After transposition :\n"<< u.transpose() << std::endl;
        }
        std::cout << std::endl;
        {
            Matrix<double> u = { {-2., -8., 4.}, {1., -23., 4.} };
            std::cout << "Before transposition :\n"<< u << std::endl;
            std::cout << "After transposition :\n"<< u.transpose() << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
