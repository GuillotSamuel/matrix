/* ---- DOT PRODUCT ---- */

#include "../includes/matrix.hpp"
#include "../includes/vector.hpp"

int main()
{
    try
    {
        {
            Vector<float> u = {0., 0.};
            Vector<float> v = {1., 1.};
            std::cout << std::fixed << std::setprecision(1) << u.dot(v) << std::endl;
        }
        {
            Vector<float> u = {1., 1.};
            Vector<float> v = {1., 1.};
            std::cout << std::fixed << std::setprecision(1) << u.dot(v) << std::endl;
        }
        {
            Vector<float> u = {-1., 6.};
            Vector<float> v = {3., 2.};
            std::cout << std::fixed << std::setprecision(1) << u.dot(v) << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}