/* ---- COSINE ---- */

#include "../includes/matrix.hpp"
#include "../includes/vector.hpp"

int main()
{
    try
    {
        {
            Vector<float> v0 = {1., 0.};
            Vector<float> v1 = {1., 0.};
            std::cout << angle_cos(v0, v1) << std::endl;
        }
        {
            Vector<float> v0 = {1., 0.};
            Vector<float> v1 = {0., 1.};
            std::cout << angle_cos(v0, v1) << std::endl;
        }
        {
            Vector<float> v0 = {-1., 1.};
            Vector<float> v1 = {1., -1.};
            std::cout << angle_cos(v0, v1) << std::endl;
        }
        {
            Vector<float> v0 = {2., 1.};
            Vector<float> v1 = {4., 2.};
            std::cout << angle_cos(v0, v1) << std::endl;
        }
        {
            Vector<float> v0 = {1., 2., 3.};
            Vector<float> v1 = {4., 5., 6.};
            std::cout << angle_cos(v0, v1) << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
