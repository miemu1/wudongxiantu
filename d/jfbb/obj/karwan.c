// shenliwan.c ��Ե��

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "��Ե��" NOR, ({ "fu wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ���߲ʵĸ�Ե������˵���˿��Խ����ˡ�������ʹ��\n");
		set("no_put",1);
              	set("no_sell",1);
              	set("no_drop",1); 
		set("unit", "��");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        me = this_player();
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
                tell_object(me, HIR "������ƺ��Լ���������һЩ��\n" NOR);
                me->add("kar", 1);
        destruct(this_object());
	return 1;
}
