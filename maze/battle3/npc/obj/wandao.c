// gangdao.c
#include <weapon.h>
inherit BLADE;
#include <ansi.h>
void create()
{
        set_name(HIW"�ط絶"NOR, ({ "wan dao","dao","blade" }));   
        set_weight(12000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������Ļط絶���ǹ��������ĳ���������\n");
                set("value", 10000);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
        }
        init_blade(200);
        setup();                   
}
