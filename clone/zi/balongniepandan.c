// jinchuang.c ��ҩ

inherit ITEM;

#include <ansi.h>

void create()
{
        set_name(HIY "����������" NOR, ({"tmd","dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���ǹ�ͨ�澭����������������\n");
                set("gongxian", 999999999);
                set("no_put", 1);
		    set("no_get", 1);
		    set("no_give", 1);
		    set("no_drop", 1);
		    set("no_sell", 1);
		    set("no_steal", 1);
            set("no_sell", 1);
		    set("value", 200);
            set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{    
   int effect;
	 mapping my;

        log_file("static/using", sprintf("%s(%s) eat ��ת�� at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        effect = 0;
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
					   
					   
if( me->query("meridian/��������")>0 )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܶ��쵤��ҩ��!\n");


if( me->query("meridian/��������")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܶ��쵤��ҩ��!\n");
		
		
if( me->query("meridian/��ά��")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܶ��쵤��ҩ��!\n");


if( me->query("meridian/��ά��")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܶ��쵤��ҩ��!\n");
		
		
if( me->query("meridian/������")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܶ��쵤��ҩ��!\n");

if( me->query("meridian/������") >0 )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܶ��쵤��ҩ��!\n");


if( me->query("meridian/����")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܶ��쵤��ҩ��!\n");


if( me->query("meridian/����")>0  )
            return notify_fail("���Ѿ���ʼ��ͨ�������޷����ܶ��쵤��ҩ��!\n");




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
               
				me->add("gain/break", 465);
				me->add("gain/armor", 465);
				me->add("gain/2dp", 32);
				me->add("gain/2ap", 47);
				me->add("gain/attack", 385);
				me->add("gain/defense", 285);
				me->add("gain/damage", 465);
				me->add("gain/max_qi", 10000);
                write("\n "+HIR+"��ϲ�㣺"+NOR+HIG+"���ö��쵤���澭������������֮�������� "+NOR);
        
		
		if(me->query("meridian/����") >=24
		&& me->query("meridian/����") >=19
		&& me->query("meridian/��ά��") >=24
		&& me->query("meridian/��ά��") >=18
		&& me->query("meridian/������") >=23
		&& me->query("meridian/������") >=18
		&& me->query("meridian/��������") >=24
		&& me->query("meridian/��������") >=24)
	{
		me->add("max_neili", 5000);
		me->add("gain/2ap", 8);
		tell_object(me,HIG"��ϲ�㣡�ɹ���ͨ8��������һʱ��ֻ��ȫ����������ȫ��������Ϣ��"NOR"\n");
		message_vision(HIY"$N��Хһ����Х����Խ���������಻��������"NOR"\n",me);
	}
		
                destruct(this_object());
                return 1;
}