#include <boost/python.hpp>
#include <iostream>

const int oneforth(int num, int bound) {
    if (num < bound) {return num;}
    std::cout << num;
    return oneforth(num/4, bound);
}

int someint(int i) {
    return i-1;
}

int mem(int *x, int a[]) {
    while (*x < 10) {
        a[*x] = *x+1;
        x+=1;
    }
}

BOOST_PYTHON_MODULE(modd)
{
    using namespace boost::python;
    def("oneforth", oneforth);
    def("someint", someint);
    def("mem", mem);
}

int main() {
    int x = 0;
    int xp[] = {};
    //std::cout << xp;
    return 0;
}
