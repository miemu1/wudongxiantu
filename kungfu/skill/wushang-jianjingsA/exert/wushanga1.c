// zongjue.c

#include <ansi.h>
string query_name() { return BYEL+HIR"无尽"ZJBR"剑域"NOR; }
inherit F_CLEAN_UP;

int check_fight(object me);
void remove_effect(object me, int skill);

int exert(object me, object target)
{
        int skill;
        if( target != me ) return
            notify_fail("你只能对自己用["+HIB+"无尽剑域·"+NOR+"]\n"NOR,);

	if ((int)me->query_skill("wushang-jianjingsAA", 1) < 300)
		return notify_fail("你的无上剑经太差了。\n");

        if( (int)me->query("neili") < 1000 )
        	return notify_fail("你的内力不够。\n");
		
	        if( (int)me->query("qi") < 1000 )
        	return notify_fail("你的气血不够。\n");

        if( (int)me->query_temp("jiuyin/powerup") )
        	return notify_fail("你已经在运功中了。\n");

	me->set_temp("jiuyin/powerup", 1);
        skill = me->query_skill("sword");

        me->add("neili", -1000);
        me->add("qi", -1000);
        me->receive_damage("qi",0);

        message_combatd(HIC"$N运起了无尽剑域，你的属性陡然大增！\n" NOR, me);
        me->add_temp("apply/damage", skill*5/2);
        tell_object(me, HIG"你的伤害提升了。\n"NOR);
        me->add_temp("apply/2ap", skill*5/2);
        tell_object(me, HIG"你的暴击提升了。\n"NOR);
        me->add_temp("apply/2dp", skill*5/2);
        tell_object(me, HIG"你的抗暴提升了。\n"NOR);
        me->add_temp("apply/break", skill*5/2);
        tell_object(me, HIG"你的破甲提升了。\n"NOR);
	    check_fight(me);
        me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill:),skill);
        if( me->is_fighting() ) me->start_busy(2);
        return 1;
}

int check_fight(object me)
{
	if (!me || !(int)me->query_temp("jiuyin/powerup")) return 0;
        if (!me->is_ghost() && living(me)
            && me->is_fighting() && me->query("neili") > 500
            && me->query_skill_mapped("sword") == "wushang-jianjingsAA")
        {
                if(me->query("qi") < (int)me->query("max_qi")){
                        message_vision(HIY"$N脸色一沈又回复正常，想是正在调节内息。\n"NOR,me);
                        me->add("neili", -10000);
                        me->add("eff_qi",me->query_skill("sword")/2);
			if (me->query("eff_qi") > me->query("max_qi")) me->set("eff_qi", me->query("max_qi"));
                        me->add("qi",me->query_skill("sword"));
			if (me->query("qi") > me->query("eff_qi")) me->set("qi", me->query("eff_qi"));
                        }
        }
        call_out("check_fight", 2, me);
        return 1;
}

void remove_effect(object me, int skill)
{
        me->delete_temp("jiuyin/powerup");
        me->add_temp("apply/damage", -skill*5/2);
        me->add_temp("apply/2ap", -skill*5/2);
        me->add_temp("apply/2dp", -skill*5/2);
        me->add_temp("apply/break", -skill*5/2);
        tell_object(me, "你的["+HIB+"无尽剑域"+NOR+"]运行完毕，将内力收回丹田。\n");
}

