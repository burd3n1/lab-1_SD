
#include <cassert>
#include "../src/rect.hpp"

int main() {
    // === Тест: getWidth и getHeight ===
    {
        Rect r(2, 8, 10, 3);  // left=2, right=8, top=10, bottom=3
        assert(r.getWidth() == 6);   // 8 - 2
        assert(r.getHeight() == 7);  // 10 - 3
    }

    // === Тест: отрицательные координаты ===
    {
        Rect r(-5, 5, 10, -10);
        assert(r.getWidth() == 10);   // 5 - (-5)
        assert(r.getHeight() == 20);  // 10 - (-10)
    }

    // === Тест: getSquare ===
    {
        Rect r(0, 4, 5, 0);
        assert(r.getSquare() == 20);  // 4 * 5
    }

    // === Тест: setWidth (сохраняет left) ===
    {
        Rect r(2, 8, 10, 3);  // width = 6
        r.setWidth(10);       // теперь width = 10, left = 2 → right = 12
        assert(r.getLeft() == 2);
        assert(r.getRight() == 12);
        assert(r.getWidth() == 10);
        // top/bottom не должны измениться
        assert(r.getTop() == 10);
        assert(r.getBottom() == 3);
    }

    // === Тест: setHeight (сохраняет bottom) ===
    {
        Rect r(2, 8, 10, 3);  // height = 7
        r.setHeight(5);       // теперь height = 5, bottom = 3 → top = 8
        assert(r.getBottom() == 3);
        assert(r.getTop() == 8);
        assert(r.getHeight() == 5);
        // left/right не должны измениться
        assert(r.getLeft() == 2);
        assert(r.getRight() == 8);
    }

    // === Тест: нулевая ширина/высота ===
    {
        Rect r(5, 5, 10, 10);  // вырожденный прямоугольник
        assert(r.getWidth() == 0);
        assert(r.getHeight() == 0);
        assert(r.getSquare() == 0);
    }

    return 0;
}