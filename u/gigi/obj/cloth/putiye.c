// gigiflower.c  ^_^

#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIG"����Ҷ"NOR, ({ "bodhi leaf", "head" }) );
        set_weight(100);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("unit", "Ƭ");
                 set("long","����һƬ����ɫ��"+HIG"����Ҷ"NOR+"��ҶƬɫ��������Բ������\n������������������������ȴ���ǡ�\n"); 
                set("value",0);
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
            set("enchase", ([  
                      "apply_prop" : ([ /* sizeof() == 2 */ 
                              "per" : 25, 
                              "int" : 25, 
                      ]), 
             ])); 

        setup();
}
