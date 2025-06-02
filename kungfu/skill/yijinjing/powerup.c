// powerup.c �׽����

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "�׽�"ZJBR"����"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("��ֻ�������Լ���ս������\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("�������������\n");

	if ((int)me->query_temp("powerup"))
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("force");

	message_combatd(HIR "$N" HIR "����һЦ�����ִȺ�֮�⣬������"
			"���Զ����ƺ���һ������������"NOR"\n", me);

        if (me->query("family/family_name") == "������")
        {    
				me->add_temp("apply/dodge", skill / 4);
				me->add_temp("apply/parry", skill / 4);
                me->add_temp("apply/attack", skill / 3);      
        }
        else
        {
				me->add_temp("apply/dodge", skill / 5);
				me->add_temp("apply/parry", skill / 5);
                me->add_temp("apply/attack", skill / 3);
        }

	me->set_temp("powerup", 1);
	me->add("neili", -100);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);

	if (me->is_fighting()) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if (me->query_temp("powerup"))
	{
        if (me->query("family/family_name") == "������")
                {
						me->add_temp("apply/dodge", -amount / 4);
						me->add_temp("apply/parry", -amount / 4);
                        me->add_temp("apply/attack", - (amount / 3));
                }
                else
                {
					    me->add_temp("apply/dodge", -amount / 5);
						me->add_temp("apply/parry", -amount / 5);
                        me->add_temp("apply/attack", - (amount / 3)); 
                }
		me->delete_temp("powerup");
		tell_object(me, "����׽��������ϣ��������ջص��\n");
	}
}
