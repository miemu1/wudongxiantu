// necklace.c 肚带
#include <ansi.h>   
#include <armor.h>
 
inherit SURCOAT;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name((order[random(13)])+"流水肚带"NOR, ({ "surcoat8"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "条");
		set("long", "这是一件皮质的流水肚带，用以保护腹部。\n");
		set("value", 1900);
	set("armor_prop/dodge", 14);
set("armor_prop/intelligence",14);
set("armor_prop/armor", 30);
	}
	setup();
}
