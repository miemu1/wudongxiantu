#include <ansi.h>
inherit "inherit/char/boss";

void sp_attack();
void create()
{
        string *names = ({"������ʿ"});

        ::create();
        set_name( names[random(sizeof(names))], ({ "skeleton fighter","skeleton"}));
        set("long", "����һֻ��ͷ���ӡ�\n");
        set("title", HIB "(����)" NOR);

        set("str", 50);
        set("con", 120);
        set("dex", 22);
        set("int", 50);
        set("max_qi", 800000);
        set("max_jing", 500000);
        set("neili", 450000);
        set("max_neili", 450000);
        set("max_jingli", 500000);
        set("attitude", "killer");
				set_skill("force", 1000);
        set_skill("dodge", 1000);
        set_skill("parry", 1000);

        set("chat_chance", 1);
        set("chat_msg", ({
                "���ÿն����ۿ�����˸�ſ��µ�ӫ�⡣\n"
        }) );
        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: sp_attack :),
        }));

        set("combat_exp", 150000000);
        set("jiali", 5000);
        set("level", 20 );
       	set("death_msg",BLU"\n$Nɢ����һ�����ͷ��\n\n"NOR);
        set_temp("apply/attack", 2000+random(1000));
        set_temp("apply/unarmed_damage",2000+random(1000));
        set_temp("apply/armor", 2000+random(1000));
        set_temp("apply/reduce_damage", 60);
        setup();
        carry_object("/clone/weapon/changjian");
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

void sp_attack()
{
        object *enemies, enemy;
        object weapon, ob;
        string msg;

        enemies = query_enemy();
        if( !enemies || sizeof(enemies) == 0 )
                return;
        enemy = enemies[random(sizeof(enemies))];
        weapon = query_temp("weapon");
        if( objectp(weapon) ) weapon->unequip();
        if( objectp(ob = present("long sword", this_object())) ) {
                ob->wield();
                msg = HIB"$N˫��ͻȻ����ǿ�ҵ����⣬��$n�������ۣ�$n�е�һ���ʹ��\nƬ�̺��âɢȥ��$n��Ȼ����$N�����г������ڵ�Ѫ��\n"
                 "$n��$Nʹ��һ��ʧ���ѾõĹŴ��������ˣ�\n"NOR;
                message_vision(append_color(msg, HIB),this_object(),enemy);
                enemy->receive_damage("qi",2000+random(2000),this_object());
                COMBAT_D->report_status(enemy);
                ob->unequip();
                if( !enemy->is_busy() )
                        enemy->start_busy(1);
        }
        if( objectp(weapon) ) weapon->wield();
        return;
}

