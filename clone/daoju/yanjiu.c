// 研究勋章
inherit ITEM;

#include <ansi.h>

void create()
{
        set_name(HIG"限定研究勋章"NOR, ({ "yj"}) );
	        set("long", "一枚限定版研究勋章，可以加成研究效率。\n");
                set("yuanbao", 30000); 
				set("unit","枚");
		    set("no_sell", 1);
                set("no_give", 1);
                set("no_steal", 1);
		    set("no_drop", 1);
	setup();
}
int query_autoload() { return 1; }
