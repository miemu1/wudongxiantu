// zongjue.c

#include <ansi.h>
string query_name() { return BYEL+HIR"�޾�"ZJBR"����"NOR; }
inherit F_CLEAN_UP;

int check_fight(object me);
void remove_effect(object me, int skill);

int exert(object me, object target)
{
        int skill;
        if( target != me ) return
            notify_fail("��ֻ�ܶ��Լ���["+HIB+"�޾�����"+NOR+"]\n"NOR,);

	if ((int)me->query_skill("wushang-jianjing", 1) < 300)
		return notify_fail("������Ͻ���̫���ˡ�\n");

        if( (int)me->query("neili") < 5000 )
        	return notify_fail("�������������\n");
		
	        if( (int)me->query("qi") < 1000 )
        	return notify_fail("�����Ѫ������\n");

        if( (int)me->query_temp("jiuyin/powerup") )
        	return notify_fail("���Ѿ����˹����ˡ�\n");

	me->set_temp("jiuyin/powerup", 1);
        skill = me->query_skill("sword");

        me->add("neili", -5000);
        me->add("qi", -1000);
        me->receive_damage("qi",0);

        message_combatd(HIC"$N�������޾�����������Զ�Ȼ������\n" NOR, me);
        me->add_temp("apply/damage", skill*7/2);
        tell_object(me, HIG"����˺������ˡ�\n"NOR);
        me->add_temp("apply/2ap", skill*7/2);
        tell_object(me, HIG"��ı��������ˡ�\n"NOR);
        me->add_temp("apply/2dp", skill*7/2);
        tell_object(me, HIG"��Ŀ��������ˡ�\n"NOR);
        me->add_temp("apply/break", skill*7/2);
        tell_object(me, HIG"����Ƽ������ˡ�\n"NOR);
	    check_fight(me);
        me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill:),skill);
        if( me->is_fighting() ) me->start_busy(2);
        return 1;
}

int check_fight(object me)
{
	if (!me || !(int)me->query_temp("jiuyin/powerup")) return 0;
        if (!me->is_ghost() && living(me)
            && me->is_fighting() && me->query("neili") > 500
            && me->query_skill_mapped("sword") == "wushang-jianjing")
        {
                if(me->query("qi") < (int)me->query("max_qi")){
                        message_vision(HIY"$N��ɫһ���ֻظ��������������ڵ�����Ϣ��\n"NOR,me);
                        me->add("neili", -5000);
                        me->add("eff_qi",me->query_skill("sword")/2);
			if (me->query("eff_qi") > me->query("max_qi")) me->set("eff_qi", me->query("max_qi"));
                        me->add("qi",me->query_skill("sword"));
			if (me->query("qi") > me->query("eff_qi")) me->set("qi", me->query("eff_qi"));
                        }
        }
        call_out("check_fight", 2, me);
        return 1;
}

void remove_effect(object me, int skill)
{
        me->delete_temp("jiuyin/powerup");
        me->add_temp("apply/damage", -skill*7/2);
        me->add_temp("apply/2ap", -skill*7/2);
        me->add_temp("apply/2dp", -skill*7/2);
        me->add_temp("apply/break", -skill*7/2);
        tell_object(me, "���["+HIB+"�޾�����"+NOR+"]������ϣ��������ջص��\n");
}

