/* ---- LINEAR COMBINATION ---- */

#include "../includes/matrix.hpp"
#include "../includes/vector.hpp"

int main()
{
    try
    {
        {
            Vector<float> e1 = {1.0, 0.0, 0.0};
            Vector<float> e2 = {0.0, 1.0, 0.0};
            Vector<float> e3 = {0.0, 0.0, 1.0};

            std::vector<Vector<float>> vectors = {e1, e2, e3};
            std::vector<float> coefficients = {10.0f, -2.0f, 0.5f};

            Vector<float> result = linear_combination(vectors, coefficients);
            std::cout << result << std::endl;
        }
        {
            Vector<float> v1 = {1.0, 2.0, 3.0};
            Vector<float> v2 = {0.0, 10.0, -100.0};

            std::vector<Vector<float>> vectors = {v1, v2};
            std::vector<float> coefficients = {10.0f, -2.0f};

            Vector<float> result = linear_combination(vectors, coefficients);
            std::cout << result << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
