// yinpai.c 钻石碎粒

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIW "快捷银牌" NOR, ({ "yinpai" }) );
	set_weight(25);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIW "携带银牌多两个快捷键aa,bb"
                    "设置方法命令输入 alias aa XXXXXXXX"NOR"\n");
                set("value", 10000);
		 set("suit_point",20);
		set("unit", "面");
                set("can_be_enchased", 1);
                set("magic/type", "lighting");
                set("magic/power", 50);
                set("armor_prop/per", 3);
                set("wear_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "戴在头上。"NOR"\n");
                set("remove_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "从头上摘了下来。"NOR"\n");
	}
        setup();
}

int query_autoload() { return 1; }
