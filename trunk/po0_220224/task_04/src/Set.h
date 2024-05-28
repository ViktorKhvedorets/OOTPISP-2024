#pragma once
#include <iostream>
#include <memory>
#include <vector>

template <typename T>
class Set
{
public:
    Set() = default;
    ~Set() = default;

    void Add(const T& element)
    {
        if (!Contains(element))
        {
            if (count >= capacity)
            {
                auto newElements = std::make_unique<std::vector<T>>(capacity * 2);
                for (int i = 0; i < count; ++i)
                {
                    (*newElements)[i] = (*elements)[i];
                }
                elements = std::move(newElements);
                capacity *= 2;
            }
            (*elements)[count] = element;
            count++;
        }
    }

    void Remove(const T& element)
    {
        for (int i = 0; i < count; ++i)
        {
            if ((*elements)[i] == element)
            {
                for (int j = i; j < count - 1; ++j)
                {
                    (*elements)[j] = (*elements)[j + 1];
                }
                --count;
                return;
            }
        }
    }

    bool Contains(const T& element) const
    {
        for (int i = 0; i < count; ++i)
        {
            if ((*elements)[i] == element)
            {
                return true;
            }
        }
        return false;
    }

    int Size() const
    {
        return count;
    }

    void print() const
    {
        std::cout << "{ ";
        for (int i = 0; i < count; ++i)
        {
            std::cout << (*elements)[i] << " ";
        }
        std::cout << "}" << std::endl;
    }

    
    T operator[](const int index) const
    {
        if (index >= 0 && index < count)
        {
            return (*elements)[index];
        }
        throw std::out_of_range("Index out of range");
    }

   
    bool operator()(const T& element) const
    {
        return Contains(element);
    }

    
    bool operator!=(const Set<T>& rhs) const
    {
        if (this->count != rhs.count)
        {
            return true;
        }
        for (int i = 0; i < this->count; ++i)
        {
            if (!rhs.Contains((*this->elements)[i]))
            {
                return true;
            }
        }
        return false;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const Set<U>& a);

    template <typename U>
    friend std::istream& operator>>(std::istream& in, Set<U>& a);

private:
    std::unique_ptr<std::vector<T>> elements = std::make_unique<std::vector<T>>(2);
    int capacity = 2;
    int count = 0;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Set<T>& a)
{
    a.print();
    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, Set<T>& a)
{
    T temp;
    while (in >> temp)
    {
        a.Add(temp);
    }
    return in;
}
