#ifdef linux
#include "Python.h"
#endif
#ifdef _WIN32
#include "C:/Python36/include/Python.h"
#endif

static PyObject *modify_co_consts(PyObject *self, PyObject *args) {
  // (function, object)
  PyObject *function_obj, *object;
  Py_ssize_t pos;
  if (!PyArg_ParseTuple(args, "OOn", &function_obj, &object, &pos))
    return NULL;

  PyFunctionObject *function = (PyFunctionObject *)function_obj;
  PyObject *consts = ((PyCodeObject *)function->func_code)->co_consts;
  Py_IncRef(object);
  PyTuple_SET_ITEM(consts, pos, object); // do that instead
  Py_RETURN_NONE;
}

static char module_docstring[] = "Replace constants in a function";
static char modify_co_consts_docstring[] =
    "Usage: edit_co_consts.modify_co_consts(func, object, index)";

static PyMethodDef module_methods[] = {{"modify_co_consts", modify_co_consts,
                                        METH_VARARGS,
                                        modify_co_consts_docstring},
                                       {NULL, NULL, 0, NULL}};

static struct PyModuleDef init_fuck_module = {
    PyModuleDef_HEAD_INIT, "edit_co_consts", module_docstring, -1,
    module_methods};

PyMODINIT_FUNC PyInit_edit_co_consts() {
  return PyModule_Create(&init_fuck_module);
}
