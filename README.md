Python binding or extention demos for libary written in c++
----

![travis](https://travis-ci.org/PatxiofromAlphensign/python-binding.svg?branch=master)

### presupposing

- `boost.python` (#sources)
- default `python.h` (#sources) (from `python3-dev`)

or `Python.h`. :o:
- unwrap methods of `boost.python` and `python.h` :x:

### main focus

Easily to do computations and ops using the exposed python api. All the different types of objects representing different types of computaions are being added as frequenctly as possible. The core focus is :

### notes
    - made initial wrapper for python in py.cpp and struct.cpp .
    - main classes should be put into `src/`.

### TODO 
    - type equivance with python and c++
    - type conversion between c++ and python
    - extend the lib to defining numeric computations
    - implement different text and image algorithms

### sources

- [tutorial](https://docs.python.org/3/extending/extending.html) in which `Python.h` is employed.

- [tutorial](https://www.boost.org/doc/libs/1_70_0/libs/python/doc/html/tutorial/index.html) in which `boost.python.hpp` is employed.
