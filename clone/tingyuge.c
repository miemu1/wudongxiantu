
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
	set_name(HIB"������ʸ�"NOR, ({"zige dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������ҩ�裬��˵���Ի��������ʸ�\n");
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 100000000);
        set("no_sell", 1);
		set("only_do_effect", 1);
		set("end","/clone/tingyuge");
	}
	setup();
}

int do_effect(object me)
{
    int var;

    if (me->is_busy())
        return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");
	
	if (me->query("tingyvge"))
		return notify_fail("�㻹��һ���ʸ��ء�\n");


        me->add("tingyvge",1);
		me->set("lenque",1);

        message_vision("$NС�ķ�����һ" + query("unit") + name() + "�������һ���������ʸ�\n", me);

	    add_amount(-1);
        return 1;
    

}
