from setuptools import setup, Extension
from Cython.Build import cythonize
from Cython.Distutils import build_ext

setup(name="dring",
      ext_modules = cythonize(Extension(
          "dring",
          ["dring.pyx", "cpp/daemon.cpp"],
          language="c++",
          extra_compile_args=["-std=c++11"],
      )),
      cmdclass = {'build_ext' : build_ext}
)
