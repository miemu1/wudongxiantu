#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIR "��ң" + HIY + "����" + HIR "��" NOR; }
string query_name() { return "��ң"ZJBR"���Ľ�"; }
int perform(object me, object target)
{
        string type1, type2, msg;
        object weapon1, weapon2, weapon;
        int ap, dp, damage;
        int fmsk = me->query_skill("beiming-shengong", 1);
        int da_add;
        int i, count;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
        if( me->is_busy() )
                return notify_fail("����æ���ء�\n");
       

        if ( (string)me->query("family/family_name") != "��ң��") 
     return notify_fail("ֻ����ң���Ӳ���ʹ�ø�PFM��\n");
		if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
		if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");

        if (me->query_skill_mapped("sword") != "zuixin-sword")
                return notify_fail("��û�м�����ң���Ľ�������ʩչ" + name() + "��\n");

        if (me->query_skill("zuixin-sword", 1) < 500)
                return notify_fail("��Ľ�����ȼ�����������ʩչ" + name() + "��\n");

        if (me->query("neili") < 2000)
                return notify_fail("�����ڵ���������������ʩչ" + name() + "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");
		
		fmsk = me->query_skill("daojian-xiaotianwai", 1);
        ap = me->query_skill("sword", 1) + me->query_skill("martial-cognize", 1);
        dp = target->query_skill("force", 1)+ me->query_skill("martial-cognize", 1);

        damage = ap;
        damage+= me->query_skill("sword", 1);
        damage+= me->query("jiali");

        msg = HIY "$N" HIY "�� ���б�����������ǰ����ת��" + name() + HIY "��һ����ر任��\n" NOR;

        msg += HIY "�������µĽ�" HIY "$N" HIY "�������⽣��Ϊһ�壬\n"
                   "ֻ��˲�����б�������ת˲����\n"
                   HIY"$N" HIY "��ǰ��һ�о���������\n"
                   "���޵�֮������"HIY "$n"HIY"��\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "$n" HIR "�������$N" HIR "���������ƣ��������书��������"
                       "�����⣬�мܶ�ʱɢ�ң�ȫȻ��������\n" NOR;

                target->receive_damage("jing", damage / 2);
                target->receive_wound("jing", damage / 3);

                msg += COMBAT_D->do_damage(me, target, SPECIAL_ATTACK, damage, 100,
                                           HIR "$n" HIR " һʱ����֪�ֵ�"
                                           "����$N" HIR "һ��������"
                                           "�˲��ᡣ\n" NOR);
                ap += ap / 5;
                damage += damage / 3;
        } else
        {
                msg += HIG "$n" HIG "��$N" HIG "�书ϡ�棬˿����"
                       "�Ҵ��⣬��æ��������\n" NOR;
        }

        msg += HIW "\nͻȻ��$N" HIW "����һ�ã�����" + weapon->name() +
               HIW "����һ������\n" NOR;

        if (me->query_skill("count", 1) > 300)
        {
                damage = damage + damage / 3;
                da_add = (80 + fmsk / 15) + (80 + fmsk / 15) / 3;
        }

        if (ap / 2 + random(ap) > dp)
        {

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, da_add,
                                           HIR "$n" HIR "�����ֵ���ȴ�����޷��м�"
                                           "����$N" HIR "һ��������������Ѫ�Ĵ���"
                                           "����\n" NOR);
        } else
        {
                msg += CYN "$n" CYN "������һ����ǿ�󣬼�æ����"
                       "������С�Ĳ��С�\n" NOR;
        }

        msg += HIW "\n����$N" HIW "�ֽ�����" + weapon->name() +
               HIW "������ǰ���������⣬�޿�������"
               "�������ϵĽ���\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                /*
                weapon1->move(me, 1);
                weapon2->wield();
                */

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, da_add,
                                           HIR "$n" HIR "ֻ���ۻ����ң�ȫȻ�޷���"
                                           "���Ȼ���$N" HIR "һ�����У����һ����"
                                           "Ѫ��\n" NOR);
                /*
                weapon2->move(me, 1);
                weapon1->wield();
                set_temp("handing", weapon2, me);
                */
        } else
        {
                msg += CYN "$n" CYN "��֪��һ�е���������æ����"
                       "������С�Ĳ��У�˿������\n" NOR;
        }
        if( me->query("family/family_name") == "��ң��"&& fmsk >= 100 && me->query("neili")>1000)
        {
                msg += HIC "\n====================" HIY" ��" HIR "  ң" HIG "  ��" HIW " �Ľ�" HIC " ====================" NOR;
                msg += HIC "\n��Ȼ�䣬$N" HIC "����" + weapon->name()  + HIC +
                           "������������������һ�����⣬����$n" HIC "��\n" NOR;

                if (ap / 2 + random(ap)  + fmsk / 2 > dp)
                {
                        damage *= 2;
                        msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 350,
                                           HIR "$n" HIR "ɲ�Ǽ�Ŀ�ɿڴ���ȫȻ�޷�����"
                                           "��ǰ֮����$N" HIR "һ�����У����������"
                                           "Ѫ��\n" NOR);
                        me->add("neili", -500);
                        
                        count = me->query_skill("martial-cognize", 1) + me->query_skill("sword-cognize", 1);
                        count /= 1000;
                        if (! target->is_busy())
                                target->start_busy(8 + random(count));
                        
                        target->set_weak(3 + random(count));
                } else
                {
                        msg += CYN "$n" CYN "˿��������ǰ������Ӱ�죬�������㣬�ܿ���һ�С�\n" NOR;
                }
        }
        
        count = 0;
        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIW "$n" HIW "ֻ�������������Լ�Ϯ�����ŵ�һ����\n" NOR;
                count = ap / 15;
                me->set_temp("xiaoyao/max_pfm", 1);
        } else
        {
                msg += HIG "$n" HIG "ͻȻ�����Լ����ܽԱ���������Χ����æС�ķ�����\n" NOR;
                count = ap / 30;
        }
        message_combatd(msg, me, target);
        
        me->add("neili", -500);
        me->add_temp("apply/attack", count);
        me->add_temp("apply/damage", count*2/3);
        me->add_temp("apply/avoid_locked", 50);
        for (i = 0; i < 12; i++)
        {
                if (! me->is_fighting(target))
                        break;

                COMBAT_D->do_attack(me, target, weapon, 100);
        }
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -count*2/3);
        me->add_temp("apply/avoid_locked", -50);
        me->delete_temp("xiaoyao/max_pfm"); 
        me->start_busy(3 + random(2));
        
        message_combatd(msg, me, target);
        return 1;
}
