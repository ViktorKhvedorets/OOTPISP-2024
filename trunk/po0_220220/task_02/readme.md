
# Лабораторная работа №2 #

## Наследование и виртуальрые функции ##

## Вариант 6 ##
 

## Цель работы ##
Получить практические навыки создания иерархии классов и использования статических компонентов класса.


### Конструктор базового класса ###
```c++
PrintPublication::PrintPublication(const std::string &name)
    : mName(name)
{
    if (begin == nullptr)
    {
        begin = this;
    }
    next = nullptr;
    if (last != nullptr)
    {
        last->SetNext(this);
    }
    last = this;
}
```

### Статические компоненты класса ###

```c++
    static PrintPublication *begin;
    static PrintPublication *last;
```

#### Реализация метода для просмотра списка ####

```c++
void PrintPublication::PrintAll()
{
    auto ptr = begin;
    while (ptr != nullptr)
    {
        std::cout << ptr->GetName() << std::endl;
        ptr = ptr->GetNext();
    }
}
```

#### Реализация метода для добавления объекта в список ####

```c++
void PrintPublication::Add()
{
    if (begin == nullptr)
    {
        begin = this;
    }
    next = nullptr;
    if (last != nullptr)
    {

        last->SetNext(this);
    }
    last = this;
}
```

#### Если функции не будут виртуальными, то программа не скомпилируется ####


#### Результат работы программы ####

[img_02](images/img_02.png)
