#include <armor.h>
#include <ansi.h>

inherit CLOTH;


void create()
{
        set_name(HIG "����֮��" NOR, ({ "jianling zhihun", "zhihun" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIG "����һ�����������ӻû����ɲ������ڰ������ϵı��£���������ɫ��â������һֻ������\n" NOR);
                set("material", "steel");
                set("xy_money", 300);
                set("armor_prop/con", 10);
        }
        setup();
}

int query_autoload()
{
        return 1;
}
