#ifndef VECTOR_3D_HPP
#define VECTOR_3D_HPP

#include <memory>
#include <vector>

namespace math
{
    class Vector3D
    {
    public:
        /// @brief Конструктор
        Vector3D();

        /// @brief Конструктор
        Vector3D(double, double, double);

        /// @brief Конструктор
        Vector3D(const std::vector<double> &);

        /// @brief Конструктор копирования
        Vector3D(const Vector3D &);

        /// @brief Конструктор перемещения
        Vector3D(Vector3D &&);

        /// @brief Оператор присваивания копированием
        Vector3D &operator=(const Vector3D &);

        /// @brief Оператор присваивания перемещением
        Vector3D &operator=(Vector3D &&);

        /// @brief Выводит адрес указателя и координаты вектора
        void print();

        /**
         * @brief Выполняет нормализацию переданного в аргументе вектора
         */
        friend void normalize(std::shared_ptr<Vector3D> &);

    protected:
        /**
         * @brief Указатель на std::vector с контравариантными координиатами 3d
         * вектора
        */
        std::unique_ptr<std::vector<double>> coords_;
    };

    /**
     * @brief Выполняет нормализацию переданного в аргументе вектора
     */
    void normalize(std::shared_ptr<Vector3D> &);
    
}

#endif