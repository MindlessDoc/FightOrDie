#pragma once

#include <iostream>
#include <string>
#include <memory>

template<class T>
class Vector
{
public:
    Vector() {}

    Vector(size_t size)
        :_size(size)
        ,_max_size(CreateMaxSize(_size))
    {
        _array = new T[_max_size];
    }

    Vector(const Vector& other)
        :_size(other._size)
        ,_max_size(other._max_size)
    {
        _array = new T[_max_size];
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
        try
        {
            if(index >= _size)
            {
                throw "Invalid index";
            }
            return _array[index];
        }
        catch (std::string exception)
        {
            std::cout << "Error: " << exception << std::endl;
        }
    }

    const T& operator[](size_t index) const
    {
        try
        {
            if(index >= _size)
            {
                throw "Invalid index";
            }

            return _array[index];
        }
        catch (std::string exception)
        {
            std::cout << "Error: " << exception << std::endl;
        }
    }

    Vector& operator= (const Vector& other)
    {
        if(&other == this)
            return *this;

        _size = other._size;
        _max_size = other._max_size;

        delete[] _array;
        _array = new T[_max_size];
        for(size_t i = 0; i < _size; i++)
        {
            _array[i] = other._array[i];
        }

        return *this;
    }

    void push_back(T elemetn)
    {
        if(_size >= _max_size)
        {
            resize(_size);
        }
        _array[_size++] = elemetn;
    }

    void resize(size_t size)
    {
        _max_size = CreateMaxSize(size);
        T* newArray = new T[_max_size];
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

    size_t size()
    {
        return _size;
    }


private:
    T* _array = nullptr;
    size_t _size = 0;
    size_t _max_size = 0;

    size_t CreateMaxSize(size_t size)
    {
        size_t max_size = 2;
        while(max_size <= size)
        {
            max_size <<= 1;
        }
        return max_size;
    }
};
