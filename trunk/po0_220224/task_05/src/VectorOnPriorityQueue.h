#pragma once
#ifndef VECTORH
#define VECTORH
#include <vector>
#include <iostream>

template<class T>
class MyVector
{
public:
	MyVector() = default;
	explicit MyVector(int n);
	~MyVector() = default;
	void Print() const;
	void Add(const T& a);
	void putMinToEnd();
	void findByKeyAndDelete(T key);
	void addAllMinMaxSum();
private:
	std::vector <T> _vect;
	int leng = 0;
};

#endif 

template<class T>
inline MyVector<T>::MyVector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a;
		_vect.push_back(a);
	}
	leng = _vect.size();
}

template<class T>
inline void MyVector<T>::Print() const
{
	for (int i = 0; i < _vect.size(); i++)
	{
		std::cout << _vect[i] << std::endl;
	}
}

template<class T>
inline void MyVector<T>::Add(const T& a)
{
	_vect.push_back(a);
	leng++;
}

template<class T>
inline void MyVector<T>::putMinToEnd()
{
	int index = 0;
	T tmp = _vect[0];
	for (int i = 1; i < _vect.size(); i++)
	{
		if (_vect[i] < tmp)
		{
			index = i;
			tmp = _vect[i];
		}
	}

	_vect.erase(_vect.begin() + index);

	_vect.push_back(tmp);
}

template<class T>
inline void MyVector<T>::findByKeyAndDelete(T key)
{
	int index = 0;
	for (int i = 0; i < _vect.size(); i++)
	{
		if (_vect[i] == key)
		{
			index = i;
			_vect.erase(_vect.begin() + index);
			break;
		}
	}
	leng--;
}

template<class T>
inline void MyVector<T>::addAllMinMaxSum()
{
	int index = 0;
	T min = _vect[0];
	for (int i = 1; i < _vect.size(); i++)
	{
		if (_vect[i] < min)
		{
			index = i;
			min = _vect[i];
		}
	}

	int index1 = 0;
	T max = _vect[0];
	for (int i = 1; i < _vect.size(); i++)
	{
		if (_vect[i] > max)
		{
			index1 = i;
			max = _vect[i];
		}
	}

	T sum = min + max;

	for (int i = 0; i < _vect.size(); i++)
	{
		_vect[i] = _vect[i] + sum;
	}
}
