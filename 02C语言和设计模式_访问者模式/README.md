��֪�������У����Ǿ͵������һ�����ģʽ����������ģʽ��������ģʽ������ȥ����һЩ�����ǣ�����ģʽ�ü򵥵�һ�仰˵�����ǲ�ͬ���˶Բ�ͬ�������в�ͬ�ĸо�������˵�ɣ�����������������������Ҳ�������ɳ����������ǣ���ͬ�ĵط�����δ�ض�ϲ�������ֶ������Ĵ������ѿ��ܸ�ϲ����������������˾Ϳ��ܶԳ�������ϲ��һЩ����ô���������Ӧ����ô�����ģʽ����أ�

typedef struct _Tofu
{
    int type;
    void (*eat)	(struct _Visitor* pVisitor, struct _Tofu* pTofu);
}Tofu;
 
typedef struct _Visitor
{
    int region;
    void (*process)(struct _Tofu* pTofu, struct _Visitor* pVisitor);
}Visitor;
? ? ��������һ��������eat��ʱ���Ҫ����ͬ���ж��ˡ�
void eat(struct _Visitor* pVisitor, struct _Tofu* pTofu)
{
    assert(NULL != pVisitor && NULL != pTofu);
 
    pVisitor->process(pTofu, pVisitor);
}
? ? ��Ȼeat�Ĳ�������ǿ���ͬ��visitor�������ˣ���ô����͸ö���process�����ˡ�
void process(struct _Tofu* pTofu, struct _Visitor* pVisitor)
{
    assert(NULL != pTofu && NULL != pVisitor);
 
    if(pTofu->type == SPICY_FOOD && pVisitor->region == WEST ||
        pTofu->type == STRONG_SMELL_FOOD && pVisitor->region == EAST)
    {
        printf("I like this food!\n");
        return;
    }
 
    printf("I hate this food!\n");   
}
��������������������������������
��Ȩ����������ΪCSDN�����������С���ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/feixiaoxing/java/article/details/7188574