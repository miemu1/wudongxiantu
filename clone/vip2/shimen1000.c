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
	set_name(YEL"ʦ��1000������"NOR, ({"1000shimen"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("yuanbao", 2000);
        set("no_sell",1);
		set("item_origin", 1);
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 100);
		set("long","ʹ�ÿɼ���ʦ����������1000"NOR"��\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	
	if(me->query("shimen/today")< 1001)
	{
		tell_object(me,"�뽫ʦ��������������>1001����ʹ�á�"NOR"\n");
		return 1;
	}
	
	me->add("shimen/today",-1000);
	write(YEL"�������ʦ�Ŵ�����¼������1000�Σ����Լ�����ʦ����!"NOR"\n");
	add_amount(-1);
	return 1;
}