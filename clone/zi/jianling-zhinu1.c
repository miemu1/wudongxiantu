#include <armor.h>
#include <ansi.h>

inherit HEAD;
 
void create()
{
        set_name(HIG "����֮ŭ" NOR, ({ "jianling zhinu", "zhinu", }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIG "�����ɺ���ʯ�ͽ����ŭ���ᾧ���ɵ�ͷ���������â������η��\n" NOR);
                set("xy_money", 300);
                set("armor_prop/dex", 10);
                set("armor_prop/str", 10);               
        }
        setup();
}

int query_autoload()
{
        return 1;
}
