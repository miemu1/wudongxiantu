#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string attack1(object me, object target, int damage);
string attack2(object me, object target, int damage);
string attack3(object me, object target, int damage);
string attack4(object me, object target, int damage);
string attack5(object me, object target, int damage);
string attack6(object me, object target, int damage);

string name() { return HIR "六道轮回" NOR; }
string query_name() { return "六道"ZJBR"轮回"; }
int perform(object me, object target)
{
        object weapon;
        string wn, msg;
        object sroom, room;
        int ap, dp, damage;
        int wait_time;
        int in_shejingdong;

        /*
        // 检查是否经过赛神龙效果过轮回点6点
        if( !query("scborn/perform_zhen_saishenlong", me) && !query("thborn/ok", me) )
        {
                // 轮回点大于6则自动扣除并设置标志
                if( query("scborn/cur_lunhui_point", me) >= 6 )
                {
                        addn("scborn/cur_lunhui_point", -6, me);
                        set("scborn/perform_zhen_saishenlong", 1, me);
                        me->save();
                }
                // 否则无法施展该招
                else
                        return notify_fail("对不起，由于你的轮回点有问题，你暂时无法施展该招，详情参见新闻。\n");
        }
        */

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能对战斗中的对手使用。\n");

        if( !objectp(weapon=me->query_temp("weapon") )
            || weapon->query("skill_type") != "sword" )
                return notify_fail("你使用的武器不对，难以施展" + name() + "。\n");

        if( me->query("max_neili")<10000 )
                return notify_fail("你的内力修为不够，难以施展" + name() + "。\n");

        if ((int)me->query_skill("buddhism", 1) < 500)
                return notify_fail("你对禅宗心法参悟不够，难以施展" + name() + "。\n");

        if ((int)me->query_skill("lunhui-sword", 1) < 300)
                return notify_fail("你六道仙经火候不够，难以施展" + name() + "。\n");

        if( me->query("neili")<4000 )
                return notify_fail("你现在真气不够，难以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        wait_time = 30;

        if (me->query_skill("lunhui-sword", 1) >= 300)
                wait_time = 22;

        if (me->query_skill("lunhui-sword", 1) >= 400)
                wait_time = 14;

        if (me->query_skill("lunhui-sword", 1) >= 600)
                wait_time = 6;

        if( time()-me->query_temp("last_perform_zhen")<wait_time )
                return notify_fail("你刚施展过" + name() + "，体内真气还没有完全顺畅，此时不宜强行运功。\n");


        wn = weapon->name();

        message_combatd(HIW "$N" HIW "面露拈花之意，祭起手中" + wn +
                        HIW "，霎时碧波流转，华光万丈，说不尽的祥和。"
                        "\n" NOR, me, target);

        //  记录下最初的房间
        if (! objectp(sroom = environment(me)))
                return 1;

        if (base_name(sroom) == "/d/shenlong/shejingdong" ||
            base_name(sroom) == "/d/shenlong/huodong1" ||
            sroom->query("fight_room") )
                in_shejingdong = 1;

        ap = me->query_skill("sword");
        dp = target->query_skill("force");

        damage = me->query_skill("sword")*3;

        // 六道轮回之人间道
        room = find_object("/d/death/liudaolunhui/rendao");
        if (! room) room = load_object("/d/death/liudaolunhui/rendao");

        if (! in_shejingdong)me->move(room);
        if (! in_shejingdong)target->move(room);

        message_combatd(HIY "\n$N" HIY "左手轻轻一拨，右手所持的" + wn +
                       HIY "叮呤做响，剑姿说不出的潇洒妙曼。\n" NOR, me, target);

        if (ap * 4 / 5 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 200,
                                           (: attack1, me, target, damage :));
        } else
        {
                msg = CYN "可是$n" CYN "收敛心神，奋力招"
                      "架，将剑招卸于无形。\n" NOR;
        }
        message_combatd(msg, me, target);

        // 六道轮回之畜生道
        room = find_object("/d/death/liudaolunhui/chushengdao");
        if (! room) room = load_object("/d/death/liudaolunhui/chushengdao");

        if (! in_shejingdong)me->move(room);
        if (! in_shejingdong)target->move(room);

        message_combatd(HIY "\n却见$N" HIY "面无表情，将手中" + wn +
                       HIY "猛的往前一递，犹如毒蛇般噬向$n" HIY "。\n"
                       NOR, me, target);

        if (ap * 4 / 5  + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 200,
                                           (: attack2, me, target, damage :));
        } else
        {
                msg = CYN "可是$n" CYN "收敛心神，奋力招"
                      "架，将剑招卸于无形。\n" NOR;
        }
        message_combatd(msg, me, target);

        // 六道轮回之饿鬼道
        room = find_object("/d/death/liudaolunhui/eguidao");
        if (! room) room = load_object("/d/death/liudaolunhui/eguidao");

        if (! in_shejingdong)me->move(room);
        if (! in_shejingdong)target->move(room);

        message_combatd(HIY "\n$N" HIY "一声长叹，左手捏着剑诀，忽闻" +
                       wn + HIY "上血腥之气渐浓，朝$n" HIY "迎头斩落。\n"
                       NOR, me, target);

        if (ap * 4 / 5  + random(ap) > dp)
        {
                if( target->query("death_skill/guimai") )
                        msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage / 2, 100,
                                                   (: attack3, me, target, damage :));
                else

                        msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 300,
                                                   (: attack3, me, target, damage :));
        } else
        {
                msg = CYN "可是$n" CYN "收敛心神，奋力招"
                      "架，将剑招卸于无形。\n" NOR;
        }
        message_combatd(msg, me, target);

        // 六道轮回之修罗道
        room = find_object("/d/death/liudaolunhui/xiuluodao");
        if (! room) room = load_object("/d/death/liudaolunhui/xiuluodao");

        if (! in_shejingdong)me->move(room);
        if (! in_shejingdong)target->move(room);

        message_combatd(HIY "\n忽见$N" HIY "身形微晃，顿时幻出十数个身"
                       "影，十数柄" + wn + HIY "齐向$n" HIY "刺去。"
                       "\n" NOR, me, target);

        if (ap * 4 / 5  + random(ap) > dp)
        {
                if( target->query("death_skill/lonely") )
                        msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage / 2, 100,
                                                   (: attack4, me, target, damage :));
                else

                        msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 400,
                                                   (: attack4, me, target, damage :));
        } else
        {
                msg = CYN "可是$n" CYN "收敛心神，奋力招"
                      "架，将剑招卸于无形。\n" NOR;
        }
        message_combatd(msg, me, target);

        // 六道轮回之地狱道
        room = find_object("/d/death/liudaolunhui/diyudao");
        if (! room) room = load_object("/d/death/liudaolunhui/diyudao");

        if (! in_shejingdong)me->move(room);
        if (! in_shejingdong)target->move(room);

        message_combatd(HIY "\n紧接着$N" HIY + wn + HIY "一颤，有若龙吟"
                       "，剑身腾起一道滔天寒流，向四周扩散开去。\n" NOR,
                       me, target);

        if (ap * 4 / 5 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 500,
                                           (: attack5, me, target, damage :));
        } else
        {
                msg = CYN "可是$n" CYN "收敛心神，奋力招"
                      "架，将剑招卸于无形。\n" NOR;
        }
        message_combatd(msg, me, target);

        // 六道轮回之天极道
        room = find_object("/d/death/liudaolunhui/tiandao");
        if (! room) room = load_object("/d/death/liudaolunhui/tiandao");

        if (! in_shejingdong)me->move(room);
        if (! in_shejingdong)target->move(room);

        message_combatd(HIY "\n$N" HIY "身外化身，剑外化剑，手中" + wn +
                       HIY "便似蛟龙腾空，拨云见日，天地为之失色。\n"
                       NOR, me, target);

        if (ap * 4 / 5 + random(ap) > dp)
        {
                if( target->query("death_skill/emperor") )
                        msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage / 2, 100,
                                                   (: attack6, me, target, damage :));
                else

                        msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 600,
                                                   (: attack6, me, target, damage :));
        } else
        {
                msg = CYN "可是$n" CYN "收敛心神，奋力招"
                      "架，将剑招卸于无形。\n" NOR;
        }
        message_combatd(msg, me, target);

        me->start_busy(4 + random(4));
        me->add("neili", -4000);
        me->set_temp("last_perform_zhen", time());

        // 为什么提行？为了画面更为赏心悦目而已
        tell_object(me, "\n\n");
        tell_object(target, "\n\n");

        // 转移回最初的房间
        if (! in_shejingdong)me->move(sroom);
        if (! in_shejingdong)target->move(sroom);

        return 1;
}

string attack1(object me, object target, int damage)
{
        string msg;

        msg = HIR "$n" HIR "只觉心头一阵凄苦，竟忍不住要落"
              "下泪来，喉咙一甜，呕出一口鲜血。\n" NOR;

        if( !target->query_temp("liudaolunhui") )
        {
                msg += WHT "$p忽然察觉到全身的力气竟似一丝"
                       "丝远离自己而去，无助之极。\n" NOR;

                target->add_temp("apply/attack", -damage/10);
                target->add_temp("apply/parry", -damage/10);
                target->add_temp("apply/dodge", -damage/10);

                if( target->query_temp("apply/attack")<0 )
                        target->set_temp("apply/attack", 0);
                if( target->query_temp("apply/parry")<0 )
                        target->set_temp("apply/parry", 0);
                if( target->query_temp("apply/dodge")<0 )
                        target->set_temp("apply/dodge", 0);

                target->set_temp("liudaolunhui", 1);
        }
        return msg;
}

string attack2(object me, object target, int damage)
{
        object weapon;
        string wn, msg;

        msg = HIR "忽然间$n" HIR "感到胸口处一阵火热，剑气"
              "袭体，带出一蓬血雨。\n" NOR;

        if( objectp(weapon=target->query_temp("weapon")) )
        {                
                wn = weapon->name();
                msg += WHT "忽听「锵锵锵」几声脆响，$n" WHT "的" + wn +
                       WHT "竟被$N" WHT "绞成了块块碎片。\n" NOR;

                weapon->set("consistence", 0);
                weapon->move(target);
        }
        return msg;
}

string attack3(object me, object target, int damage)
{
        int shd;
        string msg;

        msg = HIR "剑锋过处，卷起漫天血浪，$n" HIR "只感头晕目"
              "眩，四肢乏力，难以再战。\n" NOR;

        if( target->query_temp("shield") )
        {
                shd=target->query_temp("apply/armor");

                target->add_temp("apply/armor", -shd);

                if( target->query_temp("apply/armor")<0 )
                        target->set_temp("apply/armor", 0);

                target->delete_temp("shield");

                msg += WHT "$N" WHT "气劲涌至，宛若刀割，顿时将$n"
                       WHT "的护体真气摧毁得荡然无存。\n" NOR;
        }
        return msg;
}

string attack4(object me, object target, int damage)
{
        object cloth, armor;
        string cn, an, msg;

        msg = HIR "$n" HIR "顿时大惊失色，瞬间已被$N" HIR "连中"
              "数剑，直削得血肉模糊。\n" NOR;

        if( objectp(cloth=target->query_temp("armor/cloth")) )
        {
                cn = cloth->name();
                msg += WHT "忽听轰然声大作，$n" WHT "身着的" + cn +
                       WHT "在$N" WHT "内力激荡下，竟被震得粉碎。\n"
                       NOR;

                cloth->set("consistence", 0);
                cloth->move(target);
        } else
        if( objectp(armor=target->query_temp("armor/armor")) )
        {                
                an = armor->name();
                msg += WHT "忽听「哧啦」一声脆响，$n" WHT "身着的" +
                       an + WHT "竟被$N" WHT "震裂，化成块块碎片。\n"
                       NOR;

                armor->set("consistence", 0);
                armor->move(target);
        }
        return msg;
}

string attack5(object me, object target, int damage)
{
        string msg;

        msg = HIR "只见$n" HIR "全身一阵抽搐，被剑锋所携的极寒气流"
              "包裹其中，刺痛难当。\n" NOR;

        if (! target->query_condition("poison"))
        {
                target->affect_by("poison",
                        (["level":me->query("jiali")*3+random(me->query("jiali")),
                           "name"     : "炼狱寒焰",
                           "id":me->query("id"),
                           "duration" : 80 ]));

                msg += WHT "霎时间$n" WHT "忽觉一股奇寒散入七经八脉"
                       "，仿佛连血液都停止了流动。\n" NOR;
        }
        return msg;
}
void clear_no_exert(object target)
{
        if (! objectp(target))return;

        target->delete_temp("no_exert");
}

string attack6(object me, object target, int damage)
{

        string msg;

        msg = HIR "$N" HIR "剑势迅猛之极，令$n" HIR "毫无招架余地，"
              "竟镇怯当场，素手待毙。\n" NOR;

        if( !target->query_temp("no_exert") )
        {
                target->set_temp("no_exert", 1);
                remove_call_out("clear_no_exert");
                call_out("clear_no_exert", 20, target);

                msg += WHT "$n" WHT "只感到全身真气涣散，丹元瓦解，似"
                       "乎所有的武功竟都消逝殆尽。\n" NOR;
        }
        return msg;
}