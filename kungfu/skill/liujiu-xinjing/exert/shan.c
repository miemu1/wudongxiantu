// shengang.c ���������������

#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int amount);

 string query_name() { return "��������"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	object weapon;  
	string msg;
	int skill;

		if ((int)me->query_temp("shan"))
                return notify_fail("���Ѿ�������������ˡ�\n");
		if ((int)me->query_skill("liujiu-xinjing", 1) < 150)
                return notify_fail("��������ľ��ȼ�����������ʩչ����������\n");

        if ((int)me->query_dex() < 32)
                return notify_fail("���������������ʩչ����������\n");

        if ((int)me->query_skill("force", 1) < 150)
                return notify_fail("����ڹ���򲻹�������ʩչ����������\n");

        if ((int)me->query_skill("dodge", 1) < 150)
                return notify_fail("����Ṧ��Ϊ����������ʩչ����������\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("���������Ϊ����������ʩչ����������\n");

        if ((int)me->query("neili") < 250)
                return notify_fail("���ʱ���������㣬����ʩչ����������\n");

        msg = HIY "$N" HIY "һ����Х������һչ���貽����������ˮ�����ķ�"
              "�������������\n\n" NOR;

		skill = (int)me->query_skill("dodge", 1)*2;

		me->add_temp("dex", skill);
        me->set_temp("shan", 1);
	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);
	me->add("neili", -150);

	message_combatd(msg, me);
	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("shan"))
	{
		 me->add_temp("dex", -amount);
                me->delete_temp("shan");
                tell_object(me, "��Ĵ�������������ϣ��������ջص��\n");
	}
}
