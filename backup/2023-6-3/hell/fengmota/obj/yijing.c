inherit ITEM;

void create()
{
        set_name( "�׾�", ({ "shu", "book" }));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���׾���\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "taoism",       // name of the skill
                        "exp_required": 1000000,  // minimum combat experience required
                        "jing_cost": 200,         // jing cost every time study this
                        "difficulty":   105,     // the base int to learn this skill
                        "max_skill":    100      // the maximum level you can learn
                ]) );
        }
}
