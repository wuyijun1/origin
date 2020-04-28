#include <stdio.h>  /* for printf() */
#include "stdlib.h"
#include <string.h>
// Shape 的属性

typedef struct {
    int16_t x; 
    int16_t y; 
} Shape;

// Shape 的操作函数，接口函数
void Shape_ctor(Shape * const me, int16_t x, int16_t y);
void Shape_moveBy(Shape * const me, int16_t dx, int16_t dy);
int16_t Shape_getX(Shape const * const me);
int16_t Shape_getY(Shape const * const me);

// 构造函数
void Shape_ctor(Shape * const me, int16_t x, int16_t y)
{
    me->x = x;
    me->y = y;
}

void Shape_moveBy(Shape * const me, int16_t dx, int16_t dy) 
{
    me->x += dx;
    me->y += dy;
}

// 获取属性值函数
int16_t Shape_getX(Shape const * const me) 
{
    return me->x;
}
int16_t Shape_getY(Shape const * const me) 
{
    return me->y;
}

int main() 
{
    Shape s1, s2; /* multiple instances of Shape */

    Shape_ctor(&s1, 0, 1);
    Shape_ctor(&s2, -1, 2);

    printf("Shape s1(x=%d,y=%d)\n", Shape_getX(&s1), Shape_getY(&s1));
    printf("Shape s2(x=%d,y=%d)\n", Shape_getX(&s2), Shape_getY(&s2));

    Shape_moveBy(&s1, 2, -4);
    Shape_moveBy(&s2, 1, -2);

    printf("Shape s1(x=%d,y=%d)\n", Shape_getX(&s1), Shape_getY(&s1));
    printf("Shape s2(x=%d,y=%d)\n", Shape_getX(&s2), Shape_getY(&s2));

    return 0;
}

/***********************************************************************************
编译之后，看看执行结果：

Shape s1(x=0,y=1)
Shape s2(x=-1,y=2)
Shape s1(x=2,y=-3)
Shape s2(x=0,y=0)
*********************************************************************************************/