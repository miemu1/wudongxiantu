// This program is a part of NT MudLIB
// ab_crystal.c ����ˮ��

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM"ʥ��ˮ��"NOR, ({ "shengling crystal", "shengling", "crystal" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIM "ʥ��ˮ�������Ա�֤��ǿ��װ��ʧ��ʱ�򲻵��Ǽ����������ϼ��ɡ�\n" NOR);
                set("value", 50000);
                set("unit", "��");
        }
        //set("set_data", 1);
        set("autoload", 1);
        setup();
}
