/* ---- ADD, SUBSTRACT AND SCALE ---- */

#include "../includes/matrix.hpp"
#include "../includes/vector.hpp"

int main()
{
    try{
        std::cout << std::endl;
        {
            Vector<float> u({2., 3.});
            const Vector<float> v({5., 7.});
            u.add(v);
            std::cout << u << std::endl;
        }
        std::cout << std::endl;
        {
            Vector<float> u({2., 3.});
            const Vector<float> v({5., 7.});
            u.sub(v);
            std::cout << u << std::endl;
        }
        std::cout << std::endl;
        {
            Vector<float> u({2., 3.});
            u.scl(2.);
            std::cout << u << std::endl;
        }
        std::cout << std::endl;
        {
            Matrix<float> u({{1., 2.}, {3., 4.}});
            const Matrix<float> v({{7., 4.}, {-2., 2.}});
            u.add(v);
            std::cout << u << std::endl;
        }
        {
            Matrix<float> u({{1., 2.}, {3., 4.}});
            const Matrix<float> v({{7., 4.}, {-2., 2.}});
            u.sub(v);
            std::cout << u << std::endl;
        }
        {
            Matrix<float> u({{1., 2.}, {3., 4.}});
            u.scl(2.);
            std::cout << u << std::endl;
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
