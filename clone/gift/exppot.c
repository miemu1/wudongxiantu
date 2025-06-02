
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG "��ʱ�ӱ���" NOR, ({"exp dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ���ܹ���ʱ������һ����ΪǱ�ܵĵ�ҩ������ʧЧ��\n");
                set("base_unit", "��");
                set("base_value", 10000);
                set("no_sell", 1);
                set("base_weight", 80);
                set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        mapping my;

        if (time() - me->query_temp("last_eat/exp") < 3600)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        me->set_temp("last_eat/exp", time());

        tell_object(me, HIG "����һ����ΪǱ�ܡ�"NOR"\n");

        log_file("static/using", sprintf("%s(%s) eat �ӱ��� at %s.\n",
                        me->name(1), me->query("id"), ctime(time())));

		destruct(this_object());
	return 1;
}
