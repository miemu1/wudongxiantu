#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name(HIG "����֮��" NOR, ({ "jianling zhihen", "zhihen" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("long", HIG "�����ɽ���������ᾧ���ɵı�ѥ������ȥ�쳣���ء�\n");
                set("xy_money", 300);
                
                set("armor_prop/dex", 10);
                set("armor_prop/T_jianling", 1);
                set("material", "boots");
        }
        setup();
}

int query_autoload()
{
        return 1;
}
