// gigiflower.c  ^_^

#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIW"������"NOR, ({ "pear flower", "head" }) );
        set_weight(100);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("unit", "��");
                 set("long","����һ���׵��滨�����������£�\n����ʫ������:�������ʣ�һ���滨ϸ���С���\n"); 
                set("value",0);
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
