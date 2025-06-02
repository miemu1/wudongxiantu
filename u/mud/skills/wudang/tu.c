#include <ansi.h>
#include <combat.h>

#include "/kungfu/skill/eff_msg.h"

inherit F_SSERVER;

string name() { return HIW "̫��ͼ" NOR; }

int perform(object me, object target)
{
        mapping buff;
        object *obs;
        string msg;
        int duration;
        int damage;
        int ap, dp;
        int flag;
        int time;
        int delta;
        int i;
        int p;
        int per;

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail(name() + "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail(name() + "ֻ�ܿ���ʩչ��\n");

        if( (int)me->query_skill("taiji-quan", 1) < 250 )
                return notify_fail("���̫��ȭ������죬����ʩչ" + name() + "��\n");

        if( (int)me->query_skill("taiji-shengong", 1) < 300 )
                return notify_fail("���̫������Ϊ�������ߣ�����ʩչ" + name() + "��\n");

        if( (int)me->query_skill("taoism", 1) < 300 )
                return notify_fail("��ĵ�ѧ�ķ���Ϊ�������ߣ�����ʩչ" + name() + "��\n");

        if( me->query_skill_mapped("cuff") != "taiji-quan" )
                return notify_fail("������û�м���̫��ȭ������ʩչ" + name() + "��\n");

        if( me->query_skill_mapped("force") != "taiji-shengong" )
                return notify_fail("������û�м���̫���񹦣�����ʩչ" + name() + "��\n");

        if( query("jing", me)<2000 )
                return notify_fail("�����ھ�������������ʩչ" + name() + "��\n");

        if( query("neili", me)<2000 )
                return notify_fail("��������������������ʩչ" + name() + "��\n");

             if( userp(me)&& !wizardp(me) ) 
        {
                if( (duration = BUFF_D->get_buff_overtime(me, "tjq_tu")) > 0 )
                        return notify_fail(MAG"̫��ͼ��������̫��������ȴ�"+duration+"�롣\n"NOR);
        }
        
        msg = HIM "$N" HIM "��ȻһЦ��˫�����Ữ������Ȧ�ӣ���ʱ���ܵ���"
              "��������ԴԴ���ϵı�ǣ��������\n\n" NOR;
        message_combatd(msg, me, target);

        per = me->query_skill("taiji-shengong",1)/2000 + me->query_skill("tianwei-zhengqi",1)/240;
        if(per < 1) per = 1;
        if(per > 20) per = 20;
                
        addn("neili", -1000, me);
        addn("jing", -1000, me);
        
        ap = attack_power(me, "cuff") + me->query_skill("taoism", 1);
        delta = ABILITY_D->check_ability(me, "ap_power-tjq-tu");
        if( delta ) ap += ap*delta/100;
        obs = me->query_enemy();
        for (flag = 0, i = 0; i < sizeof(obs); i++)
        {
                dp = defense_power(obs[i], "force") + obs[i]->query_skill("count", 1);
                if( ap > dp * 12 / 10 ) 
                {
                        switch (random(3))
                        {
                        case 0:
                                tell_object(obs[i], HIY "���֮�����ƺ��ص��˹�ȥ�����磬��"
                                                    "Ȼ���޷��������ң���Ȼ��ǰ��һ��\n"
                                                    "��ȫȻ����������ͷһ�ң�����һ���"
                                                    "ʹ�������������Կ��ƣ�\n" NOR);
                                break;
                        case 1:
                                tell_object(obs[i], HIW "����ǰһ�н�����ģ�������������ǵ�"
                                                    "���ɾ���Ȼ����ȴ������ϢԽ��Խ�ң�\n"
                                                    "��֫һ����ʹ������Ҫվ����ס��\n" NOR);

                                break;
                        default:
                                tell_object(obs[i], HIR "����ߺ�Ȼ����һ���������ۼ������"
                                                    "��紸����������㲻�����һ����\n"
                                                    "�������¶�����ʹ����ֻ�и������ȡ�\n" NOR);
                                break;
                        }
                        damage = damage_power(me, "cuff");
                                                damage+= me->query_all_buff("unarmed_damage");
                        damage*= me->query_skill("tianwei-zhengqi",1) /100;
                        delta = ABILITY_D->check_ability(me, "da_power-tjq-tu"); // ����ab
                        if( delta ) damage += damage*delta/100;
        
                        if( damage < query("max_qi", obs[i])* (per + random(6)) / 100 )
                            damage = query("max_qi", obs[i])* (per + random(6)) / 100;
                        if( damage < query("max_qi", obs[i]) /100*50 )
                            damage = query("max_qi", obs[i]) /100*50;                                                   
                                                        
                            obs[i]->receive_damage("qi", damage, me);
                            obs[i]->receive_wound("qi", damage/2, me);
                                                        
                        if( damage < query("max_jing", obs[i])* (per + random(6)) / 100 )
                            damage = query("max_jing", obs[i])* (per + random(6)) / 100;                                             
                        if( damage > query("max_jing", obs[i]) /100*50 )
                            damage = query("max_jing", obs[i]) /100*50;                                                 
 
                            obs[i]->receive_damage("jing", damage / 2, me);
                            obs[i]->receive_wound("jing", damage / 4, me);

                        p=query("qi", obs[i])*100/query("max_qi", obs[i]);

                        switch (random(3))
                        {
                        case 0:
                                msg = HIR "ֻ��" + obs[i]->name() +
                                      HIR "�����㵸���������ԣ���"
                                      "Ȼ���һ������Ѫ��ֹ��\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                
                                break;
                        case 1:
                                msg = HIR "ȴ��" + obs[i]->name() +
                                      HIR "��ò���ݣ��ƺ�������ʲ"
                                      "ô����֮�£�����һ�Σ�Ż��������Ѫ��\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;
                        default:
                                msg = HIR + obs[i]->name() +
                                      HIR "����������һ��������������"
                                      "а�����϶��ų���Ѫ����\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;
                        }
                        msg += COMBAT_D->report_status(obs[i], 1)+"\n";
                        if( !obs[i]->is_busy() )
                                obs[i]->start_busy(3);
                        message("vision", msg, environment(me), ({ obs[i] }));
                        COMBAT_D->report_status(obs[i], 1);
                        addn("neili", -500, obs[i]);
                        flag = 1;
                } else
                {
                        tell_object(obs[i], HIC "�㷢����ǰ�ľ����ƻ����棬��æ"
                                            "Ĭ���ڹ����������š�\n" NOR);
                        addn("neili", -200, obs[i]);
                }
                if( query("neili", obs[i])<0 )
                        set("neili", 0, obs[i]);
        }


        if( !flag )
                message_combatd(HIM "Ȼ��û���κ�������$N"
                               HIM "��Ӱ�졣\n\n" NOR, me, 0, obs);
        
        time  = 40;
        time -= ABILITY_D->check_ability(me, "cd-tjq-tu"); // ab���ɼ�cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent��cd 
               
        buff = // Perform Cool Dow
        ([
                "caster" : me,
                "target" : me,
                "type"   : "cooldown",
                "type2"  : "tjq_tu",
                "attr"   : "curse",
                "name"   : "̫��ȭ��̫��ͼ",
                "time"   : time,
                "buff_msg" : "̫��ͼ��������̫��������ȴ�"+time+"�뷽���ٴ�ʩչ��\n",
                "disa_msg" : "",
                "disa_type": 0,
       
        ]);
        BUFF_D->buffup(buff);
        me->start_busy(1+random(2));
        return 1;
}


