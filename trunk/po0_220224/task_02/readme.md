# Лабораторная работа №2 #

## Наследование и виртуальрые функции ##

## Вариант 10 ##


## Цель работы ##
Получить практические навыки создания иерархии классов и использования статических компонентов класса в с++.


### Конструктор началного класса ###
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
### Статические элементы в классе ###
```c++
    static Document *begin;
    static Document *last;
```

#### Просмотр списка ####

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

#### Добавление в список объекта ####

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
