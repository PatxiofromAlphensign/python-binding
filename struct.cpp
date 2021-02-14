#include <cstddef>
#include <valarray>
#include <map>
#include <string>
#include <main.h>
#include <boost/python.hpp>

struct F {
    int k = 0;
    f<2> a;
    int max() {
        a.arr(4);
        return a.max();
        
    }
    int x() {return a.X;}
    PyObject* script(PyObject* command) {
        return a.script(command);
    }

};

typedef std::slice fm;
typedef std::map<std::string, int> dict;

void apply(PyObject *callable, F& x ) {
    boost::python::call<void>(callable, boost::ref(x));
}


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


BOOST_PYTHON_MODULE(modd) {
    using namespace boost::python;

    f<2> a;
    def("func1", func1);
    def("wrap", wrap); 
    class_<F>("F")
        .def("script", &F::script)
        .def("max", &F::max)
    ;
}

int main() {return 0;}

