// jiuzhuan.c 九转金丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIM "高级战令激活卡" NOR, ({ "zhanling card"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "使用此卡可以解锁高级战令，从而领取奖励。\n");
		set("spectxt", "注：只对当前赛季有效。\n");
		set("value", 1);
		set("unit", "张");
            set("no_sell",1);
            set("no_give",1);
            set("no_drop",1);
            //set("no_put",1);
		set("only_do_effect", 1);
		set("suit_point",300);
				set("yuanbao", 100000);
	}
}

int do_effect(object me)
{
	int effect;
	 mapping my;



	effect = 0;
	message_vision("$N使用了一张" + this_object()->name() +
		       "。\n", me);

	write(HIM "恭喜你解锁了高级战令奖励领取资格。"NOR"\n");
	me->set("zhanling/goumai", 10);

	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }