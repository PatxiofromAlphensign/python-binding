from distutils.core import setup, Extension

example_module = Extension(
    'py',
    sources=['py.cpp'],
    language='C++', )

setup(
    name='py',
    version='0.1.0',
    description='example module written in C++',
    ext_modules=[example_module], )
