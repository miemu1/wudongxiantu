
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"传奇"HIY"灵"HIC"石" NOR, ({"magic stone", "ling", "shi"}));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIY"传奇异世界掉落的伪天灵石装备石。"NOR"\n");
		set("spectxt", "制造灵兵的材料。\n");
		set("unit", "块");
		set("no_put", 1);
		set("value", 80000000);
		set("shenbing",10);
		set("yuanbao", 2522);
		set("item_origin", 1);
		set("material_attrib", "magic stone");
		set("material_name", HIY "传奇"MAG"灵石" NOR);
		set("can_make", "all");
		//set("not_make", ({ "战衣", "腰带", "裤子" }));
		set("power_point", 600);
	}
}

int query_autoload() { return 1; }