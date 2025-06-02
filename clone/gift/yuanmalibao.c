
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
	set_name("Դ�����", ({"yuanma libao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��ʦ�׵ĲƲ���\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 10);
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
	int i,num1,num2,num3,num4;
	object gong,bagua,jian;

	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");

	num1=200000;
	me->add("combat_exp",num1);
	num2=250000;
	me->add("potential",num2);
	//me->add("weiwang",num4);
	me->set("p_master/last_learnto",me->query("combat_exp"));
	//me->add("zjvip/times",72*3600);

	message_vision("$N����һ" + query("unit") + name() + "��\n", me);
	write(YEL"��ϲ���������"+num1+"����Ϊ��"NOR"\n");
	write(YEL"��ϲ���������"+num2+"��Ǳ�ܡ�"NOR"\n");
	
	/*gong = new("/clone/gift/weiwang");
	write(YEL"��ϲ���������"+gong->short()+"��"NOR"\n");
	gong->move(me);*/
	jian = new("/clone/jifeng/dan_wuji");
	jian->set_amount(5);
	write(YEL"��ϲ���������"+jian->short()+"��"NOR"\n");
	jian->move(me);
	bagua = new("/clone/jifeng/kuilei");
	bagua->set_amount(3);
	write(YEL"��ϲ���������"+bagua->short()+"��"NOR"\n");
	bagua->move(me);

	
	add_amount(-1);
	me->save();

	return 1;
}
