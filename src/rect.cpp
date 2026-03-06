
#include "rect.hpp"
#include <iostream>

Rect::Rect(){
    left = 0;
    right = 0;
    top = 0;
    bottom = 0;
    getLeft();
    getRight();
    getBottom();
    getTop();
    setAll(0 , 0 , 0 , 0 );
    std::cout<< "Hello from Default constructor" << this << std::endl;
}

Rect::Rect(int a , int b, int c,int d) {
    left = a;
    right = b;
    top = c;
    bottom = d;
    std::cout<< "Hello from constructor" << this << std::endl;
}

Rect::Rect(const Rect &r) {
    left = r.left;
    right = r.right;
    top = r.top;
    bottom = r.bottom;
    std::cout<< "Hello from cloning constructor" << this << std::endl;
}

Rect::~Rect()
{
    std::cout<< "Hello from Distructor" << this << std::endl;   
}

int Rect::getLeft() const{
    return left;
}

int Rect::getRight() const{
    return right;
}

int Rect::getTop() const{
    return top;
}

int Rect::getBottom() const{
    return bottom;
}



void Rect::setAll(int left, int right, int top, int bottom)
{
    this->left = left;
    this->right = right;
    this->top = top;
    this->bottom = bottom;
}

void Rect::inflate(int amount)
{
    left -= amount;
    right += amount;
    top += amount;
    bottom -= amount;
}

void Rect::inflate(int dw, int dh)
{
    left -= dw;
    right += dw;
    top += dh;
    bottom -= dh;
}

void Rect::inflate(int dLeft, int dRight, int dTop, int dBottom)
{
    left -= dLeft;
    right += dRight;
    top += dTop;
    bottom -= dBottom;
}

void Rect::move(int dx, int dy)
{
    left += dx;
    right += dx;
    top += dy;
    bottom += dy;
}

int Rect::getWidth() const
{
    return right - left;
}

int Rect::getHeight() const
{
    return top - bottom;
}

int Rect::getSquare() const
{
    return getWidth() * getHeight();
}

void Rect::setWidth(int width){
    right = left + width;
}

void Rect::setHeight(int height){
    top = bottom + height;
}

Rect boundingRect(Rect r1, Rect r2) {
    Rect r3;
    r3.setAll(
        std::min(r1.getLeft(), r2.getLeft()),
        std::max(r1.getRight(), r2.getRight()),
        std::max(r1.getTop(), r2.getTop()),
        std::min(r1.getBottom(), r2.getBottom())
    );
    return r3;
}

void printRect(Rect &r) {
    std::cout << "Left: " << r.getLeft() 
              << "; Right: " << r.getRight() 
              << "; Top: " << r.getTop() 
              << "; Bottom: " << r.getBottom() << '\n';
}

