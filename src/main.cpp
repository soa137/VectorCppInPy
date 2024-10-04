#include <pybind11/pybind11.h>
#include <iostream>
#include <memory>
#include<math.h>
 
#define SIZE 3

class Vector3D
{
private:
    std::unique_ptr<float[]> m_array;
public:
    Vector3D()
    {
        m_array = std::make_unique<float[]>(SIZE);
    }
    Vector3D(float x, float y, float z)
        :m_array (new float[SIZE])
    {
        m_array[0] = x;
        m_array[1] = y;
        m_array[2] = z;
    }

    const float length() const
    {
        float x = m_array.get()[0];
        float y = m_array.get()[1];
        float z = m_array.get()[2];

        return sqrt(x*x + y*y + z*z);
    }

    Vector3D& normalization()
    {
        float v_length = this->length();

        for(int i = 0; i < SIZE; ++i)
            m_array.get()[i] /= v_length;

        return *this;
    }

    const float& operator[] (int index ) const { return m_array[index];}

    void print()
    {
        std::cout << "Vector3D (";
        for(int i = 0; i < SIZE; ++i)
            std::cout << m_array.get()[i] << " ";
        std::cout << ")\n";
    }
 
};

Vector3D addition(const Vector3D& v1, const Vector3D& v2)
{
    return Vector3D(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}

Vector3D substraction(const Vector3D& v1, const Vector3D& v2)
{
    return Vector3D(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}

float scalar_prod(const Vector3D& v1, const Vector3D& v2)
{
    return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
}

namespace py = pybind11;

PYBIND11_MODULE(vector2py, m)
{
    m.doc() = R"pbdoc(
    Pybind11 vector2py
    -------------
    )pbdoc";

    m.def("addition", &addition, R"pbdoc(addition vectors)pbdoc");

    m.def("substraction", &substraction, R"pbdoc(substraction vectors)pbdoc");

    m.def("scalarProd", &scalar_prod, R"pbdoc(scalar product vectors)pbdoc");

    py::class_<Vector3D>(m, "Vector3D")
        .def(py::init<float, float, float>())
        .def("length", &Vector3D::length)
        .def("normalization", &Vector3D::normalization)
        .def("print", &Vector3D::print);
}
