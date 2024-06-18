#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <numeric>
#include <optional>

#include "MyMoney.h"
#include "Vector.h"
#include "VectorOnPriorityQueue.h"

template <class T>
void InsertMaxToEnd(std::deque<T> &deq)
{
    auto maximalElement = std::ranges::max_element(deq);
    deq.push_back(*maximalElement);
}

template <class T>
void PopIndexFromDeq(std::deque<T> &deq, const T index)
{
    auto element = std::ranges::find(deq, index);
    deq.erase(element);
}

template <class T>
void AddAverageToDeque(std::deque<T> &deq)
{
    auto avrValue = std::accumulate(deq.begin(), deq.end(), T());
    avrValue = avrValue / static_cast<int>(deq.size());
    std::ranges::for_each(deq, [avrValue](auto &i)
                          { i = i + avrValue; });
}

template <typename T>
void addMaxElement(std::queue<T> &q)
{
    if (q.empty())
    {
        return;
    }

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

// Найти элемент с заданным ключом и удалить его из контейнера
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

// К каждому элементу добавить среднее арифметическое элементов контейнера
template <typename T>
void addAverageToAllElements(std::queue<T> &q)
{
    if (q.empty())
    {
        return;
    }

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

int main()
{
    // TASK 1 //

    std::deque<int> doubleDeque = {1, 2, 4, 3};

    addElementAtPosition(doubleDeque, 2, 3);
    deleteElementFromDeque(doubleDeque, 1);
    subtractDifferenceMaxMin(doubleDeque);

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

	putMinToEnd(moneybagVec);
	findByKeyAndDelete(moneybagVec, Money(1.50));
	addAllMinMaxSum(moneybagVec);
	for (auto elt1 : moneybagVec)
	{
		std::cout << elt1 << std::endl;
	}

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

    // TASK 5 //

    QVector<int> qvectorOfInts;
    qvectorOfInts.append(1);
    qvectorOfInts.append(1);
    qvectorOfInts.append(2);
    qvectorOfInts.append(11);
    qvectorOfInts.append(11);

    qvectorOfInts.addMaxElement();
    qvectorOfInts.removeElement(1);
    qvectorOfInts.addAverageToAllElements();

    qvectorOfInts.print();
}