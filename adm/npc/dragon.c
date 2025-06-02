// This program is a part of NT mudlib
// boss ģ��

#include <ansi.h>

inherit BOSS;

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
        set("level", 20);
        set("qi", 2000000);
        set("max_qi", 2000000);
        set("jing", 1000000);
        set("max_jing", 1000000);
        set("neili", 4000000);
        set("max_neili", 4000000);
        set("neili", 4000000);
        set("jiali", 20000);

        set("chat_chance", 5);
        set("chat_msg", ({
                HIB "���״���һ�����ˣ���������ߣ�\n" NOR,
                HIB "������ͻȻ�³�һ��տ�������ӣ��־��˻�ȥ��\n" NOR,
        }));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: big_blowing :),
        }));

        set_temp("apply/attack", 2000+random(1000));
        set_temp("apply/unarmed_damage",2000+random(1000));
        set_temp("apply/armor", 2000+random(1000));
        set_temp("apply/add_xuruo", 60);
        set_temp("apply/reduce_damage", 80);
        set_temp("apply/reduce_busy", 20);
        set_temp("apply/add_busy", 5);
        
        set("bonus", 80000);
        // ��Ʒ����
        // set("killer_reward", killer_reward("sea_dragon"));
	set("killer_reward", ([
                "RA&RANDOM70"                                    :       10000,  // �ͼ���ͨװ��
                "RA&RANDOM80"                                    :       300,    // �м���ͨװ��
                "FI&/clone/fam/skpaper/finger1"   :   5000,
                "FI&/clone/fam/skpaper/hand1"   :   5000,
                "FI&/clone/fam/skpaper/claw1"   :   5000,
                "FI&/clone/enchase/rune10"   :   5000,
                "FI&/clone/enchase/rune11"   :   5000,
                "FI&/clone/enchase/rune12"   :   5000,
                "MO&A1000"       :       300,
                "MO&A1001"       :       300,
                "MO&A1002"       :       300,
                "MO&A1003"       :       300,
                "MO&A1004"       :       300,
                "MO&A1005"       :       300,
	]));
	
        setup();
        carry_object("/clone/money/gold")->set_amount(200);
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
                        dam -= inv[i]->query_temp("apply/reduce_cold");
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
        
        damage = 5000 + random(5000);
        reduce = (int)ob->query_temp("apply/reduce_cold");
        damage = damage - damage * reduce / 100;
        if (damage < 0) damage = 0;
        ob->receive_damage("qi", damage, me);
        ob->receive_wound("qi", damage, me);
        me->set("neili", me->query("max_neili"));
        return HIB "$N" HIB "��������һ���³�һ�ں�������ʱ��$n"
               HIB "ȫ����������\n" NOR;
}

