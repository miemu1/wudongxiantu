#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "��˫"ZJBR"һ��"; }

int perform(object me, object target)
{
        object weapon;
           
   if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��˫һ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if((int)me->query("neili") < 150)
                return notify_fail("�������������\n");

        if ((int)me->query("max_neili") < 200)
                return notify_fail("�������������\n");

        if((int)me->query("jing") < 20)
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("anyezangdi-jing", 1) < 300)
                return notify_fail("��İ�ҹ�ᾭ�ȼ��������޷�ʹ�á���˫һ������\n");
        if((int)me->query_skill("zuoyou-hubo", 1) > 7)
        	    return notify_fail("�˾����������ͼ���󣬻�����ϻ���֮������\n");
 
             weapon=me->query_temp("weapon");
           me->delete("env/brief_message");
           message_vision(HIY"\n$N����Ծ��ʹ����ҹ�ᾭ�ռ���������˫һ����!n"NOR, me);
           message_vision(HIB"\nͻȻֻ��$Nʹ����ҹ�ᾭ�ռ���������˫һ������\n"NOR, me);
                      me->delete("env/brief_message");
   target->delete("env/brief_message");

message_vision(HIC"\n$N����Ծ��ʹ����ҹ�ᾭ�ռ���������˫һ����!\n"NOR,me,target);
message_vision(HBMAG"$N��ȭ��Х�����ޣ�����\n"NOR,me,target);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
message_vision(HBMAG"$N��ȭ��Х����˫������\n"NOR,me,target);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HBMAG"$N��ȭ��Х����һ��������\n"NOR,me,target);                
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HBMAG"$N��ȭ��Х��������������\n"NOR,me,target);                
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"\n$N������δ��,������������籩����ȭ���$n��ȥ��\n"NOR, me, weapon);
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HBMAG"$N����δ��,��������.ȭ������,Ʈҡ���𡱣�\n"NOR,me,target);  
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           message_vision(HIC"\n$N�޷�������Ϣ������ֻ�ú�Ծ���С�\n"NOR, me, weapon);


           me->add("neili", -70);

          if( !target->is_fighting(me) ) {
                    if( living(target) ) {
                    if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

   me->start_busy(1);
   return 1;
}


