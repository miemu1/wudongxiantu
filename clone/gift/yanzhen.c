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
	set_name(HIG"ʦ����֤��"NOR, ({"shimen"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("jifeng", 12);
		set("no_put", 1);
		set("no_give",1);
		set("no_sell",1);
		set("no_drop",1);
		set("no_get",1);
		set("yuanbao",10);
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 100);
		set("long","�������˹����ܺ����������ʦ����֤owo(����֤ʱ������1��)\n");
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

	me->add("yanzhen",60*60*24);
	write(YEL"���ٻ�"HIR"����"YEL"���������֤!"NOR"\n");

        if (random(1000)==1) {
            me->add("per",1);
            message_vision(HIW"ֻ��$N���Ϸ���һ��ҫ�۵İ׹⣬�ƺ�������ʲô��������顣"NOR"\n", me);
            write(HIM"��ϲ�����������ò������!"NOR"\n");
            }
	add_amount(-1);
	return 1;
}