from distutils.core import setup, Extension

example_module = Extension(
    'example',
    sources=['struct.cpp'],
    extra_link_args=["-lpython3.8", "-lboost_python38"],
    language='C++')

setup(
    name='example',
    version='0.1.0',
    description='example module written in C++',
    ext_modules=[example_module], )            
