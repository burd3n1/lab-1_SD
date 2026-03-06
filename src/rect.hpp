#ifndef RECT_HPP
#define RECT_HPP

class Rect {
    private:
        int left;
        int right;
        int top;
        int bottom;

    public: 
    Rect();

    Rect(int a , int b, int c,int d);
    Rect(const Rect &r);

    ~Rect();

    int getLeft() const;
    int getRight() const;
    int getTop() const;
    int getBottom() const;
    void setAll(int left , int right, int top, int bottom);


  /**
     * Задание 1.9. Перегрузка функций и методов. Значение параметров по
     * умолчанию.
     *
     * Добавьте методы в класс Rect:
    */
      void inflate(int amount); //отодвигает каждую из сторон от центра прямоугольника на величину amount;
      void inflate(int dw, int dh); //отодвигает верхнюю и нижнюю сторону на dh, а левую и правую - на dw;
      void inflate(int dLeft, int dRight, int dTop, int dBottom);// - аналогично, но для каждой стороны отдельно.
      void move(int dx = 0, int dy = 0); /* со значениями параметров по умолчанию,
     * который осуществляет параллельный перенос по следующей логике: 
     * - rect.move(1, 2) перемещает прямоугольник на 1 по оси Х и на 2 по оси Y;
     * - rect.move(1) перемещает прямоугольник на 1 по оси X.
     */

    int getWidth() const;
    int getHeight() const;
    int getSquare() const;
    void setWidth(int width);
    void setHeight(int height);


};

Rect boundingRect(Rect r1, Rect r2);
void printRect(Rect &r);

#endif // RECT_HPP