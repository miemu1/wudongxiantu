#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "师门重置令" NOR, ({ "shimenchongzhi ling", "ling"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一枚重置师门，不信试试。\n");
                set("value", 1);
		set("unit", "颗");
		set("no_put", 1);
		set("kedian", 950);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("tianji1", 500);
		set("only_do_effect", 1);
	}
}

int do_effect(object me)
{
        message_vision("$N手轻轻一挥师门重置令，师门次数发生了变化" + this_object()->name() +
                       "。\n", me);
      me->set("shimen/today", 0);

      write("\n "HIR"师门次数归零。"NOR);
     destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }
