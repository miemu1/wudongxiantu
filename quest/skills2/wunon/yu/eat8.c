// ë�� /clone/eat/food/mao_sun.c
// by lala, 1997-12-16

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name(HIM"�з"NOR, ({"yu8"}));
    set_weight(30000);
	    if ( clonep() )
            set_default_object( __FILE__ );
    else {
    set("long", "һ�������з\n");
    set("unit", "��");

        set( "value", 1 );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
	}
}

