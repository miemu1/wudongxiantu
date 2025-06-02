#include <ansi.h>
inherit BOSS;

void do_bite();
void create()
{
        set_name("��ʬ", ({ "zombie" }));
        set("vendetta_mark","zombie");
        set("long", "����һ�����õĽ�ʬ��\n");
        set("title", HIB "(����)" NOR);

        set("str", 50);
        set("con", 120);
        set("dex", 22);
        set("int", 50);
        set("max_qi", 100000);
        set("eff_qi", 100000);
        set("max_jing", 50000);
        set("eff_jing", 50000);
        set("neili", 250000);
        set("max_neili", 50000);
        set("jingli", 50000);
        set("max_jingli", 50000);
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: do_bite() :),
        }) );
        set("combat_exp", 100000000);
        set("bellicosity", 5 );
        set("death_msg", RED"\n$N������һ̲Ѫˮ��\n\n"NOR);
        set("rewards", ([ 
                "exp"   : 20000, 
                "pot"   : 20000, 
        ])); 

        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("unarmed", 300);
        set_skill("parry", 300);
        set_temp("apply/attack", 500);
        set_temp("apply/parry", 500);
        set_temp("apply/unarmed_damage", 1000);
        set_temp("apply/reduce_damage", 60);

        setup();
}

void init()
{
        object me;

        ::init();
        if (! interactive(me = this_player()) ||
            this_object()->is_fighting())
                return;

        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}

void do_bite()
{
        object *enemies,enemy;
        string msg;

        clean_up_enemy();
        enemies = query_enemy();

        if( !enemies || sizeof(enemies)==0 )
                return;
        enemy = enemies[random(sizeof(enemies))];
        if( !userp(enemy) ) return;
        message_vision(RED"$N¶��ɭɭ�İ���������$n��\n"NOR,this_object(), enemy);
        message_vision(HIR"$Nҧס$n��������Ѫ��\n"NOR,this_object(),enemy);
        enemy->receive_damage("qi",200+random(200),this_object());
        msg = "( $n" +
              COMBAT_D->status_msg(query("qi", enemy)*100/
              (query("max_qi", enemy)?query("max_qi", enemy):100))+")\n";
        message_vision(msg, this_object(), enemy);
        this_object()->receive_heal("qi",200+random(200));
        this_object()->receive_curing("qi",100+random(100));

        if( !this_object()->is_busy() )
                this_object()->start_busy(2);
}

