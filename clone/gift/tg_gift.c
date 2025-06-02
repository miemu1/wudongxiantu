
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
	set_name(HIR"�ƹ����"NOR, ({"tuiguang box"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�䶯��;����һ·������л������ף����Ϸ��죡\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 100);
		set("yuanbao", 10);
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	int num1,num2,num3;
	object dan;

	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");

	num1=1000000;
	me->add("combat_exp",num1);
	num2=1000000;
	me->add("potential",num2);
	num3=1000000;
	me->add("experience",num3);
	me->add("score",5000);
	dan = new("/clone/gift/huiling");

	if(me->query("p_master"))
		me->set("p_master/last_learnto",me->query("combat_exp"));

	dan->move(me);
	message_vision("$Nʹ����һ" + query("unit") + name() + "��\n", me);
	write(YEL"��ϲ���������"+num1+"����Ϊ��"NOR"\n");
	write(YEL"��ϲ���������"+num2+"��Ǳ�ܡ�"NOR"\n");
	write(YEL"��ϲ���������5000��������"NOR"\n");
	write(YEL"��ϲ���������"+num3+"��ʵս��ᡣ"NOR"\n");
	write(YEL"��ϲ���������"+dan->short()+"��"NOR"\n");
	add_amount(-1);
	me->save();
	return 1;

}
