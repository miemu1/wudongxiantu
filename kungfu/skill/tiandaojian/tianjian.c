#include <ansi.h>
#include <combat.h>

#define XIAN "��" HIR "�콣��ʽ" NOR "��"
string query_name() { return "�콣"ZJBR"��ʽ"; }
inherit F_SSERVER;

string attack1(object me, object target, int damage);
string attack2(object me, object target, int damage);

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIAN "ֻ����ս���жԶ���ʹ�á�\n");

        if( !objectp(weapon=me->query_temp("weapon")) ||
            weapon->query("skill_type") != "sword" )
                return notify_fail("��ʹ�õ��������ԣ�\n");

        if ((int)me->query_skill("tiandaojian", 1) < 800)
                return notify_fail("�����������㣬�޷�ʩչ" XIAN "��\n");

        if ((int)me->query_skill("force", 1) < 600)
                return notify_fail("������ڹ���Ϊ�������޷�ʩչ" XIAN "��\n");

        if( me->query("neili")<3000 )
                return notify_fail("�����������������޷�ʩչ" XIAN "��\n");

        if (me->query_skill_mapped("sword") != "tiandaojian")
                return notify_fail("��û�м�����������޷�ʹ��" XIAN "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -1000);

        ap=me->query_skill("sword")+me->query_skill("force")+me->query_skill("martial-cognize",1)+me->query("str");
        dp = target->query_skill("dodge") + target->query_skill("force") + target->query_skill("martial-cognize", 1);

        message_combatd(HIW "\n$N" HIW "һ����̾���ƺ�����������ɣ����̬��ǧ���ֽ�������ң����� ����\n\n", me, target);

        // ��һ��
        msg = HIY "$N" HIY "̤����ǰ��ʩչ���콣��ʽ֮���˷��ء���" + weapon->name() + HIY
              "�ӽ���ɨ�������е�����\n" NOR;

        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap * 3 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,300+me->query("str"),
                                           HIR "$n" HIR "����δ������Ȼ��֪��ܣ���$N"
                                           HIR "һ���������������壬������Ѫ���������ˡ�\n" NOR);
        }
        else
        {
                msg += CYN "$n" CYN "����һԾ������һ�ߡ�\n" NOR;
        }

        // �ڶ���
        msg += HIY "\n$N" HIY "��̾����Ȼ�䣬�ֱ�һ�ӣ�һʽ�콣��ʽ֮���ط��졹��Ȼʹ����" + weapon->name() + HIY "����һ��"
               "�����ƺڰ��������䣬һ�����ȵİ׹����$n" HIY "����Χ����������Ϣ��\n" NOR;

        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap * 4 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,300+me->query("str"),
                                          (: attack1, me, target, damage :));
        }
        else
        {
                msg += CYN "$n" CYN "����ʩչ��ʽ���������л��⡣\n" NOR;
        }

        // ������
        msg += HIY "\n$N" HIY "����һ�����콣��ʽ֮���취������Ȼʹ����$N" HIY "ȴ����û����Ӱ��\n" NOR;
        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap * 5 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,350+me->query("str"),
                                           (: attack2, me, target, damage :));


        }
        else
        {
                msg += CYN "$n" CYN "��������С��Ӧ�ԣ��������л��������Ρ�\n" NOR;
        }

        me->start_busy(3 + random(3));
        message_combatd(sort_msg(msg), me, target);
        return 1;
}

string attack1(object me, object target, int damage)
{
        string msg;

        msg = HIR "$n" HIR "ֻ������һ���������ؿ�ȴ�ѷ��ڲ�Ϣ��˵���������ܡ�\n" NOR;

        target->add("neili", -1*damage*2/3);

        return msg;
}

string attack2(object me, object target, int damage)
{
        string msg;

        msg = HIR "$n" HIR "����ʮ��ʧ�˰��ǣ������ɼ䣬��ǰһ��������͸�������\n" NOR;

        target->receive_wound("jing", damage / 7, me);
        if (random(3) == 1)target->start_busy(6 + random(6));

        return msg;
}