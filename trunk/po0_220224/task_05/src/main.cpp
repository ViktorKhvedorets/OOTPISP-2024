#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <numeric>
#include <optional>
#include <stack>

#include "Money.h"
#include "Vector.h"
#include "VectorOnPriorityQueue.h"

// Вставить максимальный элемент в конец deque
template <class T>
void InsertMaxToEnd(std::deque<T> &deq)
{
    auto maximalElement = std::ranges::max_element(deq);
    deq.push_back(*maximalElement);
}

// Удалить элемент по индексу из deque
template <class T>
void PopIndexFromDeq(std::deque<T> &deq, const T index)
{
    if (index < 0 || index >= deq.size()) return;
    auto element = deq.begin() + index;
    deq.erase(element);
}

// Добавить среднее арифметическое ко всем элементам deque
template <class T>
void AddAverageToDeque(std::deque<T> &deq)
{
    T sum = std::accumulate(deq.begin(), deq.end(), T());
    T average = sum / static_cast<int>(deq.size());
    std::ranges::for_each(deq, [average](auto &i)
    {
        i = i + average;
    });
}

// Вставить максимальный элемент в конец очереди
template <typename T>
void addMaxElement(std::queue<T> &q)
{
    if (q.empty()) return;

    std::queue<T> tempQueue = q;
    T maxElement = tempQueue.front();
    while (!tempQueue.empty())
    {
        if (tempQueue.front() > maxElement)
        {
            maxElement = tempQueue.front();
        }
        tempQueue.pop();
    }
    q.push(maxElement);
}

// Найти элемент с заданным ключом и удалить его из очереди
template <typename T>
void removeElement(std::queue<T> &q, const T &key)
{
    std::queue<T> tempQueue;
    while (!q.empty())
    {
        if (q.front() != key)
        {
            tempQueue.push(q.front());
        }
        q.pop();
    }
    q = std::move(tempQueue);
}

// Добавить среднее арифметическое ко всем элементам очереди
template <typename T>
void addAverageToAllElements(std::queue<T> &q)
{
    if (q.empty()) return;

    std::vector<T> elements;
    std::queue<T> tempQueue = q;
    while (!tempQueue.empty())
    {
        elements.push_back(tempQueue.front());
        tempQueue.pop();
    }

    T sum = std::accumulate(elements.begin(), elements.end(), T{});
    T average = sum / static_cast<int>(elements.size());

    for (auto &elem : elements)
    {
        elem = elem + average;
    }

    q = std::queue<T>();
    for (const auto &elem : elements)
    {
        q.push(elem);
    }
}

// Вставить максимальный элемент в начало стека
template <typename T>
void PushMaxToBeginStack(std::stack<T> &stk)
{
    if (stk.empty()) return;

    std::stack<T> tempStack = stk;
    T maxElement = tempStack.top();
    while (!tempStack.empty())
    {
        if (tempStack.top() > maxElement)
        {
            maxElement = tempStack.top();
        }
        tempStack.pop();
    }

    std::stack<T> newStack;
    newStack.push(maxElement);
    while (!stk.empty())
    {
        newStack.push(stk.top());
        stk.pop();
    }
    stk = std::move(newStack);
}

// Удалить минимальный элемент из стека
template <typename T>
void DeleteMinStack(std::stack<T> &stk)
{
    if (stk.empty()) return;

    std::stack<T> tempStack = stk;
    T minElement = tempStack.top();
    while (!tempStack.empty())
    {
        if (tempStack.top() < minElement)
        {
            minElement = tempStack.top();
        }
        tempStack.pop();
    }

    std::stack<T> newStack;
    while (!stk.empty())
    {
        if (stk.top() != minElement)
        {
            newStack.push(stk.top());
        }
        stk.pop();
    }

    while (!newStack.empty())
    {
        stk.push(newStack.top());
        newStack.pop();
    }
}

// Добавить среднее арифметическое ко всем элементам стека
template <typename T>
void AddAverageValueToStack(std::stack<T> &stk)
{
    if (stk.empty()) return;

    std::stack<T> tempStack = stk;
    std::vector<T> elements;
    while (!tempStack.empty())
    {
        elements.push_back(tempStack.top());
        tempStack.pop();
    }

    T sum = std::accumulate(elements.begin(), elements.end(), T{});
    T average = sum / static_cast<int>(elements.size());

    for (auto &elem : elements)
    {
        elem = elem + average;
    }

    std::stack<T> newStack;
    for (auto it = elements.rbegin(); it != elements.rend(); ++it)
    {
        newStack.push(*it);
    }
    stk = std::move(newStack);
}

int main()
{
    // TASK 1 //

    std::deque<int> doubleDeque = {1, 2, 4, 3};

    InsertMaxToEnd(doubleDeque);
    PopIndexFromDeq(doubleDeque, 2);
    AddAverageToDeque(doubleDeque);

    for (const auto &i : doubleDeque)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    // TASK 2 //

    std::vector<Money> moneybagVec;
    moneybagVec.push_back(Money(1.50));
    moneybagVec.push_back(Money(1.20));
    moneybagVec.push_back(Money(1.10));
    moneybagVec.push_back(Money(2.50));
    moneybagVec.push_back(Money(2.00));

    VectorOnPriorityQueue<Money> vectorOnPQ;
    for (const auto &m : moneybagVec)
    {
        vectorOnPQ.application(m);
    }

    vectorOnPQ.show();
    vectorOnPQ.fold(Money(1.50), 2);
    vectorOnPQ.deleteEl(Money(1.20));
    vectorOnPQ.subMinMax();
    vectorOnPQ.show();

    // TASK 3 //

    Vector<int> vectorOfInts;
    vectorOfInts.append(1);
    vectorOfInts.append(1);
    vectorOfInts.append(2);
    vectorOfInts.append(0);
    vectorOfInts.append(5);

    vectorOfInts.addMaxElement();
    vectorOfInts.removeElement(1);
    vectorOfInts.addAverageToAllElements();

    vectorOfInts.print();

    // TASK 4 //

    std::stack<Money> somePieceOfStack;

    somePieceOfStack.push(Money(1.66));
    somePieceOfStack.push(Money(4.51));
    somePieceOfStack.push(Money(0.4));
    somePieceOfStack.push(Money(6.53));

    PushMaxToBeginStack(somePieceOfStack);
    DeleteMinStack(somePieceOfStack);
    AddAverageValueToStack(somePieceOfStack);

    while (!somePieceOfStack.empty())
    {
        std::cout << somePieceOfStack.top() << " ";
        somePieceOfStack.pop();
    }

    std::cout << std::endl;

    return 0;
}
