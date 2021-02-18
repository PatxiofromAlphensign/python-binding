#include <cstddef>
#include <valarray>
#include <vector>
#include <map>
#include <string>
#include <Python.h>

template<int T>
class f {
    private:
        typedef std::slice fm;
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

    typedef std::map<std::string, int> dict;
    dict b;
    PyObject* script(PyObject* command) {
        const char* cmd = (char*)command;
        int sts = system(cmd);
        return PyLong_FromLong(sts);
    }

    PyObject *string(PyObject *in) { 
       const char *x;
       std::string s;

       if (!PyArg_ParseTuple(in,"s",*x)) return NULL;
       PyObject *chr = PyObject_Repr(in);
       PyObject *unicode =  PyUnicode_AsEncodedString(chr, "UTF-8", "strict");
       char *pystring = PyBytes_AS_STRING(unicode);
       //char ar[s.length() + 1];
       strcpy(pystring, s.c_str());
       return unicode;
    }
    dict mdict(int count) { //not implementing now
        for(int i;i<count;i++) {
        //b[std::__cxx11::to_string(i)] = i;
        this->b[std::to_string(i)] = i;
        }
        return this->b;
    }
    std::vector<int> iterate(PyObject *key, PyObject *val, PyObject *Dict = NULL) {
        if (!Dict) {
            Dict = PyDict_New();
        }
        std::vector<int> vec;
        Py_ssize_t pos = 0;
        while (PyDict_Next(Dict, &pos, &key, &val)) {
            long i = PyLong_AsLong(val), j = PyLong_AsLong(key);
            vec[i] = j + i;
        }

        return vec;
    }
};

        

