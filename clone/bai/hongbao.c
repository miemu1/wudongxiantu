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
	set_name(HIR"���"NOR, ({"hongbao"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("jifeng", 12);
		set("no_put", 1);
		set("channel_id", "����");
		set("no_give",1);
		set("no_sell",1);
		set("no_drop",1);
		set("no_get",1);
		set("no_sell", 1);
            set("no_sell",1);
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 100);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	int sui,ji,liwu;
	sui=random(666);
	me->set("shfdaskjdfh",sui);
	ji=me->query("shfdaskjdfh",1);
      if (me->is_busy())
                return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		    return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");

	me->add("jifeng",ji);
	CHANNEL_D->do_channel( this_object(), "chat","��˵"+me->query("name")+"�򿪺�����"HIR+ji+NOR"��ȯ��");

      
	add_amount(-1);
	return 1;
}