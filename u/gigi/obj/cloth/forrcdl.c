// gigiflower.c  ^_^

#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(YEL"һ��ѱ��"NOR, ({ "shit for rcdl", "head" }) );
        set_weight(100);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("unit", "��");
                 set("long","�������������"+YEL"һ��ѱ��"NOR+"��\n"); 
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
