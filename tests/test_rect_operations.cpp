#include <cassert>
#include "../src/rect.hpp"

int main() {
    // === Тест: move(dx, dy) ===
    {
        Rect r(1, 5, 10, 2);  // left=1, right=5, top=10, bottom=2
        r.move(3, -1);        // сдвиг на +3 по X, -1 по Y
        assert(r.getLeft() == 4);    // 1 + 3
        assert(r.getRight() == 8);   // 5 + 3
        assert(r.getTop() == 9);     // 10 - 1
        assert(r.getBottom() == 1);  // 2 - 1
    }

    // === Тест: move(dx) — только по X ===
    {
        Rect r(0, 10, 20, 0);
        r.move(5);  // сдвиг только по X
        assert(r.getLeft() == 5);
        assert(r.getRight() == 15);
        assert(r.getTop() == 20);    // Y не изменился
        assert(r.getBottom() == 0);
    }

    // === Тест: inflate(amount) — равномерное расширение ===
    {
        Rect r(2, 8, 10, 3);  // width=6, height=7
        r.inflate(1);         // все стороны сдвигаются на 1 от центра
        assert(r.getLeft() == 1);    // 2 - 1
        assert(r.getRight() == 9);   // 8 + 1
        assert(r.getTop() == 11);    // 10 + 1
        assert(r.getBottom() == 2);  // 3 - 1
        assert(r.getWidth() == 8);   // было 6, стало 8
        assert(r.getHeight() == 9);  // было 7, стало 9
    }

    // === Тест: inflate(dw, dh) ===
    {
        Rect r(0, 10, 20, 0);
        r.inflate(2, 3);  // по X на 2, по Y на 3
        assert(r.getLeft() == -2);   // 0 - 2
        assert(r.getRight() == 12);  // 10 + 2
        assert(r.getTop() == 23);    // 20 + 3
        assert(r.getBottom() == -3); // 0 - 3
    }

    // === Тест: inflate(dLeft, dRight, dTop, dBottom) ===
    {
        Rect r(5, 15, 25, 10);
        r.inflate(1, 2, 3, 4);  // разные отступы
        assert(r.getLeft() == 4);    // 5 - 1
        assert(r.getRight() == 17);  // 15 + 2
        assert(r.getTop() == 28);    // 25 + 3
        assert(r.getBottom() == 6);  // 10 - 4
    }

    // === Тест: отрицательный inflate (сжатие) ===
    {
        Rect r(0, 10, 10, 0);
        r.inflate(-2, -2, -2, -2);  // сжатие на 2 со всех сторон
        assert(r.getLeft() == 2);
        assert(r.getRight() == 8);
        assert(r.getTop() == 8);
        assert(r.getBottom() == 2);
    }

    return 0;
}