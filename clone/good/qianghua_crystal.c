// This program is a part of NT MudLIB
// ab_crystal.c ����ˮ��

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC"ǿ��ˮ��"NOR, ({ "qianghua crystal", "qianghua", "crystal" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIC "���淺����ɫ��â��ǿ��ˮ����װ����6��֮ǰʹ�ã�������6�ǣ�������100%ǿ���ɹ���\n" NOR);
                set("value", 50000);
                set("unit", "��");
        }
        //set("set_data", 1);
        set("autoload", 1);
        setup();
}
