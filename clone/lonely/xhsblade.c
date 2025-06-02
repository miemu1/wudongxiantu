// xuehun.c Ѫ����

#include <weapon.h>
#include <ansi.h>

//inherit F_OBSAVE;
inherit BLADE;

string do_wield();
string do_unwield();

void create()
{
        set_name(HIR "Ѫ����" NOR, ({ "xuehun shendao", "blade", "xuehun" }));
        set_weight(1500);
        if (clonep())
                destruct(this_object());
        else {
                set("long", HIR "�˵��˵���Ѫʬ����Я��֮���˵�ɱ��̫�أ�"
                                "��������Ѫ�������Ŷ���������ʹ�á�\n" NOR );
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", (: do_wield() :));
                set("unwield_msg", (: do_unwield() :));
                set("stable", 80);
        }
        init_blade(200);
        setup();
        //restore();
}

string do_wield()
{
        object me;

        me = this_player();
        remove_call_out("check_npc");
        call_out("check_npc", 0, me, environment(me));
        if (me->query("shen") < -10000)
        {
                me->set_temp("apply/attack", me->query_skill("blade", 1) / 4);
                me->set_temp("apply/defense", me->query_skill("parry", 1) / 4);
                return HIW "$N�����ͺ𣬻����γ�$n" HIW "��ֻ�е�һ��Ѫ��֮�����������\n" NOR;
        } else
        if (me->query("shen") <= 0)
        {
                return HIC "$N���ְ�$n" HIW "������ʡ�\n" NOR;
        } else
        if (me->query("shen") > 10000)
        {
                me->set_temp("apply/attack", -me->query_skill("blade", 1) / 5);
                me->set_temp("apply/defense", -me->query_skill("parry", 1) / 5);
                return HIB "$Nսս�����İγ�һ��$n" HIB "��\n" NOR;
        } else
        {
                return HIB "$N�����һ��ͺ𣬡�ৡ���һ��������$n" HIB "��\n" NOR;
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
                return HIC "$N���ֽ�Ѫ���񵶲�ص��ʡ�\n" NOR;
        else
        if (me->query("shen") > 10000)
                return HIG "$N��$n" HIG "�����������о���������ȫ�����ѡ�\n" NOR;
        else
                return HIG "$Nһɹ����$n" HIG "��ص��ʡ�\n" NOR;
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
                    ob[i]->query("id") == "xuedao laozu")
                        continue;

                if (me->is_good())
                {
                        if (userp(ob[i]))
                                continue;

                        if (ob[i]->query("shen") < -10000)
                        {
                                message_vision("$N��ŭ�ȵ��������" + RANK_D->query_rude(me) +
                                               "����Ȼ�ҵ���Ѫ���񵶣�\n", ob[i]);
                                if (! env->query("on_fight"))
                                        ob[i]->kill_ob(me);
                        } else
                        if (ob[i]->is_good())
                        {
                                message_vision(random(2) ? "$N������Ц����$n�����ɵ�Ư������֮"
                                                           "���ߣ�Ҳ������̨������\n" :
                                                           "$Nƴ�����ƣ���$n�����벻��Ѫ������"
                                                           "����̨�������֮��ѽ��",
                                               ob[i], me);
                        }
                        continue;
                }

                if (me->is_not_bad())
                        continue;

                if (ob[i]->query("shen") < -10000 && ! userp(ob[i]))
                {
                        message_vision(random(2) ? "$N�޵����õ����õ���\n" :
                                                   "$N̾����Ҳ��֪Ѫ���������ϼһ������ô���ˣ�\n",
                                       ob[i]);
                } else
                if (ob[i]->query("shen") > 10 && ! userp(ob[i]))
                {
                        int ob_exp, my_exp;
                        ob_exp = ob[i]->query("combat_exp");
                        my_exp = me->query("combat_exp");
                        if (ob_exp > my_exp * 2 || ob_exp > 1500000)
                        {
                                message_vision(random(2) ? "$N��$n���������������������ǰ��Ū��\n" :
                                                           "$Nһ����Ц����$n��������Ϊ����˭��Ѫʬ"
                                                           "�ǣ�����������\n",
                                               ob[i], me);
                        } else
                        if (ob_exp > 20000)
                        {
                                message_vision(random(2) ? "$N��ɫ��Щ���Ծ���\n" :
                                                           "$N¶�����µ���ɫ��\n",
                                               ob[i]);
                                if (env->query("no_fight"))
                                        continue;
                                message_vision(random(2) ? "$Nŭ��һ��������Ҷ���Ҫ���ˣ���\n" :
                                                           "$Nһ�Բ�������������$n�����μ��졣\n",
                                               ob[i], me);
                                ob[i]->kill_ob(me);
                        } else
                        {
                                message_vision(random(2) ? "$N��ͨһ����̱���ڵأ�˫�ּ�ҡ"
                                                           "�����������ң���Ĳ����ң���\n" :
                                                           "$Nһ�����£����Ͱ͵�ʲôҲ˵"
                                                           "��������\n",
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

        if (me->query_skill_mapped("blade") != "xue-dao" ||
            me->query_skill("xue-dao", 1) < 100)
                // only increase damage
                return damage_bonus / 2;

        switch (random(4))
        {
        case 0:
                if (! victim->is_busy())
                        victim->start_busy(me->query_skill("blade") / 10 + 2);
                return HIB "$N��ǰһ�������е�" NOR+HIR "Ѫ����" NOR+HIB "�����벻����"
                       "�Ƕ���$n��ȥ��$nֻ����������������������\n"
                       "��֪��εֵ���ֻ���������ˡ�\n" NOR;

        case 1:
                n = me->query_skill("blade");
                victim->receive_damage("qi", n, me);
                victim->receive_wound("qi", n, me);
                n = victim->query("eff_jing");
                n /= 2;
                victim->receive_damage("jing", n, me);
                victim->receive_wound("jing", n / 2, me);
                return random(2) ? HIB "$N����ͺ����е�Ѫ���񵶻��������⣬��ৡ���ɨ��$n��\n" NOR:
                                   HIB "$NͻȻ�����ȵ�����ʲô�������ɣ�����������������Ѫ����"
                                   HIB "����һ����$n��ʱ������ǰ����ǧ�򵶹ⲻͣ������\n" NOR;
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

                message_vision("��Ȼһ��Ѫ���ŵĵ������˹���������$N��æ�к�����������˵"
                               "��ѵ����ܶ��ˣ����������ϲ�����ģ������������û�Ѫ���񵶣������ڲ�����ô����\n"
                               "$N���������ˣ����ˣ�����û�ȥ�ɡ���\n"
                               "$N���񵶽���Ѫ���ŵ��Ӵ��ߡ�\n", me);
        } else
        {
                message("vision", "��Ȼһ��Ѫ���ŵ������˹���������Ѫ���񵶣�̾�˿�����ҡҡ"
                                  "ͷ���ˡ�\n", me);
        }

        destruct(this_object());
}

