// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

string query_name() { return "����"ZJBR"̫��"; }

#define JING "��" HIW "����̫����" NOR "��"

inherit F_SSERVER;

string final1(object me, object target, int damage, int lvl);
string final2(object me, object target, int damage);
string final3(object me, object target, int damage, int lvl, string msg);

int perform(object me, object target)
{
        int damage;
        string msg, sub_msg;
        int ap, dp;
        int flag = 0;
        int lvl;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JING "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("force", 1) < 380)
                return notify_fail("���ڹ���Ϊ����������ʩչ" JING "��\n");

        if ((int)me->query("max_neili") < 5000)
                return notify_fail("��������Ϊ����������ʩչ" JING "��\n");

        lvl = (int)me->query_skill("taixuan-gong", 1);
        if (lvl < 380)
            return notify_fail("��̫������򲻹�������ʩչ" JING "��\n");

        if (me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("������û�м���̫����Ϊ�ڹ�������ʩչ" JING "��\n");

     //   if (me->query_skill_prepared("unarmed") != "taixuan-gong")
       //         return notify_fail("������û��׼��ʹ��̫����������ʩչ" JING "��\n");

        if ((int)me->query("neili") < 850)
                return notify_fail("��������������������ʩչ" JING "��\n");

        if (me->query_skill("martial-cognize", 1) < 100)
                return notify_fail("����ѧ�������㣬����ʩչ" JING "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        message_combatd(HIM "\n$N" HIM "�鲻�Խ���������Х����ʱ֮�䣬ǧ������ʽ���������ӿ"
                     "����ͷ��$N" HIM "���ֻ��裬���ǲ������򣬵������ۺ�����ʽ������������"
                     "���Ȳ��ش�����Ϣ���಻�����������ʯ���ϵ�ǧ������ʽ����Ȼ��Ȼ�Ĵ���"
                     "�д������㣬����Ϯ��$n" HIM "��\n" NOR, me, target);

        damage = me->query_skill("unarmed"); 
        ap = me->query_skill("unarmed") + me->query_str() * 20;

        // ��һ�У��ж϶Է�����
        dp = target->query_skill("parry") + target->query_str() * 20;

        message_combatd(HIW "\n$N" HIW "ͻȻ��ֻ���������¡�ԨҺѨ����һ����һ���������š�����"
                     "�������������š����¡��������š���Ѩ��ȥ��һ�С�ʮ��ɱһ�ˡ���" + sub_msg + 
                     "��������ʹ����������ʽԴԴ��������$n" HIW "���֡�\n" NOR, me, target);

        if (ap / 2 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30 + random(10),
                                         (: final1, me, target, damage, lvl :));
        } else
        {
                msg = HIC "$n" HIC "����˫�ۣ������Զԣ�����$N" HIC "֮��жȥ��\n" NOR;
        }
        message_combatd(msg, me, target);

        ap = me->query_skill("unarmed") + target->query("int") * 20;
        // �ڶ��У��ж϶Է�����
        dp = target->query_skill("parry") + target->query("int") * 20;

        message_combatd(HIW "\n$N" HIW "�����������ѣ���Ϣ�������������š��Կ��Ϻ�ӧ�����׾�����"
                     "��ͼ��ת����ͬʱ�����㵸�����Ǵ�ϲ�����ƴ���ա�\n" NOR, me);

        if (ap / 2 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30 + random(10),
                                     HIY "$n" HIY "��Цһ��������$N" HIY "���з�ǳ֮������"
                                     "�������мܣ���Ȼ�䣬�����͡���һ����һ�������Ѵ�͸$n" HIY "�����ţ���Ѫ����ӿ����\n" NOR, me , target);
        } else
        {
                msg = HIC "$n" HIC "����һЦ������$N" HIC "�����е�����������ʩ�о������л�ȥ��\n" NOR;
        }
        message_combatd(msg, me, target);

        ap = me->query_skill("unarmed") + target->query_con() * 20;
        // �����У��ж϶Է�����
        dp = target->query_skill("force") + target->query_con() * 20;

        message_combatd(HIW "\n���Կ��Ϻ�ӧ���ȱϣ�����ȥ���ǡ��⹳˪ѩ������$N" HIW "��"
                    "��˼����ʯ���ϵ�ͼ��һ�������Ժ�����Ȼӿ�����ԡ������հ���ֱ����˭������¡���"
                    "һ���ǳɵ�ʹ�˳�����\n" NOR, me);

        if (ap / 2 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 25 + random(10),
                                           (: final2, me, target, damage :));
        } else
        {
                msg = HIC "$n" HIC "Ĭ���ڹ����ھ�����ȫ�������ֵ�ס$N" HIC "���С�\n" NOR;
        }
        message_combatd(msg, me, target);

        // �����У��ж϶Է���

        ap = me->query_skill("unarmed") + target->query_dex() * 20;        
        dp = target->query_skill("dodge") + target->query_dex() * 20;

        message_combatd(HIW "\n���á�˭������¡����׹������꣬$N" HIW "ֻ����Ϣ��ת"
                     "������������Ӣ����ʹ��ȥ��\n" NOR, me);

        if (ap / 2 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30 + random(10),
                                          (: final3, me, target, damage, lvl, sub_msg :));
        } else
        {
                msg = HIC "$n" HIC "�������������ͣ����μ��ˣ�˲��Ʈ����"
                      "�ɣ����Ŷ��$N" HIC "���С�\n" NOR;
        }
        message_combatd(msg, me, target);

        me->start_busy(3 + random(3));
        me->add("neili", -800);
        return 1;
}

string final1(object me, object target, int damage, int lvl)
{
        target->add("neili", -(lvl + random(lvl)));

        return  HIY "$n" HIY "ȴ��$N" HIY "�������ƻֺ룬�������������ֵ�������������"
                "���������ˣ�$n" HIY "�ƺ�һ�������˼������پ���Ϣ��ɢ��\n" NOR;
}

string final2(object me, object target, int damage)
{
        target->receive_damage("jing", damage / 2, me);
        target->receive_wound("jing", damage / 4, me);
        return  HIY "$n" HIY "����һ��������$N" HIY "�⼸�������ޱȣ���ʽ�仯Ī�⣬"
                "������ȴ��Ȼ����������ԥ�䣬$n" HIY "ȴ�����У��ٸо������ã���"
                "��������\n" NOR;
}

string final3(object me, object target, int damage, int lvl, string msg)
{
        target->start_busy(4 + random(lvl / 50));
  
        return  HIY "$N" HIY + msg + "�������ޱȣ�ʱ������������ʱ��"
                "�������裬���Ǽ�$n" HIY "�ѱ������ˣ�$N" HIY "��Ȼ����ʽһ"
                "ת����Ȼ�ӿ죬��$n" HIY "����Χס������һ˿��϶��\n" NOR;

}

