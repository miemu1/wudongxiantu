// youran-bu.c  

#include <ansi.h>
inherit SKILL;
string *dodge_msg = ({
    HIM "$n漫不经心的向左迈出一步，刚好避过了这个凌厉的攻势。\n"NOR,
     YEL"可是$n恰巧往右走了一步，躲过了这一招。\n"NOR,
        WHT "但是$n身形飘忽，轻轻一纵，早已避开。\n"NOR,
         HIC"$n身随意转，倏地往一旁挪开了三尺，避过了这一招。\n"NOR,
       CYN "可是$n侧身一让，结果这一招扑了个空。\n"NOR,
       HIY "却见$n足不点地，往旁窜开数尺，躲了开去。\n"NOR,
         HIW"$n身形微晃，有惊无险地避开了这一招。\n"NOR,
});
int valid_enable(string usage) { return (usage == "dodge"); }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("youran-bu", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
string query_dodge_msg(string limb,object me)
{
        if (me) me->set_temp("fight/dodge",random(2*me->query_skill("youran-bu",1)));
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练悠然来往。\n");
        me->receive_damage("qi", 30);
        return 1;
}


