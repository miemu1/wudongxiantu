
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"天外"HIY"神"HIC"石" NOR, ({"magic stone", "tianwai", "tianwai"}));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIY"元年二十三，天运不详，杀星降世，神石落地。"NOR"\n");
		set("spectxt", "制造神兵的材料。\n");
		set("unit", "块");
		set("no_put", 1);
		set("value", 80000000);
		set("shenbing",10);
		set("yuanbao", 62222);
		set("no_give",1);
		set("no_shop", 1);//下架
		 set("no_get", 1);
        set("no_drop", 1);
        set("no_give", 1);
        set("no_sell", 1);
		set("item_origin", 1);
		set("material_attrib", "magic stone");
		set("material_name", HIY "天外"MAG"神石" NOR);
		set("can_make", "all");
		//set("not_make", ({ "战衣", "腰带", "裤子" }));
		set("power_point", 600);
	}
}

int query_autoload() { return 1; }