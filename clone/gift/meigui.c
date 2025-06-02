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
	set_name(HIR"õ�廨"NOR, ({"meigui hua"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 1);
		set("no_sell",1);
		set("no_give",1);
		set("no_drop",1);
		set("no_get",1);
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 1);
		set("long","����һ���ɺ�������ֲ��"HIR"��õ��"NOR"���������ᷢ����ֵ����飡\n");
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

	me->add("max_qi",5000);
	write(YEL"��ʹ��"HIR"õ��"YEL"�������Լ���Ƥ����ˣ�������500Ѫ!"NOR"\n");

    if (random(1)==1) {
            me->add("per",1);
            message_vision(HIW"ֻ��$N���Ϸ���һ��ҫ�۵İ׹⣬�ƺ�������ʲô��������顣"NOR"\n", me);
            write(HIM"��ϲ�����������ò������!"NOR"\n");
    }
	add_amount(-1);
	return 1;
}

