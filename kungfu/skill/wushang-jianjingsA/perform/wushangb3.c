#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIR "����֮Ϣ" NOR; } 
string query_name() { return "����"ZJBR"֮Ϣ"; }
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
        string sexs;
         
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "ֻ����ս���жԶ���ʹ�á�\n");

        if( !objectp(weapon=me->query_temp("weapon") )
            || weapon->query("skill_type") != "sword" )
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" + name() + "��\n");

        if( !objectp(weapon=me->query_temp("weapon") )
            || weapon->query("skill_type") != "sword" )
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" + name() + "��\n");

        if (me->query_skill("wushang-jianjingsAA", 1) < 300)
                return notify_fail("������Ͻ�����Ϊ����������ʩչ" + name() + "��\n");

        if (me->query_skill("sword", 1) < 300)
                return notify_fail("��Ľ�����Ϊ����������ʩչ" + name() + "��\n");

        if (me->query_skill_mapped("sword") != "wushang-jianjingsAA")
                return notify_fail("��û�м������Ͻ���������ʩչ" + name() + "��\n");

        if (me->query_skill_mapped("force") != "wushang-jianjingsAA")
                return notify_fail("��û�м������Ͻ���������ʩչ" + name() + "��\n");

        if( me->query("neili")<2000 )
                return notify_fail("�����������������ʩչ" + name() + "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        sexs=me->query("gender") == "����"?"�н��������":"Ů������������";
        msg = HIR "$N" HIR "����������ɲ�Ǽ䣬�������ƣ���̬Ʈ��֮�������紫˵�е�" + sexs + "����Ȼ�䣬$N" HIR 
              "����" + weapon->name() + HIR "����һ�����⣬����һ�����ν�������$n" HIR "������һ˿Ԥ�ס�\n" NOR;

        ap = me->query_skill("sword"); 
        dp = target->query_skill("parry"); 
        
        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = me->query_skill("sword"); 
                damage *= 3;
                me->add("neili", -2000);
                me->start_busy(2 + random(4));
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 500,
                                           HIR "ֻ��$n" HIR "һ���ҽУ�$N" HIR +
                                           weapon->name() + HIR "����һ����һ������Ƕ"
                                           "��$p" HIR "���ڳ�������һ��Ѫ�ꡣ\n"
                                           NOR);
                if (random(3) == 1)
                {
                        target->receive_damage("jing", damage / 40, me);
                        target->receive_wound("jing", damage / 80, me);
                        target->start_busy(3 + random(4));
                        msg = msg + target->name() +  HIM "ͻȻ�о���ͷ��ľѣ���������ܵ��˽���֮Ϣ��Ӱ�졣\n" NOR;
                }
        } else
        {
                me->add("neili", -1000);
                me->start_busy(4);
                msg += CYN "$n" CYN "��$P" CYN "������ӿ���������׵�"
                       "������æ������Ų������������\n" NOR;
        }
        message_combatd(sort_msg(msg), me, target);

        return 1;
}