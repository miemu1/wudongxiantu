#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(NOR + YEL "�ɹ���" NOR, ({ "cloth" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
