#include "../includes/matrix.hpp"
#include "../includes/vector.hpp"

int main()
{
    try{
        {
            Vector<float> u({2., 3.});
            const Vector<float> v({5., 7.});
            u.add(v);
            std::cout << u << std::endl;
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}