/* ---- LINEAR MAP, MATRIX MULTIPLICATION ---- */

#include "../includes/matrix.hpp"
#include "../includes/vector.hpp"

int main()
{
    try
    {
        {
            Matrix<double> u = { {1., 0.}, {0., 1.} };
            Vector<double> v = {4., 2.};
            std::cout << u.mul_vec(v) << std::endl;
        }
        std::cout << std::endl;
        {
            Matrix<double> u = { {2., 0.}, {0., 2.} };
            Vector<double> v = {8., 4.};
            std::cout << u.mul_vec(v) << std::endl;
        }
        std::cout << std::endl;
        {
            Matrix<double> u = { {2., -2.}, {-2., 2.} };
            Vector<double> v = {4., 2.};
            std::cout << u.mul_vec(v) << std::endl;
        }
        std::cout << std::endl;
        {
            Matrix<double> u = { {1., 0.}, {0., 1.} };
            Matrix<double> v = { {1., 0.}, {0., 1.} };
            std::cout << u.mul_mat(v) << std::endl;
        }
        std::cout << std::endl;
        {
            Matrix<double> u = { {1., 0.}, {0., 1.} };
            Matrix<double> v = { {2., 1.}, {4., 2.} };
            std::cout << u.mul_mat(v) << std::endl;
        }
        std::cout << std::endl;
        {
            Matrix<double> u = { {3., -5.}, {6., 8.} };
            Matrix<double> v = { {2., 1.}, {4., 2.} };
            std::cout << u.mul_mat(v) << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
