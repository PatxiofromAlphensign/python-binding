#include <cstddef>
#include <valarray>
#include <map>
#include <string>
#include <boost/python.hpp>

template<int T>
class f {
    private:
        int x;
    public:
        f() {
        this->x = T;
        }
        int X ;
        void param(int i) {
            X = T + this->x + i;
        }
};
struct F {
    int k = 0;
    f<2> a;
    int param (int i) {
        a.param(i);
    }
    int x() {return a.X;}
};

typedef std::slice fm;
typedef std::map<std::string, int> dict;

dict func1(int count) {
dict b;
fm a;
for(int i;i<count;i++) {
b[std::__cxx11::to_string(i)] = i;
}
return b;
}
   
int wrap(std::string k, int i) {
    dict b = func1(i);
    f<2> a;
    a.param(3);
    return b[k];
}


BOOST_PYTHON_MODULE(modd)
{
    using namespace boost::python;

    f<2> a;
    def("func1", func1);
    def("wrap", wrap); 
    class_<F>("F")
        .def("param", &F::param)
        .def("x", &F::x)
    ;
}

int main() {return 0;}

