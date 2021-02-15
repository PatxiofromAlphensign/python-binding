#include <Python.h> 
#include <stdlib.h> 
#include <iostream> 
#include <vector> 

static int pyobj(const char *cmd) {
    return system(cmd);
    }

static PyObject *add(PyObject *self, PyObject *args)  {
    (void *)pyobj("ls -l");
    int i;
    while (i<10){
        i++;
        }

    if (!PyArg_ParseTuple(args, "s", &i)) {return NULL;}
    return PyLong_FromLong(i);

}
static PyObject *spam(PyObject *self, PyObject *args) {
    const char *cmd;
    if (!PyArg_ParseTuple(args, "s", &cmd)) {return NULL;}
    int sts = pyobj(cmd);
    return PyLong_FromLong(sts);
}

static PyMethodDef example_methods[] = {
    {"spam", spam, METH_VARARGS},
    {"add", add, METH_VARARGS}
};

static struct PyModuleDef example_definition = {
    PyModuleDef_HEAD_INIT,
    "example",
    "test",
    -1,
    example_methods
};

struct pythonobj {
    int t;
    pythonobj(int x) {
        int t;
        this -> t = 0;}
        };
    template<int a> 
    std::vector<int> f() {}

PyObject *dict(PyObject *m,int range ) {
 
    if (!PyDict_Check(m)) m = PyDict_New();
    for (int i; i<range;i++) {
        char* f  = "f";
        PyObject *fpy = (PyObject*)f;
        PyDict_SetItem(m, PyObject_Repr(fpy), (PyObject*)i);}

    return m;
    }

int *check(PyObject *m) {
    PyObject *key, *val;
    Py_ssize_t pos = 0;
    int vals[] = {};
    while (PyDict_Next(m , &pos , &key, &val))    {
            PyObject *o = PyLong_FromLong(PyLong_AsLong(val));
            int  i = PyDict_SetItem(m, key,0);
            vals[i] = i;
        }
    return vals;
}
PyObject *  checkAndMake() {
    PyObject *m;
    int  *x = check(m);
    return PyLong_FromLong(*x);
}


PyObject *create(PyModuleDef &e) {
  Py_Initialize();
  PyObject *m = PyModule_Create(&e);
  return m;
}


int main() {
    create(example_definition);
    return 0;
}

