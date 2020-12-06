#pragma once

#include <string>
#include <iostream>
#include <cstring>

class String
{
private:
    char* _data;
    size_t _len;

public:
    // Constructors and stuff
    String();
    String(const char* c_str);
    String(const String& other);
    String(String&& other);
    String& operator=(const String& other);
    String& operator=(String&& other);
    ~String();

    // Utilities
    const char* c_str() const;
    std::string std_str() const;
    char at(size_t index) const;

    // Operators
    char& operator[](size_t index);
    friend std::ostream& operator<<(std::ostream& os, const String& str);

    // Static
    static String from_std_string(const std::string& std_str);
};

String::String()
    : _data(nullptr), _len(0)
{}

String::String(const char* c_str)
    : _data(nullptr), _len(0)
{
    _len = strlen(c_str);
    _data = new char[_len + 1];
    for (int i = 0; i < _len; i++)
        _data[i] = c_str[i];
    _data[_len] = '\0';
}

String::String(const String& other)
{
    if (&other != this) {
        _len = other._len;
        _data = new char[_len + 1];
        for (int i = 0; i < _len; i++)
            _data[i] = other._data[i];
        _data[_len] = '\0';
    }
}

String::String(String&& other)
{
    if (&other != this) {
        _len = other._len;
        _data = new char[_len + 1];
        for (int i = 0; i < _len; i++)
            _data[i] = other._data[i];
        _data[_len] = '\0';

        if (other._data)
            delete[] other._data;
    }
}

String& String::operator=(const String& other)
{
    if (&other != this) {
        _len = other._len;
        _data = new char[_len + 1];
        for (int i = 0; i < _len; i++)
            _data[i] = other._data[i];
        _data[_len] = '\0';
    }

    return *this;
}

String& String::operator=(String&& other)
{
    if (&other != this) {
        _len = other._len;
        _data = new char[_len + 1];
        for (int i = 0; i < _len; i++)
            _data[i] = other._data[i];
        _data[_len] = '\0';

        if (other._data)
            delete[] other._data;
    }

    return *this;
}

String::~String()
{
    if (_data)
        delete[] _data;
}

const char* String::c_str() const
{
    return _data;
}

std::string String::std_str() const
{
    return std::string(_data);
}

char String::at(size_t index) const
{
    return _data[index];
}

char& String::operator[](size_t index)
{
    return _data[index];
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
    return os << str.c_str();
}

String String::from_std_string(const std::string& std_str)
{
    return String(std_str.c_str());
}