// jinchuang.c ����ԭ����

inherit ITEM;

#include <ansi.h>

void create()
{
        set_name(HIY "����ԭ����" NOR, ({"blcs s"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���������澭�����������������������������ܳ�\n");
                set("tianji1", 999);
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

        log_file("static/using", sprintf("%s(%s) eat ����ԭ���� at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        effect = 0;
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
					   
					   
if( me->query("meridian/��������") <24 )
            return notify_fail("��ľ��������������޷����ܰ���ԭ������ҩ��!\n");


if( me->query("meridian/��������") <24  )
            return notify_fail("��ľ��������������޷����ܰ���ԭ������ҩ��!\n");
		
		
if( me->query("meridian/��ά��") <18  )
            return notify_fail("��ľ��������������޷����ܰ���ԭ������ҩ��!\n");


if( me->query("meridian/��ά��") <24  )
            return notify_fail("��ľ��������������޷����ܰ���ԭ������ҩ��!\n");
		
		
if( me->query("meridian/������") <18  )
            return notify_fail("��ľ��������������޷����ܰ���ԭ������ҩ��!\n");

if( me->query("meridian/������") <23 )
            return notify_fail("��ľ��������������޷����ܰ���ԭ������ҩ��!\n");


if( me->query("meridian/����") <19  )
            return notify_fail("��ľ��������������޷����ܰ���ԭ������ҩ��!\n");


if( me->query("meridian/����") <24  )
            return notify_fail("��ľ��������������޷����ܰ���ԭ������ҩ��!\n");




 CHANNEL_D->do_channel(this_object(), "rumor", "��ϲ" + me->name() + "������"HIR"ȫ���С���쾭��"HIM",�����Ѿ���ɢȥ��\n");

                effect++;
                write(HIM "������Լ���ͷ�Ը������ˡ�"NOR"\n");
                me->set("meridian/��������", -24);
				me->set("meridian/��������", -24);
				me->set("meridian/��ά��", -18);
				me->set("meridian/��ά��", -24);
				me->set("meridian/������", -23);
				me->set("meridian/������", -18);
				me->set("meridian/����", -24);
				me->set("meridian/����", -19);
               
				me->add("gain/break", 0);
				me->add("gain/armor", 0);
				me->add("gain/2dp", 0);
				me->add("gain/2ap", 0);
				me->add("gain/attack", 0);
				me->add("gain/defense", 0);
				me->add("gain/damage", 0);
				me->add("gain/max_qi", 0);
                write("\n "+HIR+"��ϲ�㣺"+NOR+HIG+"���ð���ԭ�������澭������Ȼ���ܳɹ������� "+NOR);
        
		
		if(me->query("meridian/����") =0
		&& me->query("meridian/����") =0
		&& me->query("meridian/��ά��") =0
		&& me->query("meridian/��ά��") =0
		&& me->query("meridian/������") =0
		&& me->query("meridian/������") =0
		&& me->query("meridian/��������") =0
		&& me->query("meridian/��������") =0)
	{
		me->add("max_neili", -0);
		tell_object(me,HIG"��ϲ�㣡�ɹ�����8��������һʱ��ֻ��ȫ������ɢ����"NOR"\n");
		message_vision(HIY"$N��Хһ����Х����ſſ�ģ���һֻ���򣡣���"NOR"\n",me);
	}
		
                destruct(this_object());
                return 1;
}