#include <ansi.h>
#include <combat.h>

string name() { return HIR "����ȭ" NOR; }
string query_name() { return "����ȭ"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int i, count;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail(name() + "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("martial-cognize", 1) < 300)
                return notify_fail("�����ѧ�����������ң�����ʩչ" + name() + "��\n");

        if (me->query_skill_mapped("unarmed") != "tiandaoquan")
                return notify_fail("��û�м������ȭ��������ʩչ" + name() + "��\n");

        if (me->query_skill_prepared("unarmed") != "tiandaoquan")
                return notify_fail("��û��׼�����ȭ��������ʩչ" + name() + "��\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���Ϊ����������ʩչ" + name() + "��\n");

        if( me->query("max_neili")<100 )
                return notify_fail("���������Ϊ����������ʩչ" + name() + "��\n");

        if( me->query("neili")<100 )
                return notify_fail("�����ڵ��������㣬����ʩչ" + name() + "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "����һչ��ʩ�����ȭ������" HIR "����ȭ" NOR +
              WHT "����ʮ�˵�ȭ�漤�������ˣ���$n" WHT "������ȥ��\n" NOR;

        message_combatd(msg, me, target);
	me->add("neili", -100);

	count = me->query_skill("unarmed") / 2;
	me->add_temp("apply/attack", count);

	for (i = 0; i < 18; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, 0, 0);
	}


	me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(6));
	return 1;

}
