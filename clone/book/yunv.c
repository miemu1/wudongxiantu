// mengzi.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(WHT "��Ů�ط�" NOR, ({ "yunv book", "shu" }));
	set_weight(300);

	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "��Ĺ�ط���ֻ��ѧϰһ�ټ���\n");
		set("value", 100);
		set("no_sell", "��...��ֵʲôǮ��\n");
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("no_beg", 1);
		set("material", "paper");
		set("skill", ([
			"name": "taishang-wangqing",    // name of the skill
			"jing_cost":   100,    // jing cost every time study this
			"difficulty":   38,    // the base int to learn this skill
			"max_skill":   100,    // the maximum level you can learn to
			"min_skill":   0,    // minimun level required
		]));
	}
}

int query_autoload() { return 1; }