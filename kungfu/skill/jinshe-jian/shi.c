#include <ansi.h>
#include <combat.h>

#define SHEN "��" HIY "��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg, wn;
        object weapon;
        int ap, dp;
        me = this_player();

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHEN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query_skill("jinshe-jian", 1) < 200)
                return notify_fail("����߽���������죬����ʩչ" SHEN "��\n");

        if (me->query_skill_mapped("sword") != "jinshe-jian")
                return notify_fail("��û�м�����ɽ���񽣣�����ʩչ" SHEN "��\n");

        if ((int)me->query_skill("force", 1) < 240)
                return notify_fail("����ڹ���򲻹�������ʩչ" SHEN "��\n");

        if ((int)me->query_skill("dodge", 1) < 240)
                return notify_fail("����Ṧ��򲻹�������ʩչ" SHEN "��\n");  

        if( me->query("max_neili")<4500 )
                return notify_fail("���������Ϊ���㣬����ʩչ" SHEN "��\n");

        if( me->query("neili")<400 )
                return notify_fail("�����ڵ���������������ʩչ" SHEN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        msg = HIY "һ����⻮����$N" HIY "��ʧ����Ӱ���٣���Ȼ��ֻ��һ��"
              "���ߴ�����£�" + weapon->name() + HIY "�ѽ�$n" HIY "���֡�\n" NOR;

        message_sort(msg, me, target);
        
        ap = me->query_skill( "sword");
        dp = target->query_skill( "dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap;
                if( me->query_family() == "�嶾��" )
                        damage *= 3;

                // ʮ��֮һ�ļ��ʿɱ��м�
                if (random(10) <= 1 && ap / 2 < dp)
                {
                        damage = damage / 3;

                        msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                                  HIG "$n" HIG "��$N" HIG "һ���������"
                                                  "����æ������������мܡ���֪$P��"
                                                  "�������Ƿ���$pһ���ƺߣ����˼�������"
                                                  "��һ����Ѫ��\n" NOR);
                        me->addn("neili", -200);
                        me->start_busy(3 + random(2));
                } else 
                {
                        msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 85,
                                                  HIR "$n" HIR "��$N" HIR "��⻮������"
                                                  "�ײ��ɴ󾪣���ʱ���á����͡�һ������"
                                                  "��͸�������\n" NOR);
                        me->addn("neili", -300);
                        me->start_busy(2 + random(3));
                }
        } else
        {
                msg = CYN "\nȻ��$n" CYN "�Կ�Կ죬����һ��"
                      "��Ȼ���$N" CYN "��һ�С�\n" NOR;
                me->addn("neili", -150);
                me->start_busy(2);
        }
        message_sort(msg, me, target);
        return 1;
}
