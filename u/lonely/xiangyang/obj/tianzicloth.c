#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIY "�����ӷ�" NOR, ({ "tianzi cloth", "cloth" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 200);
                                set("armor_prop/int", 2);
                                set("armor_prop/con", 2);
                                set("armor_prop/dex", 2);
                                set("armor_prop/str", 2);
        }
        setup();
}
