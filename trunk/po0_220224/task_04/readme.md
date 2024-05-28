
# Лабораторная работа №4 #

## Шаблоны классов ##

## Вариант 9 ##
 

## Цель работы ##
Создание консольного приложения, состоящего  файлов в системе  программирования Visual Studio. Реализация шаблона класса-контейнера. 

### Перегрузка операций ввода/вывода в классе Set ###
```c++
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
```

### Перегрузка операторов ввода/вывода в классе Money ###

```c++
friend std::ostream& operator<<(std::ostream& out, const Money& a)
	{
		out << a.GetRubles() << " Rub, " << a.GetPenny() << " Kopeks" << std::endl;
		return out;
	}

	friend std::istream& operator>>(std::istream& in, Money& a)
	{
		std::cout << "Enter the amount of rubles" << std::endl;
		in >> a.rub;
		std::cout << "Enter the amount of kopecks" << std::endl;
		in >> a.pennys;
		return in;
	}
```

### Перегрузка оператора != класса Set для проверки на неравенство ###

```c++
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
```

### Перегрузка оператора ()  класса Set для определения принадлежности числа множеству ###

```c++
bool operator()(const T& element) const
    {
        return Contains(element);
    }

```

### Перегрузка оператора [] класса Set для обращения к элементу по индексу ###

```c++
T operator[](const int index) const
    {
        if (index >= 0 && index < count)
        {
            return (*elements)[index];
        }
        throw std::out_of_range("Index out of range");
    }
```

