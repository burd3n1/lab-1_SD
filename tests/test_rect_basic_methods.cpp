// tests/test_rect_basic_methods.cpp
#include <cassert>
#include "../src/rect.hpp"

int main() {
    // === Тест 1: Конструктор по умолчанию ===
    {
        Rect r;
        assert(r.getLeft() == 0);
        assert(r.getRight() == 0);
        assert(r.getTop() == 0);
        assert(r.getBottom() == 0);
    }

    // === Тест 2: Параметризованный конструктор ===
    {
        Rect r(1, 5, 10, 2);
        assert(r.getLeft() == 1);
        assert(r.getRight() == 5);
        assert(r.getTop() == 10);
        assert(r.getBottom() == 2);
    }

    // === Тест 3: Конструктор копирования ===
    {
        Rect r1(3, 7, 8, 1);
        Rect r2(r1);
        assert(r2.getLeft() == 3);
        assert(r2.getRight() == 7);
        assert(r2.getTop() == 8);
        assert(r2.getBottom() == 1);
        
        // Убедимся, что это копия, а не ссылка
        r1.setAll(0, 0, 0, 0);
        assert(r2.getLeft() == 3);  // r2 не должен измениться
    }

    // === Тест 4: Метод setAll ===
    {
        Rect r;
        r.setAll(-10, 20, 15, -5);
        assert(r.getLeft() == -10);
        assert(r.getRight() == 20);
        assert(r.getTop() == 15);
        assert(r.getBottom() == -5);
    }

    // === Тест 5: Перезапись значений через setAll ===
    {
        Rect r(1, 2, 3, 4);
        r.setAll(10, 20, 30, 40);
        assert(r.getLeft() == 10);
        assert(r.getRight() == 20);
        assert(r.getTop() == 30);
        assert(r.getBottom() == 40);
    }

    // === Тест 6: Отрицательные координаты ===
    {
        Rect r(-5, -1, -2, -10);
        assert(r.getLeft() == -5);
        assert(r.getRight() == -1);
        assert(r.getTop() == -2);
        assert(r.getBottom() == -10);
    }

    return 0;  // Все тесты пройдены
}