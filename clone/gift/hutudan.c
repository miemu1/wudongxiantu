// xiandan.c ��Ϳ��

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "��Ϳ��" NOR, ({ "hutu dan", "dan", "hutu" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��԰԰����ĵ�ҩ����˵���˿��Խ���������\n");
                set("value", 10000);
                set("unit", "��");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);

                tell_object(me, HIG "һ�ɻ�����Ȼ����������"
                            "��ͷʹ���ѣ��о���������һ��"
			    "��ʱ���Ӳ�̫����ˡ�\n");
                me->add("int", -1);
             write("\n "+HIR+"��ϲ�㣺"+NOR+HIG+"�����ɵ��ɹ������������ԡ������ˣ����� "+NOR);

        me->add("gift/xiandan", 1);
        destruct(this_object());
	return 1;
}
