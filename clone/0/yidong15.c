

inherit ITEM;

void create()
{
	set_name("�Թ���ʮ���", ({ "yingdong15"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���ǿ��ܴ���("ZJURL("cmds:yidong lev15")ZJSIZE(15)""HIY"����"NOR")���Թ��ı��顣\n");
		set("value", 100);
		set("material", "stone");
				set("credit",250);

	}
	setup();
}



void init()
{
        add_action("do_go","yidong");
}

int do_go(string arg)
{
	string mapm;
	object *inv;
	int sizeinv;

	object me=this_player();

	while (sizeinv--)
	{
       	if (inv[sizeinv]->is_character())
     		return notify_fail("�㱳�����������Ĺ����͵���ȥ��\n");
	}
	if(arg=="lev15") {
		message_vision(HIG "һ����������$N!\n" NOR, me);
		mapm="/d/migong/lev15/dong4";
		me->move(mapm);
		destruct(this_object());
	}
	return 1;
}