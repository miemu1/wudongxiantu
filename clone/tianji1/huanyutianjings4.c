
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "神源晶石" NOR, ( {"tian jings4", "tians4", "jings4"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "终极炼器材料，传言此乃救赎圣晶吸收了神明的力量变化而成！"NOR"\n" );
		set("spectxt", "制造装备的材料。\n");
		set("unit", "颗");
		set("value", 100);
		set("tianji1", 150);
        set("no_sell",1);
		set("max_buy",4);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", HIW "神源" NOR);
		set("can_make", "all");
		set("power_point", 3500);
	}
}

int query_autoload() { return 1; }