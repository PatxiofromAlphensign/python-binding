from distutils.core import setup, Extension
from ctypes import cdll
import os

class build_config:
    def ctypes_obj(self):
        flist = os.listdir(os.path.abspath(os.curdir))
        self.sofile =[f for f in flist if f.endswith("so")][0]
        #return cdll.Loadlibrary(s.path.abspath(sofile))
    def get_discription(self):
        with open("README.md", "r") as r:
            return r.read()

c = build_config()
c.ctypes_obj()
name = c.sofile.split(".")[0]

example_module = Extension(
    name,
    sources=['struct.cpp'],
    include_dirs= ["src"],
    extra_link_args=["-lpython3.8", "-lboost_python38"],
    language='C++')

setup(
    name=name,
    description=c.get_discription(),
    ext_modules=[example_module])     
