//modify by gladiator

#include <ansi.h>
#include <combat.h>

string name() { return HIY "��" HIG "��" HIC "��" HIW "ɽ" NOR; }
string query_name() { return "�ƶ�"ZJBR"��ɽ"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon, weapon2;
        int damage, i, n;
        string msg;
        int ap, dp;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !objectp(weapon=me->query_temp("weapon") )
                 || weapon->query("skill_type") != "sword"
                 && weapon->query("skill_type") != "blade" )
                        return notify_fail("����ʹ�õ��������ԣ�����ʩչ" + name() + "��\n");

        if (me->query_skill("daojian-guizhen", 1) < 300)
                return notify_fail("��ĵ������治����죬����ʹ��" + name() + "��\n");

        if (me->query_skill("force") < 350)
                return notify_fail("����ڹ���Ϊ�����ߡ�\n");

        if( me->query("neili")<800 )
                return notify_fail("����������̫��������ʹ��" + name() + "��\n");
		if( me->query_skill("lengyue-shengong")<500 )
                return notify_fail("�����ڵ��ڹ�����������ʩչ" + name() + "��\n");


        msg = HIC "$N" HIC "���һ����˫�ֺ���" + weapon->name() +
              HIC "������һ������ȫ����$n" HIC "Ѹ����ȥ��\n\n" NOR;


        if( me->query_temp("powerup") )
        {
                msg += HIW + weapon->name() +
                HIW "�ޱߵ�ɱ��˺�ѿ����������������ĺ����·���Ա���һ�У�"
                "��δ�������ȼ���$n" HIW "üë�������˱�����˪��\n\n" NOR;
        }

        ap = me->query_skill("blade", 1) ;
        dp = target->query_skill("parry", 1);
        if (ap / 2 + random(ap) > dp)
        {
                damage = ap;
                damage+=me->query("jiali");

                me->add("neili", -600);

                if( !objectp(weapon2=target->query_temp("weapon")) )
                {
                        msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 100,
                                                       HIR "ֻ��$n" HIR "һ���ҽУ��ؿڸ�"
                                                       "����һ���޴�Ŀ��ӣ���Ѫ��ӿ�����\n" NOR);

                        if (me->query_skill("daojian-guizhen", 1) > 320)
                                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
                                                           HIB "\n$n" HIB "����ҡ�μ䣬�о���"
                                                           + weapon->name() + HIB +
                                                           "��һ��̹ǵĺ����������ڣ��������"
                                                           "һ����Ѫ��\n" NOR);

                        if (me->query_skill("daojian-guizhen", 1) > 350)
                                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
                                                           HIY "\n$n" HIY "��Ҳ��ֲ�ס�������ε�"
                                                           "$N�����������ڵ���һ�ϣ�$N˳�Ʒ���������"
                                                           "����һ�У�$n���޷������˿��ٴ�����\n"
                                                           "����һ��Ѫ��ֱ�������\n" NOR);

                } else
                {
                        if( weapon2->is_item_make() || weapon2->query("damage")>800 ||
                            weapon2->query("skill_type") == "hammer" )
                                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 90,
                                                           HIG "$p" HIG "���" + weapon2->name() + HIG "��ͼ�мܣ�"
                                                           HIG "�����⵶�����Ϭ����͸��" + weapon2->name() +
                                                           HIG "ֱ���$p" HIG "������Ѫ������������Ҫ��ת������\n\n" NOR);
                        else
                        {
                                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 70,
                                                           HIR "$n" HIR "��״�����æ����" +
                                                           weapon2->name() + HIR + "�ֵ�����$N" HIR
                                                           "�������˫��һ���£�" + weapon2->name() +
                                                           HIR "�������Ƭ��\n\n" NOR);
                                n = 3 + random(3);
                                for (i = 0; i < n; i++)
                                {
                                        msg += (random(2) ? HIB : HIC) + "��Ƭ��ɢ�ɽ���������$n�����壡\n" NOR;

                                        target->receive_damage("qi", damage / 7, me);
                                                target->receive_wound("qi",damage / 15 + random(damage / 15), me);
                                }

                                msg += "\n" + HIY + weapon->name() + HIY "����δ������������$n" + HIY +
                                        "���ؿڣ�$n����ش�����Ѫ���������\n" NOR;

                                if( weapon2->query("material") != "tian jing" && random(2) == 1 )
                                {
                                        weapon2->set_name("���ѵ�"+weapon2->query("name"));
                                        weapon2->move(environment(target));
                                        weapon2->set("value", 0);
                                        weapon2->set("weapon_prop", 0);
                                } else
                                {
                                        weapon2->move(environment(target));
                                        weapon2->add("consistence", - 20);
                                }
                        }

                        target->reset_action();
                        target->receive_damage("qi", damage / 2, me);
                                               target->receive_wound("qi",
                                               damage / 4 + random(damage / 4), me);

                        if( me->query_temp("powerup") )
                                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 25,
                                                           HIB "\n$n" HIB "����ҡ�μ䣬�о���"
                                                           + weapon->name() + HIB +
                                                           "��һ��̹ǵĺ����������ڣ��������"
                                                           "һ����Ѫ��\n" NOR);
                }
                me->start_busy(3);
                target->start_busy(1 + random(2));
        } else
        {
                msg += HIY "$n" HIY "���Ʋ�������ˣ����ձܹ�$N"
                       HIY "��ɱ�У����������У������ѿ���һ������ӣ�\n"
                       HIR "$N��ͷ��ð��һ�ſŶ�����亹��һʱ֮��Ҳ�޷�ʹ����������ʽ��\n" NOR;
                me->add("neili", -100);
                me->start_busy(3);
                if( !target->is_busy() )
                        target->start_busy(1 + random(2));
        }

        message_combatd(sort_msg(msg), me, target);

        return 1;
}