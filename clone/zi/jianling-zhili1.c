#include <armor.h>
#include <ansi.h>

inherit HANDS;

void create()
{
        set_name(HIG "����֮��" NOR, ({ "jianling zhili", "zhili"}) );
        set_weight(1);
        if( clonep())
                set_default_object(__FILE__);
        else {
                set("material", "paper");
                set("unit", "��");
                set("long", HIG "����һ�ŵ���ɫ�Ļ���������������������һ�㡣\n" NOR);
                set("xy_money", 300);
                set("armor_prop/int", 10);              
        }
        setup();
}

int query_autoload()
{
        return 1;
}
