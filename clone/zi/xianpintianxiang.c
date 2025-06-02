// jinsha.c

#include <ansi.h>
inherit COMBINED_ITEM;
string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIG "��Ʒ������¶" NOR, ({"magic water", "yvlu", "lu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("base_unit", "��");
		set("long", HIG "���Ǹ�������֥�ϵ�һ�ξ�Ө��͸����¶����˵����"
				"��ɽ��ǧ��������֥Ϊĸ�����ϵ���ȡ���վ��»����������ޱ�����Ĺ�Ч(��������������ڹ��ȼ�1800֮ǰ����������)��\n");
		set("tianji1", 300);//�۸�
		set("value", 100000);
		set("give",1);
		set("put", 1);
		set("drop",1);
        set("get",1);
		set("base_value", 100000);
		set("base_weight", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	string force;

	message_vision(HIG "$N" HIG "С������Ľ���¶�������У���ʱ����"
		       "��̨һ���������������ƮƮ���ɣ�һʱ�侹�в��ڳ����ĸо���"NOR"\n", me);
	
	
	if (me->improve_neili(3200 + random(15000)))
		me->set("neili", me->query("max_neili"));
	force = me->query_skill_mapped("force");
	if (me->can_improve_skill("force")&&me->query_skill("force",1)<1801)
		me->improve_skill("force", 40000);
	if (stringp(force) && me->can_improve_skill(force)&&me->query_skill(force,1)<1801)
		me->improve_skill(force, 40000);

	//me->start_busy(3);
	add_amount(-1);
	return 1;
}
