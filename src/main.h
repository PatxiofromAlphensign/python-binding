#include <cstddef>
#include <valarray>
#include <map>
#include <string>
#include <Python.h>

template<int T>
class f {
    private:
        int x;
        std::valarray<int> valarr;
    public:
        f() {
        this->x = T;
        }
        int X;
        void param(int i) {
            X = T + this->x + i;

        }
        std::valarray<int> arr (int i) {
            f::param(i);
            std::valarray<int> val(f::X);
            this->valarr =  val;
    }
        int max() {
            this->valarr;
            return valarr.max();
        }
    PyObject* script(PyObject* command) {
        const char* cmd = (char*)command;
        int sts = system(cmd);
        return PyLong_FromLong(sts);
}
};


