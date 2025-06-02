// This program is a part of NT mudlib
// boss ģ��

#include <ansi.h>

inherit BOSS;

int big_blowing();

void create()
{
        set_name(HIY "�ƽ����" NOR, ({ "golden dragon king", "dragon king", "dragon" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 200);
        set("long",
HIY"����һ��ȫ���ƣ��ڻ�ɳ�г������������ȫ��ɢ���Ž��ɫ�Ĺ�â��\n\n"NOR);

        set("dex",100);
        set("con",100);
        set("int",100);
        set("str",100);

        set("combat_exp", 500000000);
        set("level", 70);
        set("qi", 10000000);
        set("max_qi", 10000000);
        set("jing", 5000000);
        set("max_jing", 5000000);
        set("neili", 20000000);
        set("max_neili", 20000000);
        set("jiali", 50000);

        set("chat_chance", 5);
        set("chat_msg", ({
                HIB "ͻȻһ���ɳ��������������ߣ�\n" NOR,
                HIB "�ƽ����ͻȻ�³�һ�Ž�Ƶ����ӣ��־��˻�ȥ��\n" NOR,
        }));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: big_blowing :),
        }));

        set_temp("apply/attack", 5000+random(5000));
        set_temp("apply/unarmed_damage",5000+random(5000));
        set_temp("apply/armor", 5000+random(5000));
        set_temp("apply/add_weak", 60);
        set_temp("apply/reduce_damage", 80);
        set_temp("apply/reduce_busy", 20);
        set_temp("apply/add_busy", 5);

        // ��Ʒ����
        set("rewards", ([
                "exp"   : 50000,
                "pot"   : 20000,
                "mar"   : 5000,
                "score"   : 800,
                "gold"  : 100,
                "weiwang"   : 1000,
        ]));

        set("drops", ([
                "RA&RANDOM30"    :       100,  // �ͼ���ͨװ��
                "RA&RANDOM40"    :       30,   // �м���ͨװ��
                "FI&/clone/fam/skpaper/whip1"   :   50,
                "FI&/clone/fam/skpaper/club1"   :   50,
                "FI&/clone/fam/skpaper/hammer1"   :   50,
                "FI&/clone/enchase/rune16"   :   5,
                "FI&/clone/enchase/rune17"   :   5,
                "FI&/clone/enchase/rune18"   :   5,
                "FI&/clone/enchase/rune19"   :   5,
        ]));

        setup();
        //carry_object("/clone/money/gold")->set_amount(200);
}

void init()
{
        object me, ob;

        ::init();
        if (! interactive(me = this_player()))
                return;

        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}

int big_blowing()
{
        message_vision(HIB "$N" HIB "�ӻ�ɳ�����������һ������ȫ����ҫ�۵Ľ�ɫ��"
                       "���������ʹ��˼�������\n" NOR, this_object());

        remove_call_out("hurting");
        call_out("hurting", random(2) + 1);
        return 1;
}

int hurting()
{
        int dam, i , num;
        object *inv;

        message_vision(HIB "$N" HIB "���һ�ž޴�Ļ�ɳ������������������ض�����ɳ��û������\n" NOR,
                       this_object());

        inv = all_inventory(environment(this_object()));

        num = sizeof(inv);
        if (num < 1) num = 1;
        if (num > 5) num = 5;

        dam = 80000 / num;

        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object())
                {
                        dam -= query_temp("apply/reduce_wind", inv[i]);
                        if (dam <0) dam = 0;

                        inv[i]->receive_wound("qi", dam, this_object());
                        inv[i]->receive_wound("jing", dam/2, this_object());
                        COMBAT_D->report_status(inv[i], 1);
                }
        }
        return 1;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        int damage;

        damage = 10000 + random(10000);
        damage-=query_temp("apply/reduce_cold", ob);
        if (damage < 0) damage = 0;
        ob->receive_wound("qi", damage, me);
        set("neili", query("max_neili", me), me);
        return HIB "$N" HIB "���𡱵�һ���³�һƬ��ɳ����ʱ��$n"
               HIB "����ǧ�����\n" NOR;
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        return;
}
