// moonblade.c 圆月弯刀

#include <weapon.h>
#include <ansi.h>

//inherit F_OBSAVE;
inherit BLADE;

string do_wield();
string do_unwield();

void create()
{
        set_name(HIW "圆月弯刀" NOR, ({ "moon blade", "blade", "moon" }));
        set_weight(1500);
        if (clonep())
                destruct(this_object());
        else {
                set("long", HIW "此刀乃魔教镇教之宝，威力无比，圆月刀法配合"
                                "其在月光下使用有通灵之能。\n" NOR );
                set("unit", "把");
                set("value", 800000);
                set("no_sell", 1);
                set("no_store", 1);
                set("material", "steel");
                set("wield_msg", (: do_wield() :));
                set("unwield_msg", (: do_unwield() :));
                set("stable", 80);
        }
        init_blade(200);
        setup();
      //  restore();
}

string do_wield()
{
        object me;

        me = this_player();
        remove_call_out("check_npc");
        call_out("check_npc", 0, me, environment(me));
        if (me->query("shen") < -100000)
        {
                me->set_temp("apply/attack", me->query_skill("blade", 1) / 4);
                me->set_temp("apply/defense", me->query_skill("parry", 1) / 4);
                return HIW "$N沉声低吼，缓缓拔出$n" HIW "，只感到一轮月光当中照来。\n" NOR;
        } else
        if (me->query("shen") <= 0)
        {
                return HIC "$N伸手把$n" HIW "抽出刀鞘。\n" NOR;
        } else
        if (me->query("shen") > 100000)
        {
                me->set_temp("apply/attack", -me->query_skill("blade", 1) / 5);
                me->set_temp("apply/defense", -me->query_skill("parry", 1) / 5);
                return HIB "$N战战兢兢的拔出一把$n" HIB "。\n" NOR;
        } else
        {
                return HIB "$N吼管内一阵低吼，“唰”的一声亮出了$n" HIB "。\n" NOR;
        }
}

string do_unwield()
{
        object me;

        me = this_player();
        remove_call_out("check_npc");
        me->delete_temp("apply/attack", me->query_skill("blade", 1) / 4);
        me->delete_temp("apply/defense", me->query_skill("parry", 1) / 4);
        if (me->query("shen") <= 0)
                return HIC "$N随手将圆月弯刀插回刀鞘。\n" NOR;
        else
        if (me->query("shen") > 1000000)
                return HIG "$N把$n" HIG "收了起来，感觉心神不宁，全身虚脱。\n" NOR;
        else
                return HIG "$N一晒，把$n" HIG "插回刀鞘。\n" NOR;
}

void check_npc(object me, object env)
{
        object *ob;
        int i;

        if (! objectp(me) || ! living(me))
                return;

        if (environment(me) != env)
                return;

        ob = all_inventory(env);
        for (i = 0; i < sizeof(ob); i++)
        {
                if (! ob[i]->is_character() || ob[i] == me ||
                    ! living(ob[i]) || ob[i]->query("not_living") ||
                    ob[i]->query("id") == "qing qing")
                        continue;

                if (me->is_good())
                {
                        if (userp(ob[i]))
                                continue;

                        if (ob[i]->query("shen") < -100000)
                        {
                                message_vision("$N大怒喝道：好你个" + RANK_D->query_rude(me) +
                                               "，居然敢盗用圆月弯刀？\n", ob[i]);
                                if (! env->query("no_fight"))
                                        ob[i]->kill_ob(me);
                        } else
                        if (ob[i]->is_good())
                        {
                                message_vision(random(2) ? "$N哈哈大笑，对$n道：干得漂亮，侠之"
                                                           "大者，也就是兄台这般人物。\n" :
                                                           "$N拼命鼓掌，对$n道：想不到魔教有"
                                                           "象兄台如此厉害之人呀。",
                                               ob[i], me);
                        }
                        continue;
                }

                if (me->is_not_bad())
                        continue;

                if (ob[i]->query("shen") < -100000 && ! userp(ob[i]))
                {
                        message_vision(random(2) ? "$N赞道：好刀，好刀！\n" :
                                                   "$N叹道：也不知魔教教主那老家伙到底死没有死？\n",
                                       ob[i]);
                } else
                if (ob[i]->query("shen") > 10 && ! userp(ob[i]))
                {
                        mixed ob_exp, my_exp;
                        ob_exp = ob[i]->query("combat_exp");
                        my_exp = me->query("combat_exp");
                        if (ob_exp > my_exp * 2 || ob_exp > 1500000)
                        {
                                message_vision(random(2) ? "$N对$n冷冷道：滚开！少在我面前卖弄。\n" :
                                                           "$N一声冷笑，对$n道：你以为你是谁？血尸"
                                                           "那？哈哈哈哈！\n",
                                               ob[i], me);
                        } else
                        if (ob_exp > 20000)
                        {
                                message_vision(random(2) ? "$N脸色有些不对劲。\n" :
                                                           "$N露出害怕的神色。\n",
                                               ob[i]);
                                if (env->query("no_fight"))
                                        continue;
                                message_vision(random(2) ? "$N怒喝一声，“大家都不要活了！”\n" :
                                                           "$N一言不发，忽的扑向$n，身形极快。\n",
                                               ob[i], me);
                                ob[i]->kill_ob(me);
                        } else
                        {
                                message_vision(random(2) ? "$N扑通一声，瘫倒在地，双手急摇"
                                                           "道：“不是我！真的不是我！”\n" :
                                                           "$N一个哆嗦，结结巴巴的什么也说"
                                                           "不上来。\n",
                                               ob[i], me);
                                if (! env->query("no_fight"))
                                        ob[i]->unconcious();
                        }
                }
        }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
//        int my_exp, ob_exp;

        if (me->is_good() || victim->is_bad())
                return - damage_bonus / 2;

        if (me->is_not_bad() || victim->is_not_good())
                return 0;

        if (me->query_skill_mapped("blade") != "moon-blade" ||
            me->query_skill("moon-blade", 1) < 100)
                // only increase damage
                return damage_bonus / 2;

        switch (random(4))
        {
        case 0:
                if (! victim->is_busy())
                        victim->start_busy(me->query_skill("blade") / 10 + 2);
                return HIB "$N跨前一步，手中的" NOR+HIW "圆月弯刀" NOR+HIB "从意想不到的"
                       "角度向$n攻去，$n只见四周有无数刀光闪动。\n"
                       "不知如何抵挡，只有连连后退。\n" NOR;

        case 1:
                n = me->query_skill("blade");
                victim->receive_damage("qi", n, me);
                victim->receive_wound("qi", n, me);
                n = victim->query("eff_jing");
                n /= 2;
                victim->receive_damage("jing", n, me);
                victim->receive_wound("jing", n / 2, me);
                return random(2) ? HIB "$N沉身低吼，手中的圆月弯刀化作万道红光，“唰”的扫过$n。\n" NOR:
                                   HIB "$N突然大声喝道：“什么名门正派，还不受死？”手中圆月弯刀"
                                   HIB "忽的一抖，$n登时觉得眼前有如千万刀光不停闪动。\n" NOR;
        }

        // double effect
        return damage_bonus;
}

void start_borrowing()
{
        remove_call_out("return_to_laozu");
        call_out("return_to_laozu", 14400 + random(1800));
}

void return_to_laozu()
{
        object me;

        me = environment();
        if (! objectp(me))
                return;

        while (objectp(environment(me)) && ! playerp(me))
                me = environment(me);

        if (playerp(me))
        {
                if (me->is_fight())
                {
                        call_out("return_to_laozu", 1);
                        return;
                }

                message_vision("忽然一个魔教的弟子走了过来，看到$N，忙招呼道：“青青说"
                               "这把刀不能丢了，放在你手上不大放心，让我来找你拿回圆月弯刀，你现在不用了么？”\n"
                               "$N道：“好了，好了，你就拿回去吧。”\n"
                               "$N将神刀交给魔教弟子带走。\n", me);
        } else
        {
                message("vision", "忽然一个魔教弟子走了过来，捡起圆月弯刀，叹了口气，摇摇"
                                  "头走了。\n", me);
        }

        destruct(this_object());
}

