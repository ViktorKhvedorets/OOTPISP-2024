#pragma once
#ifndef VECTOR
#define VECTOR
#include <queue>
#include <iostream>


template <class T>
class Vector
{
public:
	Vector() = default;
	explicit Vector(int n);
	~Vector() = default;
	void Print() const;
	void Add(const T& a);
	void putMinToEnd();
	void findByKeyAndDelete(T key);
	void addAllMinMaxSum();
private:
	std::queue <T> _q;
	int _len = 0;
};

#endif

template<class T>
inline void Vector<T>::Print() const
{
	std::queue <T> tmp_q = _q;
	for (int i = 0; i < _len;  i++)
	{
		std::cout << tmp_q.front() << std::endl;
		tmp_q.pop();
	}
}

template<class T>
inline void Vector<T>::Add(const T& a)
{
	_q.push(a);
	_len++;
}

template<class T>
inline void Vector<T>::putMinToEnd()
{
	int index = 0;
	std::queue<T> tmp_q = _q;
	T tmp = tmp_q.front(); tmp_q.pop();
	for (int i = 1; i < _q.size(); i++)
	{
		T tmp1 = tmp_q.front(); tmp_q.pop();
			if (tmp1 < tmp)
			{
				index = i;
				tmp = tmp1;
			}
	}
	auto len = static_cast<int>(_q.size());
	tmp_q = _q;
	for (int i = 0; i < len; i++)
	{
		_q.pop();
		if (i != index)
			_q.push(tmp_q.front());
		tmp_q.pop();
	}
	_q.push(tmp);
}

template<class T>
inline void Vector<T>::findByKeyAndDelete(T key)
{
	int index = 0;
	std::queue<T> tmp_q = _q;
	for (int i = 0; i < _q.size(); i++)
	{
		if (tmp_q.front() == key)
		{
			index = i;
		}
		tmp_q.pop();
	}
	auto len = static_cast<int>(_q.size());
	tmp_q = _q;
	for (int i = 0; i < len; i++)
	{
		_q.pop();
		if (i != index)
		{
			_q.push(tmp_q.front());
			tmp_q.pop();
		}
	}
	_len--;
}

template<class T>
inline void Vector<T>::addAllMinMaxSum()
{
	std::queue<T> tmp_q = _q;
	T min = tmp_q.front(); tmp_q.pop();
	for (int i = 1; i < _q.size(); i++)
	{
		T tmp1 = tmp_q.front(); tmp_q.pop();
		if (tmp1 < min)
		{
			min = tmp1;
		}
	}

	tmp_q = _q;
	T max = tmp_q.front(); tmp_q.pop();
	for (int i = 1; i < _q.size(); i++)
	{
		T tmp1 = tmp_q.front(); tmp_q.pop();
		if (tmp1 > max)
		{
			max = tmp1;
		}
	}

	T sum = min + max;
	auto len = static_cast<int>(_q.size());
	tmp_q = _q;
	for (int i = 0; i < len; i++)
	{
		_q.pop();
		_q.push(tmp_q.front() + sum);
		tmp_q.pop();
	}

}


template<class T>
inline Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a;
		_q.push(a);
	}
	_len = _q.size();
}