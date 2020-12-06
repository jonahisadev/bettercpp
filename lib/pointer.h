#pragma once

template <typename T>
class RefPtr
{
private:
    T* _ptr;
    unsigned int* _ref;

public:
    RefPtr()
        : _ptr(nullptr), _ref(new unsigned int(0))
    {}

    RefPtr(T* data)
        : _ptr(data), _ref(new unsigned int(1))
    {}

    RefPtr(const RefPtr<T>& other)
    {
        if (&other != this) {
            _ref = other._ref;
            _ptr = other._ptr;

            (*_ref)++;
        }
    }

    RefPtr<T>& operator=(const RefPtr<T>& other)
    {
        if (&other != this) {
            _ref = other._ref;
            _ptr = other._ptr;

            (*_ref)++;
        }

        return *this;
    }

    ~RefPtr()
    {
        (*_ref)--;
        if (*_ref == 0 && _ptr)
            delete _ptr;
    }

    T* get()
    {
        return _ptr;
    }

    T* operator->()
    {
        return _ptr;
    }

    T& operator*()
    {
        if (_ptr)
            return *_ptr;
        throw;
    }
};

template <typename T>
static RefPtr<T> make_ref(const T& data)
{
    T* t = new T(data);
    return RefPtr<T>(t);
}

template <typename T>
static RefPtr<T> make_ref(const T* data)
{
    T* t = new T(*t);
    return RefPtr<T>(t);
}