// cdiamond.c ×êÊ¯ËéÁ£

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HBRED "µÛ×ðº¡¹Ç¡¤ËéÆ¬" NOR, ({ "dzhgm1 sp" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIW "¼¯Æë999Æ¬¡ºµÛ×ðº¡¹Ç¡¤ËéÆ¬¡»¼´¿ÉºÏ³É1¿é µÛ×ðº¡¹Ç£¡"NOR"\n");
		set("base_value", 1000);
		set("base_weight", 1);
		set("base_unit", "Æ¬");
		set("can_be_enchased", "/clone/GMwupin/GMSSS1");
		set("enchased_need", 999);
		set("yuanbao", 10000);
		set("no_put", 1);
		set("no_give",1);
		set("no_sell",1);
		set("no_drop",1);
		set("no_get",1);
		set("no_sell", 1);
		set("magic/type", "lighting");
		set("magic/power", 30);
	}
	set_amount(1);
	setup();
}
