#include <assert.h>
#include <python2.7/Python.h>

int main()
{
    setenv("PYTHONPATH", ".", 1);

    Py_Initialize();

    PyObject* serverModule = PyImport_ImportModule("server");
    assert(serverModule != NULL);

    PyObject* startServerFunc = PyObject_GetAttrString(serverModule, "startServer");
    assert(startServerFunc != NULL);

    PyObject_CallObject(startServerFunc, NULL);

    Py_Finalize();

    return 0;
}
