// gigiflower.c  ^_^

#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(YEL"һ������"NOR, ({ "shit for dcgz", "cloth" }) );
        set_weight(100);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("unit", "��");
                 set("long","���Ǵ󳦸����"+YEL"һ������"NOR+"��\n"); 
                set("wear_msg", NOR "$N���Ĵ�����ͳ�" YEL "һ������" NOR "Ĩ�����ϡ�\n" NOR); 
                set("remove_msg", NOR "$N�ֽŲ��õذ�����" YEL "һ������" NOR "���һ�����������\n" NOR); 
                set("value",0);
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
            set("enchase", ([  
                      "apply_prop" : ([ /* sizeof() == 2 */ 
                              "per" : -25, 
                              "int" : -25, 
                      ]), 
             ])); 

        setup();
}
