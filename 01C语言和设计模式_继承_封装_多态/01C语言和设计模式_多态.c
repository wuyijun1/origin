/*  
������û������
����ʵ�ֶ�̬����ʹ���麯������ C �������棬Ҳ����ʵ�ֶ�̬�� ���ڣ�������Ҫ����һ��Բ�Σ������� Shape Ҫ��չ���ܣ�����Ҫ���� area() �� draw() ���������� Shape �൱�ڳ����࣬��֪����ôȥ�����Լ������������֪����ôȥ�������Լ������ң����κ�Բ�ε�������㷽ʽ�ͼ���ͼ��Ҳ�ǲ�һ���ġ�
*/


#include <stdint.h>

struct ShapeVtbl;
// Shape ������
typedef struct {
    struct ShapeVtbl const *vptr;
    int16_t x; 
    int16_t y; 
} Shape;

// Shape �����
struct ShapeVtbl {
    uint32_t (*area)(Shape const * const me);
    void (*draw)(Shape const * const me);
};

// Shape �Ĳ����������ӿں���
void Shape_ctor(Shape * const me, int16_t x, int16_t y);
void Shape_moveBy(Shape * const me, int16_t dx, int16_t dy);
int16_t Shape_getX(Shape const * const me);
int16_t Shape_getY(Shape const * const me);

static inline uint32_t Shape_area(Shape const * const me) //�����麯������
{
    return (*me->vptr->area)(me);
}

static inline void Shape_draw(Shape const * const me)//�����麯������
{
    (*me->vptr->draw)(me);
}


Shape const *largestShape(Shape const *shapes[], uint32_t nShapes);
void drawAllShapes(Shape const *shapes[], uint32_t nShapes);

static inline uint32_t Shape_area(Shape const * const me) 
{
    return (*me->vptr->area)(me);
}


// Shape ���麯��
static uint32_t Shape_area_(Shape const * const me);
static void Shape_draw_(Shape const * const me);

// ���캯��
void Shape_ctor(Shape * const me, int16_t x, int16_t y) 
{
    // Shape ������
    static struct ShapeVtbl const vtbl = 
    { 
       &Shape_area_,
       &Shape_draw_
    };
    me->vptr = &vtbl; 
    me->x = x;
    me->y = y;
}


void Shape_moveBy(Shape * const me, int16_t dx, int16_t dy)
{
    me->x += dx;
    me->y += dy;
}


int16_t Shape_getX(Shape const * const me) 
{
    return me->x;
}
int16_t Shape_getY(Shape const * const me) 
{
    return me->y;
}

// Shape ����麯��ʵ��
static uint32_t Shape_area_(Shape const * const me) 
{
    assert(0); // ���ƴ��麯��
    return 0U; // ���⾯��
}

static void Shape_draw_(Shape const * const me) 
{
    assert(0); // ���麯�����ܱ�����
}


Shape const *largestShape(Shape const *shapes[], uint32_t nShapes) 
{
    Shape const *s = (Shape *)0;
    uint32_t max = 0U;
    uint32_t i;
    for (i = 0U; i < nShapes; ++i) 
    {
        uint32_t area = Shape_area(shapes[i]);// �麯������
        if (area > max) 
        {
            max = area;
            s = shapes[i];
        }
    }
    return s;
}


void drawAllShapes(Shape const *shapes[], uint32_t nShapes) 
{
    uint32_t i;
    for (i = 0U; i < nShapes; ++i) 
    {
        Shape_draw(shapes[i]); // �麯������
    }
}




// Rectangle �麯��
static uint32_t Rectangle_area_(Shape const * const me);
static void Rectangle_draw_(Shape const * const me);

// ���캯��
void Rectangle_ctor(Rectangle * const me, int16_t x, int16_t y,
                    uint16_t width, uint16_t height)
{
    static struct ShapeVtbl const vtbl = 
    {
        &Rectangle_area_,
        &Rectangle_draw_
    };
    Shape_ctor(&me->super, x, y); // ���û���Ĺ��캯��
    me->super.vptr = &vtbl;           // ���� vptr
    me->width = width;
    me->height = height;
}

// Rectangle's �麯��ʵ��
static uint32_t Rectangle_area_(Shape const * const me) 
{
    Rectangle const * const me_ = (Rectangle const *)me; //��ʾ��ת��
    return (uint32_t)me_->width * (uint32_t)me_->height;
}

static void Rectangle_draw_(Shape const * const me) 
{
    Rectangle const * const me_ = (Rectangle const *)me; //��ʾ��ת��
    printf("Rectangle_draw_(x=%d,y=%d,width=%d,height=%d)\n",
           Shape_getX(me), Shape_getY(me), me_->width, me_->height);
}


int main() 
{
    Rectangle r1, r2; 
    Circle    c1, c2; 
    Shape const *shapes[] = 
    { 
        &c1.super,
        &r2.super,
        &c2.super,
        &r1.super
    };
    Shape const *s;

    // ʵ�������ζ���
    Rectangle_ctor(&r1, 0, 2, 10, 15);
    Rectangle_ctor(&r2, -1, 3, 5, 8);

    // ʵ����Բ�ζ���
    Circle_ctor(&c1, 1, -2, 12);
    Circle_ctor(&c2, 1, -3, 6);

    s = largestShape(shapes, sizeof(shapes)/sizeof(shapes[0]));
    printf("largetsShape s(x=%d,y=%d)\n", Shape_getX(s), Shape_getY(s));

    drawAllShapes(shapes, sizeof(shapes)/sizeof(shapes[0]));

    return 0;
}


/*
��������

largetsShape s(x=1,y=-2)
Circle_draw_(x=1,y=-2,rad=12)
Rectangle_draw_(x=-1,y=3,width=5,height=8)
Circle_draw_(x=1,y=-3,rad=6)
Rectangle_draw_(x=0,y=2,width=10,height=15)
*/