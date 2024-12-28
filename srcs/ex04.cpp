/* ---- NORM ---- */

#include "../includes/matrix.hpp"
#include "../includes/vector.hpp"

int main()
{
    try
    {
        {
            Vector<float> v1 = {0., 0., 0.};
            std::cout << "Norm 1: " << v1.norm_1() << std::endl;
            std::cout << "Norm: " << v1.norm() << std::endl;
            std::cout << "Norm inf: " << v1.norm_inf() << std::endl;
        }
        {
            Vector<float> v1 = {1., 2., 3.};
            std::cout << "Norm 1: " << v1.norm_1() << std::endl;
            std::cout << "Norm: " << v1.norm() << std::endl;
            std::cout << "Norm inf: " << v1.norm_inf() << std::endl;
        }
        {
            Vector<float> v1 = {-1., -2};
            std::cout << "Norm 1: " << v1.norm_1() << std::endl;
            std::cout << "Norm: " << v1.norm() << std::endl;
            std::cout << "Norm inf: " << v1.norm_inf() << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
