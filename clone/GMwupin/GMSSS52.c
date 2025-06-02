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
	set_name(HIR"��Ϊ��ʯ"NOR, ({"xw2 jj"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 1);
			set("tianji1", 100);
            set("no_sell",1);
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 10000);
		set("tianji1", 1);
		set("long","����һ����Ϊ��ʯ��(��Ϊ+1000��)\n");
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

	me->add("combat_exp",10000000);
	write(YEL"������"HIM"��Ϊ�ᾧ"YEL"�����Լ�����Ϊ����!"NOR"\n");

        if (random(50)==1) {
            me->add("per",1);
            message_vision(HIW"ֻ��$N���Ϸ���һ��ҫ�۵İ׹⣬�ƺ�������ʲô��������顣"NOR"\n", me);
            write(HIM"��ϲ�����������ò������!"NOR"\n");
            }
	add_amount(-1);
	return 1;
}
