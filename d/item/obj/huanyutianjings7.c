
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "世界本源石" NOR, ( {"tian jings7", "tians7", "jings7"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "终极炼器材料，此乃一方小世界的完全本源之力坍塌压缩而成的源石！"NOR"\n" );
		set("spectxt", "制造装备的材料。\n");
		set("unit", "颗");
		set("value", 1);
		set("tianji1", 500);
        set("no_sell",1);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", HIW "世界" NOR);
		set("can_make", "all");
		set("power_point", 10000);
	}
}

int query_autoload() { return 1; }