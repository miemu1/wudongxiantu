// shenliwan.c ���ݵ�

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIB "������" NOR, ({ "power wan", "liliang"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ��������,���˿�������ı�����\n");
              	set("no_sell",1);
              	set("no_drop",1);
		set("unit", "��");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        me = this_player();
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
        if (me->query("baoji") >= 2000)
        {
                message_vision("$NͻȻ����һ������ޱȵ���ƨ��\n", me);
                tell_object(me, "����ô���ǳԻ��˶��ӡ�\n");
        } else
        {
                message("vision", "���ƺ�����" + me->name() + "��ȫ���������졣\n",
                                  environment(me), ({ me }));
                tell_object(me, HIY "��о������ƺ�һ���ӳ�ʵ�ˣ�������������ˬ��"
                                "����һ�����ͣ���������ƺ��������ȸ��ۺ��ˡ�\n" NOR);
                me->add("baoji", 2+random(2));
        }

        destruct(this_object());
	return 1;
}

