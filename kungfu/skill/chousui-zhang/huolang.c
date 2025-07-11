// 火浪

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "火浪掌"; }

int perform(object me, object target)
{
	int damage;
	int ap;
	string msg;
	int lvl;
	int fault;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("你只能对战斗中的对手施展火浪。\n");

	if ((int)me->query_skill("chousui-zhang", 1) < 220)
		return notify_fail("你的抽髓掌火候不够。\n");

	if ((int)me->query_skill("poison", 1) < 250)
		return notify_fail("你的基本毒技火候不够。\n");

	if ((int)me->query_skill("huagong-dafa", 1) < 220)
		return notify_fail("你的化功大法火候不够。\n");

	if ((int)me->query("max_neili") < 3000)
		return notify_fail("你的内力修为不足，无法用内力施展火浪。\n");

	if ((int)me->query("neili") < 3000)
		return notify_fail("你现在内息不足，无法用内力施展火浪。\n");

	if (! me->query_temp("powerup"))
		return notify_fail("你必须将全身功力尽数提起才能施展火浪。\n");

    if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "只见$N" HIR "双目血红，头发散乱，猛地仰天发出一声悲啸。\n\n"
	      "$N" HIR "把心一横，在自己舌尖狠命一咬，将毕生功力尽"
	      "数喷出，顿时只见空气中血雾弥漫，腥臭无比，随即又"
	      "听$N" HIR "骨骼“噼里啪啦”一阵爆响，双臂顺着喷出的"
	      "血柱一推，刹那间一座丈来高的奇毒火墙拔地而起，带"
	      "着排山倒海之势向$n" HIR "涌去！"NOR"\n";
	me->start_busy(3 + random(4));
	me->set("neili", 0);

	lvl = me->query_skill("chousui-zhang", 1);
	damage = 1000 + random(lvl * 3);

	fault = 0;
	if (me->query("max_neili") + random(me->query("max_neili")) < target->query("max_neili") * 18 / 10)
	{
		msg += WHT "$n" WHT "见状连忙提运内力，双臂猛"
		       "的推出，掌风澎湃，强大的气流顿时将火浪"
		       "刮得倒转，竟然掉头向$N" WHT "扑去。"NOR"\n";
		msg += HIR "$N" HIR "一声惨笑，长叹一声，摇摇欲坠，眼前不禁就是一黑。"NOR"\n";
		fault = 1;
	} else
	{
		ap = me->query_skill("poison", 1) + me->query_skill("force");
		if (ap / 2 + random(ap) < target->query_skill("dodge"))
		{
			msg += CYN "$n" CYN "见势不妙，急忙腾挪身形，避开了$N" CYN "的攻击。"NOR"\n";
			if (! target->is_busy())
				target->start_busy(5);
		} else
		{
			msg += HIR "$n" HIR "见滔天热浪扑面涌来，只觉眼前一片通红，已被卷入火浪，毒焰席卷全身，连骨头都要烤焦一般。"NOR"\n";
			target->affect_by("fire_poison",
				       ([ "level" : 10 + me->query_skill("force") + random(20),
					  "id"    : me->query("id"),
					  "duration" : 10 + lvl / 10 + random(lvl / 10) ]));
			target->receive_damage("qi", damage, me);
			target->receive_damage("jing", damage/4, me);
			if (! target->is_busy())
				target->start_busy(10);
		}
	}

	message_combatd(msg, me, target);
	me->want_kill(target);
	if (! target->is_killing(me)) target->kill_ob(me);

	return 1;
}
