#include <ansi.h>
inherit "inherit/char/boss";

void do_swing();
void set_from_me(object me);
void create()
{
        string *names = ({ "青铜狮子" });

        ::create();
        set_name( names[random(sizeof(names))], ({ "bronze lions"}));
        set("long", @LONG
这是一个沉睡在皇陵青铜机关兽。身长丈许。它的眼如铜铃，咆哮起来声震四壁。在
东方仙术的作用下，它的行动奇快，进退如风，再加上毛皮刀枪不入，利爪快如刀刃，
端的是极难对付。
LONG);
        set("title", HIR"机关兽" NOR);

        set("str", 150);
        set("con", 150);
        set("dex", 150);
        set("int", 150);
        set("max_qi", 2500000);
        set("max_jing", 1500000);
        set("neili", 2500000);
        set("max_neili", 2500000);
        set("max_jingli", 500000);
        set("attitude", "killer");
        set("auto_perfrom", 1);
				set_skill("force", 1000);
        set_skill("dodge", 1000);
        set_skill("parry", 1000);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: do_swing :),
        }) );

        set("combat_exp", 100000000);
        set("death_msg",YEL"\n$N散落成一堆青铜。\n\n"NOR);

        set("bonus", 18000);
        set_temp("apply/attack", 10000);
        set_temp("apply/parry", 10000);
        set_temp("apply/damage", 10000);
        set_temp("apply/unarmed_damage", 10000);
        set_temp("apply/armor", 10000);
        setup();
}

void init()
{
        object me;

        ::init();
        if( !interactive(me = this_player()) ||
            this_object()->is_fighting())
                return;

        set_from_me(me);
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}

void set_from_me(object me)
{
        mapping my;

        NPC_D->init_npc_skill(this_object(), NPC_D->check_level(me));
        my = query_entire_dbase();
        my["eff_jing"] = my["max_jing"];
        my["jing"] = my["max_jing"];
        my["eff_qi"] = my["max_qi"];
        my["qi"] = my["max_qi"];
        set("jiali", query_skill("force") / 2);
}

void do_swing()
{
        object *enemies,enemy;
        string msg;

        enemies = query_enemy();
        if( !enemies || sizeof(enemies)==0 )
                return;

        msg = HIW"$N将身子对正敌人，张开大口，突然间金光闪动,一阵钢针由$N口中激射而出！\n"NOR;
        message_vision(msg,this_object());

        foreach( enemy in enemies ) {
                msg = HIW"钢针既细，为数又多，$n大惊之下，不及躲闪，被打了个正着！\n"NOR;
                message_vision(msg,this_object(), enemy);
                enemy->receive_damage("qi",8000+random(8000),this_object());
                COMBAT_D->report_status(enemy);
                if( !enemy->is_busy() )
                        enemy->start_busy(1);
        }
}
