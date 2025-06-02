#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload()
{
	return query_amount() + "";
}

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
	set_name(HIY"ϴ�㵤"NOR, ( {"xidian dan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value", 100);
		set("jifeng", 2000);
		set("no_sell",1);
		set("unit", "��");
		set("no_put", 1);
		set("no_give",1);
		set("no_sell",1);
		set("no_drop",1);
		set("no_get",1);
		set("no_sell", 1);
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 100);
		set("long","ϴ����ߣ�ʹ�ú����ȥ����ϴ��ʦ����ϴ�㡣\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");

	if (me->query("zjvip/xiaobaizuishuai"))
		return notify_fail("��ʹ�ù�ϴ�㵤�����ǻ�û��ϴ�㣬�����ظ�ʹ�á�\n");

	me->set("zjvip/xiaobaizuishuai",1);
	write(YEL"��ʹ����һ��"HIY"ϴ�㵤"YEL"�������ڿ���ȥ������ϴ��ʦϴ����!"NOR"\n");

	add_amount(-1);
	return 1;
}