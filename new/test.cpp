#include <boost/python.hpp>
#include <iostream>

const int oneforth(int num, int bound) {
    if (num < bound) {return num;}

    return oneforth(num * (1/4), bound);
}


BOOST_PYTHON_MODULE(modd)
{
    using namespace boost::python;
    def("oneforth", oneforth);
}


int main() {
    std::cout << oneforth(10, 4);
    return 0;
}
