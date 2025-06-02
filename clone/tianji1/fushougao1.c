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
	set_name(HIW "��Ʒ���ٸ�" NOR, ({"xianpinyao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIY "һ��ںڵ�ҩ���������󣬾�˵�������˾���ٱ���\n");
		set("value", 1);
		set("tianji1", 1);
		set("give",1);
		set("put", 1);
		set("drop",1);
        set("get",1);
		set("only_do_effect", 1);
		set("base_weight", 200);
	}
	setup();
}

int do_effect(object me)
{
	string force;

	message_vision(HIC"$N�ͳ�һ֧��ǹ�����������һ��"
		       NOR HIW"���ٸ࣬"NOR HIC"��������ƮƮ���ɣ�����¶�������"
		       "���顣"NOR"\n",
		       me);
	if (me->improve_jingli(1000 + random(500)))
		me->set("jingli", me->query("max_jingli"));
	add_amount(-1);
	return 1;
}
