
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "救赎圣晶" NOR, ( {"tian jings3", "tians3", "jings3"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "终极炼器材料，传言此乃深渊晶石得到神明的救赎从而变化而成！"NOR"\n" );
		set("spectxt", "制造装备的材料。\n");
		set("unit", "颗");
		set("value", 100);
		set("tianji1", 125);
        set("no_sell",1);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", HIW "救赎" NOR);
		set("can_make", "all");
		set("power_point", 3000);
	}
}

int query_autoload() { return 1; }