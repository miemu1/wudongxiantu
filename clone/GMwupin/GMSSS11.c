// jinchuang.c �������ɵ�

inherit ITEM;

#include <ansi.h>

void create()
{
        set_name(HIY "�������ɵ�" NOR, ({"bmsd danMR"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���ǹ�ͨ�澭����������������\n");
                set("tianji1", 700);
		    set("no_get", 1);
		    set("no_give", 1);
		    set("no_sell", 1);
		    set("no_steal", 1);

                set("no_sell", 1);set("value", 200);
                set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{    
   int effect;
	 mapping my;

        log_file("static/using", sprintf("%s(%s) eat �������ɵ� at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        effect = 0;
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
					   
					   
if( me->query("meridian/��������")>0 )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܰ������ɵ���ҩ��!\n");


if( me->query("meridian/��������")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܰ������ɵ���ҩ��!\n");
		
		
if( me->query("meridian/��ά��")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܰ������ɵ���ҩ��!\n");


if( me->query("meridian/��ά��")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܰ������ɵ���ҩ��!\n");
		
		
if( me->query("meridian/������")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܰ������ɵ���ҩ��!\n");

if( me->query("meridian/������") >0 )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܰ������ɵ���ҩ��!\n");


if( me->query("meridian/����")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܰ������ɵ���ҩ��!\n");


if( me->query("meridian/����")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܰ������ɵ���ҩ��!\n");




 CHANNEL_D->do_channel(this_object(), "rumor", "��ϲ" + me->name() + "��ͨ��"HIR"ȫ���С���쾭��"HIM",�����������ˡ���\n");

                effect++;
                write(HIM "������Լ���ͷ�Ը������ˡ�"NOR"\n");
                me->set("meridian/��������", 0);
				me->set("meridian/��������", 0);
				me->set("meridian/��ά��", 0);
				me->set("meridian/��ά��", 0);
				me->set("meridian/������", 0);
				me->set("meridian/������", 0);
				me->set("meridian/����", 0);
				me->set("meridian/����", 0);
               
				me->add("gain/break", 5000);
				me->add("gain/armor", 5000);
				me->add("gain/2dp", 1000);
				me->add("gain/2ap", 1000);
				me->add("gain/attack", 5000);
				me->add("gain/defense", 5000);
				me->add("gain/damage", 5000);
				me->add("gain/max_qi", 50000);
                write("\n "+HIR+"��ϲ�㣺"+NOR+HIG+"���ð������ɵ����澭������������֮�������� "+NOR);
        
		
		if(me->query("meridian/����") >=0
		&& me->query("meridian/����") >=0
		&& me->query("meridian/��ά��") >=0
		&& me->query("meridian/��ά��") >=0
		&& me->query("meridian/������") >=0
		&& me->query("meridian/������") >=0
		&& me->query("meridian/��������") >=0
		&& me->query("meridian/��������") >=0)
	{
		me->add("max_neili", 50000);
		me->add("max_qi", 50000);
		me->add("gain/2ap", 200);
		me->add("gain/2dp", 200);
		tell_object(me,HIG"��ϲ�㣡�ɹ���ͨ8��������һʱ��ֻ��ȫ����������ȫ��������Ϣ��"NOR"\n");
		message_vision(HIY"$N��Хһ����Х����Խ���������಻��������"NOR"\n",me);
	}
		
                destruct(this_object());
                return 1;
}