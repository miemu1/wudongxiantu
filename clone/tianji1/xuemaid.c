// jinchuang.c ����������

inherit ITEM;

#include <ansi.h>

void create()
{
        set_name(HIY "����Ѫ����" NOR, ({"xuemaid"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���ú�ֱ�Ӵ�ͨ�����ͳ�����\n");
                set("tianji1", 35);
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

        log_file("static/using", sprintf("%s(%s) eat ����Ѫ���� at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        effect = 0;
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
					   
					   

if( me->query("meridian/����")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܶ��쵤��ҩ��!\n");


if( me->query("meridian/����")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܶ��쵤��ҩ��!\n");




 CHANNEL_D->do_channel(this_object(), "rumor", "��ϲ" + me->name() + "��ͨ��"HIR"�����ͳ���"HIM",�����������ˡ���\n");

                effect++;
                write(HIM "������Լ���ͷ�Ը������ˡ�"NOR"\n");
				me->set("meridian/����", 24);
				me->set("meridian/����", 19);
               
				me->add("gain/damage", 500);
				me->add("gain/max_qi", 12500);
                write("\n "+HIR+"��ϲ�㣺"+NOR+HIG+"���ö��쵤���澭������������֮�������� "+NOR);
        
		
		if(me->query("meridian/����") >=24
		&& me->query("meridian/����") >=19)
	{
		me->add("max_neili", 1000);
		tell_object(me,HIG"��ϲ�㣡�ɹ���ͨ2��������һʱ��ֻ��ȫ����������ȫ��������Ϣ��"NOR"\n");
		message_vision(HIY"$N��Хһ����Х����Խ���������಻��������"NOR"\n",me);
	}
		
                destruct(this_object());
                return 1;
}