

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "�츳��" NOR, ({ "tianfu", "dan" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�ſ�������ת���츳��ҩ�衣\n");
                set("value", 5000);
                set("unit", "��");
                set("per",10);
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{

        log_file("static/using", sprintf("%s(%s) eat �츳�� at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);

        message("vision", "�����ϵĹ�ͷžž�����죬�ƺ��о��Լ���������˲�С�ı仯��\n",
                          environment(me), ({ me }));

		UPDATE_D->born_playerone(me);

        destruct(this_object());
        return 1;
}
int query_autoload() { return 1; }

