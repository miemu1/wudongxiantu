// baowu.c
// by smash
#include <ansi.h>
inherit ITEM;


void create()
{
	set_name(HIM"红颜玲珑舞"NOR, ({"hongyanwu"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一本由韩老魔撰写的武功秘籍，只有杰出贡献的玩家才能拥有"ZJURL("cmds:use bao wu")ZJSIZE(15)""HIW"打开"NOR"学习。\n");
		set("unit", "个");
		set("value", 50);
		set("tianji1", 100);
		 set("mingjiao", 1);
set("no_sell",1);
            set("no_drop",1);
            set("no_give",1);
            set("no_drop",1);
            set("no_get",1);	}
}
int init()
{
	add_action("do_use", "use");
}

int do_use(string arg)
{
	object me = this_player();

	if(arg=="bao wu")
	{
		tell_object(me,HIW"你学会了红颜玲珑舞，"NOR+HIG"感谢您对韩老魔的大力支持，祝您游戏愉快！\n"NOR);
		me->set_skill("hongyan-wu", 100);
		destruct(this_object());
	}
	return 1;
}
