#include <Python.h> 
#include <stdlib.h> 
#include <iostream> 

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
    {"adder", add, METH_VARARGS}
};

static struct PyModuleDef example_definition = {
    PyModuleDef_HEAD_INIT,
    "example",
    "test",
    -1,
    example_methods
};

PyMODINIT_FUNC PyInit_modd(void) {
  Py_Initialize();
  PyObject *m = PyModule_Create(&example_definition);
  return m;
}

