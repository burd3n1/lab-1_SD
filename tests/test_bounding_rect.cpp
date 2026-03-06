// tests/test_bounding_rect.cpp
#include <cassert>
#include "../src/rect.hpp"

// Объявление функции из main.cpp
Rect boundingRect(Rect r1, Rect r2);

int main() {
    // === Тест 1: обычные прямоугольники ===
    {
        Rect r1(2, 5, 8, 3);
        Rect r2(6, 9, 10, 4);
        Rect r3 = boundingRect(r1, r2);
        
        assert(r3.getLeft() == 2);    // min(2, 6)
        assert(r3.getRight() == 9);   // max(5, 9)
        assert(r3.getTop() == 10);    // max(8, 10)
        assert(r3.getBottom() == 3);  // min(3, 4)
    }

    // === Тест 2: один прямоугольник внутри другого ===
    {
        Rect r1(0, 20, 20, 0);
        Rect r2(5, 10, 15, 5);
        Rect r3 = boundingRect(r1, r2);
        
        assert(r3.getLeft() == 0);
        assert(r3.getRight() == 20);
        assert(r3.getTop() == 20);
        assert(r3.getBottom() == 0);
    }

    // === Тест 3: непересекающиеся прямоугольники ===
    {
        Rect r1(0, 2, 10, 8);
        Rect r2(20, 22, 30, 28);
        Rect r3 = boundingRect(r1, r2);
        
        assert(r3.getLeft() == 0);
        assert(r3.getRight() == 22);
        assert(r3.getTop() == 30);
        assert(r3.getBottom() == 8);
    }

    // === Тест 4: пользователь перепутал left/right ===
    {
        // Прямоугольник с "неправильными" координатами: left > right
        Rect r1(10, 2, 8, 12);  // left=10, right=2 (ошибка пользователя)
        Rect r2(5, 15, 20, 5);
        
        // boundingRect должна корректно обработать это через std::min/std::max
        Rect r3 = boundingRect(r1, r2);
        
        // Ожидаем: left = min(10, 2, 5) = 2, right = max(10, 2, 15) = 15
        assert(r3.getLeft() == 2);
        assert(r3.getRight() == 15);
        // top = max(8, 12, 20) = 20, bottom = min(8, 12, 5) = 5
        assert(r3.getTop() == 20);
        assert(r3.getBottom() == 5);
    }

    // === Тест 5: пользователь перепутал top/bottom ===
    {
        Rect r1(1, 5, 3, 10);  // top=3, bottom=10 (ошибка: top < bottom)
        Rect r2(0, 6, 12, 0);
        Rect r3 = boundingRect(r1, r2);
        
        // top = max(3, 10, 12) = 12, bottom = min(3, 10, 0) = 0
        assert(r3.getTop() == 12);
        assert(r3.getBottom() == 0);
        assert(r3.getLeft() == 0);   // min(1, 5, 0, 6)
        assert(r3.getRight() == 6);  // max(1, 5, 0, 6)
    }

    // === Тест 6: одинаковые прямоугольники ===
    {
        Rect r1(3, 7, 9, 4);
        Rect r2(3, 7, 9, 4);
        Rect r3 = boundingRect(r1, r2);
        
        assert(r3.getLeft() == 3);
        assert(r3.getRight() == 7);
        assert(r3.getTop() == 9);
        assert(r3.getBottom() == 4);
    }

    return 0;
}