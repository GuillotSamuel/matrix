/* ---- ROW ECHELON FORM ---- */

#include "../includes/matrix.hpp"
#include "../includes/vector.hpp"

int main()
{
    try
    {
        std::cout << "REDUCED : " << std::endl;
        {
            Matrix<double> u = { {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.} };
            std::cout << u.row_echelon() << std::endl;
        }
        std::cout << std::endl;
        {
            Matrix<double> u = { {1., 2.}, {3., 4.} };
            std::cout << u.row_echelon() << std::endl;
        }
        std::cout << std::endl;
        {
            Matrix<double> u = { {1., 2.}, {2., 4.} };
            std::cout << u.row_echelon() << std::endl;
        }
        std::cout << std::endl;
        {
            Matrix<double> u = { {8., 5., -2., 4., 28.}, {4., 2.5, 20., 4., -4.}, {8., 5., 1., 4., 17.} };
            std::cout << u.row_echelon() << std::endl;
        }
        // std::cout << "\nNON REDUCED : " << std::endl;
        // {
        //     Matrix<double> u = { {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.} };
        //     std::cout << u.row_echelon_non_reduced() << std::endl;
        // }
        // std::cout << std::endl;
        // {
        //     Matrix<double> u = { {1., 2.}, {3., 4.} };
        //     std::cout << u.row_echelon_non_reduced() << std::endl;
        // }
        // std::cout << std::endl;
        // {
        //     Matrix<double> u = { {1., 2.}, {2., 4.} };
        //     std::cout << u.row_echelon_non_reduced() << std::endl;
        // }
        // std::cout << std::endl;
        // {
        //     Matrix<double> u = { {8., 5., -2., 4., 28.}, {4., 2.5, 20., 4., -4.}, {8., 5., 1., 4., 17.} };
        //     std::cout << u.row_echelon_non_reduced() << std::endl;
        // }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
