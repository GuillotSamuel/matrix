/* ---- CROSS PRODUCT ---- */

#include "../includes/matrix.hpp"
#include "../includes/vector.hpp"

int main()
{
    try
    {
        {
            Vector<float> u = {0., 0., 1.};
            Vector<float> v = {1., 0., 0.};
            std::cout << cross_product(u, v) << std::endl;
        }
        {
            Vector<float> u = {1., 2., 3.};
            Vector<float> v = {4., 5., 6.};
            std::cout << cross_product(u, v) << std::endl;
        }
        {
            Vector<float> u = {4., 2., -3.};
            Vector<float> v = {-2., -5., 16.};
            std::cout << cross_product(u, v) << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
