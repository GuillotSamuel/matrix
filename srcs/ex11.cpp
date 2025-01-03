/* ---- DETERMINANT ---- */

#include "../includes/matrix.hpp"
#include "../includes/vector.hpp"

int main()
{
    try
    {
        {
            Matrix<double> u = { {1., -1.}, {-1., 1.} };
            std::cout << u.determinant() << std::endl;
        }
        std::cout << std::endl;
        {
            Matrix<double> u = { {2., 0., 0.}, {0., 2., 0.}, {0., 0., 2.} };
            std::cout << u.determinant() << std::endl;
        }
        std::cout << std::endl;
        {
            Matrix<double> u = { {8., 5., -2., 4.}, {4., 2.5, 20., 4.}, {8., 5., 1., 4.}, {28., -4., 17., 1.} };
            std::cout << u.determinant() << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
