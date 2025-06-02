#include <ansi.h>

int checking(object me, object ob);

inherit NPC;

void create()
{
        object ob;
        set_name("��������", ({"dongfang bubai", "dongfang", "bubai", "dong"}));
        set("long", "������������̽������ݴ��书���µ�һ����˴�ž��ǡ��������ܡ���\n");
        set("nickname", HIY "�书���µ�һ" NOR );
        set("gender", "����");
        set("class", "eunach");
        set("attitude", "peaceful");
        set("age", 40);
        set("shen_type", -1);
        set("str", 91);
        set("int", 39);
        set("con", 50);
        set("dex", 62);

        set("qi", 1200000);
        set("max_qi", 1200000);
        set("jing", 90000000);
        set("max_jing", 90000000);
        set("max_neili", 12000000);
        set("neili", 12000000);
        set("jiali", 20000);
        set("combat_exp", 700000000);
        set("score", 1200000);
        set("level", 40);
        set("fight_boss", 1);

        set_skill("force", 9999);
        set_skill("parry", 9999);
        set_skill("dodge", 9999);
        set_skill("sword", 9999);
        set_skill("unarmed", 9999);
        set_skill("pixie-jian", 9999);
        set_skill("literate", 9999);
        set_skill("martial-cognize", 9999);
        set_skill("kuihua-mogong", 9999);

        map_skill("force", "kuihua-mogong");
        map_skill("dodge", "kuihua-mogong");
        map_skill("unarmed", "kuihua-mogong");
        map_skill("sword", "kuihua-mogong");
        map_skill("parry", "kuihua-mogong");

        prepare_skill("unarmed", "kuihua-mogong");


        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.sheng" :),
                (: perform_action, "sword.bian" :),
                (: perform_action, "sword.tian" :),
                (: perform_action, "sword.qiong" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "dodge.sheng" :),
                (: perform_action, "unarmed.bian" :),
                (: perform_action, "unarmed.tian" :),
                (: perform_action, "unarmed.qiong" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
                (: exert_function, "roar" :),
        }) );

        set_temp("apply/attack", 3000);
        set_temp("apply/defense", 15000);
        set_temp("apply/armor", 10000);
        set_temp("apply/damage", 5000);
        set_temp("apply/unarmed_damage", 5000);
        set_temp("apply/add_xuruo", 90);
        set_temp("apply/reduce_damage", 90);
        set_temp("apply/reduce_busy", 36);
        set_temp("apply/add_busy", 15);
        set_temp("apply/add_poison", 80);

        set("clear_fuben", 1);
        set("auto_perform", 1);
        set("rewards", ([
                "exp"   : 250000,
                "pot"   : 120000,
                "mar"   : 25000,
                "score" : 1200,
                "gold"  : 1200,
        ]));

        set("drops", ([
                "RA&RANDOM40"    :       100,   // �ͼ���ͨװ��
                "RA&RANDOM40"    :       100,   // �ͼ���ͨװ��
                "RA&RANDOM40"    :       100,   // �ͼ���ͨװ��
                "RA&RANDOM40"    :       100,   // �ͼ���ͨװ��
                "RA&RANDOM40"    :       100,   // �ͼ���ͨװ��
                "RA&RANDOM50"    :       100,   // �ͼ���ͨװ��
                "RA&RANDOM50"    :       40,    // �ͼ���ͨװ��
                "FI&/clone/tessera/rune21" :   30,
                "FI&/clone/tessera/rune22" :   30,
                "FI&/clone/goods/sun"   :   50,
                "FI&/clone/goods/moon"  :   50,
        ]));

        setup();

        carry_object("/d/fuzhou/obj/xiuhua")->wield();
        carry_object("/d/wanjiegu/npc/obj/qi-dress")->wear();
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        return;
}

void kill_ob(object me)
{
        remove_call_out("checking");
        call_out("checking", 1, this_object(), me);
        return ::kill_ob(me);
}

int accept_fight(object ob)
{
        kill_ob(ob);
        return -1;
}

int accept_kill(object ob)
{
        return 1;
}

int accept_hit(object ob)
{
        kill_ob(ob);
        return -1;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        int wound;

        if (random(5) == 1)ob->start_busy(8 + random(16));
        wound=20000+random(20000)-me->query_temp("apply/armor");
        if (wound < 1)wound = 1;
        me->receive_wound("qi", wound, ob);
        return HIY "$N" HIY "ŭ��һ�����������������Ƶ�$n" HIY "��æ���ҡ�\n" NOR;
}

void heart_beat()
{
        if (query("neili") < 100 && random(50) == 1)
                set("neili", query("max_neili"));

        return ::heart_beat();
}

int checking(object me, object ob)
{
        object weapon;

        remove_call_out("checking");
        if( !objectp(me) || !objectp(ob) )
                return 0;

        if( !me->query_temp("weapon") )
        {
                weapon = new("/d/fuzhou/obj/xiuhua");
                weapon->move(me);
                weapon->wield();
        }

        call_out("checking", 1, me, ob);
        return 1;
}
