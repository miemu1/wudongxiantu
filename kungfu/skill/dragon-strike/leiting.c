// leiting.c 「雷霆一击」

#include <ansi.h>
#include <combat.h>

#define LEITING "「" HIY "雷霆一击" NOR "」"

inherit F_SSERVER;

string query_name() { return "雷霆"ZJBR"一击"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me, object target)
{
	int damage;
	string msg;
	int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail(LEITING "只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("force") < 250)
		return notify_fail("你的内功火候不够，使不出" LEITING "。\n");

	if ((int)me->query_skill("dragon-strike", 1) < 170)
		return notify_fail("你的降龙十八掌不够熟练，不会使用" LEITING "。\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你的真气不够，无法使用" LEITING "。\n");

	if (me->query_skill_mapped("strike") != "dragon-strike")
		return notify_fail("你没有激发降龙十八掌，无法使用" LEITING "。\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "默运内功，施展出" LEITING HIC "，全身急速转动起来，"
	      "越来越快，就犹如一股旋风，骤然间，$N" HIC "已卷向正看"
	      "得发呆的" HIC "$n。"NOR"\n";  

	ap = me->query_skill("strike")+me->query_skill("taiji-shengong")+me->query_skill("liangyi-yinyangjue");
	dp = target->query_skill("force")+target->query_skill("taoism")+target->query_skill("liangyi-yinyangjue");
	me->start_busy(3);
	if (ap / 2 + random(ap) > dp)
	{ 
		damage = ap + random(ap / 2);
		me->add("neili", -400);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 90,
					   HIR "$p" HIR "只见一阵旋风影中陡然现出$P"
					   HIR "的双掌，根本来不及躲避，被重重击中，五"
					   "脏六腑翻腾不休，口中鲜血如箭般喷出！！！"NOR"\n");
	} else
	{
		msg += HIG "可是$p" HIG "看破了$P" HIG "的企图，没"
		       "有受到迷惑，闪在了一边。"NOR"\n";
	}
	message_combatd(msg, me, target);
	
	if (me->query_skill("bixue-danxin", 1) > 49 ) 
	{
        msg = HIW "$N" HIW "右掌斜挥，前招掌力未消，此招掌力又到，竟然又攻出一招「" HIR "亢龙有悔" HIW "」，掌夹风势，势如破竹，"
              HIW "便如一堵无形气墙，向前疾冲而去。$n" HIW "只觉气血翻涌，气息沉浊。\n" NOR;

	if (ap / 2 + random(ap) > dp)
	{
		damage = (ap + random(ap / 2))*(me->query_skill("bixue-danxin", 1)+100)/100;
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
                                          HIR "结果$n" HIR "躲闪不及，掌劲顿时穿胸而过，口中鲜血狂喷。\n" NOR);

		me->add("neili", -300);
		message_combatd(msg, me, target);

		return 1;
	}

                msg += HIC "$p眼见来势凶猛，身形疾退，瞬间"
                       "飘出三丈，脱出掌力之外。\n" NOR;
	message_combatd(msg, me, target);
	}

	return 1;
}

