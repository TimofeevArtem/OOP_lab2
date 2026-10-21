#pragma once
#include <iostream>
#include <cstddef>
#include <utility>

class String{
public:
    String();
    String(const char* str);
    String(const String &old_str);
    String(String &&old_str);
    ~String();
    void append(const char* str);
    void print(std::ostream& out) const;
    String& operator=(String other);
    std::size_t find(const char* str) const;
    String wrap(size_t width) const;
private:
    char* data_;
    std::size_t size_;
    std::size_t capacity_;

    std::size_t count_length(const char* str) const;
    void copy_text(const char* str, char* data, std::size_t length) const;
    void swap(String &other);
};