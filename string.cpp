#include <iostream>
#include <cstddef>
#include "string.h"


String::String(){
    capacity_ = 1;
    size_ = 0;
    data_ = new char[capacity_ + 1];
    data_[0] = '\0';
}

String::String(const char* str){
    size_ = count_length(str);
    if (size_ >= 1){
        capacity_ = size_ * 2 + 1;
    }
    else{
        capacity_ = 1;
    }
    data_ = new char[capacity_ + 1];
    copy_text(str, data_, size_);
}

String::String(const String &old_str){
    size_ = old_str.size_;
    capacity_ = old_str.capacity_;
    data_ = new char[capacity_ + 1];
    copy_text(old_str.data_, data_, size_);
}

String::String(String &&old_str){
    size_ = old_str.size_;
    capacity_ = old_str.capacity_;
    data_ = old_str.data_;
    old_str.data_ = nullptr;
    old_str.size_ = 0;
    old_str.capacity_ = 0;
}

String::~String(){
    delete[] data_;
}

String& String::operator=(String other){
    swap(other);
    return *this;
}

void String::append(const char* str){
    std::size_t new_size = size_ + count_length(str);
    if (new_size >= capacity_){
        capacity_ = new_size * 2 + 1;
        char* new_data = new char[capacity_ + 1];
        copy_text(data_, new_data, size_);
        delete[] data_;
        data_ = new_data;
    }
    copy_text(str, data_ + size_, count_length(str));
    size_ = new_size;
}

void String::print(std::ostream& out) const{
    if (data_ != nullptr){
        out << data_;
    }
    
}

String String::warp(size_t width) const{
    String res{};
    String temp_data;
    std::size_t count = 0;
    for(std::size_t i = 0; i < size_; ++i){
        if (data_[i] != ' '){
            temp_data.append(&data_[i]); //Доделать
        }
        
    } 
    
}

std::size_t String::count_length(const char* str) const{
    std::size_t length = 0;
    while (str[length] != '\0'){
        ++length;
    }
    return length;
}

std::size_t String::find(const char* str) const{
    size_t str_length = count_length(str);
    if (str_length == 0){
        return 0;
    }
    if (str_length > size_){
        return static_cast<std::size_t>(-1);
    }
    for(std::size_t i = 0; i <= size_ - str_length; ++i){
        bool found = true;
        for(std::size_t j = 0; j < str_length; ++j){
            if(data_[i + j] != str[j]){
                found = false;
                break;
            }
        }
        if(found){
            return i;
        }
    }
    return static_cast<std::size_t>(-1);

}

void String::copy_text(const char* str, char* data, std::size_t length) const{
    for (std::size_t i = 0; i < length; ++i){
        data[i] = str[i];
    }
    data[length] = '\0';
}

void String::swap(String& other){
    char* temp_data = data_;
    data_ = other.data_;
    other.data_ = temp_data;

    std::size_t temp_size = size_;
    size_ = other.size_;
    other.size_ = temp_size;

    std::size_t temp_capacity = capacity_;
    capacity_ = other.capacity_;
    other.capacity_ = temp_capacity;
}
