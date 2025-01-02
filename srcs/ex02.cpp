/* ---- LINEAR INTERPOLATION ---- */

#include "../includes/matrix.hpp"
#include "../includes/vector.hpp"

int main()
{
    try
    {
        {
            std::cout << lerp(0., 1., 0.) << std::endl;
        }
        {
            std::cout << lerp(0., 1., 1.) << std::endl;
        }
        {
            std::cout << lerp(0., 1., 0.5) << std::endl;
        }
        {
            std::cout << lerp(21., 42., 0.3) << std::endl;
        }
        {
            Vector<float> v1 = {2., 1.};
            Vector<float> v2 = {4., 2.};
            std::cout << lerp(v1, v2, 0.3f) << std::endl;
        }
        {
            Matrix<float> m1 = {{2., 1.}, {3., 4.}};
            Matrix<float> m2 = {{20., 10.}, {30., 40.}};
            std::cout << lerp(m1, m2, 0.5f) << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}