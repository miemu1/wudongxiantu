#include <ansi.h>
#include <combat.h> 
	 
inherit F_SSERVER; 
	 
string query_name() { return "[古秘术]"ZJBR"囚天指"; }
string *pfm_type() { return ({ "finger", }); }

int perform(object me, object target) 
{ 
	object weapon; 
	string msg; 
	int ap, dp; 
	int damage; 
	
	if (! target) target = offensive_target(me); 
	
	if (! target || ! me->is_fighting(target)) 
		return notify_fail("「古秘术·囚天指」只能在战斗中对对手使用。\n"); 
	 
	if (me->query_skill("force") < 600) 
		return notify_fail("你的内功的修为不够，不能使用「古秘术·囚天指」！\n"); 
	
	if (me->query_skill("shanggu-mijings", 1) < 100) 
		return notify_fail("你的上古秘经修为不够，目前不能使用「古秘术·囚天指」！\n"); 

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "眼中神光湛湛，双手平伸，陡然使出「" HIR "古秘术·囚天指" HIY "」绝技，只见天地间只剩一只手指点向"
              "$n！\n" NOR;
	 
	ap = me->query_skill("finger") + me->query_skill("force"); 
	dp = target->query_skill("dodge") + target->query_skill("parry"); 
	 
	if (ap / 2 + random(ap) > dp) 
	{ 
		damage = ap *100 + random(ap / 3*100); 
		me->add("neili", -500);
		me->start_busy(1);
		msg +=HIM "$n眼见巨指袭来，避无可避，躲无可躲，只得闭目受死。刹那间被巨指吞没，软瘫在地。\n" NOR;
	} else 
	{ 
		me->add("neili", -100); 
		me->start_busy(1);
		msg += NOR + CYN "$n眼见巨指袭来，竟毫无畏惧，双掌抓向巨指，掌中使力之下，那巨指竟就此散碎了。\n" NOR;
	} 
	message_combatd(msg, me, target); 
	 
	return 1; 
}

