#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR "����֮��" NOR, ({ "wangzhe zhixin", "wangzhe", "stone" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "����һ�ž�Ө��覵ı�ʯ����˵ӵ������õ��������������̻���װ�ıر����ϡ�\n" NOR); 
                set("unit", "��");
                set("value", 500000);
                set("no_sell", 1);
                set("auto_load", 1);
        }
        setup();
}
