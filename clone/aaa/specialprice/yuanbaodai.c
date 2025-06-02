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
	set_name(HIY"������ʯ��"NOR, ({"nhua dai"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW"���˴������ʯ���ӣ��и��ʻ��һ����ʯ\n"NOR);
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 1000);

		set("yuanbao", 1200);
        set("no_sell", 1);
		set("no_put",1);
		set("no_get",1);
		set("no_give",1);
		set("no_drop",1);
		set("no_sell",1);
		set("no_steal",1);
        set("no_drop",1);
        set("no_give",1); 
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
    int i,ob1;

    if (me->is_busy())
           return notify_fail("����æ���ء�\n");
i=random(6);

if (i>=1){
me->add("yuanbao",1000000);
message_vision(HIR"$N�����100000000����ʯ��"NOR"\n", me, this_object());
}	
	add_amount(-1);
	return 1;

}
