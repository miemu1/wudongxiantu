#include <ansi.h>
#include <combat.h>

#define XIAN "��" HIR "������ն" NOR "��"
string query_name() { return "����"ZJBR"��ն"; }
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
            weapon->query("skill_type") != "blade" )
                return notify_fail("��ʹ�õ��������ԣ�\n");

        if ((int)me->query_skill("taiyan-dijing", 1) < 200)
                return notify_fail("��̫�ܵ۾�����㣬�޷�ʩչ" XIAN "��\n");

        if ((int)me->query_skill("force", 1) < 600)
                return notify_fail("������ڹ���Ϊ�������޷�ʩչ" XIAN "��\n");

        if ((int)me->query_skill("blade", 1) < 600)
                return notify_fail("��Ļ������������������ң��޷�ʩչ" XIAN "��\n");

        if( me->query("neili")<3000 )
                return notify_fail("�����������������޷�ʩչ" XIAN "��\n");

        if (me->query_skill_mapped("blade") != "taiyan-dijing")
                return notify_fail("��û�м���̫�ܵ۾����޷�ʹ��" XIAN "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -3000);

        ap=me->query_skill("blade")+me->query_skill("tanyan-dijing")+me->query_skill("martial-cognize",1)+me->query("str");
        dp = target->query_skill("dodge") + target->query_skill("force") + target->query_skill("martial-cognize", 1);

        message_combatd(HIW "\n$N" HIW "һ����̾���ƺ�����������ɣ����̬��ǧ���ֵ�������ң����� ����\n\n", me, target);

        // ��һ��
        msg = HIY "$N" HIY "̤����ǰ��ʩչ��������ն��һն����" + weapon->name() + HIY
              "˳��������������𣬴�ػع�ڰ� ����\n" NOR;

        if (ap * 3 / 2 + random(ap) > dp)
        {
                damage = ap * 1/5 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,50+me->query("str")/6,
                                           HIR "$n" HIR "����δ������Ȼ��֪��ܣ���$N"
                                           HIR "һ���������������壬������Ѫ���������ˡ�\n" NOR);
        }
        else
        {
                msg += CYN "$n" CYN "����һԾ������һ�ߡ�\n" NOR;
        }

        // �ڶ���
        msg += HIY "\n$N" HIY "��̾����Ȼ�䣬�ֱ�һ�ӣ�������ն����ն����Ȼʹ����" + weapon->name() + HIY "����һ��"
               "�����ƺڰ��������䣬һ�����ȵİ׹����$n" HIY "����Χ����������Ϣ��\n" NOR;

        if (ap * 3 / 2 + random(ap) > dp)
        {
                damage = ap * 2/5 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,55+me->query("str")/6,
                                          (: attack1, me, target, damage :));
        }
        else
        {
                msg += CYN "$n" CYN "����ʩչ��ʽ���������л��⡣\n" NOR;
        }

        // ������
        msg += HIY "\n$N" HIY "��̾����Ȼ�䣬�ֱ�һ�ӣ�������ն����ն����Ȼʹ����" + weapon->name() + HIY "����һ��"
               "�����ƺڰ��������䣬һ�����ȵİ׹����$n" HIY "����Χ����������Ϣ��\n" NOR;

        if (ap * 3 / 2 + random(ap) > dp)
        {
                damage = ap * 3/5 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,60+me->query("str")/6,
                                          (: attack1, me, target, damage :));
        }
        else
        {
                msg += CYN "$n" CYN "����ʩչ��ʽ���������л��⡣\n" NOR;
        }

        // ���ĵ�
        msg += HIY "\n$N" HIY "��̾����Ȼ�䣬�ֱ�һ�ӣ�������ն����ն����Ȼʹ����" + weapon->name() + HIY "����һ��"
               "�����ƺڰ��������䣬һ�����ȵİ׹����$n" HIY "����Χ����������Ϣ��\n" NOR;

        if (ap * 3 / 2 + random(ap) > dp)
        {
                damage = ap * 4/5 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,65+me->query("str")/6,
                                          (: attack1, me, target, damage :));
        }
        else
        {
                msg += CYN "$n" CYN "����ʩչ��ʽ���������л��⡣\n" NOR;
        }

        // ���嵶
        msg += HIY "\n$N" HIY "��̾����Ȼ�䣬�ֱ�һ�ӣ�������ն����ն����Ȼʹ����" + weapon->name() + HIY "����һ��"
               "�����ƺڰ��������䣬һ�����ȵİ׹����$n" HIY "����Χ����������Ϣ��\n" NOR;

        if (ap * 3 / 2 + random(ap) > dp)
        {
                damage = ap * 5/6 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,70+me->query("str")/6,
                                          (: attack1, me, target, damage :));
        }
        else
        {
                msg += CYN "$n" CYN "����ʩչ��ʽ���������л��⡣\n" NOR;
        }

        // ������
        msg += HIY "\n$N" HIY "˫��һ�죬������������Ȼŭ��һ�����ֱ�һ�ӣ�������ն����ն����Ȼʹ��������������ع�ڰ����ƺ����������Ѿ�"
              "׹���޼�����㣬�������ް�����ͻȻ�����ܳ���Ź���Ǻ��ľ��죬$N" HIY "ȴ����û����Ӱ��\n" NOR;
        if (ap * 5 / 1 + random(ap) > dp)
        {
                damage = ap * 6/7 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,75+me->query("str")/6,
                                           (: attack2, me, target, damage :));


        }
        else
        {
                msg += CYN "$n" CYN "��������С��Ӧ�ԣ��������л��������Ρ�\n" NOR;
        }

        me->start_busy(4 + random(4));
        message_combatd(sort_msg(msg), me, target);
        return 1;
}

string attack1(object me, object target, int damage)
{
        string msg;

        msg = HIR "$n" HIR "ֻ������һ���������ؿ�ȴ�ѷ��ڲ�Ϣ��˵���������ܡ�\n" NOR;

        target->add("neili", -3*damage/2);
        target->add("qi", -3*damage/2);
        return msg;
}

string attack2(object me, object target, int damage)
{
        string msg;

        msg = HIR "$n" HIR "����ʮ��ʧ�˰��ǣ������ɼ䣬��ǰһ��������͸�������\n" NOR;

        target->receive_wound("jing", damage * 5 / 3, me);
        if (random(4) == 1)target->start_busy(5 + random(5));

        return msg;
}