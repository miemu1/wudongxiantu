
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
	set_name(HIW"威望丹[绑]"NOR, ({"weiwang dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一颗神奇的药丸，据说可以提升人物的江湖威望。\n");
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);
		set("base_value", 10000);
		set("yuanbao", 10);
        set("no_sell", 1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
        set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
    int var;

    if (me->is_busy())
        return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

    if (me->query("combat_exp")<me->query("weiwang"))
        return notify_fail("你的江湖威望已极高了，无需使用"+ name() +"。\n");
    else {
        var=10000;
        me->add("weiwang",var);

        message_vision("$N小心服用了一" + query("unit") + name() + "，你的江湖威望提高了。\n", me);

	    add_amount(-1);
        return 1;
    }

}
