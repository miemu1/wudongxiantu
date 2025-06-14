// ban.c 狂风快剑天外狂龙

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "天外"ZJBR"狂龙";}
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int count,ap,dp,damage;
	int i;

	if (! target ) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("狂风快剑天外狂龙只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("kuangfeng-jian", 1) < 100)
		return notify_fail("你的狂风快剑不够娴熟，不会使用天外狂龙。\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("你的内功不够深厚，难以使用天外狂龙。\n");

	if (me->query("neili") < 100)
		return notify_fail("你现在的真气不够，无法使用天外狂龙。\n");

	if (me->query_skill_mapped("sword") != "kuangfeng-jian")
		return notify_fail("你没有激发狂风快剑，不能使用天外狂龙。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "剑斜斜刺出，激起股股剑气，拔剑，收剑。在那一瞬间，天地变幻，人影竟似已缩小，"
              "但见剑夹杂着风，风里含着剑影！那剑气幻作无数条金黄色的龙铺天盖地袭向$n！"NOR"\n";

	ap = me->query_skill("sword");
	dp = target->query_skill("force");

        if (ap / 2 + random(ap)> dp)
        {
		damage = (ap + random(ap / 2))*(me->query_skill("jianxin-tongming", 1)+100)/100;
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 90,
                                           HIR "$n" HIR "只觉得脑中轰的一下，身子往后倒飞出去，跌倒在地，不禁“哇”的吐了一口鲜血！" NOR"\n");
                me->start_busy(3);
		me->add("neili", -200);
        } else
        {
                msg += CYN "可$n" CYN "看破了$N" CYN "的狠毒企图，向旁跳开数步，躲开了$N" CYN "的这一波可怕的攻击！" NOR"\n";
                me->start_busy(3);
		me->add("neili", -200);
        }
        message_combatd(msg, me, target);

	return 1;
}
