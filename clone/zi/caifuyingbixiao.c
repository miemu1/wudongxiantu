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
	set_name(HIY"�Ƹ���ң�С��"NOR, ({"xiaowealth coin"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("tianji1", 10);
        set("no_sell",1);
        set("no_give",1);
		set("no_put", 1);
		set("no_drop",1);
        set("no_get",1);
		set("no_auto_get",1);
		set("unit", "ö");
		set("base_unit", "ö");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","һöӲ�Ҷ��������档\n");
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
	me->add("zhanling/a5",20);
	write(YEL"�����20ս����Ϊ��"NOR"\n");
		me->add("yuanbao",88);
	write(YEL"������˱��װ�ʮ����ʯ��"NOR"\n");
	if (random(4)<=2) {
	me->add("jifeng",88);
	write(YEL"��ϲ������֮һ�ĸ�����������˰�ʰ�Ƶ�ȯ��"NOR"\n");
	}else
	if (random(4)==1){
	me->add("tianji1",1);
	write(YEL"��ϲ�������֮һ�ĸ��ʻ����һ����㣡"NOR"\n");
	}

	add_amount(-1);
	return 1;
}