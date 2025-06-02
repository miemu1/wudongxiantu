// This program is a part of NT mudlib
// boss ģ��

#include <ansi.h>

inherit NPC;

int big_blowing();

void create()
{
        set_name( HIB "������" NOR, ({ "sea dragon king", "dragon king", "dragon" }) );
        set("long", HIB "����һ��ȫ����̣�����֮��ľ���������"
                    "����������ȫ��ɢ���ű���ɫ�Ĺ�â��\n\n" NOR);

        set("race", "Ұ��");
        set("gender", "����");
        set("age", 200);
        set("no_get", 1);
        set("shen_type", 0);
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("dex",100);
        set("con",100);
        set("int",100);
        set("str",100);

        set("combat_exp", 200000000);
        set("level", 70);
        set("qi", 200000);
        set("max_qi", 200000);
        set("jing", 1000000);
        set("max_jing", 1000000);
        set("neili", 4000000);
        set("max_neili", 4000000);
        set("neili", 4000000);
        set("jiali", 20000);

        set("unarmed", 1500);
        set("parry", 1500);
        set("claw", 1500);
        set("dodge", 1500);
        set("force", 1500);

        set("chat_chance", 5);
        set("chat_msg", ({
                HIB "���״���һ�����ˣ���������ߣ�\n" NOR,
                HIB "������ͻȻ�³�һ��տ�������ӣ��־��˻�ȥ��\n" NOR,
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: big_blowing :),
        }));

        set_temp("apply/attack", 200+random(100));
        set_temp("apply/unarmed_damage",200+random(100));
        set_temp("apply/armor", 200+random(100));
        set_temp("apply/add_weak", 60);
        set_temp("apply/reduce_damage", 80);
        set_temp("apply/reduce_busy", 20);
        set_temp("apply/add_busy", 5);

        set("rewards", ([
                "exp"   : 30000,
                "pot"   : 10000,
                "mar"   : 1000,
                "score"   : 500,
                "gold"  : 100,
                "weiwang"   : 1000,
        ]));
        // ��Ʒ����
        // set("killer_reward", killer_reward("sea_dragon"));
        set("drops", ([
                "RA&RANDOM20"    :       100,  // �ͼ���ͨװ��
                "RA&RANDOM80"    :       30,   // �м���ͨװ��
                "FI&/clone/fam/skpaper/finger1" :   50,
                "FI&/clone/fam/skpaper/hand1"   :   50,
                "FI&/clone/fam/skpaper/claw1"   :   50,
           //     "FI&/clone/tessera/rune10"      :   5,
           //     "FI&/clone/tessera/rune11"      :   5,
           //     "FI&/clone/tessera/rune12"      :   5,
                "MO&A1000"       :       10,
                "MO&A1001"       :       10,
                "MO&A1002"       :       10,
                "MO&A1003"       :       10,
                "MO&A1004"       :       10,
                "MO&A1005"       :       10,
                "MO&A1006"       :       10,
        ]));

        setup();
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

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        return;
}

int big_blowing()
{
        message_vision(HIB "$N" HIB "�Ӻ�ˮ�����������һ������ȫ����ҫ��"
                       "����ɫ�����������ʹ��˼�������\n" NOR, this_object());

        remove_call_out("hurting");
        call_out("hurting", random(2) + 1);
        return 1;
}

int hurting()
{
        int dam, i , num;
        object *inv;

        message_vision(HIB "$N" HIB "�³�һ�ɾ޴�ĺ��ˣ�������������������ƺ�������û������\n" NOR,
                       this_object());

        inv = all_inventory(environment(this_object()));

        num = sizeof(inv);
        if (num < 1) num = 1;
        if (num > 5) num = 5;

        dam = 25000 / num;

        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object())
                {
                        dam-=query_temp("apply/reduce_cold", inv[i]);
                        if (dam <0) dam = 0;

                        inv[i]->receive_damage("qi", dam, this_object());
                        inv[i]->receive_damage("jing", dam/2, this_object());
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
        int reduce;

        damage = 500 + random(500);
        reduce=ob->query_temp("apply/reduce_cold");
        damage = damage - damage * reduce / 100;
        if (damage < 0) damage = 0;
        ob->receive_damage("qi", damage, me);
        ob->receive_wound("qi", damage, me);
        me->set("neili",me->query("max_neili"));
        return HIB "$N" HIB "��������һ���³�һ�ں�������ʱ��$n"
               HIB "ȫ����������\n" NOR;
}

