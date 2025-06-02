// puti-zi.c ������

#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void init()
{
	add_action("do_eat", "drink");
}

void create()
{
	set_name("ę́��", ({"maotai jiu",}));
	set_weight(30);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ�ƵĴ�ƴ������װ�ðˡ������ľơ�\n");
		set("unit", "��");
		set("value", 500);
		set("max_liquid", 15);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "ę́��",
		"remaining": 15,
		"drunk_supply": 6,
	]));
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("������û�պȾơ�\n");

	if ( me->query("drunk") == 100)
	{
		message_vision(HIR "$N�Ⱦ�̫�࣬��ò������¡�\n" NOR, me);
		me->unconcious();
	}
	if ( (int)me->query_condition("a_jiu6" ) > 0 )
	{
		me->add("drunk", 30);
		message_vision(HIR "$N����ę́�ƾͺ�������,���������˼��֣�\n" NOR, me);
	}
	else
	{
		me->add_temp("apply/dex",60);
		me->add_temp("apply/str",60);
		me->add("drunk", 30);
		message_vision(HIY "$N���˿�ę́�ƣ������˸о���ƮƮ�ģ�\n" NOR, this_player());
		me->apply_condition("a_jiu6", 60);
	}
	destruct(this_object());
	return 1;
}

