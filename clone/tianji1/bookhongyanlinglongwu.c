// baowu.c
// by smash
#include <ansi.h>
inherit ITEM;


void create()
{
	set_name(HIM"����������"NOR, ({"hongyanwu"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ���ɺ���ħ׫д���书�ؼ���ֻ�нܳ����׵���Ҳ���ӵ��"ZJURL("cmds:use bao wu")ZJSIZE(15)""HIW"��"NOR"ѧϰ��\n");
		set("unit", "��");
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
		tell_object(me,HIW"��ѧ���˺��������裬"NOR+HIG"��л���Ժ���ħ�Ĵ���֧�֣�ף����Ϸ��죡\n"NOR);
		me->set_skill("hongyan-wu", 100);
		destruct(this_object());
	}
	return 1;
}
