#pragma once

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <ranges>

// Параметризированный класс VectorOnPriorityQueue для работы с очередью с приоритетом
template <typename T>
class VectorOnPriorityQueue
{
public:
    VectorOnPriorityQueue() = default;
    ~VectorOnPriorityQueue() = default;

    T front() const; // Вернуть первый элемент
    auto operator*(const T value) const; // Оператор умножения всех элементов на значение
    void show() const; // Показать элементы

    void application(const T &value); // Применить элемент (добавить в очередь)

    void fold(const T &key, int position); // Вставить элемент по ключу на заданную позицию
    void deleteEl(const T &key); // Удалить элемент по ключу
    void subMinMax(); // Вычесть разницу между максимальным и минимальным элементами из всех элементов
    int sizeVec() const; // Вернуть размер вектора

private:
    void fromVector(const std::vector<T> &vec); // Инициализировать очередь из вектора

    std::vector<T> toVector() const; // Преобразовать очередь в вектор

    std::priority_queue<T> objects; // Очередь с приоритетом для хранения элементов
};

template <typename T>
void VectorOnPriorityQueue<T>::application(const T &cost)
{
    objects.push(cost);
}

template <typename T>
void VectorOnPriorityQueue<T>::subMinMax()
{
    if (objects.empty())
        return;

    std::vector<T> vec = toVector();
    T min = *std::ranges::min_element(vec);
    T max = *std::ranges::max_element(vec);

    T diff = max - min;

    for (auto &elem : vec)
    {
        elem = elem - diff;
    }

    fromVector(vec);
}

template <typename T>
int VectorOnPriorityQueue<T>::sizeVec() const
{
    return objects.size();
}

template <typename T>
auto VectorOnPriorityQueue<T>::operator*(const T cost) const
{
    VectorOnPriorityQueue<T> newArr;

    for (const auto &elem : toVector())
    {
        newArr.application(elem * cost);
    }

    return newArr;
}

template <typename T>
void VectorOnPriorityQueue<T>::show() const
{
    auto ourvec = toVector();

    std::cout << "{ ";
    for (const auto &elem : ourvec)
    {
        std::cout << elem << " ";
    }
    std::cout << "}" << std::endl;
}

template <typename T>
void VectorOnPriorityQueue<T>::fold(const T &key, int position)
{
    std::vector<T> ourvec = toVector();
    auto it = std::ranges::find(ourvec, key);

    if (it == ourvec.end())
        return;

    if (position < 0 || position > static_cast<int>(ourvec.size()))
        return;

    ourvec.insert(ourvec.begin() + position, *it);
    fromVector(ourvec);
}

template <typename T>
void VectorOnPriorityQueue<T>::deleteEl(const T &key)
{
    std::vector<T> vec = toVector();
    vec.erase(std::remove(vec.begin(), vec.end(), key), vec.end());
    fromVector(vec);
}

template <typename T>
std::vector<T> VectorOnPriorityQueue<T>::toVector() const
{
    std::vector<T> vect;
    std::priority_queue<T> temp = objects;

    while (!temp.empty())
    {
        vect.push_back(temp.top());
        temp.pop();
    }

    std::ranges::reverse(vect);
    return vect;
}

template <typename T>
void VectorOnPriorityQueue<T>::fromVector(const std::vector<T> &vec)
{
    std::priority_queue<T> newQue(vec.begin(), vec.end());
    objects = std::move(newQue);
}

template <typename T>
T VectorOnPriorityQueue<T>::front() const
{
    if (!objects.empty())
        return objects.top();
    return T();
}
