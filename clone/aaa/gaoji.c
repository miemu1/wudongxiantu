
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"高级传奇"HIY"灵"HIC"石" NOR, ({"gao stone", "ling", "shi"}));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIY"低级传奇灵石万中之一中诞生出来的神奇装备石。"NOR"\n");
		set("spectxt", "制造灵兵的材料。\n");
		set("unit", "块");
		set("no_put", 1);
		set("value", 80000000);
		set("shenbing",10);
		set("yuanbao", 2555);
		set("item_origin", 1);
		set("material_attrib", "magic stone");
		set("material_name", HIY "高级传奇"MAG"灵石" NOR);
		set("can_make", "all");
		//set("not_make", ({ "战衣", "腰带", "裤子" }));
		set("power_point", 800);
	}
}

int query_autoload() { return 1; }