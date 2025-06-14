
#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIB "六道剑心" NOR; }
string query_name() { return "六道"ZJBR"剑心"; }
inherit F_SSERVER;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("你只能用六道仙经来提升自己的战斗力。\n");

        if( me->query_temp("shield") )
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("sword");

        message_combatd(HIR "$N" HIR "暗运六道轮回真气，须臾，只见天边云开雾去，流光溢彩，一把气剑奔射而出，围绕在$N" HIR "四周。\n" NOR, me);

        // 打通BREAKUP后的效果增加10%
        if( me->query("breakup"))skill=skill+skill*1/10;
     
        me->add_temp("apply/armor", skill*2/3);
        me->add_temp("apply/parry", skill*2/3);
		me->add_temp("apply/attack", skill*2/3);
        me->add_temp("apply/damage", skill*2/3);
        me->set_temp("shield", 1);
        me->start_call_out((: call_other, __FILE__, "remove_effect",
                              me, skill :), skill / 2);

        if (me->is_fighting()) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if (! objectp(me))return;

        if( me->query_temp("shield") )
        {
                me->add_temp("apply/armor", -(amount*2/3));
                me->add_temp("apply/parry", -(amount*2/3));
		        me->add_temp("apply/attack", -(amount*2/3));
                me->add_temp("apply/damage", -(amount*2/3));
                me->delete_temp("shield");
                tell_object(me, HIW "你的六道仙经「六道剑心」运行完毕，将内力收回丹田。\n" NOR);
        }


}