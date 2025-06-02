
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
	set_name("�������", ({"buchang libao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��ʦ�ĲƲ���\n");
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
	object gong,bagua,jian,jiuzhuan;

	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");


	//me->add("jifeng",500);
	me->set("p_master/last_learnto",me->query("combat_exp"));
	

	message_vision("$N����һ" + query("unit") + name() + "��\n", me);
	write(YEL"��ϲ���������500���ȯ��"NOR"\n");

	jiuzhuan = new("/clone/vip3/jiuzhuan");
	jiuzhuan->set_amount(3);
	write(YEL"��ϲ���������"+jiuzhuan->short()+"��"NOR"\n");
	jiuzhuan->move(me);
	jian = new("/clone/vip3/kuilei");
	jian->set_amount(2);
	write(YEL"��ϲ���������"+jian->short()+"��"NOR"\n");
	jian->move(me);
	bagua = new("/clone/vip3/putao");
	bagua->set_amount(5);
	write(YEL"��ϲ���������"+bagua->short()+"��"NOR"\n");
	write(YEL"��л���Ե�֧�֣����ڱ��ε�ƽ��ͻص��¼� ���Ǳ�ʾ���Ե�Ǹ�⣡�صظ���λ������ֿ��Ǹ�⣡"NOR"\n");
	bagua->move(me);


	add_amount(-1);
	me->save();

	return 1;
}