
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
	set_name("�·�С���", ({"kaihuang libao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�·�С�����\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 10);
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop",1);
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
	if (! me->query("born"))
return notify_fail("�㻹û�г����أ�������ȡ���\n");

	if (me->is_fighting())
		return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");

	
	message_vision("$N����һ" + query("unit") + name() + "��\n", me);
	
	
	
	jian = new("/clone/shizhe/tianling3");
	jian->set_amount(2);
	write(YEL"��ϲ���������"+jian->short()+"��"NOR"\n");
	jian->move(me);
	jian = new("/clone/shizhe/dan_yuanbao");
	jian->set_amount(1);
	write(YEL"��ϲ���������"+jian->short()+"��"NOR"\n");
	jian->move(me);
	bagua = new("/clone/vip3/putao1");
	bagua->set_amount(50);
	write(YEL"��ϲ���������"+bagua->short()+"��"NOR"\n");
	bagua->move(me);
	bagua = new("/clone/jifeng/dan_chongmai2");
	bagua->set_amount(150);
	write(YEL"��ϲ���������"+bagua->short()+"��"NOR"\n");
	bagua->move(me);
	bagua = new("/clone/vip2/gaojibtdan");
	bagua->set_amount(1);
	write(YEL"��ϲ���������"+bagua->short()+"��"NOR"\n");
	bagua->move(me);

	

	add_amount(-1);
	me->save();

	return 1;
}
