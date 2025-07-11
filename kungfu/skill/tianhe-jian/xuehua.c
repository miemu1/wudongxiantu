// fenfei.c 雪花太山
 
#include <ansi.h>

string query_name() { return "雪花"ZJBR"太山"; }

inherit F_SSERVER;

int perform(object me)
{
        string msg, msg_1, msg_2;
        object weapon, target;
        object ob;
        int skill, skill2, skill3, skill4, skill5;
        int neili_wound, qi_wound, count, count_2, i;

if( me->query("family/family_name") != "血河派" ) 
            return notify_fail("你不理解血河派的信念，怎么用的出他们的武功。\n"); 
        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("sword");
        skill2 = me->query_skill("force");
        skill3 = me->query_skill("dodge");
        if (target)
        {
                skill4 = target->query_skill("parry");
                skill5 = target->query_skill("dodge");
        }

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("笨蛋，不使剑怎么能使「雪花太山」？\n");

        if( !me->is_fighting()|| !living(me) )
                return notify_fail("「雪花太山」只能在战斗中使用。\n");

        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("你的内力修为还不够高！\n");

        if( (int)me->query("neili") < 2000 )
                return notify_fail("你现在的内力不足！\n");

        if( me->query_skill_mapped("sword") != "tianhe-jian") 
                return notify_fail("你没有激发天河剑法，无法使用「雪花太山」！\n");

        if( skill < 150 )
                return notify_fail("你天河剑法的修为不够，不能使用「雪花太山」! \n");

        if( skill2 < 120)
                return notify_fail("你内功修为不够，不能使用「雪花太山」! \n");
 
        if( skill3 < 150)
                return notify_fail("你的轻功太差，不能使用「雪花太山」! \n");

        msg = HIW "\n$N怒啸一声，左刺右刺，前刺後刺，左刺右刺，这是「雪花太山」，即封死了$n的退路，虚虚实实十一剑，分袭$n。\n\n"NOR;
        message_vision(msg, me, target);
        ob = me->query_temp("weapon");

        if (skill < 240 || skill3 < 240)
        {
                if (random(me->query_dex() * skill3) > random(target->query_dex() * skill5 / 2))
                {
                        msg_1 = "$n看着满眼的剑光，已经无暇顾及判断哪剑是实、哪剑是虚了。\n";
                        msg_2 = "$n只得硬起头皮，向着其中的一道剑光挡了上去。\n";
                        count = 1;
                }
                else
                {
                        msg_1 = "$n一瞥之间便已明了，这虚虚实实十一剑只有一剑是实招，其他皆是虚招。\n";
                        if (random(skill * skill3) > random(skill4 * skill5 / 2))
                                msg_2 = "$n虽然看出了一实十虚，却无法找到真正杀招之所在，只得硬起头皮，向着其中的一道剑光挡了上去。\n";
                        else msg_2 = "$n的眼光实在是敏锐之极，电光星闪之间已经判断到了$N真正杀招之所在，毫不犹豫的挡了上去。\n";
                        count = 1;
                }
        }
        else if (skill < 360 || skill3 < 360)
        {
                if (random(me->query_dex() * skill3) > random(target->query_dex() * skill5 / 2))
                {
                        msg_1 = "$n看着满眼的剑光，已经无暇顾及判断哪剑是实、哪剑是虚了。\n";
                        msg_2 = "$n只得硬起头皮，向着其中的几道剑光胡乱的挡了上去。\n";
                        count = 12;
                }
                else
                {
                        msg_1 = "$n一瞥之间心中不禁一惊，由于$N的剑移动得极快，这虚虚实实十一剑居然有六剑皆实招，实在难防之极。\n";
                        if (random(skill * skill3) > random(skill4 * skill5 / 2))
                                msg_2 = "$n虽然看出了五虚六实，却无法找到真正杀招之所在，只得硬起头皮，向着其中的几道剑光胡乱的挡了上去。\n";
                        else msg_2 = "$n的眼光实在是敏锐之极，电光星闪之间已经判断到了$N真正杀招之所在，毫不犹豫的挡了上去。\n";
                        count = 6;
                }
        }
        else
        {
                if (random(me->query_dex() * skill3) > random(target->query_dex() * skill5 / 2))
                {
                        msg_1 = "$n看着满眼的剑光，已经无暇顾及判断哪剑是实、哪剑是虚了。\n";
                        msg_2 = "$n只得硬起头皮，向着其中的几道剑光胡乱的挡了上去。\n";
                        count = 22;
                }
                else
                {
                        msg_1 = "$N这招一出$n不禁大惊失色，原来这这虚虚实实十一剑变幻无常，不停的实变虚、虚变实，根本无从判断。\n";
                        msg_1 = "$n知道对这十一剑的判断毫无意义，便毫不犹豫的向着所有剑光迎了上去。\n";
                        count = 11;
                }
        }

        message_vision(HIC + msg_1 + msg_2 + "\n" + NOR, me, target);

        for (i=0;i<count;i++)
        {
                if (random(skill*skill3*me->query_str()) > random(skill4*skill5*target->query_str()/2))
                        count_2 ++;
                if (count_2 > 6) count_2 = 6;
        }

        if (count_2 == 0)
                msg = HIG"一时间剑光人影交织在一起，叮叮当当一阵乱响之后，$N的这一式「雪花太山」竟然被$n完全封了下来，一剑未中。\n\n"NOR;
        else if (count_2 == 1)
                msg = HIM"一时间剑光人影交织在一起，然后只听一声闷哼，人影陡然分开。\n"
                        + "只见$n身上已经渐渐渗出了血迹，虽然$n奋力招架，毕竟还是有一剑透过了重重防御刺中了$n。\n"NOR;
        else if (count_2 == 2 || count_2 == 3)
                msg = HIM"一时间剑光人影交织在一起，然后只听一声闷哼，人影陡然分开。\n"
                        + "只见$n身上鲜血喷涌，原来虽然$n奋力招架，但虚虚实实的「雪花太山」还是有"
                        + chinese_number(count_2) + "剑刺中了$n。\n"NOR;
        else if (count_2 == 4 || count_2 == 5)
                msg = HIR"一时间剑光人影交织在一起，然后只听一声惨叫，人影陡然分开。\n"
                        + "只见$n身上数道鲜血喷涌而出，$n的招架已经形同虚设，虚虚实实的「雪花太山」竟然有"
                        + chinese_number(count_2) + "剑刺中了$n。\n"NOR;
        else
                msg = HIR"一时间剑光人影交织在一起，然后只听一声惨叫，人影陡然分开，$n已经摇摇欲倒了。\n"
                        + "只见$n已经几乎变成了一个血人，虚虚实实的「雪花太山」的"
                        + chinese_number(count_2) + "招实招剑无虚发，全部刺中了$n。\n"NOR;

        message_vision(msg, me, target);
        qi_wound = (skill + random(skill2)) * count_2 / 2;

        if(qi_wound > target->query("qi")) qi_wound = (target->query("qi") + 1);
        target->add("qi", -qi_wound);
        target->add("eff_qi", -(qi_wound/4));
        if (count_2) COMBAT_D->report_status(target, 0);
        me->start_busy(3 + random(2));
        me->add("neili",-(500 * count_2));

        return 1;
}

    
    
