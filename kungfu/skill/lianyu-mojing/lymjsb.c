#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "�ն�"ZJBR"����"; }

int perform(object me, object target)
{
        object weapon;
           
   if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�ն�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if((int)me->query("neili") < 500)
                return notify_fail("�������������\n");

        if ((int)me->query("max_neili") < 500)
                return notify_fail("�������������\n");

        if((int)me->query("jing") < 100)
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("lianyu-mojing", 1) < 300)
                return notify_fail("�������ħ���ȼ��������޷�ʹ�á��ն���������\n");
 
           weapon=me->query_temp("weapon");
           me->delete("env/brief_message");
           message_vision(HIY"\n$N����Ծ��ʹ������ħ���ռ��������ն�������!n"NOR, me);
           message_vision(HIB"\nͻȻֻ��$Nʹ������ħ���ռ��������ն���������\n"NOR, me);
           me->delete("env/brief_message");
   target->delete("env/brief_message");
message_vision(HIC"\n$N����Ծ��ʹ������ħ���ռ��������ն�������!\n"NOR,me,target);
message_vision(HBMAG"$N��ȭ��Х�����գ�����\n"NOR,me,target);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon") * 2); 
message_vision(HBMAG"$N��ȭ��Х�����ɣ�����\n"NOR,me,target);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon") * 3);
message_vision(HBMAG"$N��ȭ��Х�����ڣ�������\n"NOR,me,target);                
        COMBAT_D->do_attack(me, target, me->query_temp("weapon") * 4);
message_vision(HBMAG"$N��ȭ��Х��������������\n"NOR,me,target);                
        COMBAT_D->do_attack(me, target, me->query_temp("weapon") * 5);
message_vision(HIW"\n$N������δ��,������������籩����ȭ���$n��ȥ��\n"NOR, me, weapon);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon") * 6);
message_vision(HBMAG"$N����δ��,��������.ȭ������,Ʈҡ���𡱣�\n"NOR,me,target);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon") * 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon") * 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon") * 9);
message_vision(HIC"\n$N�޷�������Ϣ������ֻ�ú�Ծ���С�\n"NOR, me, weapon);


           me->add("neili", -500);

          if( !target->is_fighting(me) ) {
                    if( living(target) ) {
                    if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

   me->start_busy(1);
   return 1;
}


