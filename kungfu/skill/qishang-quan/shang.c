// qimai.c ���־�

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
 
string query_name() { return "���־�"; }
string *pfm_type() { return ({ "cuff", }); }

int perform(object me, object target)
{
	string msg;
	int ap, dp;
	int count;
	int damage,i;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("�����־���ֻ����ս���жԶ���ʹ�á�\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����־���ֻ�ܿ���ʹ�á�\n");
		
	if (me->query("max_neili") < 1000)
		return notify_fail("���������Ϊ���������޷�ʩչ�����־�����\n");

	if ((int)me->query("neili") < 300)
		return notify_fail("�������������\n");

	ap = me->query_skill("cuff") + me->query("con") * 6;
	dp = target->query_skill("force") + target->query("con") * 6;

	if ((int)me->query("qi") < ap*2)
		return notify_fail("���־�δ�˵����˼�������������ڲ�����ʩչ���־��ˣ�\n");

	if ((int)me->query_skill("qishang-quan", 1) < 180)
		return notify_fail("�������ȭ��򲻹����޷�ʹ�á����־�����\n");

	if ((int)me->query_skill("force",1) < 180)
		return notify_fail("����ڹ���Ϊ�������޷�ʹ�á����־�����\n");

	if (me->query_skill_prepared("cuff") != "qishang-quan")
		return notify_fail("������û��׼��ʹ������ȭ���޷�ʹ�á����־�����\n");

	if (! living(target))
	    return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "ŭ��һ����ʩ�����С�" HIW "���־�" HIY "����˫ȭѸ���ޱȵ�Ϯ��$n" HIY "��\n" NOR;

	me->start_busy(2);
	if (ap / 2 + random(ap) > dp)
	{
		me->add("qi", -ap);   
		damage = ap + random(ap / 2);
		me->add("neili", -200);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 60,
                   HIR "ֻ��$P" HIR "��һȭ��$p" HIR
                   "����˳�ȥ�����ص�ˤ�ڵ��ϣ���Ѫ��ֹ��\n" NOR);
	} else
	{
		msg += HIG "����$p" HIG "������$P" HIG "����ͼ��û���ܵ��Ի�������һ�ߡ�"NOR"\n";
	}
	message_combatd(msg, me, target);

	return 1;
}
