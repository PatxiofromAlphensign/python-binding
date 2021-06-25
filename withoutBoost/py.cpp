#include <Python.h>
#include <iostream>

PyObject *getstuff(PyObject *self, PyObject *range) {
    int rng;
    if (!PyArg_ParseTuple(range, "i", &rng)) return NULL;
    int X[] = {};
    for (int i; i<rng; i++)  {
        X[i] = i;
    }
    return PyLong_FromLong(X[rng - 2]);

} 

PyObject *noargs() {
    int xint;
    return PyLong_FromLong(xint);
}

static PyMethodDef SpamMethods[] = {
    {"getstuff",  getstuff, METH_VARARGS,
     "test."},
    {"noargs",  (PyCFunction)noargs, METH_NOARGS, "without param."},

   {NULL, NULL, 0, NULL}        /* Sentinel */
};



static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    SpamMethods
};

PyMODINIT_FUNC PyInit_modd(void)
{
    return PyModule_Create(&spammodule);
}


