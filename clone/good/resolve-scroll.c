#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIM "�ֽ����" NOR, ({ "resolve scroll", "scroll" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "�ֽ���������ֽ⶯̬װ���и���ħ������Ԫ�ء�\n" NOR);
                set("unit", "��");
                set("value", 500000);
                set("no_sell", 1);
        }
        setup();
}

