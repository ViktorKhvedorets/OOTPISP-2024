# Лабораторная работа №2 #

## Наследование и виртуальрые функции ##

## Вариант 10 ##


## Цель работы ##
Получить практические навыки создания иерархии классов и использования статических компонентов класса.


### Конструктор базового класса ###
```c++
Document::Document(const string &name)
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
    static Document *begin;
    static Document *last;
```

#### Реализация метода для просмотра списка ####

```c++
void Document::PrintAll()
{
    auto ptr = begin;
    while (ptr != nullptr)
    {
        cout << ptr->GetName() << endl;
        ptr = ptr->GetNext();
    }
}
```

#### Реализация метода для добавления объекта в список ####

```c++
void Document::Add()
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