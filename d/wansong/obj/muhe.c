// smallbox.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("ľ����", ({"ľ����"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
"��Сľ�������ǻҳ���ճ����úм��ݣ����ƺ����԰���"ZJURL("cmds:�� ľ����")ZJSIZE(15)"��"NOR"����!\n");
		set("unit", "ֻ");
		set("open_count", 1);
		set_weight(1000);
	}
}

void init()
{
	add_action("do_open","��");
}

int do_open(string arg)
{
	object ob, me = this_player();
	if (! id(arg))
		return notify_fail("�����ʲô��\n");
	else if (query("open_count") > 0)
	{
       		message_vision(HIR 
"$N���ִ�ľ���ӣ���������һ���飬��д��ħ��ҽ�������֣���
ǯ�ӽҿ���ҳ����д������С�֣��������ͼ�����е��ǵ�ͼ��
�е���ҩ��ͼ����"NOR"\n", this_player());
		ob = new("/clone/book/mojiao");
		ob -> move(me);
		return 1;
	}
	else return notify_fail("ľ�����Ѿ������˴򿪹��ˡ�\n");
}
