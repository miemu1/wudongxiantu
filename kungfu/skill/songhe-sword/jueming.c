// qixing. �ɺ׾�����

#include <ansi.h>

inherit F_SSERVER;
string query_name() { return "�ɺ�"ZJBR"����"; }
int perform(object me, object target)
{
        string msg;
        object weapon = me->query_temp("weapon");
        int ap,dp,damage;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ɺ׾�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if( (int)me->query_skill("songhe-sword", 1) < 120 )
                return notify_fail("����ɺ׽�������������ʹ�����ɺ׾�������\n");
  
    if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "songhe-sword")
                return notify_fail("�������޷�ʹ���ɺ׾�������\n");

    if ( (int)me->query("neili") < 1000)
                return notify_fail("��������������޷�ʹ���ɺ׾�������\n");

        msg = HIY"\n$Nһ����Х��һ�����н�����ʱ�γ�һ����Ļ����籩���ѹ��$n������
$n����֮�䣬��Ļ�зɳ��߶亮�ǣ������ǰ�����$n��\n\n"NOR;

      ap = me->query_skill("sword");
      dp = target->query_skill("dodge", 1) + target->query_skill("parry", 1); 
        if (ap / 2 + random(ap) > dp)
{
                msg +=HIR"$n������������Ȼ�н���\n"NOR;
                damage = 3*(int)me->query_skill("sword");
                if (damage > target->query("neili") / 10)
                damage -= target->query("neili") / 10;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                if( damage < 40 ) msg += HIR"$n���������������ϵ�����Ѫ��\n"NOR;
                else if( damage < 80 ) msg += HIR"$n�����߽�����Ѫ���������\n"NOR;
                else msg += HIR"$n���ۡ��Ŀ��һ������������ߵ�Ѫ����\n"NOR;
                message_vision(msg, me, target);
        } 
        else {
                msg += HIC"$n�鼱֮����󼤷ɣ����ſ�£����������������һ����\n"NOR;
                message_vision(msg, me, target);
        }
        me->add("neili", -80);
        me->start_busy(2);

        return 1;
}

