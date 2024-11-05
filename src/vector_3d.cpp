#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

#include <pybind11/pybind11.h>

#include "vector_3d.hpp"

math::Vector3D::Vector3D()
    : coords_(std::make_unique<std::vector<double>>((size_t)3))
{
}

math::Vector3D::Vector3D(double a, double b, double c)
    : math::Vector3D::Vector3D()
{
    *this->coords_ = {a, b, c};
}

math::Vector3D::Vector3D(const std::vector<double> &vector)
    : math::Vector3D::Vector3D()
{
    // Проверка корректности аргумента
    if (vector.size() != 3)
    {
        throw std::invalid_argument(
            std::string("Vector3D: Incorrect size of given vector: "
                        "expected size is 3; "
                        "size of given vector is ") +
            std::to_string(vector.size()) + std::string("\n"));
    }

    // Поверхностное копирование переданного вектора 
    *this->coords_ = vector;
}

math::Vector3D::Vector3D(const math::Vector3D &vector_3d)
{  
    /* 
    Использование оператора присваивания копированием, чтобы не дублировать
    код
    */
    *this = vector_3d;
}

math::Vector3D::Vector3D(math::Vector3D &&vector_3d)
{
    /* 
    Использование оператора присваивания перемещением, чтобы не дублировать
    код
    */
    *this = std::move(vector_3d);
}

math::Vector3D &math::Vector3D::operator=(const Vector3D &vector_3d)
{
    // Проверка корректности аргумента
    if (!vector_3d.coords_)
    {
        throw std::invalid_argument("Vector3D: Trying to copy from nullptr");
    }

    // Копирование координат переданного вектора
    if (this->coords_)
    {
        /*
        Экземпляр владеет объектом std::vector<double>:
        Копирование в существующий объект std::vector<double> 
        */
        *this->coords_ = *vector_3d.coords_;
    }
    else
    {
        /* 
        Экземпляр не владеет объектом std::vector<double>:
        Создание объекта std::vector<double> и его инициализация копированием.
        */
        this->coords_ = std::make_unique<std::vector<double>>(*vector_3d.coords_);
    }

    return *this;
}

math::Vector3D &math::Vector3D::operator=(Vector3D &&vector_3d)
{
    // Передача владения объектом типа std::vector<double> 
    this->coords_ = std::move(vector_3d.coords_);
    
    return *this;
}

void math::Vector3D::print() const
{
    std::cout << "Vector3D:\nunique_ptr:" << this->coords_.get() << "\n"; 
    if (!this->coords_)
    {
        return;
    }
    std::cout  <<"coords: ";
    for (double coord : *this->coords_) 
    {
        std::cout << coord << " ";
    }
    std::cout << "\n";
}


double math::Vector3D::length() const
{
    // Квадрат длины вектора
    double vector_length_sq {0};
    for (double coord : *this->coords_)
    {
        vector_length_sq += coord * coord;
    }
    return std::sqrt(vector_length_sq);
}


void math::Vector3D::normalize()
{
    // Вычисление длины вектора
    double vector_length {this->length()};

    // Нормализация
    for (double &coord : *this->coords_)
    {
        coord /= vector_length;
    }
}

math::Vector3D math::vectorAddition(
    const math::Vector3D &vector_1, const math::Vector3D &vector_2)
{
    math::Vector3D result_vector;
    for(int i{0}; i < result_vector.coords_->size(); i++)
    {
        (*result_vector.coords_)[i] = 
            (*vector_1.coords_)[i] + (*vector_2.coords_)[i];
    } 
    return result_vector;
}

math::Vector3D math::vectorSubstraction(
    const math::Vector3D &vector_1, const math::Vector3D &vector_2)
{
    math::Vector3D result_vector;
    for(int i{0}; i < result_vector.coords_->size(); i++)
    {
        (*result_vector.coords_)[i] = 
            (*vector_1.coords_)[i] - (*vector_2.coords_)[i];
    } 
    return result_vector;
}

math::Vector3D math::vectorDotProduct(
    const math::Vector3D &vector_1, const math::Vector3D &vector_2)
{
    math::Vector3D result_vector;
    for(int i{0}; i < result_vector.coords_->size(); i++)
    {
        (*result_vector.coords_)[i] = 
            (*vector_1.coords_)[i] * (*vector_2.coords_)[i];
    } 
    return result_vector;
}