#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC "����" HIY "�Իƽ�" NOR, ({ "nao huangjin", "nao", "huangjin" }) );
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "����д�š�" HIY "2003���ҼҲ���������ֻ"
                            "���Իƽ�" HIG "���������Ǹ߼�����\n" NOR);
                set("value", 500000);
                set("no_sell", 1);
                set("unit", "��");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
              message_vision(HIW "$N" HIW "����һЦ����һ�����Իƽ���ͬ"
                       "����һ�����¶�ȥ��\n" NOR, me);
               addn("combat_exp", 100000000, me);
               addn("potential", 30000000, me);
         addn("experience", 15000000, me);

        destruct(this_object());
        return 1;
}
