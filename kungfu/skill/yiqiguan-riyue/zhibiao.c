// made by lks
 
#include <ansi.h>

 string query_name() { return "指镖"; }

inherit F_SSERVER;
 
int exert(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, neili_wound, qi_wound;

if( me->query("family/family_name") != "血河派" ) 
            return notify_fail("你不理解血河派的信念，怎么用的出他们的武功。\n"); 

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("yiqiguan-riyue",1);

        if( !me->is_fighting())
                return notify_fail("「指镖」只能在战斗中用在对手身上。\n");
 
        if( skill < 50)
                return notify_fail("你的一气贯日月不够纯熟, 不能使用「指镖」！\n");

        if( me->query("neili") < 150 )
                return notify_fail("你的内力不够，无法运用「指镖」！\n");
 
        if (me->query("yiqiguan-riyue")==1) {
        msg = HIY "$N默运“从心所欲”神功，运力于指，一式「指镖」，直奔$n的\n“孔最”，“列缺”，“径渠”，“大渊”，“血际”五穴。\n";
        ap = me->query_skill("force") + skill;
        }
          else if (me->query("yiqiguan-riyue")==2) {
        msg = HIY "$N默运“登峰造极”神功，运力于指，一式「指镖」，直奔$n的\n“孔最”，“列缺”，“径渠”，“大渊”，“血际”五穴。\n";
        ap = (me->query_skill("force") + skill)*3/2;
        }
            else  {
        msg = HIY "$N默运内息，运力于指，一式「指镖」，直奔$n的\n“孔最”，“列缺”，“径渠”，“大渊”，“血际”五穴。\n";
        ap = (me->query_skill("force") + skill)/2;
        }
 
        dp = target->query_skill("force") / 2;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp )
        {
                if(userp(me))
                        me->add("neili",-100);
                  msg += "$N「指镖」正中目标, $n顿时觉得丹田上一阵刺痛，\n";
                msg += "全身真气狂泄而出！\n" NOR;

                neili_wound = ap + random(skill);
                if(neili_wound > target->query("neili"))
                        neili_wound = target->query("neili");

                qi_wound = neili_wound / 2;
                if(qi_wound > target->query("qi"))
                        qi_wound = target->query("qi");

                target->add("neili", -neili_wound * 50);
                target->add("qi", -qi_wound * 25);
                target->add("eff_qi", -qi_wound * 25);
                target->start_busy(2);
                me->start_busy(random(2));
        }
        else
        {
                if(userp(me))
                        me->add("neili",-80);
                 msg += "可是$n瞬间反应过来，腾挪跳跃，躲过了这次重创。\n"NOR;
                me->start_busy(3);
        }
        message_vision(msg, me, target);

        return 1;
}

