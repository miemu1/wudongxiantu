//chahua12.c
#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
	set_name(HIW"抓破"HIG"美"NOR"人"HIR"脸"NOR, ({"cha hua", "hua"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "朵");
		set("long", 
"一株茶花，白色花瓣上有一抹绿晕、一丝红条。\n");
		set("value", 50);
		set("material", "plant");
		set_weight(10);
	set("armor_prop/armor", 0);
	set("armor_prop/personality", 3);
		set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
		set("unequip_msg", "$N轻轻地把$n从头上摘了下来。\n");
	}
	setup();
}

