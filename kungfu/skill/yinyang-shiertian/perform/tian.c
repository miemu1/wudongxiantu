#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

#define TIAN "��" HIY "ʮ������" NOR "��"



////////////////////////////////////////
//1  �ж�����
//2  �ж���������
//3  �жϷ�ѧ����ѧ����
//4  �жϽ�������
//5  �ж��������
//6  �жϺ��������unarmed
//7  �ж���������
//8  �жϺ������Լ�literate
//9  �ж��������
//10 �жϺ�����Ǽ�force
//11 �ж�������
//12 �жϺ�������dodge
///////////////////////////////////////

string final(object me, object target, int damage);

int perform(object me, object target)
{
        int damage, damage1;
        int p;
        string msg, cl, wp;
        int ap, dp, dp1;
        int lvl;
        object weapon, cloth;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(TIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("force", 1) < 1000)
                return notify_fail("���ڹ���Ϊ����������ʩչ" TIAN "��\n");

        if ((int)me->query("max_neili") < 50000)
                return notify_fail("��������Ϊ����������ʩչ" TIAN "��\n");

        if ((int)me->query("max_jingli") < 10000)
                return notify_fail("�㾫����Ϊ����������ʩչ" TIAN "��\n");

        lvl = (int)me->query_skill("yinyang-shiertian", 1);
        if (lvl < 1000)
                return notify_fail("��̫ʼ�۾���򲻹�������ʩչ" TIAN "��\n");

        if ((int)me->query("neili") < 12000)
                return notify_fail("��������������������ʩչ" TIAN "��\n");

        if (me->query_skill("martial-cognize", 1) < 500)
                return notify_fail("����ѧ�������㣬����ʩչ" TIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        message_sort(HIM "\n$N" HIM "����Ĭ�����޳����������ʮ�����쾳�磬"
                     "���ռ��ƺ�ҲŤ����������$n" HIM "��ʧɫ���·���������磡\n" NOR, me, target);


        ap = me->query_skill("force");

        damage = target->query_skill("force");

        if (me->query_temp("weapon"))
        {
				damage += me->query_temp("apply/damage");
        } else
        {
                damage += me->query_temp("apply/unarmed_damage");
        }

        dp = target->query_skill("dodge") + target->query_skill("yinyang-shiertian", 1);

        // ��һ�У��ж϶Է�����
        message_sort(HIW "$N" HIW "˫��һ��һ�ɻ���������ھ���ӿ���ȣ�"
                     "������ɽ����֮����$n" HIW "ϯ�������\n" NOR, me, target);

        damage1 = 0;

        if (ap * 10 / 3 + random(ap) > dp)
        {
                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                        msg = HIW "$n" HIW "�ٱ�����,Ȼ��$N" HIW "���������޿ɵ�����"
                              "ɲ�Ǽ�ͽ�$n" HIW "ȫ���ͷѹ�顣" NOR "( $n" RED "���˹��أ���"
                              "��������в�����ʱ�����ܶ�����" NOR ")\n";
                        damage1 = -1;
                        me->add("neili", -2000);
                } else
                {
                        target->receive_damage("qi", damage, me);
                        target->receive_wound("qi", damage / 2, me);
                        target->receive_damage("jing", damage / 4, me);
                        target->receive_wound("jing", damage / 8, me);
                        p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

                        msg = HIY "$n" HIY "˼��δ����$N" HIY "���ھ���������룬"
                              "$n" HIY "�ܴ��ػ������һ��Ż������" HIR "��Ѫ" HIY "��\n" NOR;
                        msg += "( $n" + eff_status_msg(p) + " )\n";

                        me->add("neili", -500);
                }
        } else
        {
                msg = CYN "$n" CYN "֪��$N�����޿ɵֵ���"
                       CYN "��������Ծ����������������\n" NOR;
                me->add("neili", -200);
        }
        message_sort(msg, me, target);

        if (damage1 < 0)
        {
	        me->start_busy(2);
	        target->receive_wound("qi", damage, me);
                target->set("qi", 1);
                target->set("eff_qi", 1);
                target->set("jing", 1);
                target->set("eff_jing", 1);
                target->unconcious(me);
	        return 1;
        }

        // �ڶ��У��ж϶Է���������
        dp1 = target->query_skill("guzheng-jifa", 1) + target->query_skill("tanqin-jifa", 1) +
	      target->query_skill("chuixiao-jifa", 1) + dp;

        message_sort(HIW "\n$N" HIW "һ����Х��ƾ�����������ƾ�մ�����Ī��������,"
		     HIW "�����д���һ˿���������ˣ��·��ֻص���ңԶ��ͯ�ꡣ\n" NOR, me, target);

        if (ap * 10 / 3 + random(ap) > dp1)
        {
                target->receive_damage("qi", damage / 2, me);
                target->receive_wound("qi", damage / 4, me);
                target->receive_damage("jing", damage * 2 / 3, me);
                target->receive_wound("jing", damage / 2, me);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

                msg = HIY "$N" HIY "�����϶�������ϣ�$n" HIY "ȴ�Գ����ڻ���֮�У�"
                      HIY "$N" HIY "һ�����֡�\n" NOR;
                msg += "( $n" + eff_status_msg(p) + " )\n";
        } else
        {
                msg = CYN "�Ҷ�$n" CYN "��ͨ���ɣ������Դ���$N" CYN "�޴����֡�\n" NOR;
        }
        message_sort(msg, me, target);

        // �����У��ж϶Է���ѧ����ѧ����
        dp1 = target->query_skill("buddhism", 1) + target->query_skill("lamaism", 1) +
	      target->query_skill("taoism", 1) + dp;

        message_sort(HIW "\n$N��������һ�����˵�������������������һ������"
		     HIW "������Ů���������һ��\n" NOR, me, target);

        if (ap * 10 / 3 + random(ap) > dp1)
        {
                target->receive_damage("qi", damage / 2, me);
                target->receive_wound("qi", damage / 4, me);
                target->receive_damage("jing", damage * 2 / 3, me);
                target->receive_wound("jing", damage / 2, me);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

                msg = HIY "��ʱ��$n" HIY "ֻ����ͷ���ȣ�������˵���������ܡ�\n" NOR;
                msg += "( $n" + eff_status_msg(p) + " )\n";
        } else
        {
                msg = CYN "$n" CYN "������һ��˿����Ϊ������\n" NOR;
        }
        message_sort(msg, me, target);

        // �����У��ж϶Է���������
        dp1 = target->query("score");
	dp1 /= 20000;
        if (dp1 > 10000)
	        dp1 = 10000;
        if (dp1 > 2000)
        {
                dp1 -= 2000;
	        dp1 /= 5;
	        dp1 += 2000;
        }

        dp1 += dp;

        message_sort(HIW "\n$Nҡ��һ�Σ���ʱ����ǧ����Ӱ��$n"
		     HIW "�������ң���֪$N" HIW "������ڡ�\n" NOR, me, target);

        if (ap * 10 / 3 + random(ap) > dp1)
        {
                msg = COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 80 + random(15),
                                          (: final, me, target, damage :));
        } else
        {
                msg = CYN "$n" CYN "����ʶ�㣬Σ��ʱ�����ڿ���$N"
		      CYN "��ʽ��·����æ����ܿ���\n" NOR;
        }
        message_sort(msg, me, target);

        // �����У��ж϶Է���������������м�
        dp1 = target->query("str") * 30 + target->query_skill("parry", 1) + dp;

        message_sort(HIW "\n$N" HIW "���һ����һ�й���$n" HIW "����Ȼ"
                     "�����ˣ�ȴ��ʯ���쾪֮�ƣ�\n" NOR, me, target);

        if (ap * 10 / 3 + random(ap) > dp1)
        {
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage / 2, me);
                target->receive_damage("jing", damage / 4, me);
                target->receive_wound("jing", damage / 8, me);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

                msg = HIY "$n" HIY "����������ǿ���һ�У������޷��мܣ������ػ��У�\n"
		      HIY "�����������ڲ��ݣ�����" HIR "��Ѫ" HIY "����������\n" NOR;
                msg += "( $n" + eff_status_msg(p) + " )\n";

                if (objectp(weapon = target->query_temp("weapon"))
                   && weapon->query("stable", 1) < 100
                   && ap / 2 + random(ap) > dp1)
                {
                        wp = weapon->name();
                        msg += HIW "ֻ�����ϡ���һ�����죬$n" HIW "��"
                               "�е�" + wp + HIW "��$N" HIW "��������"
                               "��Ӧ�����飬���ֵ����ڵ��ϡ�\n" NOR;
                        me->add("neili", -150);
                        weapon->set("consistence", 0);
                        weapon->move(environment(target));
                }
        } else
        {
                msg = CYN "$n" CYN "�������������ͣ����μ��ˣ�˲��Ʈ����"
                      "�ɣ����Ŷ��$N" CYN "���С�\n" NOR;
        }
        message_sort(msg, me, target);

        // �����У��ж϶Է��������������ȭ��
        dp1 = target->query_str() * 2 + target->query_skill("unarmed", 1) + dp;

        message_sort(HIW "\n$N" HIW "ǰ��δ�䣬������������ʮ�����$n"
		     HIW "���������\n" NOR, me, target);

        if (ap * 10 / 3 + random(ap) > dp1)
        {
		target->add("neili", -(lvl + random(lvl)));
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 80 + random(10),
                                          HIY "ֻ��$n" HIY "һ���ҽУ���$N" HIY "�ھ�������ǰ��"
					  "�����꿦�ꡱ���˼����߹ǡ���\n" NOR, me , target);
        } else
        {
                msg = CYN "$n" CYN "����˫�ۣ������Զԣ�����$N" CYN "֮��жȥ��\n" NOR;
        }
        message_sort(msg, me, target);

        // �����У��ж϶Է��������Լ������м�
        dp = target->query("int") * 30 + target->query_skill("parry", 1) + dp1;

        message_sort(HIW "\n$N" HIW "һ�л���$n" HIW "��ǰ�յ���"
		     "����������Ȼ�γ���һ�����С�\n" NOR, me, target);

        if (ap * 10 / 3 + random(ap) > dp1)
        {
                target->receive_damage("qi", damage * 3 / 2, me);
                target->receive_wound("qi", damage * 2 / 3, me);
                target->receive_damage("jing", damage / 4, me);
                target->receive_wound("jing", damage / 8, me);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

                msg = HIY "$n" HIY "δ�ϵ�$N" HIW "���о����ڱؾ�֮·��"
		      HIY "���������У������Ѿ�ײ���ھ�����֮�У�\n" NOR;
                msg += "( $n" + eff_status_msg(p) + " )\n";
        } else
        {
                msg = CYN "$n" CYN "��æ���У���ǿ�������Ա��ӹ���\n" NOR;
        }
        message_sort(msg, me, target);

        // �ڰ��У��ж϶Է��������Լ�����д��
        dp1 = target->query_int() * 2 + target->query_skill("literate", 1) + dp;

        message_sort(HIW "\n$N" HIW "˫��������ظ�֮�侹Ȼ¶��һ�������������\n" NOR, me, target);

        if (ap * 10 / 3 + random(ap) > dp1)
        {
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 95 + random(10),
                                          HIY "$n" HIY "һ����Ц������$N" HIY "��ǰ��"
					  "������ʽδ��,$N" HIY "���������Ѳ���������\n" NOR, me , target);
        } else
        {
                msg = CYN "$n" CYN "���ƴ��������յУ�������أ�����������\n" NOR;
        }
        message_sort(msg, me, target);

		// �ھ��У��ж϶Է�������Ǽ������м�
        dp1 = target->query("con") * 30 + target->query_skill("parry", 1) + dp;

        message_sort(HIW "\n$N�������У����������ھ�����һ��������ǽ����ǰ�����"
		     HIW "ȥ��$n" HIW "ֻ����·���ˣ����д󾪡�\n" NOR, me, target);

        if (ap * 10 / 3 + random(ap) > dp1)
        {
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage / 2, me);
                target->receive_damage("jing", damage / 4, me);
                target->receive_wound("jing", damage / 8, me);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

                msg = HIY "$n����˼��������ܣ���ɽ����ھ�"
		      HIY "�Ѿ�ѹ�˹��������ػ���$n" HIY "���ؿڡ�\n" NOR;
                msg += "( $n" + eff_status_msg(p) + " )\n";

                if (objectp(cloth = target->query_temp("armor/armor"))
                   && cloth->query("stable", 1) < 100
                   && ap / 2 + random(ap) > dp1)
                {
                        cl = cloth->name();
                        msg += HIW "ֻ�����䡱��һ�����죬$n" HIW "��"
                               "�ŵ�" + cl + HIW "��$N" HIW "��������"
                               "��Ӧ�����ѣ�����һ�����Ƭ��\n" NOR;
                        me->add("neili", -150);
                        cloth->set("consistence", 0);
                        cloth->move(environment(target));
                }
        } else
        {
                msg = CYN "$n" CYN "����һЦ��һ�л�����ǽ���ģ�����������ȥ��\n" NOR;
        }
        message_sort(msg, me, target);

        // ��ʮ�У��ж϶Է�������Ǽ������ڹ�
        dp1 = target->query_con() * 2 + target->query_skill("force", 1) + dp;

        message_sort(HIW "\n$N" HIW "˫�۶�Ȼ�������ߡ�ֻ���ƿ�֮�����죬"
		     HIW "˫�ƻó�������Ӱ������ǵ���$n" HIW "��ȥ��\n" NOR, me, target);

        if (ap * 10 / 3 + random(ap) > dp1)
        {
		target->receive_damage("jing", damage / 2, me);
	        target->receive_wound("jing", damage / 4, me);
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 80 + random(10),
                             HIY "$n������������$N" HIY "һ�л����˳�ȥ��\n" NOR, me , target);
        } else
        {
                msg = CYN "$n" CYN "���$N" CYN "����ɽ�������ƣ���ȫ"
					  CYN "�޷��ֵ���Ψ���˺󼸲�������Ӧ�ԡ�\n" NOR;
        }

        message_sort(msg, me, target);

        // ��ʮһ�У��ж϶Է��������������м�
        dp1 = target->query("dex") * 30 + target->query_skill("parry", 1) + dp;

        message_sort(HIW "\n$N" HIW "������Ȼ��ת��������������С������"
		     HIW "�������Ǹ��£���$n" HIW "�����ȥ��\n" NOR, me, target);

        if (ap * 10 / 3 + random(ap) > dp1)
        {
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage / 2, me);
                target->receive_damage("jing", damage / 4, me);
                target->receive_wound("jing", damage / 8, me);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

                msg = HIY "$n" HIY "��Ų���㣬�߾�ȫ����Ҳû�취�㿪�����������˸����ţ�\n" NOR;
                msg += "( $n" + eff_status_msg(p) + " )\n";

                if (objectp(cloth = target->query_temp("armor/cloth"))
                   && cloth->query("stable", 1) < 100
                   && ap / 2 + random(ap) > dp1)
                {
                        cl = cloth->name();
                        msg += HIW "ֻ�����䡱��һ�����죬$n" HIW "��"
                               "�ŵ�" + cl + HIW "��$N" HIW "��������"
                               "��Ӧ�����飬����һ�����Ƭ��\n" NOR;
                        me->add("neili", -150);
                        cloth->set("consistence", 0);
                        cloth->move(environment(target));
                }
        } else
        {
                msg = CYN "$n���һ������æ�˺󣬾�Ȼ"
                      CYN "���Ҷ㿪����һ�У�\n" NOR;
        }
        message_sort(msg, me, target);

        // ��ʮ���У��ж϶Է��������������Ṧ
        dp1 = target->query_dex() * 2 + target->query_skill("dodge", 1) + dp;

        message_sort(HIW "\n$N�������ӵ��������û���ǧ�����Σ�һ������$n��\n" NOR, me, target);

        if (ap * 10 / 3 + random(ap) > dp1)
        {
                if (! target->is_busy())
	                target->start_busy(4 + random(lvl / 400));
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 80 + random(10),
                                          HIY "$n�������ʮ��ս�������ﻹ�ֵܵ���ס��"
					  HIY "������Ϣ֮�䣬�Ѿ��������У�\n" NOR, me , target);
        } else
        {
                msg = CYN "$n����߲��²���ھ�����$N" CYN "�����Ĺ��ƾ����ֵ���\n" NOR;
        }
        message_sort(msg, me, target);

        me->start_busy(3 + random(7));
        me->add("neili", -4000 - random(4000));
        return 1;
}

string final(object me, object target, int ap)
{
        target->add_temp("apply/avoid_busy", -90);
        target->add_temp("apply/reduce_busy", -36);
        target->add_temp("apply/avoid_weak", -90);
        target->add_temp("apply/avoid_locked", -90);
        target->set_temp("no_perform", 1, target);
        remove_call_out("tian_end");
        call_out("tian_end", 10 + random(ap / 50), me, target);
        return HIY "$n" HIY "˿���������а��һ�����񣬵��������ش���\n" NOR +
               WHT "$n" WHT "�е�����ĺ�������������æ�ҡ����Ӿ����䶳��������ӡ��\n" NOR;
}

void tian_end(object me, object target)
{
        if( target && target->query_temp("no_perform") )
        {
                if (living(target))
                {
                        message_combatd(HIC "$N" HIC "��������һ��"
                                        "������ɫ�ɰ�ת�죬��������"
                                        "���ˡ�\n" NOR, target);

                        tell_object(target, HIY "��е������ҵ�����"
                                            "����ƽ����������\n" NOR);
                }
        target->add_temp("apply/avoid_busy", 90);
        target->add_temp("apply/reduce_busy", 36);
        target->add_temp("apply/avoid_weak", 90);
        target->add_temp("apply/avoid_locked", 90);
        tell_object(target, HIR "��ĺ�������������æ�ҡ����Ӿ����䶳�������ڽ����ӡ��\n" NOR);
                target->delete_temp("no_perform");
        }
        return;
}