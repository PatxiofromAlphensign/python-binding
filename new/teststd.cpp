#include <Python.h>
#include <iostream>

void update(int *k) {
    *k += 1;
    *k += *k << 2;
}

static PyObject *mainm(PyObject *self, PyObject *args) {
    int cmd;
    if (!PyArg_ParseTuple(args, "s", &cmd)) {return NULL;}
    update(&cmd);
    return PyLong_FromLong(cmd);
}

int decor(int i) {
    if (!(system("test") < 0)) {return i;}
    else {return 0;}
}

static PyMethodDef ex_m[] ={{"mainm", mainm, METH_VARARGS}};
static struct PyModuleDef ex= {PyModuleDef_HEAD_INIT, "ex", "test", -1, ex_m};

PyMODINIT_FUNC init(void) {
    PyObject *m = PyModule_Create(&ex);
    return m;
}


int main() {
    int k =0;
    update(&k);
    std::cout << decor(k);
    return 0;}

