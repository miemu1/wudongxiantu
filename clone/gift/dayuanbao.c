// dayuanbao.c �����ʯ

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "�����ʯ" NOR, ({ "da yuanbao", "da", "yuanbao" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "һֻ�ƳγεĽ���ʯ��\n");
                set("value", 2000000);
		set("unit", "ֻ");
	}
}

int query_autoload() { return 1; }
