// blade-book.c

inherit ITEM;

void create()
{
        set_name("����ȭ��",({ "hujia quanjing","book"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�����ҵ��ף���¼�˺���ȭ��΢��֮����\n");
                set("value", 50);
                set("material", "paper");
                set("skill", ([
                        "name":         "hujia-quan",      //name of the skill
                        "exp_required": 1000,         //minimum combat experience required
                        "jing_cost":    30,           // jing cost every time study this
                        "difficulty":   30,           // the base int to learn this skill
                        "max_skill":    120           // the maximum level you can learn
                ]) );
        }
}

