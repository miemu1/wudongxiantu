// poison.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_weight(50);
        set_name(HIG "�����涾" NOR, ({"tangmen qidu", "du yao", "poison"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������������ط����ö��ɵĶ�ҩ��ֻҪһ����Ϳ������������أ�\n");
                set("value", 50);
		set("poison_type", "poison");
                set("can_pour", 1);
                set("can_daub", 1);
                set("can_drug", 1);
                set("poison", ([
                        "level" : 1100,
                        "id"    : "tang du",
                        "name"  : "�����涾",
                        "duration": 40,
                ]));
                set("no_sell", 1);
		set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        message_vision("$Nһ�������������涾ȫ�����������С�\n",
                       me);
        me->set_temp("die_reason", "���������涾����������");
        me->die();
        destruct(this_object());
        return 1;
}

