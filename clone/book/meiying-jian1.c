
// kuangfeng1.c

inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name("����Ӱ�������ϲ�", ({ "meiying book1", "book1", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
        "����һ�����ɵ��ؼ������飺������Ӱ�������ϲᡱ��\n"
        "��Ƥ���ƣ������Ѿ�����ܾ��ˡ�\n", );
                set("value", 0);
                set("material", "paper");
                set("skill", ([
                        "name":       "meiying-jian",
                        "exp_required": 20000000,
                        "jing_cost" :  200,
                        "difficulty":  50,
                        "max_skill" :  100,
                        "min_skill" :  0
                ]) );
        }
}
