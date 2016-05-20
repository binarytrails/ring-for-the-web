#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <python2.7/Python.h>

int main()
{
    setenv("PYTHONPATH", ".", 1);

    Py_Initialize();

    PyObject* module = PyImport_ImportModule("mymath");
    assert(module != NULL);

    PyObject* klass = PyObject_GetAttrString(module, "math");
    assert(klass != NULL);

    PyObject* instance = PyInstance_New(klass, NULL, NULL);
    assert(instance != NULL);

    PyObject* result = PyObject_CallMethod(instance, "add", "(ii)", 1, 2);
    assert(result != NULL);

    printf("1 + 2 = %ld\n", PyInt_AsLong(result));

    Py_Finalize();

    return 0;
}

