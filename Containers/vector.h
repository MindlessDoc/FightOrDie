#pragma once

#include <iostream>
#include <memory>
#include <vector>

template<class T>
class Vector
{
public:
    Vector() {}

    Vector(size_t size)
        :_size(size)
    {
        _array = new T[_size];
    }

    Vector(const Vector& other)
        :_size(other._size)
    {
        _array = new T[_size];
        for(size_t i = 0; i < _size; i++)
        {
            _array[i] = other._array[i];
        }
    }

    ~Vector()
    {
        delete[] _array;
    }

    T& operator[](size_t index)
    {
        return _array[index];
    }

    const T& operator[](size_t index) const
    {
        return _array[index];
    }

    Vector& operator= (const Vector& other)
    {
        if(&other == this)
            return *this;

        _size = other._size;

        delete[] _array;
        _array = new T[_size];
        for(size_t i = 0; i < _size; i++)
        {
            _array[i] = other._array[i];
        }

        return *this;
    }

    void resize(size_t size)
    {
        T* newArray = new T[size];
        for(size_t i = 0; i < std::min(_size, size); i++)
        {
            newArray[i] = _array[i];
        }
        _size = size;
        delete[] _array;
        _array = newArray;
    }

    bool empty()
    {
        return !_size;
    }
private:
    T* _array = nullptr;
    size_t _size = 0;
};
