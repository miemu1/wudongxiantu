#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
string query_name() { return "�ƶ���"ZJBR"�Ʒ���"; }
int perform(object me, object target)
{
        object weapon;
object ob;
        string msg;
        int i, attack_time;

        me->clean_up_enemy();
    ob = me->select_opponent();
if (me->is_fighting())
{
if  (environment(me)!=environment(ob) )
     return notify_fail("�Է��Ѿ������ˡ�\n");
}

        if( !target ) target = offensive_target(me);

        if ( me->query("gender") != "Ů��")
        return notify_fail("����̬��Ӳ���޴���ᡸ�Ʒ������Ʒ���ľ��衣\n");

//        if ( !wizardp(this_player()) && (me->query("family/family_name") != "�ƻ���"))
//                return notify_fail("�㲻���ƻ������Ӳ���ʹ��ڤ����.\n
//                                    �Ʒ罣��������, ���ƻ������Ӳ���, �治֪��������ôѧ���!\n
//                                    Ҫ������λ����֪������ɲ���.\n");
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���Ʒ������Ʒ��ֻ����ս����ʹ�á�\n");

   if (me->query_temp("perform")>time()) return notify_fail("����һ��δʹ�꣡\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if((int)me->query_dex() < 25)
                return notify_fail("���������, Ŀǰ������ʹ���������! \n");

     if(me->query_skill_mapped("sword") != "yifeng-jian")
             return notify_fail("����Ʒ罣��û�����ڽ����ϰ�? \n");

        if((int)me->query_skill("mingyu-shengong",1) < 180)
                return notify_fail("���ڤ���񹦵���Ϊ����, ����ʹ����һ���� !\n");

        if((int)me->query_skill("dodge") < 100)
                return notify_fail("����Ṧ��Ϊ����, ����ʹ���Ʒ������Ʒ��\n");

        if((int)me->query_skill("sword") < 120)
                return notify_fail("��Ľ�����Ϊ������ Ŀǰ����ʹ���Ʒ������Ʒ���! \n");

     if (me->query_temp("perform")>time()) return notify_fail("����һ��δʹ�꣡\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("�������������\n");

        msg = HIM "$N��ȻһЦ��ʹ���Ʒ罣���ľ�����"BLINK HIW"�Ʒ������Ʒ���"NOR HIM"��������" + weapon->name() +HIM"
              ��Ϊ����������裡$n�����ؿ����������������Լ�����\n"NOR;

    message_vision(msg, me, ob);
    me->clean_up_enemy();
    ob = me->select_opponent();
    me->add("neili", -500);
    me->set_temp("perform",time()+3);
    me->set_temp("perform_yifeng",1);
     for(i = 0; i < 12; i++)
        if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){
              me->set_temp("action_msg",HIR"������н�����\n"NOR);
                if (!weapon->query("equipped")) break;
              COMBAT_D->do_attack(me, ob,weapon, 0);
            }else break;
    me->delete_temp("perform_yifeng");
    me->delete_temp("secondly_weapon");
    return 1;
}


