//by system_2
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
 string query_name() { return "���衹�־�"; }
int perform(object me, object target)
{
    object weapon, ob;
    string msg;
    int i;
 
 ob = me->select_opponent();

    if( !me->is_fighting() )
        return notify_fail("���衹�־�ֻ����ս��ʱʹ�á�\n");
     if (me->query_temp("perform")>time()) return notify_fail("����һ��δʹ�꣡\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    else me->set_temp("secondly_weapon",1);
    if( (int)me->query("neili") < 1200 )
        return notify_fail("�������������\n");
if ( (string)me->query("family/family_name") != "��ң��") 
     return notify_fail("ֻ����ң���Ӳ���ʹ�ø��С�\n");
          if(me->query_skill_mapped("dodge") != "lingbo-weibu") 
               return notify_fail("����貨΢��û�������Ṧ�ϰ�? \n");

    if( (int)me->query_skill("sword") < 100 ||
        me->query_skill_mapped("sword") != "zuixin-sword")
        return notify_fail("��ġ���ң���Ľ����������������޷�ʹ�á��衹�־��\n");
msg = HIG "$Nһ����Х���������䣬����һ���ޱ�Ѥ���Ľ�â��ɲ�Ǽ佣â���ǣ�����ӵ�кһ������"+ob->name()+"!\n" NOR;
    message_vision(msg, me);
    me->clean_up_enemy();
    me->add("neili", -1000);
    me->set_temp("perform",time()+3);
    me->set_temp("perform_wu",1);
    for(i = 0; i < 15; i++)
        if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){
              me->set_temp("action_msg",HIC"����δ��\n"NOR);
                if (!weapon->query("equipped")) break;
              COMBAT_D->do_attack(me, ob,weapon, 0);
            }else break;
    me->delete_temp("perform_wu");
    me->delete_temp("secondly_weapon");
    return 1;
}


