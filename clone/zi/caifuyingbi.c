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
	set_name(HIY"�Ƹ����"NOR, ({"wealth coin"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 15000);
        set("no_sell",1);
        set("no_give",1);
		set("no_put", 1);
		set("no_drop",1);
        set("no_get",1);
		set("unit", "ö");
		set("base_unit", "ö");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","�и����������㣬�������Ż����������\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
    if (me->is_busy())
                return notify_fail("����æ���ء�\n");
	if (me->is_fighting())
		    return notify_fail("����ս���У�����ʹ��"+name()+"��\n");
		
		
	write(YEL"��ʹ����һö"+name()+YEL+"��"NOR"\n");
	me->add("zhanling/a5",2000);
	write(YEL"�����2000ս����Ϊ��"NOR"\n");
	me->add("yuanbao",100000);
	write(YEL"������˱��׵�10����ʯ��"NOR"\n");
	me->add("tianji1",5000);
	write(YEL"������˱���5000����㣡"NOR"\n");
	if (random(10)<=2) {
	me->add("jifeng",100000);
	write(YEL"��ϲ��ʮ��֮���ĸ������������10���ȯ��"NOR"\n");
	}else
	if (random(30)<=1){
	me->add("tianji1",100000);
	write(YEL"��ϲ����30��֮1�ĸ��ʻ����ʮ������㣡"NOR"\n");
	}
	// me->add("zjvip/all_pay",1000000);
	// write(YEL"�����1000000�����ף�"NOR"\n");
	add_amount(-1);
	return 1;
}