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
	set_name(HIY"Ԫ��"NOR, ({"yuanshen"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("no_steal", 1);set("yuanbao_2", 10);
            set("no_sell",1);
         set("no_give",1);
        set("no_drop",1);         
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 100);
		set("long","����һ��������õĻ�ħ��"HIY"Ԫ��"NOR"���������ᷢ�����ֵ����飡(���+2000)\n");
		set("only_do_effect", 1);set("no_sell",1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		    return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");

	me->add("experience",2000);
	write(YEL"�����һ��"HIY"Ԫ��"YEL"�����Լ���������!"NOR"\n");

	add_amount(-1);
	return 1;
}