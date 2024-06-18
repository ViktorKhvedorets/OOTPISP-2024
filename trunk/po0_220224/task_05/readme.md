
# Лабораторная работа №5 #

## Последовательные контейнеры библиотеки STL ##

## Вариант 9 ##

## Цель работы ##

Создание консольного приложения, состоящего из нескольких файлов в системе  программирования Visual Studio. Использование последовательных контейнеров библиотеки STL в ОО  программе.

### Задания для первой и второй задачи ###

```c++

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

```

### Задания для третьей задачи ###

```c++

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

```

### Задания для четвертой и пятой задачи ###

```c++

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

```
