// jinchuang.c ��������������Ʒ

inherit ITEM;

#include <ansi.h>

void create()
{
        set_name(HIY "��������������Ʒ" NOR, ({"bmsd danLR"}));
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

        log_file("static/using", sprintf("%s(%s) eat ��������������Ʒ at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        effect = 0;
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
					   
					   
if( me->query("meridian/��������")>0 )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܰ�����������ҩ��!\n");


if( me->query("meridian/��������")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܰ�����������ҩ��!\n");
		
		
if( me->query("meridian/��ά��")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܰ�����������ҩ��!\n");


if( me->query("meridian/��ά��")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܰ�����������ҩ��!\n");
		
		
if( me->query("meridian/������")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܰ�����������ҩ��!\n");

if( me->query("meridian/������") >0 )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܰ�����������ҩ��!\n");


if( me->query("meridian/����")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܰ�����������ҩ��!\n");


if( me->query("meridian/����")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܰ�����������ҩ��!\n");




 CHANNEL_D->do_channel(this_object(), "rumor", "��ϲ" + me->name() + "��ͨ��"HIR"ȫ���С���쾭��"HIM",�����������ˡ���\n");

                effect++;
                write(HIM "������Լ���ͷ�Ը������ˡ�"NOR"\n");
                me->set("meridian/��������", 24);
				me->set("meridian/��������", 24);
				me->set("meridian/��ά��", 18);
				me->set("meridian/��ά��", 24);
				me->set("meridian/������", 23);
				me->set("meridian/������", 18);
				me->set("meridian/����", 24);
				me->set("meridian/����", 19);
               
				me->add("gain/break", 3000);
				me->add("gain/armor", 3000);
				me->add("gain/2dp", 500);
				me->add("gain/2ap", 500);
				me->add("gain/attack", 750);
				me->add("gain/defense", 750);
				me->add("gain/damage", 2500);
				me->add("gain/max_qi", 35000);
                write("\n "+HIR+"��ϲ�㣺"+NOR+HIG+"���ð������������澭������������֮�������� "+NOR);
        
		
		if(me->query("meridian/����") >=24
		&& me->query("meridian/����") >=19
		&& me->query("meridian/��ά��") >=24
		&& me->query("meridian/��ά��") >=18
		&& me->query("meridian/������") >=23
		&& me->query("meridian/������") >=18
		&& me->query("meridian/��������") >=24
		&& me->query("meridian/��������") >=24)
	{
		me->add("max_neili", 35000);
		me->add("max_qi", 35000);
		me->add("gain/2ap", 100);
		me->add("gain/2dp", 100);
		tell_object(me,HIG"��ϲ�㣡�ɹ���ͨ8��������һʱ��ֻ��ȫ����������ȫ��������Ϣ��"NOR"\n");
		message_vision(HIY"$N��Хһ����Х����Խ���������಻��������"NOR"\n",me);
	}
		
                destruct(this_object());
                return 1;
}