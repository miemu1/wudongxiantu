// This program is a part of NITAN MudLIB 
// redl 2012/12/1 
#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"����"NOR, ({"ma shu", "ma"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��Ŵ�װ��ź춹ɳ���ɵ��������㰡��\n");
                set("unit", "��");
                set("value", 10000);
                set("food_remaining", 20);
                set("food_supply", 1);
        }
}


int finish_eat()
{
                message_vision(NOR + CYN + "$N" + NOR + CYN + "����" + query("name") + NOR + CYN + "����������������죬��ĺúó԰�����\n" NOR, this_player());
                return 0;
}



