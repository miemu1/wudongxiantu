
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "深渊晶石" NOR, ( {"tian jings2", "tians2", "jings2"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "终极炼器材料，传言此乃寰宇天晶彻底坠入魔界深渊之地演化而成！"NOR"\n" );
		set("spectxt", "制造装备的材料。\n");
		set("unit", "颗");
		set("value", 100);
		set("tianji1", 100);
        set("no_sell",1);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", HIW "深渊" NOR);
		set("can_make", "all");
		set("power_point", 2500);
	}
}

int query_autoload() { return 1; }