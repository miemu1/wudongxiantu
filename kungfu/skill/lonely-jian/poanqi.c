// poanqi.c 破箭式

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp, damage;
int i, lvl;
        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("lonely-jian",1);

//        if(me->query("family/master_id") != "feng qingyang"
//        && userp(me))
//           return notify_fail("你不是风清扬的弟子，不能使用绝招！\n");

        if( !(me->is_fighting() ))
            return notify_fail("「破箭式」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");

        if (!objectp(weapon2 = target->query_temp("weapon"))
        || (string)weapon2->query("skill_type") != "throwing")
             return notify_fail("对方没有使暗器，你用不了「破箭式」。\n");

        if( skill < 50)
            return notify_fail("你的独孤九剑等级不够, 不能使用「破箭式」！\n");

     if( (int)me->query_skill("zixia-shengong",1)<100)
            return notify_fail("独孤九剑必须配合紫霞神功。\n");

        if( me->query("neili") < 50 )
            return notify_fail("你的内力不够，无法运用「破箭式」！\n");

        msg = HIC "$N举剑连点，运起独孤九剑之「破箭式」, 将$n掷过来的"+
weapon2->name() + "打得向$n反击回去。\n";
        message_combatd(msg, me, target);

        damage = 10 + random(skill / 2);
        ap = me->query_skill("sword") ;
        dp = target->query_skill("throwing", 1);
        if( dp < 1 )
                dp = 1;
          if( random(ap) > dp )
          {
             if(userp(me))
                  //me->add("neili",-50);
             msg = "$n顿时觉得铺天盖地的";
             msg += weapon2->name();
             msg += "反而向自己袭来！全身上下立刻被打得跟马蜂窝似的\n" NOR;

             
             target->receive_damage("qi", damage,me);
             target->start_busy(2);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);


                lvl = me->query_skill("lonely-jian", 1) / 80;
                if (lvl>9) lvl=9;
                me->add_temp("apply/attack", 100);
me->add_temp("apply/damage", 1200);
        for (i = 0; i < lvl; i++)
        {
msg=HIM"$N剑气纵横! 第"+chinese_number(i+1)+"道剑气划过了$n的$l。结果鲜血狂奔!\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -1200);
        }
        else
        {
             if(userp(me))
                  //me->add("neili",-30);
             msg = "可是$n看破了$N的意图，立刻将手中" + weapon2->name()+
"舞得风雨不透，将反击回来的" + weapon2->name() + "尽数击落在地。\n"NOR;
            
		message_combatd(msg, me, target);
        }



me->start_busy(2);

        return 1;
}
