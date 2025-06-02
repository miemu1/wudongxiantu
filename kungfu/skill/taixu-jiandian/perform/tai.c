// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

#define TAI "��" HIC "̫�齣��" NOR "��"
string query_name() { return "̫��"ZJBR"����"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
		object weapon;
        int ap, dp;
        int count;
        int i;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

     

        if (! target || ! me->is_fighting(target))
                return notify_fail(TAI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        /* if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(TAI "ֻ�ܿ���ʩչ��\n"); */

        if (me->query("max_neili") < 6000)
                return notify_fail("�����������Ϊ�����������޷�ʹ��" TAI "��\n");

        if (me->query_skill("taixu-jiandian", 1) < 200)
                return notify_fail("���̫�齣����������죬����ʩչ" TAI "��\n");

        if (me->query_skill_mapped("unarmed") != "taixu-jiandian")
                return notify_fail("������û�м���̫�齣��Ϊȭ�ţ�����ʩչ" TAI "��\n");

        if (me->query_skill_mapped("force") != "taixu-jiandian")
                return notify_fail("������û�м���̫�齣��Ϊ�ڹ�������ʩչ" TAI "��\n");
			
		if (me->query_skill_mapped("sword") != "taixu-jiandian")
                return notify_fail("������û�м���̫�齣��Ϊ����������ʩչ" TAI "��\n");

        if (me->query_skill_prepared("unarmed") != "taixu-jiandian")
                return notify_fail("������û��׼��ʹ��̫�齣��������ʩչ" TAI "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("��������������޷�����" TAI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "�Խ�����������ʱһ�ɺƵ��ޱȵĽ��������ڱŷ���˫����Ϣ"
              "��Ϊ��������$n" HIC "��ɢ��ȥ��\n" NOR;

        ap = me->query_skill("sword")+ me->query("int")*20;
        dp = target->query_skill("parry")+me->query("con")*20;

        if (ap / 2 + random(ap) > dp)
        {
                count = ap;
                msg += HIC "$n" HIC "ֻ����Χ������ʹ�ޱȣ��ּ�����������"
                       "�Լ�Ϯ�������Ļ����ޱȣ���֪����εֵ���\n" NOR;
        } else
        {
                msg += HIY "$n" HIY "ֻ��$N" HIY "�����������Լ�Ϯ������"
                       "æ�͵�һ������ǿ�㿪��\n" NOR;
                count = 0;
        }

        message_vision(msg, me, target);
        me->add_temp("apply/attack", count);
        me->add_temp("apply/unarmed_damage", count/3);
		me->add_temp("apply/damage", count/3);

        me->add("neili", -300);

        for (i = 0; i < 12; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(5) < 2 && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->start_busy(1 + random(3));
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/unarmed_damage", -(count/3));
		me->add_temp("apply/damage", -(count/3));

        return 1;
}

