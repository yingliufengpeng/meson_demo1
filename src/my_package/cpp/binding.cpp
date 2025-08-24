#include <pybind11/pybind11.h>
#include "my_code.h"

namespace py = pybind11;

PYBIND11_MODULE(_my_package, m) {
m.doc() = "Python bindings for my C++ code";
m.def("greet", &greet, "Greet a person by name", py::arg("name"));
}