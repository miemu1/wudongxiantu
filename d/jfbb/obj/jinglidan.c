// shenliwan.c ���ݵ�

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "������" NOR, ({ "jingli shenwan", "shenwan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ�ž�����,���˿����Ӿ�����\n");
		set("no_put",1);
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
        if (me->query("max_jinglili") >= 50000000)
        {
                message_vision("$NͻȻ����һ������ޱȵ���ƨ��\n", me);
                tell_object(me, "����ô���ǳԻ��˶��ӡ�\n");
        } else
        {
                message("vision", "���ƺ�����" + me->name() + "��ȫ���������졣\n",
                                  environment(me), ({ me }));
                tell_object(me, HIY "��о������ƺ�һ���ӳ�ʵ�ˣ�������������ˬ��"
                                "����һ�����ͣ���������ƺ��������ۺ��ˡ�\n" NOR);
                me->add("max_jingli", 3000);
        }

        destruct(this_object());
	return 1;
}

