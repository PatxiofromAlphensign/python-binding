#include <cstddef>
#include <valarray> #include <map>
#include <cstring>
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

    PyObject *str(PyObject *in) { 
        return a.string(in); //getting seg faults
    }

    int compute(int i) {}

    f<2>::dict dicts(int i) {
        int fi = compute(i);
        PyObject * l  = PyLong_FromLong(fi);
        return a.mdict(fi);
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
    class_<F>("F")
        .def("script", &F::script)
        .def("max", &F::max)
        .def("string", &F::str)
    ;
}

int main() {return 0;}

