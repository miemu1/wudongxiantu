// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

#define RI "��" HIW "��������" NOR "��"
string query_name() { return "����"ZJBR"����"; }
int perform(object me)
{
        object *obs;
        string msg;
        int damage;
        int ap, dp;
        int flag;
        int i;
        int p;

        if (me->query("max_neili") < 2000)
                return notify_fail("�����������Ϊ�����������޷�ʹ��" RI "��\n");

        if (me->query_skill("qinglian-jiange", 1) < 250)
                return notify_fail("����������軹������죬����ʩչ" RI "��\n");

        if ((int)me->query("neili") < 2000)
                return notify_fail("��������������޷�����" RI "��\n");

        msg = HIY "ֻ��$N" HIY "˫Ŀ΢�գ�����ִ������Χ�ռ����飬"
              "ʱ���������ǰ�\n�塸" NOR + HIW "��������" NOR + HIY "������ʱ"
              "������䣬��ɳ���𣬿������ȣ��������ڡ�$N" HIY "\n�漴�ὣ��ǰ"
              "��һ���ӳ�����������������Ƭ�ռ䣬��������˺������!\n\n" NOR;

        message_combatd(msg, me);

        me->add("neili", -2000);
        me->start_busy(6);

        ap = me->query_skill("sword") + me->query_con();

        obs = me->query_enemy();
        for (flag = 0, i = 0; i < sizeof(obs); i++)
        {
                dp = obs[i]->query_skill("force") + obs[i]->query_con();

                if (ap * 10 / 1 + random(ap) > dp)
                {
                        switch (random(2))
                        {
                        case 0:
                                tell_object(obs[i], HIR "��ֻ����ǰ������䣬��Χ��������"
                                                    "���̣����������ʸһ��͸����롣\n" NOR);
                                break;

                        default:
                                tell_object(obs[i], HIR "��ֻ����ǰ����������Χ�տռ伸��"
                                                    "���飬�������������һ����������㡣\n"
                                                    NOR);
                                break;
                        }

                        damage = me->query_skill("force");
                        damage = damage * 10 / 1;

                        obs[i]->receive_damage("qi", damage, me);
                        obs[i]->receive_wound("qi", damage, me);

                        obs[i]->receive_damage("jing", damage * 10 / 1, me);
                        obs[i]->receive_wound("jing", damage * 10 / 1, me);

                        p = (int)obs[i]->query("qi") * 10 / (int)obs[i]->query("max_qi");

                        switch (random(5))
                        {
                        case 0:
                                msg = HIR "ֻ��" + obs[i]->name() +
                                      HIR "һ���Һ�������������������"
                                      "�ۡ���Ż��һ�����Ѫ��\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;

                        case 1:
                                msg = HIR "ֻ��" + obs[i]->name() +
                                      HIR "���ɳ���Զ�����صĵ�����"
                                      "���ϣ��������飬��Ҳû����վ��"
                                      "��\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;

                        case 2:
                                msg = HIR "ֻ��" + obs[i]->name() +
                                      HIR "����ײײ�����������������"
                                      "�ڵء�ȫ����������"
                                      "��\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;

                        case 3:
                                msg = HIR "����������" + obs[i]->name() +
                                      HIR "ȴ�Ǵ�����������Ҳ��������"
                                      "����Ѫ������Ť����ɷ�ǿֲ���\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;

                        default:
                                msg = HIR + obs[i]->name() +
                                      HIR "��æ������ˣ���ֻ����ǰ��"
                                      "â���ǣ�һ��������ȫ���Ѷ�����"
                                      "���˿ڣ���Ѫ�ɽ���\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;
                        }
                        if (! obs[i]->is_busy())
                        obs[i]->start_busy(1);
                        message("vision", msg, environment(me), ({ obs[i] }));
                        obs[i]->add("neili", -1000);
                        flag = 1;
                } else
                {
                        tell_object(obs[i], HIY "��ֻ����ǰ����������Ӱ����Χ�ռ伸��"
                                            "���飬��֮����æ�����ڹ�������"
                                            "������\n" NOR);
                }
                if (obs[i]->query("neili") < 0)
                        obs[i]->set("neili", 0);
        }

        if (! flag) 
                message_vision(HIY "ֻ����Ӱ������ȴû���κ��˱�$N"
                               HIY "���л��С�\n\n" NOR, me, 0, obs);

        return 1;
}

