/*
�̳о��ǻ������е�һ����ȥ����һ�����࣬�������������ô��룬���õ���֯���롣

�� C �������棬ȥʵ�ֵ��̳�Ҳ�ǳ��򵥣�ֻҪ�ѻ���ŵ��̳���ĵ�һ�����ݳ�Ա��λ�þ����ˡ�

���磬��������Ҫ����һ�� Rectangle �࣬����ֻҪ�̳� Shape ���Ѿ����ڵ����ԺͲ���������Ӳ�ͬ�� Shape �����ԺͲ����� Rectangle ��
*/

#include <stdio.h> 
// ���ε�����
typedef struct {
    Shape super; // �̳� Shape

    // �Լ�������
    uint16_t width;
    uint16_t height;
} Rectangle;

// ���캯��
void Rectangle_ctor(Rectangle * const me, int16_t x, int16_t y,uint16_t width, uint16_t height);

// ���캯��
void Rectangle_ctor(Rectangle * const me, int16_t x, int16_t y,
                    uint16_t width, uint16_t height)
{
    /* first call superclass�� ctor */
    Shape_ctor(&me->super, x, y);

    /* next, you initialize the attributes added by this subclass... */
    me->width = width;
    me->height = height;
}

int main() 
{
    Rectangle r1, r2;

    // ʵ��������
    Rectangle_ctor(&r1, 0, 2, 10, 15);
    Rectangle_ctor(&r2, -1, 3, 5, 8);

    printf("Rect r1(x=%d,y=%d,width=%d,height=%d)\n",
           Shape_getX(&r1.super), Shape_getY(&r1.super),
           r1.width, r1.height);
    printf("Rect r2(x=%d,y=%d,width=%d,height=%d)\n",
           Shape_getX(&r2.super), Shape_getY(&r2.super),
           r2.width, r2.height);

    // ע�⣬���������ַ�ʽ��һ��ǿת���ͣ�����ֱ��ʹ�ó�Ա��ַ
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
��������
Rect r1(x=0,y=2,width=10,height=15)
Rect r2(x=-1,y=3,width=5,height=8)
Rect r1(x=-2,y=5,width=10,height=15)
Rect r2(x=1,y=2,width=5,height=8)
*/