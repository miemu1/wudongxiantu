#include <ansi.h>
inherit ITEM;

void create()
{
        set_weight(50);
        set_name(HIG "��" NOR, ({"xiang"}));
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("unit", "��");
                set("long", "����һ���裬����͸¶��һ�����㣬�����̲�ס��һ�ֳ�һ�ڵĳ嶯��\n");
                set("value", 50);
                set("poison_type", "poison");
                set("can_pour", 1);
                set("can_daub", 1);
                set("can_drug", 1);
                set("poison", ([
                        "level" : 1100,
                        "id"    : "xiang",
                        "name"  : "��",
                        "duration": 40,
                ]));
                set("no_sell", 1);
                set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        message_vision("$N���һ�ţ������һ���衣\n",
                       me);
        set_temp("die_reason", "�����豩��������", me);
        me->die();
        destruct(this_object());
        return 1;
}

