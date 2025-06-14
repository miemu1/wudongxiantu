// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

#define RI "「" HIW "日照无华" NOR "」"
string query_name() { return "日照"ZJBR"无华"; }
int perform(object me)
{
        object *obs;
        string msg;
        int damage;
        int ap, dp;
        int flag;
        int i;
        int p;

        me->clean_up_enemy();
        if (! me->is_fighting())
                return notify_fail(RI "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(RI "只能空手施展。\n");
                
        if (me->query("max_neili") < 8000)
                return notify_fail("你的内力的修为不够，现在无法使用" RI "。\n");

        if (me->query_skill("tiandaoquan", 1) < 800)
                return notify_fail("你的天道拳还不够娴熟，难以施展" RI "。\n");

        if (me->query_skill("force", 1) < 600)
                return notify_fail("你的内功还不够娴熟，难以施展" RI "。\n");

        if (me->query_skill_mapped("unarmed") != "tiandaoquan")
                return notify_fail("你现在没有激发天道拳为拳脚，难以施展" RI "。\n");

        if (me->query_skill_prepared("unarmed") != "tiandaoquan")
                return notify_fail("你现在没有准备使用天道拳，难以施展" RI "。\n");

        if ((int)me->query("neili") < 2000)
                return notify_fail("你的真气不够，无法运用" RI "。\n");

        msg = HIY "只见$N" HIY "双目微闭，单手托天。掌心顿时腾起一个无比刺眼的"
              "气团，正是奥\n义「" NOR + HIW "日照无华" NOR + HIY "」。霎时"
              "金光万道，尘沙四起，空气炽热，几欲沸腾。$N" HIY "\n随即收拢掌心"
              "，气团爆裂开来，向四周电射而出，光芒足以和日月争辉。\n\n" NOR;

        message_combatd(msg, me);

        me->add("neili", -1000);
       me->start_busy(3 + random(3));

         ap = me->query_skill("unarmed") + me->query_skill("force") + me->query_skill("martial-cognize",1) + me->query("str");

        obs = me->query_enemy();
        for (flag = 0, i = 0; i < sizeof(obs); i++)
        {
                dp = obs[i]->query_skill("force") + obs[i]->query_skill("martial-cognize",1) + obs[i]->query_skill("dodge");

                if (ap * 4 / 5 + random(ap) > dp)
                {
                        switch (random(2))
                        {
                        case 0:
                                tell_object(obs[i], HIR "你只觉眼前金光万道，周围空气几欲沸"
                                                    "腾，光芒便如利箭一般透体而入。\n" NOR);
                                break;

                        default:
                                tell_object(obs[i], HIR "你只觉眼前金光万道，周围空气几欲沸"
                                                    "腾，光芒便如千万细针一齐扎入身体般。\n"
                                                    NOR);
                                break;
                        }

                         damage = ap * 2 + random(ap);

                        obs[i]->receive_damage("qi", damage * 3 / 2, me);
                        obs[i]->receive_wound("qi", damage * 3 / 2, me);

                        obs[i]->receive_damage("jing", damage / 5, me);
                        obs[i]->receive_wound("jing", damage / 5, me);

                        p = (int)obs[i]->query("qi") * 100 / (int)obs[i]->query("max_qi");

                        switch (random(5))
                        {
                        case 0:
                                msg = HIR "只听" + obs[i]->name() +
                                      HIR "一声惨嚎，接连退了数步，“"
                                      "哇”的呕出一大口鲜血。\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;

                        case 1:
                                msg = HIR "只见" + obs[i]->name() +
                                      HIR "向后飞出丈远，重重的跌落在"
                                      "地上，衣衫烧焦，再也没力气站起"
                                      "。\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;

                        case 2:
                                msg = HIR "只见" + obs[i]->name() +
                                      HIR "跌跌撞撞向后连退数步，伏倒"
                                      "在地。须眉、衣衫都发出一股焦臭"
                                      "。\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;

                        case 3:
                                msg = HIR "光芒闪过，" + obs[i]->name() +
                                      HIR "却是呆立当场，动也不动，七"
                                      "窍流血，神情扭曲，煞是恐怖。\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;

                        default:
                                msg = HIR + obs[i]->name() +
                                      HIR "急忙抽身后退，可只见眼前光"
                                      "芒暴涨，一闪而过。全身已多了数"
                                      "个伤口，鲜血飞溅。\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;
                        }
                        if (! obs[i]->is_busy())
                        obs[i]->start_busy(1);
                        message("vision", msg, environment(me), ({ obs[i] }));
                        obs[i]->add("neili", -500);
                        flag = 1;
                } else
                {
                        tell_object(obs[i], HIY "你只觉眼前金光万道，周围空气几"
                                            "欲沸腾，大惊之下连忙急运内功，抵御"
                                            "开来。\n" NOR);
                }
                if (obs[i]->query("neili") < 0)
                        obs[i]->set("neili", 0);
        }

        if (! flag) 
                message_vision(HIY "只见光芒顿敛，却没有任何人被$N"
                               HIY "这招击中。\n\n" NOR, me, 0, obs);

        return 1;
}

