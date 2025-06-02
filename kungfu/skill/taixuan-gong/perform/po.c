// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "�˷�"ZJBR"����"; }

#define PO "��" HIC "�˷�����" NOR "��"

int perform(object me,object target)
{
        object *obs;
        string msg;
        int damage;
        int ap, dp;
        int flag;
        int i;
        int p;

        me->clean_up_enemy();

        if (! me->is_fighting())
                return notify_fail(PO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(PO "ֻ�ܿ���ʩչ��\n");

        if (me->query("max_neili") < 5000)
                return notify_fail("�����������Ϊ�����������޷�ʹ��" PO "��\n");

        if (me->query_skill("taixuan-gong", 1) < 280)
                return notify_fail("���̫������������죬����ʩչ" PO "��\n");

        if (me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("������û�м���̫����Ϊ�ڹ�������ʩչ" PO "��\n");

        if (me->query_skill_prepared("unarmed") != "taixuan-gong")
                return notify_fail("������û��׼��ʹ��̫����������ʩչ" PO "��\n");

		if ((int)me->query("jingli") < 1000)
			return notify_fail("�����ھ����������޷�ʹ�á��˷����ˡ���\n");

        obs = me->query_enemy();

        if ((int)me->query("neili") < sizeof(obs) * 200)
                return notify_fail("��������������޷�����" PO "��\n");

        msg = HIW "ֻ��$N" HIW"������ʣ�����˼����ǧ����Ȼ�䣬$N" HIW "һ����̾��"
              "�漴˫�Ʋ�ͣ���ĳ������͵�ʯ���ϵ�̫��ͼ����һ����ӿ����ͷ��"
              "���Ǽ����ܿ�����𣬳������������硣������̫�������С�" 
              NOR + HIC "�˷�����" NOR + HIW "����ת�ۼ䣬$N" HIW "˫��Խ��"
              "�������Ѳ�֪�����ؽ��������֣��������˵�ս�ľ���\n" NOR;

		message_combatd(msg, me);

        me->start_busy(5);

        ap = me->query_skill("force") + me->query("con") * 10;
  
        me->add("neili", -(sizeof(obs) * 200));
		me->add("jingli", -1000);

        for (flag = 0, i = 0; i < sizeof(obs); i++)
        {
                dp = obs[i]->query_skill("force") + obs[i]->query("con") * 10;

                if (ap / 2 + random(ap) > dp)
                {
                        switch (random(2))
                        {
                        case 0:
                                tell_object(obs[i], HIR "��ֻ����ǰ��ɳ�����Χ����������"
                                                    "һ���ھ��Ѿ����������\n" NOR);
                                break;

                        default:
                                tell_object(obs[i], HIR "��ֻ����ǰ��ɳ�����Χ��ɳ���裬"
                                                    "��Ȼ��ֻ��ǧ����ھ��Ѵ��������\n" NOR);
                                break;
                        }

						damage = me->query("max_qi");
						if(damage > 10000) damage = 10000+(damage-10000)/2;
						damage = damage * (9 + random(3)) / 100;

                        obs[i]->receive_damage("qi", damage, me);
                        obs[i]->receive_wound("qi", damage / 2 , me);

						damage = me->query("max_jing");
						if(damage > 3000) damage = 3000+(damage-3000)/2;
						damage = damage * (9 + random(3)) / 100;
                        obs[i]->receive_damage("jing", damage, me);
                        obs[i]->receive_wound("jing", damage / 3, me);

                        switch (random(5))
                        {
                        case 0:
                                msg = HIR "ֻ��" + obs[i]->name() +
                                      HIR "һ���Һ�������������������"
                                      "�ۡ���Ż��һ�����Ѫ��\n" NOR;
                                break;

                        case 1:
                                msg = HIR "ֻ��" + obs[i]->name() +
                                      HIR "���ɳ���Զ�����صĵ�����"
                                      "���ϣ��������ã���Ҳ�޷�վ����"
                                      "��\n" NOR;
                                break;

                        case 2:
                                msg = HIR "ֻ��" + obs[i]->name() +
                                      HIR "����бб���˼���������"
                                      "�ڵأ�ʹ�಻����"
                                      "��\n" NOR;
                                break;

                        case 3:
                                msg = HIR "�������" + obs[i]->name() +
                                      HIR "ֻ������ɳ���裬ȴ��Ҳ������"
                                      "��Ȼ�䣬ȴ̱���ڵء�\n" NOR;
                                break;

                        default:
                                msg = HIR + obs[i]->name() +
                                      HIR "��æ�������ȴ��Ȼ׹�أ��˺۱��壬��"
                                      "Ѫ��ֹ��\n" NOR;
                                break;
                        }
                        obs[i]->start_busy(2);
                        message("vision", msg, environment(me), ({ obs[i] }));
                        obs[i]->add("neili", -500);
                        flag = 1;
                } else
                {
                    tell_object(obs[i], HIY "��ֻ����ɳ���𣬶�ʱ�����ֿ������ŵ�ס���С�\n" NOR);
                }
                if (obs[i]->query("neili") < 0)
                    obs[i]->set("neili", 0);
        }

        if (! flag) 
            message_vision(HIY "��ɳ��ͣ��ȴû���κ������ˡ�\n\n" NOR, me, 0, obs);

        return 1;
}

