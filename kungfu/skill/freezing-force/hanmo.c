// This program is a part of NT MudLIB

#include <ansi.h>
inherit F_CLEAN_UP;
string query_name() { return "��ħ"ZJBR"����"; }
int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;
        int time;

/*         if( !query("yuanshen", me) )
                return notify_fail("����δ������޷�ʹ�ú�ħ������\n"); */

        if( target != me )
                return notify_fail("��ֻ���ñ��Ϻ�����������ħ������\n");

        if( (skill = me->query_skill("freezing-force", 1)) < 250 )
                return notify_fail("��ı��Ϻ�����Ϊ�������޷�ʹ�ú�ħ������\n");

        if( me->query_skill("huagong-dafa", 1) < 150 )
                return notify_fail("��Ļ�������Ϊ�������޷�ʹ�ú�ħ������\n");

        if( me->query_skill("poison", 1) < 250 )
                return notify_fail("��Ի��������Ĳ��򻹲������޷�ʹ�ú�ħ������\n");

        if( me->query_skill("force", 1) < 150 )
                return notify_fail("��Ի����ڹ�����Ϊ���������޷�ʹ�ú�ħ������\n");

        if( (int)me->query_temp("protectshield") )
                return notify_fail("���Ѿ�������ħ�����ˡ�\n");

        if( me->query("jingli")<2000 )
                return notify_fail("�������������\n");

        if( me->query("neili")<5000 )
                return notify_fail("�������������\n");

       
        
        skill = me->query_skill("freezing-force", 1);
        me->addn("neili", -1000);
        me->receive_damage("qi", 0);


	message_combatd(HIB "$N" HIB "��ɫ���أ�����һ���������˲���Ϊ����ɫ��$N" HIB "��֮�ڳ��������ص������趯�š�\n"
                       "������Щ��������ˣ���ɫ���������ڿ��о����������������ϳ棬��$N�������в�ֹ��\n"
                       "�����¶��轵��ֻɲ�Ǽ书�򣬿����ƺ��������ˡ�\n" NOR, me);
        
        msg = HIB "��˲�䣬$N" HIB "��ͬ�����壬ʹ�����������\n" NOR;

	me->add_temp("apply/unarmed_damage", skill *3);
	me->add_temp("apply/shield_amount", skill * 3);
//	me->add_temp("apply/dodge", skill / 3);
	me->set_temp("protectshield", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect",
			   me, skill :), skill);

	if (me->is_fighting()) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("protectshield"))
	{
		me->add_temp("apply/unarmed_damage", -(amount*3));
		me->add_temp("apply/shield_amount", -(amount*3));
	//	me->add_temp("apply/dodge", -amount);
		me->delete_temp("protectshield");
		tell_object(me, "��ĺ�ħ����������ϣ��������ջص��\n");
	}
}