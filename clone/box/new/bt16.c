// boots.c 皮靴
#include <ansi.h> 
#include <armor.h>

inherit BOOTS;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"神鹰之靴"NOR, ({ "boots16"}) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "双");
		set("long", "这是一双神鹰之靴。用以保护足部。并加快你的速度。\n");
		set("value", 2400);
set("armor_prop/armor", 68);
	set("armor_prop/dodge", 11);
set("armor_prop/dexterity",19);
	}
	setup();
}
