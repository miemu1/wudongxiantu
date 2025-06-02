
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
	set_name(HIC "�����" NOR, ({"feicui lan", "feicui", "lan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("base_unit", "��");
		set("long", "����һ��ǧ���ѵ�һ�������������˵�ܽ�ٶ���\n");
		set("no_sell", 1);
		set("jifeng", 50);
		set("no_put", 1);
		set("no_give",1);
		set("no_sell",1);
		set("no_drop",1);
		set("no_get",1);
		set("no_sell", 1);
		set("base_value", 2000000);
		set("base_weight", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	me->set_temp("nopoison", 3);
	me->set("eff_jing", me->query("max_jing"));
	me->set("jing", me->query("max_jing"));
	message_vision("$N��" + name() + "�ӽ�������¾�������ȥ��\n", me);
	tell_object(me, HIG "\n��ֻ��һ�����������ķΣ���ʱ��̨һƬ������������ˬ��"NOR"\n");
	add_amount(-1);
	return 1;
}

