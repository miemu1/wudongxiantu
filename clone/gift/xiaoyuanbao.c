// xiaoyuanbao.c С����ʯ

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "С����ʯ" NOR, ({ "xiao yuanbao", "xiao", "yuanbao" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "һֻ�ƳγεĽ���ʯ��\n");
                set("value", 1200000);
		set("unit", "ֻ");
	}
}

int query_autoload() { return 1; }
