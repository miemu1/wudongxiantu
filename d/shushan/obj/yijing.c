inherit ITEM;
void create()
{
        set_name( "��ɽ����", ({ "book", "shu" }));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����д����ɽ�ɷ���������\n");
                set("value", 500);
                set("material", "paper");
                      set("skill", ([
			"name": "xianfeng-spells",
             "exp_required": 100000,
                "jing_cost": 300,
              "difficulty": 300,
	              "max_skill": 50,
]) );
        }
}

