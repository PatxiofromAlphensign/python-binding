#include <cstddef>
#include <valarray>
#include <map>
#include <cstring>
#include <string>
#include <main.h>
#include <iostream>
#include <vector>
#include <boost/python.hpp>

// sturct that wraps the main `f` class 
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

    PyObject *convert_to_pyobject(boost::python::list k, boost::python::list l ) { // later should enclose key and value into PyObject
        PyObject *n = PyDict_New();
        return n;
    }

    PyObject * dicts(int i) {
        int fi = compute(i);
        PyObject * l  = PyLong_FromLong(fi);
        f<2>::dict dict = a.mdict(fi);
        boost::python::dict d;
        PyObject* KV = convert_to_pyobject(d.keys(), d.values());
        std::vector<int> vec = a.iterate(KV,KV);
    }
    
};
typedef std::slice fm;
typedef std::map<std::string, int> dict;

void unwarpvec(std::vector<int> vec) {
    for (auto i:vec) {
        std::cout << i;
    }
}
void apply(PyObject *callable, F& x ) {
    boost::python::call<void>(callable, boost::ref(x));
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

int main() {
    PyObject *k, *v;
    f<2> a;
    std::vector<int> vec = a.iterate(k,v);
    unwarpvec(vec);
    return 0;}

