#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
    set_name(HIY"�ڹ���"NOR, ({ "huiguodan" }) );
    set_weight(1);
            set("no_put", 1);
            set("xy_money", 100);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	       
            set("no_put", 1);
	     set("icon", "05006");
            set("no_steal", 1);
            set("no_beg", 1);
            set("no_pawn", 1);
            set("value", 800000000);
            set("treasure",1);
            set("unit", "��");
            set("material", "paper");
            set("long", "�����ʦ��¼����\n");
          }

    setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
else 
{
me->set("betrayer",0);
message_vision(HIG"�����$N��ô����������һ�������ʦ������������\n"NOR, this_player());
}
	destruct(this_object());
	return 1;
}