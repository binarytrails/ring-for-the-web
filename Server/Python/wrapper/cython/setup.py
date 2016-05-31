from setuptools import setup, Extension
from Cython.Build import cythonize
from Cython.Distutils import build_ext

setup(name="dring",
      ext_modules = cythonize(Extension(
          "dring",
          ["dring.pyx"],
          language="c++",
          extra_compile_args=["-std=c++11", "-fPIC"],
          extra_link_args=["-std=c++11"],
          #libraries=["ring"],
          extra_objects=["/usr/lib/libring.a"],
          include_dirs = ["/usr/include/dring"],
      )),
      cmdclass = {'build_ext' : build_ext}
)
