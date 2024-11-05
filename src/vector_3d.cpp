#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

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

void math::Vector3D::print()
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

void math::normalize(std::shared_ptr<math::Vector3D> &vector_3d)
{
    // Вычисление длины вектора
    double vector_length {0};
    for (double coord : *vector_3d->coords_)
    {
        vector_length += coord * coord;
    }
    vector_length = std::sqrt(vector_length);

    // Нормализация
    for (double &coord : *vector_3d->coords_)
    {
        coord /= vector_length;
    }
}

