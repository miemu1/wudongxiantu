// �ٹȷ�

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW "�ٹȷ�" NOR, ({ "bigu fu", "fu" }) );
        set_weight(30);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "Я�����Զ�����ٹ�״̬, �ճ�������ʳ����ˮ��\n" NOR);
                set("value", 1);
                set("no_sell", 1);
                set("unit", "��");
        }
        set("auto_load", 1);

        setup();
}
