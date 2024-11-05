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
        void print() const;

        /**
         * @brief Вычисляет длину переданного вектор
         */
        double length() const;

        /**
         * @brief Выполняет нормализацию переданного в аргументе вектора
         */
        void normalize();

        /**
         * @brief Возвращает сумму 3D векторов
         */
        friend Vector3D vectorAddition(const Vector3D &, const Vector3D &);

        /**
         * @brief Возвращает разность 3D векторов
         */
        friend Vector3D vectorSubstraction(const Vector3D &, const Vector3D &);

        /**
         * @brief Возвращает скалярное произведение 3D векторов
         */
        friend Vector3D vectorDotProduct(const Vector3D &, const Vector3D &);

    protected:
        /**
         * @brief Указатель на std::vector с контравариантными координиатами 3d
         * вектора
         */
        std::unique_ptr<std::vector<double>> coords_;
    };

    /**
     * @brief Возвращает сумму 3D векторов
     */
    Vector3D vectorAddition(const Vector3D &, const Vector3D &);

    /**
     * @brief Возвращает разность 3D векторов
     */
    Vector3D vectorSubstraction(const Vector3D &, const Vector3D &);

    /**
     * @brief Возвращает скалярное произведение 3D векторов
     */
    Vector3D vectorDotProduct(const Vector3D &, const Vector3D &);
}

#endif