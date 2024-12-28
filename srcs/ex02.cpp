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
            Vector<float> resultVec = lerp(v1, v2, 0.3f);
            for (auto val : resultVec)
                std::cout << "[" << val << "] ";
            std::cout << std::endl;
        }
        {
            Matrix<float> m1 = {{2., 1.}, {3., 4.}};
            Matrix<float> m2 = {{20., 10.}, {30., 40.}};
            Matrix<float> resultMat = lerp(m1, m2, 0.5f);

            std::cout << "[";
            for (size_t i = 0; i < resultMat.numRows(); ++i) {
                std::cout << "[";
                for (size_t j = 0; j < resultMat.numCols(); ++j) {
                    std::cout << resultMat.data_matrix[i][j];
                    if (j < resultMat.numCols() - 1)
                        std::cout << ", ";
                }
                std::cout << "]";
                if (i < resultMat.numRows() - 1)
                    std::cout << "\n";
            }
            std::cout << "]" << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}