#include "mystring.hpp"
#include <iostream>

MyString::MyString() : data(nullptr), length(0){
    data = new char[1];
    data[0] = '\0';
}


MyString::MyString(const char* str) : length(0){
    if (str == nullptr) {
        data = new char[1];
        data[0] = '\0';
    }else{
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }
}


MyString::MyString(const MyString& other) : length(other.length){ // Глубокое копирование содержимого 
    data = new char[length + 1];
    std::strcpy(data, other.data);
}


MyString::~MyString(){
    delete[] data;
}


MyString& MyString::operator=(const MyString& other){
    if (this == &other) return *this;

    delete[] data;

    length = other.length;
    data = new char[length + 1];
    std::strcpy(data, other.data);

    return *this;
}


char MyString::get(int i) const {
    if (i < 0 || static_cast<size_t>(i) >= length) {
        return '\0';
    }
    return data[i];
}

void MyString::set(int i, char c) {
    if (i < 0 || static_cast<size_t>(i) >= length) {
        return;
    }
    data[i] = c;
}

void MyString::setNewString(const char* str) {
    // Освобождение старую память
    delete[] data;

    // Выделение новой памяти
    if (str == nullptr) {
        length = 0;
        data = new char[1];
        data[0] = '\0';
    } else {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }
}


void MyString::print() const {
    std::cout << data << std::endl;
}


void MyString::readLine() {
    // Освобождаем старую память
    delete[] data;

    // Читаем строку произвольной длины через std::string (временный буфер)
    std::string temp;
    std::getline(std::cin, temp);

    // Копируем в наш динамический массив
    length = temp.length();
    data = new char[length + 1];
    std::strcpy(data, temp.c_str());
}