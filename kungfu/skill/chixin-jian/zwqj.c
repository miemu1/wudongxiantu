#include <ansi.h>

inherit F_SSERVER;

string query_name() { return"����"ZJBR"�齣"; }

int perform(object me, object target)
{
        object weapon;
           
   if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����齣ЦȺ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if((int)me->query("neili") < 1500 )
                return notify_fail("�������������\n");

        if ((int)me->query("max_neili") < 2000)
                return notify_fail("�������������\n");
       
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if((int)me->query("jing") < 200 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        
 
             weapon=me->query_temp("weapon");
           me->delete("env/brief_message");
           message_vision(HIY"\n$N����Ծ��ʹ�������齣���ռ������������齣��\n"NOR, me);
           message_vision(HIB"\nͻȻֻ��$Nʹ�������齣���ռ������������齣����\n"NOR, me);
                      me->delete("env/brief_message");
   target->delete("env/brief_message");

message_vision(HIC"\n$N����Ծ��ʹ�������齣���ռ������������齣��!\n"NOR,me,target);
message_vision(HBRED"$N�������齣������������ƾ����Ц��񲣡����\n"NOR,me,target);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
message_vision(HBRED"$N�������齣������������̾�쳾�����䣡����\n"NOR,me,target);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HBRED"$N�������齣��������������ǧ��������������\n"NOR,me,target);                
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HBRED"$N�������齣����������һ��һ����ң�ɣ�������\n"NOR,me,target);
message_vision(HBRED"$N�������齣������������������ݺ����������׷�겻���ˡ���������\n"NOR,me,target);
message_vision(HBRED"$N�������齣�������������м��˹����ϣ�һ�轣�����ķ�����������\n"NOR,me,target);
message_vision(HBRED"$N�������齣����������������ɽɫ��ɥ�����Ϊ֮�õͰ�����������\n"NOR,me,target);
message_vision(HBRED"$N�������齣����������������������䣬����Ⱥ�������衣��������\n"NOR,me,target);
message_vision(HBRED"$N�������齣����������������������ŭ�����罭������⡣��������\n"NOR,me,target);
message_vision(HBRED"$N�������齣����������˫��һ�������£������齣ЦȺ�ۡ���������\n"NOR,me,target);
message_vision(HBRED"$N�������齣�����������Ž���������������ǧ��׹������£������Ŷ�ţ����������\n"NOR,me,target);
message_vision(HBRED"$N�������齣�����������пͽ�һ�ۣ���֮������տȻ��ϻ�У���ˮ�β�������������\n"NOR,me,target);
message_vision(HBRED"$N�������齣���������������б��ԣ���������ٱ����ʹ����ۣ�������ָ�ᡣ��������\n"NOR,me,target);
message_vision(HBRED"$N�������齣����������Ը��ֱʿ�ģ���������ͷ����Ը��СԹ��ҹ���˽�𡣣�������\n"NOR,me,target);
message_vision(HBRED"$N�������齣�����������������ὣ����������ͥ���׺�ʱ��������ҹ���ǣ�������\n"NOR,me,target);
message_vision(HBRED"$N�������齣��������������ܽ�ض���ϻ��˪ѩ��������ֱ���������ȡ��������������\n"NOR,me,target);
message_vision(HBRED"$N�������齣�����������Կ��Ϻ�ӧ���⹳˪ѩ������������\n"NOR,me,target);
message_vision(HBRED"$N�������齣���������������հ����������ǡ���������\n"NOR,me,target);                
message_vision(HBRED"$N�������齣����������ʮ��ɱһ�ˣ�ǧ�ﲻ���С���������\n"NOR,me,target);                                
message_vision(HBRED"$N�������齣�������������˷���ȥ�����������������������\n"NOR,me,target);                                                
  message_vision(HBRED"$N�������齣�����������й����������ѽ�ϥǰ�ᡣ��������\n"NOR,me,target);                                                              
   message_vision(HBRED"$N�������齣����������������캥������Ȱ��������������\n"NOR,me,target);                                                                             
  message_vision(HBRED"$N�������齣����������������Ȼŵ��������Ϊ�ᡣ��������\n"NOR,me,target); 
   message_vision(HBRED"$N�������齣�����������ۻ����Ⱥ�����������������������\n"NOR,me,target);
   message_vision(HBRED"$N�������齣�������������Իӽ�鳣��������𾪡���������\n"NOR,me,target);
   message_vision(HBRED"$N�������齣����������ǧ���׳ʿ���Ӻմ����ǡ�����������\n"NOR,me,target);
   message_vision(HBRED"$N�������齣�������������������㣬��������Ӣ����������\n"NOR,me,target);
   message_vision(HBRED"$N�������齣����������˭������£�����̫��������������\n"NOR,me,target);
   message_vision(HBRED"$N�������齣���������������ݺ��������������\n"NOR,me,target);
   message_vision(HBRED"$N�������齣����������һ��˪��ʮ���ݡ���������\n"NOR,me,target);                                                                                                                                                 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIW"\n$N������δ��,������������籩��֮�����齣������$n��ȥ��\n"NOR, me, weapon);
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HBRED"$N����δ��,��������.�����齣���������,Ʈҡ���𣡡�\n"NOR,me,target);  
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           message_vision(HIC"\n$N�޷�������Ϣ������ֻ�ú�Ծ���С�\n"NOR, me, weapon);


           me->add("neili", -700);

          if( !target->is_fighting(me) ) {
                    if( living(target) ) {
                    if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

   me->start_busy(4);
   return 1;
}


