// feilong.c by yushu@SHXY 2000.11
#include <ansi.h>

inherit F_SSERVER;
string query_name() { return "����"ZJBR"̽����"; }
int perform(object me)
{
      string msg;
      object weapon, weapon2, target;
      int skill, ap, dp, damage;

      me->clean_up_enemy();
      target = me->select_opponent();

      if( (int)me->query_temp("feilong") )
              return notify_fail("���Ѿ���æ���ˡ�\n");
      skill = me->query_skill("fumozhang",1);
      
      if( !(me->is_fighting() ))
              return notify_fail("����̽����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

      if(me->query("family/family_name")!="��ɽ��")
                return notify_fail("������ɽ�Ĳ����á�����̽���֡���\n");

      if (objectp(weapon = me->query_temp("weapon")))
              return notify_fail("�������֡�\n");

      if (!objectp(weapon2 = target->query_temp("weapon")))
         return notify_fail("�Է�û�б��У��㲻�õ��ġ�\n");

      if( skill < 50)
              return notify_fail("��ķ�ħ�Ƶȼ�����, ��ʹ�÷���̽���֣�\n");

      if( me->query("neili") < 50 )
              return notify_fail("��������������޷�����̽���֣�\n");
      
           msg = CYN "$N�����Ϣ������ʩչ����̽���ֶ�ȡ�Է�����. \n";
      message_vision(msg, me);

      ap =  me->query_str() * 2 + me->query_dex() * 2;
      dp = target->query_dex() * 3 + target->query_str() * 3;
      if( ap > dp )
      {
              if(userp(me))
              me->add("neili",-50);
              msg = HIW"$Nʹ������̽���ֵľ���, $n��ʱ������ǰһ��������һ�飬����"HIM+weapon2->query("name")+HIW"����$N�����У�\n" NOR;
              target->start_busy(2);
              weapon2->move(me);
              me->start_busy(random(2));
      }
      else
      {
              msg = "����$n�Ŀ�����$N����ͼ�����̲�ȡ���ƣ�ʹ$Nû�ܶ��±��С�\n"NOR;
              me->start_busy(random(3));
      }
      message_vision(msg, me, target);

      return 1;
}
