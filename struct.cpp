#include <cstddef>
#include <valarray>
#include <map>
#include <string>
#include <main.h>
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

};
typedef std::slice fm;
typedef std::map<std::string, int> dict;

void apply(PyObject *callable, F& x ) {
    boost::python::call<void>(callable, boost::ref(x));
}

// =============================
// rest is just python api building
// =============================

//dict func1(int count) { not implementing now
//    dict b;
//    fm a;
//    for(int i;i<count;i++) {
//    //b[std::__cxx11::to_string(i)] = i;
//    b[std::to_string(i)] = i;
//    }
//    return b;
//}
//

BOOST_PYTHON_MODULE(modd) {
    using namespace boost::python;

    f<2> a;
    class_<F>("F")
        .def("script", &F::script)
        .def("max", &F::max)
    ;
}

int main() {return 0;}

