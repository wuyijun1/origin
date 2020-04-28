/*
继承就是基于现有的一个类去定义一个新类，这样有助于重用代码，更好的组织代码。

在 C 语言里面，去实现单继承也非常简单，只要把基类放到继承类的第一个数据成员的位置就行了。

例如，我们现在要创建一个 Rectangle 类，我们只要继承 Shape 类已经存在的属性和操作，再添加不同于 Shape 的属性和操作到 Rectangle 中
*/

#include <stdio.h> 
// 矩形的属性
typedef struct {
    Shape super; // 继承 Shape

    // 自己的属性
    uint16_t width;
    uint16_t height;
} Rectangle;

// 构造函数
void Rectangle_ctor(Rectangle * const me, int16_t x, int16_t y,uint16_t width, uint16_t height);

// 构造函数
void Rectangle_ctor(Rectangle * const me, int16_t x, int16_t y,
                    uint16_t width, uint16_t height)
{
    /* first call superclass’ ctor */
    Shape_ctor(&me->super, x, y);

    /* next, you initialize the attributes added by this subclass... */
    me->width = width;
    me->height = height;
}

int main() 
{
    Rectangle r1, r2;

    // 实例化对象
    Rectangle_ctor(&r1, 0, 2, 10, 15);
    Rectangle_ctor(&r2, -1, 3, 5, 8);

    printf("Rect r1(x=%d,y=%d,width=%d,height=%d)\n",
           Shape_getX(&r1.super), Shape_getY(&r1.super),
           r1.width, r1.height);
    printf("Rect r2(x=%d,y=%d,width=%d,height=%d)\n",
           Shape_getX(&r2.super), Shape_getY(&r2.super),
           r2.width, r2.height);

    // 注意，这里有两种方式，一是强转类型，二是直接使用成员地址
    Shape_moveBy((Shape *)&r1, -2, 3);
    Shape_moveBy(&r2.super, 2, -1);

    printf("Rect r1(x=%d,y=%d,width=%d,height=%d)\n",
           Shape_getX(&r1.super), Shape_getY(&r1.super),
           r1.width, r1.height);
    printf("Rect r2(x=%d,y=%d,width=%d,height=%d)\n",
           Shape_getX(&r2.super), Shape_getY(&r2.super),
           r2.width, r2.height);

    return 0;
}


/*
输出结果：
Rect r1(x=0,y=2,width=10,height=15)
Rect r2(x=-1,y=3,width=5,height=8)
Rect r1(x=-2,y=5,width=10,height=15)
Rect r2(x=1,y=2,width=5,height=8)
*/