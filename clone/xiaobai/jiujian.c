// mengzi.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(WHT "��ħ�Ž���" NOR, ({ "jiujian book", "shu" }));
	set_weight(300);

	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "�Ȿ�������������ħ�Ľ��⣬���޼�֮����\n");
		set("value", 1000000000);
		set("no_sell", "��...��ֵʲôǮ��\n");
		set("no_give", "������ħ������� \n");
		set("material", "paper");
		set("skill", ([
			"name": "lonely-sword",    // name of the skill
			"jing_cost":   1,    // jing cost every time study this
			"difficulty":   1,    // the base int to learn this skill
			"max_skill":   10000,    // the maximum level you can learn to
			"min_skill":   0,    // minimun level required
		]));
	}
}

int query_autoload() { return 1; }