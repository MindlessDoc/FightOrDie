#pragma once

#include <iostream>
#include <memory>

template<class T>
class Vector
{
public:
    Vector() {}

    ~Vector()
    {
        delete[] _array;
    }

    T& operator[](size_t index)
    {
        return _array[index];
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
