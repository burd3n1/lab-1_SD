#ifndef MYSTRING_HPP
#define MYSTRING_HPP
#include <iostream>

class MyString {
    
private:
    char* data;
    size_t length;
    
    public:

    MyString();                 
    MyString(const char* str);           // Из C-строки
    MyString(const MyString& other);     


    ~MyString();

   
    MyString& operator=(const MyString& other);


    char get(int i) const;
    void set(int i, char c);


    void setNewString(const char* str);  // Замена содержимого
    void print() const;                  // Вывод в консоль
    void readLine();                     // Чтение строки произвольной длины

 
    size_t getLength() const { return length; }
};

#endif //MYSTRING_HPP