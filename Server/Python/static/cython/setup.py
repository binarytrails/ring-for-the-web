from setuptools import setup, Extension
from Cython.Build import cythonize
from Cython.Distutils import build_ext

setup(name="daemon_cpp",
      ext_modules = cythonize(Extension(
          "daemon_cpp",
          ["daemon_cpp.pyx", "daemon.cpp"],
          language="c++",
          extra_compile_args=["-std=c++11"],
      )),
      cmdclass = {'build_ext' : build_ext}
)
