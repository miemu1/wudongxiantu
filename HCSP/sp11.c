// cdiamond.c ×êÊ¯ËéÁ£

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HBRED "ÕæÁúº¡¹Ç¡¤ËéÆ¬" NOR, ({ "zlhga1 sp" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIW "¼¯Æë50Æ¬¡ºÕæÁúº¡¹Ç¡¤ËéÆ¬¡»¼´¿ÉºÏ³É1¿é ÕæÁúº¡¹Ç£¡"NOR"\n");
		set("base_value", 1000);
		set("base_weight", 1);
		set("base_unit", "Æ¬");
		set("can_be_enchased", "/clone/GMwupin/GMSSS3");
		set("enchased_need", 36);
		set("yuanbao", 100);
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
