

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "���Ե�" NOR, ({ "gender", "dan" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�ſ���������Ա�ĵ�ҩ��\n");
                set("value", 5000);
                set("unit", "��");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
		string msg;
        log_file("static/using", sprintf("%s(%s) eat ���Ե� at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        message_vision("$Nһ������������һ��" + this_object()->name() + "��\n", me);

		if(me->query("family/family_name") == "������" )
			return notify_fail("�㻹�����뿪�����ٱ��԰ɡ�\n");

		if(me->query("family/family_name") == "���չ�" )
			return notify_fail("�㻹�����뿪�����ٱ��԰ɡ�\n");

		if(me->query("family/family_name") == "������" )
			return notify_fail("�㻹�����뿪�����ٱ��԰ɡ�\n");

		if(me->query("family/family_name") == "�ƻ���" )
			return notify_fail("�����ƻ����Ļ��ұ��ԣ���������\n");

		if(me->query("gender") == "����")
		{
			tell_object(me, HIW "��о��Լ������巢���˵ı仯����Ů�˵ĸо���ã�\n" NOR);
			me->set("gender","Ů��");
			me->save();
		}else if(me->query("gender") == "Ů��")
		{
			tell_object(me, HIW "��о��Լ������巢���˵ı仯�������˵ĸо���ã�\n" NOR);
			me->set("gender","����");
			me->save();
		}else if (me->query("gender") == "����")
		{
				tell_object(me, HIW "����������ת����Ա����Ի�Ů�ԣ���\n" NOR);
				input_to("get_select",me);
		}

        destruct(this_object());
        return 1;
}

void get_select(string arg, object me)
{
        string msg;

        if (arg != "����" && arg != "Ů��")
        {
                tell_object(me, HIW "�����롰 ���� �� Ů�� ����\n" NOR);
                input_to("get_select",me);
                return;
        }
        if (arg == "����")
        {
				tell_object(me, HIW "��ϲ����ʰ�����۷硣\n" NOR);
                me->set("gender","����");
                me->save();
                return;
        }
        if (arg == "Ů��")
        {
				tell_object(me, HIG "��ϲ����Գ�Ϊ������Ů���ˣ�\n" NOR);
                me->set("gender","Ů��");
                me->save();
                return;
        }
        return;

}

int query_autoload() { return 1; }

