// ITEM Made by player(城南以北:z123456_1) /data/item/z/z123456_1-sqfmd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Mar 19 09:13:21 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m三千繁梦刀[2;37;0m", ({ "sqfmd" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;37m世界[2;37;0m炼制而成的一把刀。
刀柄上刻着一行小字：城南以北(z123456_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一把[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
