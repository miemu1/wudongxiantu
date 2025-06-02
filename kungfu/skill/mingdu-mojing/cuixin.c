#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
 
string query_name() { return "����"ZJBR"�鶾"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp;
	int damage, lvl;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("�����鶾ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query_temp("weapon"))
		return notify_fail("������ǿ��ֲ���ʹ�þ����鶾��\n");
 
	lvl = me->query_skill("mingdu-mojing", 1);

	if (lvl < 300)
		return notify_fail("����鶾ħ�����������죡\n");

	if (me->query_skill("force") < 600)
		return notify_fail("����ڹ����̫�ͣ��޷�ʹ�������鶾��\n");

	if (me->query("neili") < 1000)
		return notify_fail("��������������޷�ʹ�������鶾��\n");

	if (me->query_skill_mapped("strike") != "mingdu-mojing")
		return notify_fail("��û�м����鶾ħ��, ����ʹ�á������鶾����\n");
 
       if (! living(target))
	      return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = BLU "$N" BLU "�������ƣ�����һ����Х��ɲ�Ǽ�˫�ƽ���һ��"
		  "�������鶾�����������ھ�ֱ��$n" BLU "��"NOR"\n";

	ap = me->query_skill("strike") + lvl;
	dp = target->query_skill("parry");

	if (dp < 1) dp = 1;

	if ( ap / 2 + random(ap) > dp + random(dp) )
	{
	me->add("neili", -300);
	damage = lvl + random(lvl);
	target->affect_by("ming-du",
		([ "level" : me->query("jiali") + random(me->query("jiali")),
		"id"    : me->query("id"),
		"duration" : lvl / 25 + random(lvl / 20) ]));
	msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 70, 
	       HIR "ֻ��$n" HIR "�ҽ�һ����ֻ��������"
	       "����Ŀ��������һ�����Ѫ������̱����"NOR"\n");

	me->start_busy(2);
	}
    else
	{
	msg += HIY "$p��$P������ӿ����æ����һԾ���𣬶㿪����������һ����"NOR"\n";
	me->add("neili", -300);
	me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}

