// po.c 破字诀

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "破字"ZJBR"真诀"; }

int perform(object me, object target)
{
	string msg;
	object weapon, weapon2;
	int n,i;
	int skill, skill2, ap, dp, damage;
	string type;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	skill = me->query_skill("never-defeated", 1);

	skill2 = me->query_skill("martial-cognize", 1);

	if (! me->is_fighting(target))
		return notify_fail("破字诀只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必须手持兵刃才能施展破字诀！\n");

	type = weapon->query("skill_type");
	if (me->query_skill(type, 1) < 150)
		return notify_fail("你的" + to_chinese(type) + "水平有限，无法施展破字诀！\n");

	if (me->query_skill_mapped(type) != "never-defeated")
		return notify_fail("你没有激发不败神功，无法施展破字诀！\n");

	if (skill < 100)
		return notify_fail("你的不败神功等级不够，无法施展破字诀！\n");

	if (me->query("neili") < 150)
		return notify_fail("你现在真气不够！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	me->add("neili", -100);

	if(userp(target)) ap = me->query_skill(type) + skill2 + me->query_skill("count",1);
	else ap = me->query_skill(type) + me->query_skill("count",1);
	dp = target->query_skill("parry") +
	     target->query_skill("martial-cognize", 1);

	n = 4 + random(4);

	msg = HIC "$N" HIC "手中" + weapon->name() +
	      HIC "一抖，犹如夜雨流星，连出" + chinese_number(n) + "招攻向$n"
	      HIC "，没有半点规矩可循。"NOR"\n";
	message_combatd(msg, me, target);

	me->add_temp("apply/damage", skill/5);
	for (i = 0; i < n; i++)
		      {
		            if (! me->is_fighting(target))
			            break;
				if (random(2) && ! target->is_busy())
					target->start_busy(1);
				COMBAT_D->do_attack(me, target, weapon, 0);
			}
	me->add_temp("apply/damage", -skill/5);

      if (living(target)) {
			weapon2 = target->query_temp("weapon");
			if (weapon2 && random(ap) / 2 > dp && weapon2->query("type") != "pin")
			{
				msg = HIW "$n" HIW "觉得眼前眼花缭乱，手中的" + weapon2->name() +
				      HIW "一时竟然拿捏不住，脱手而出！"NOR"\n";
				weapon2->move(environment(me));
	                  message_combatd(msg, me, target);
			} 

	msg = HIY "$N" HIY "这" + chinese_number(n) + "招即巧又拙，不同于其他任何招式。"NOR"\n";

	if (ap / 2 + random(ap) > dp) {
			msg += HIY "$n" HIY "不禁大为慌乱，一时破绽迭出，竭力遮挡，全然无法反击。"NOR"\n";
			target->start_busy(3 + random(skill / 50));
			if (random(10)==8 && target->query("jiuyin-shengong")>me->query("never-defeated"))
			{
			msg += HIW "$n" HIW "貌似抵挡住了此次忙乱效果。"NOR"\n";						
			target->start_busy(0);	
			}		
	} else
	{
		msg += HIC "不过$n" HIC "一丝不苟，严守门户，没有露出半点破绽。"NOR"\n";

	}
	message_combatd(msg, me, target);
      }
	me->start_busy(4 + random(3));
	return 1;
}
