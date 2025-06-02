// tianxiang.c ������¶

#include <ansi.h>

inherit ITEM;

void setup()
{
}

void create()
{
	set_name(MAG "������¶" NOR, ({"magic water", "yvlu", "lu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIG "���Ǹ�������֥�ϵ�һ�ξ�Ө��͸����¶����˵����\n"
                                "��ɽ��ǧ��������֥Ϊĸ�����ϵ���ȡ���վ��»���\n"
                                "�������ޱ�����Ĺ�Ч��\n");
		set("value", 100000);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
        string force;

	message_vision(HIG "$N" HIG "С������Ľ���¶�������У���ʱ����"
                       "��̨һ�������������\n��ƮƮ���ɣ�һʱ�侹�в���"
                       "�����ĸо���"NOR"\n",
		       me);
	if (me->improve_neili(100 + random(100)))
		me->set("neili", me->query("max_neili"));

        force = me->query_skill_mapped("force");
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 40000);
        if (stringp(force) && me->can_improve_skill(force))
                me->improve_skill(force, 40000);

	me->start_busy(random(5) + 5);
	destruct(this_object());
	return 1;
}
