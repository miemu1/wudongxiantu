#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "������ȭ��" NOR, ({ "qishang quan"}));
	set_weight(300);

	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ��������ȭ�����ؼ���ʹ���������50������ȭ��\n");
		set("gongxian",10000);
		set("value", 100);
		set("no_give","����Ͷ��ɹ�����Ҫ�����ˡ�\n");
		set("no_drop","�ⶫ�����ܶ�����\n");
		set("no_put",1);
		set("no_steal",1);
		set("no_sell", "�����޼��ؼ�����\n");
		set("material", "paper");
		set("only_do_effect",1);
	}
	setup();
}

int do_effect(object me)
{
	string skill;
	skill = "qishang-quan";
	if (me->query_skill(skill,1))
	{
		tell_object(me,"���Ѿ�������������ˣ������ٴ�ѧϰ��\n");
		return 1;
	}
	
	//if (!SKILL_D(skill)->valid_learn(me))
	//{
	///	tell_object(me,"��Ŀǰ���������������մ���ܣ�("+skill+")\n");
	//	return 1;
	//}

	me->set_skill(skill,50);
	tell_object(me,HIY"��������50��" + to_chinese(skill) + "��\n"NOR);

	destruct(this_object());

	return 1;
}

int query_autoload() { return 1; }