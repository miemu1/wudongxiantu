// gigiflower.c  ^_^

#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(YEL"һ������"NOR, ({ "shit for toxin", "head" }) );
        set_weight(100);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("unit", "��");
                 set("long","���Ǻ��ӳ���"+YEL"һ������"NOR+"��\n"); 
                set("wear_msg", NOR "$N���Ĵ�����ͳ�" YEL "һ������" NOR "����ͷ�ϡ�\n" NOR); 
                set("remove_msg", NOR "$N����ذ�ͷ��" YEL "һ������" NOR "�����������\n" NOR); 
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
