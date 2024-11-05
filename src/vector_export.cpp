#include <vector>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "vector_3d.hpp"

namespace py = pybind11;

/**
 * @param vector3d Название python модуля
 * @param module Название переменной, с помощью которой составляется модуль
 */
PYBIND11_MODULE(vector_3d, module)
{
    module.doc() = R"pbdoc(
        vector_3d export to python using pybind11
        -----------------------------------------
    )pbdoc";

    py::class_<math::Vector3D>(module, "Vector3D")
        .def(py::init<>())
        .def(py::init<double, double, double>())
        .def(py::init<const std::vector<double> &>())
        .def("length", &math::Vector3D::length)
        .def("normalize", &math::Vector3D::normalize)
        .def("print", &math::Vector3D::print);


    module
        .def(
            "vectorAddition", 
            &math::vectorAddition, 
            R"pbdoc(Add two 3d vectors)pbdoc")
        .def(
            "vectorSubstraction", 
            &math::vectorSubstraction, 
            R"pbdoc(Substract two 3d vectors)pbdoc")
        .def(
            "vectorDotProduct", 
            &math::vectorDotProduct, 
            R"pbdoc(Return dot product of two 3d vectors)pbdoc");
}