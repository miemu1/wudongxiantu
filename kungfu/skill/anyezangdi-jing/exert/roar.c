// roar.c 

#include <ansi.h>

inherit F_CLEAN_UP;

string query_name() { return "����"ZJBR"����"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;

        if ((int)me->query("neili") < 60  
        ||  (int)me->query_skill("anyezangdi-jing", 1) < 50)
                return notify_fail("����������������Ľ���һ��, ��������˼�ֻ����\n");
                
        skill = me->query_skill("force", 1) / 4 + me->query_skill("anyezangdi-jing", 1);
        me->add("neili", -15);
        me->receive_damage("qi", 10);
        
        if (environment(me)->query("no_fight"))
                return notify_fail("���ﲻ�ܹ�������! \n");

        me->start_busy(1);
        message_combatd(HIY "$N�������һ���������췢��һ��ֱ������ʮ�ص�������\n" NOR, me);
        
        ob = all_inventory(environment(me));
        for (i = 0; i < sizeof(ob); i++) 
        {
                if (! ob[i]->is_character() || ob[i] == me)
                        continue;

                if (! living(ob[i]) || wizardp(ob[i]) || 
                    (ob[i]->query("age") < 16 && userp(ob[i])))
                        continue;

                if (skill / 2 + random(skill / 2) < (int)ob[i]->query_skill("force") / 5 )
                        continue;
 
                me->want_kill(ob[i]);
                me->fight_ob(ob[i]);
                ob[i]->kill_ob(me);

                damage = skill - ((int)ob[i]->query("max_neili") / 10);
                if (damage > 0) 
                {
                        ob[i]->set("last_damage_from", me);                     
                        ob[i]->receive_damage("jing", damage * 2, me );
                        if ((int)ob[i]->query("neili") < skill * 2)
                                ob[i]->receive_wound("jing", damage, me);
                        tell_object(ob[i], "�������ǰһ�������ð������ʹ������Ҫ�ѿ�һ����\n");
                }
        }
        return 1;
}

