// poqiang.c 「破枪式」

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp, damage;
int i, lvl;
//        if(me->query("family/master_id") != "feng qingyang"
//        && userp(me))
//           return notify_fail("你不是风清扬的弟子，不能使用绝招！\n");
     if( (int)me->query_skill("zixia-shengong",1)<100)
            return notify_fail("独孤九剑必须配合紫霞神功。\n");

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("lonely-jian",1);

        if( !(me->is_fighting() ))
            return notify_fail("「破枪式」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");

        if (!objectp(weapon2 = target->query_temp("weapon"))
        || ((string)weapon2->query("skill_type") != "staff"
        && (string)weapon2->query("skill_type") != "club"))
            return notify_fail("对方没有使枪棒，你用不了「破枪式」。\n");

        if( skill < 50)
            return notify_fail("你的独孤九剑等级不够, 不能使用「破枪式」！\n");

        if( me->query("neili") < 50 )
            return notify_fail("你的内力不够，无法运用「破枪式」！\n");

        msg = HIC "$N一式独孤九剑「破枪式」，剑势灵巧地顺着"+weapon2->name()
+"削落，划向$n的五指。\n";
        message_combatd(msg, me, target);
        damage = 10 + random(skill / 2);
        ap = me->query_skill("sword");
        if((string)weapon2->query("skill_type") == "staff")
            dp = target->query_skill("staff") / 2;
        else if((string)weapon2->query("skill_type") != "club")
            dp = target->query_skill("club") / 2;

        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
            if(userp(me))
                 //me->add("neili",-50);
            msg = "$N运起「破枪式」, $n顿时大惊，为保手指，手中";
            msg += weapon2->name();
            msg += "撒手丢出！\n" NOR;

            me->start_busy(1);
            target->receive_damage("qi", damage,me);
            target->start_busy(2);
if (!weapon2->query("systemmake") && !weapon2->query("ownmake"))
{
            weapon2->move(environment(me));
}
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
            msg = "可是$n看破了$N的剑路，舍命将手中" + weapon2->name()+
"向前急刺，迫使$N收回攻势！\n"NOR;
            //me->start_busy(2);
		message_combatd(msg, me, target);
        }

me->start_busy(2);
        return 1;
}
