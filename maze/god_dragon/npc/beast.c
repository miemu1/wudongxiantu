#include <ansi.h>

inherit NPC;
string *first_name = ({ "��", "���"});
string *first_id = ({ "tian", "sky"});
string *name_words = ({ "����", "��"});
string *id_words = ({ "juling", "guai"});
int combatpower();

void create()
{
        string name;
        int i, j;

        i = random(sizeof(first_name));
        name = first_name[i];
        j = random(sizeof(name_words));
        name += name_words[j];

        set_name(name, ({ first_id[i]+" "+id_words[j] }) );
        // random_name_color(this_object());

        set("age", 20);
        set("vrm_guard", 1);
        set("attitude", "aggressive");

        set("dex",100);
        set("con",100);
        set("int",100);
        set("str",100);

        set("combat_exp", 20000000);
        set("level", 20);
        set("qi", 60000);
        set("max_qi", 60000);
        set("jing", 300000);
        set("max_jing", 300000);
        set("neili", 1200000);
        set("max_neili", 1200000);
        set("jiali", 4000);

        set_skill("unarmed", 2000);
        set_skill("dodge", 2000);
        set_skill("parry", 2000);
        set_skill("force", 2000);


        set_temp("apply/attack", 200+random(200));
        set_temp("apply/unarmed_damage",200+random(200));
        set_temp("apply/armor", 2000+random(2000));

        set("drops", ([
                "RA&RANDOM70"                                    :       40,  // �ͼ���ͨװ��
                "RA&RANDOM80"                                    :       30,  // �м���ͨװ��
        ]));

        set_weight(500000);
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

mixed hit_ob(object me, object ob, int damage_bouns)
{
        int damage;

        damage = 200 + random(200);
        damage-=ob->query_temp("apply/reduce_wind");
        if (damage < 0) damage = 0;
        ob->receive_wound("qi", damage, me);
        me->set("neili",me->query("max_neili"));
        return HIC "$N" HIC "��������һ������һ���磬��ʱ��$n"
               HIC "�������絶��һ�㡣\n" NOR;
}

void unconcious()
{
        die();
}

void die()
{
        ::die();
}


