// hongchen .剑破苍穹


string query_name() { return BGRN+BLK"剑破"ZJBR"苍穹"NOR; }
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        string wname;
	int delta;

        int ap, dp; if (userp(me) && ! me->query("can_perform/feixian-sword/jiandao"))

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("「剑破苍穹」只能对战斗中的对手使用。\n");

    if(me->query("con")<120||me->query("dex")<120||me->query("str")<120)
		return notify_fail("你的先天属性不够施展此等霸道招式。\n");

 	if (target->query("no_huaxue"))
		return notify_fail("此招对他无效。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("没装备剑怎么使用「剑破苍穹」？\n");
				
//	if (me->query("bieyunzsss", 1) < 10)
//		return notify_fail("你使用不了这招「剑破苍穹」，请移步赞助商城购买！\n");
		
        if (me->query_skill_mapped("sword") != "feixian-sword")
                return notify_fail("你没有激发飞仙剑，不能使用「剑破苍穹」。\n");


        if ((int)me->query_skill("feixian-sword", 1) < 300)
                return notify_fail("你的飞仙剑不够娴熟，还使不出「剑破苍穹」。\n");
if ((int)me->query_skill("martial-cognize") < 200)
                return notify_fail("你的武学修养境界不够，难以施展「剑破苍穹」。\n");

        if ((int)me->query("neili") < 2000)
               return notify_fail("你现在真气不够，难以施展「剑破苍穹」！"NOR"\n");

       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");
	if (me->query("gender") == "女性" &&
	    target->query("gender") != "无性")
		delta =  me->query("per") - target->query("per") / 2;
	else
		delta = 0;
        wname = weapon->name();
       ap = me->query("per") / 20;
//       damage = ((int)me->query_skill("feixian-sword", 1) + (int)me->query_skill("sword", 1)) * 15;

 //       damage *= ap;


        // 第一招
        ap = me->query_skill("sword"); 
        dp = target->query_skill("parry"); 
         msg = HIW "$N" HIW "诵曰："BLK HBYEL"----------万点剑芒---------- \n" NOR
	      HIW "$N" HIW "诵曰："BLK HBYEL"---飞仙剑阵----- \n" NOR
              HIW "$N" HIW "手中" + weapon->name() +"清吟" HIW "血光大方"HIW"，剑花飞扬中依次展现新月、残月、半月、满月等幻影，\n" NOR
              HIW "无数樱花从天地间$n" HIC" 围攻而去！\n" NOR;
        if (ap + random(ap) > dp)
        {
		damage = ap * 4 + random(ap * 2) + delta * 50;

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
                                           HIW "$p" HIW "奋力抵挡，却哪里招架得住？被$P"
                                           HIW "这一刀劈下，登时气喘吁吁！"NOR"\n");
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
                                           HIW "$p" HIW "奋力抵挡，却哪里招架得住？被$P"
                                           HIW "这一刀劈下，登时气喘吁吁！"NOR"\n");
//			target->receive_damage("qi",damage+400+(me->query_temp("apply/damage")+me->query("jingmai/damage"))*2*70+(me->query("str")+me->query("dex")+me->query("con")+me->query("int"))*100);
//			target->receive_wound("qi",damage+400+(me->query_temp("apply/damage")+me->query("jingmai/damage"))*2*70+(me->query("str")+me->query("dex")+me->query("con")+me->query("int"))*100);

        } else
        {
                msg += HBWHT "$p" CYN "嘿的一声，硬声声将$P"
                       HBMAG "这一下接下，不料这恰好正是飞仙剑法唯一生门，竟侥幸逃过一劫。"NOR"\n";
        }

        // 第二招
        ap = me->query_skill("sword"); 
        dp = target->query_skill("parry"); 
  
  	msg +=  HIW "$N" HIW "诵曰："BLK HBWHT"----------剑破苍穹---------- \n\n" NOR;
       	msg +=	HIW "$N" HIW "诵曰："BLK HBWHT"----------剑破苍穹之残心道法------ \n\n" NOR;
        msg +=  HIW "$N" HIW "顿时" + weapon->name() +"刀光一闪" HIY "光芒未暗，金芒又起"HIY"，一剑挥出，似乎永远没有终点。。\n\n" NOR;
	msg +=	BLK HBWHT "神圣光芒吞没了$n ！.\n\n" NOR;
        if (ap  + random(ap) > dp)
        {
			damage/=2;
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
                                          HIW "$p" HIW "始料不及，慌乱之中四处躲闪，刹那间已经身中数剑！"NOR"\n");
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
                                           HIW "$p" HIW "奋力抵挡，却哪里招架得住？被$P"
                                           HIW "这一刀劈下，登时气喘吁吁！"NOR"\n");
//			target->receive_damage("qi",damage+400+(me->query_temp("apply/damage")+me->query("jingmai/damage"))*2*70+(me->query("str")+me->query("dex")+me->query("con")+me->query("int"))*100);
//			target->receive_wound("qi",damage+400+(me->query_temp("apply/damage")+me->query("jingmai/damage"))*2*70+(me->query("str")+me->query("dex")+me->query("con")+me->query("int"))*100);
        } else
        {
                msg += HBWHT "$p" CYN "眉头一皱，浑然不将$P"
                HBWHT "玄妙的招数放在眼中，冷笑一声，竟没起到半点作用。"NOR"\n";
        }

        // 第三招
        ap = me->query_skill("sword"); 
        dp = target->query_skill("parry"); 
     
  	msg +=  HIW "$N" HIW "朱唇轻起：" HBRED"----------剑破苍穹----------  \n\n" NOR;	
  	msg +=  HIW "$N" HIW "口诵而曰：" HBRED"---------星星剑光---------- \n\n" NOR;
        msg +=  HIW "$N" HIR "抛起" + weapon->name() +"血光一闪" HIR "剑光飞舞"HIR"，侵蚀了天地。\n\n" NOR;
        msg +=  HIW "剑芒爆射，星星剑光笼罩$n!\n\n" NOR;
        if (ap + random(ap) > dp)
        {
			damage /= 2;

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
                                           HIW "$p" HIW "只觉神情恍惚，思绪拥动，悲欢离合百般滋味一一泛显，手脚逐渐缓慢下来！"NOR"\n");
//			target->receive_damage("qi",damage+(me->query_temp("apply/damage")+me->query("jingmai/damage"))*2*70+(me->query("str")+me->query("dex")+me->query("con")+me->query("int"))*100);
//			target->receive_wound("qi",damage+(me->query_temp("apply/damage")+me->query("jingmai/damage"))*2*70+(me->query("str")+me->query("dex")+me->query("con")+me->query("int"))*100);							   
        } else
        {
                msg += HIW "$p" HIW "一口冰凉的内气运起，$P"
                HBWHT "大惊之下呆若木鸡，却未能伤$p" HBWHT "分毫，居然躲开了。"NOR"\n";
        }



        me->start_busy(2);
        me->add("neili", -400 - random(100));
        message_combatd(msg, me, target);
        return 1;
}
