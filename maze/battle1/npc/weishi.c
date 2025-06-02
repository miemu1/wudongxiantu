// This program is a part of NT MudLIB
// weishi.c

inherit NPC;

#include <ansi.h>
//#include "/kungfu/class/wudang/auto_perform.h"

int auto_perform();
#define BATTLEFIELD_D "/adm/daemons/battlefieldd"
#define CANPIAN "/kungfu/class/wudang/obj/canpian"

string do_huqi();

void create()
{
        object zhenwu;

        set_name("��ʿ", ({ "wu shi", "shi" }));
        set("long","����λ��ʿ�������ּף���ִ������˫Ŀ���⾼���������Ѳ�������ܵ����Ρ�\n");
        set("gender", "����");
        set("age", 50);
        set("attitude", "heroism");
        set("shen_type", 0);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 1123);
        set("max_jing", 3000);
        set("eff_jingli", 3000);
        set("max_jingli", 3000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 300);
        set("combat_exp", 6400000);

        set_skill("force", 200);
        set_skill("taiji-shengong", 200);
        set_skill("dodge", 200);
        set_skill("tiyunzong", 200);
        set_skill("cuff", 200);
        set_skill("taiji-quan", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("taiji-jian", 200);
        set_skill("taoism", 200);
        set_skill("literate", 200);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");

        create_family("�䵱��", 2, "");

        set("chat_chance_combat", 50);
    /*    set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
*/
        set("inquiry", ([
                "����": (: do_huqi :),
        ]));


        setup();
        if( clonep() )
        {
                carry_object("/d/city/obj/gangjian")->wield();
                carry_object("/d/city/obj/tiejia")->wear();
        }
}


void attempt_apprentice(object ob)
{
        return;
}

int accept_kill(object obj)
{
        object me = this_object();
        mapping skill_status;
        string *sname;
        int i, max = 200;

        command("say "+RANK_D->query_rude(obj)+"��Ȼ����ɱ���ң����У�");

        if( !objectp(obj->query_temp("weapon")) || !objectp(me->query_temp("weapon")) )
        {
                command("unwield sword");
                command("enable parry taiji-quan");
        }
        else if( objectp(obj->query_temp("weapon")) )
        {
                command("wield sword");
                command("enable parry taiji-jian");
        }
        command("exert taiji");
        return 1;
}

string do_huqi()
{
        object ob = this_player();
        object me = this_object();

        if( ob->query_temp("battle/team_name") != query_temp("battle/team_name") )
        {
                me->kill_ob(ob);
                return RANK_D->query_rude(this_player()) + "�Ǳ�������Ī������ڿ�ң����У�\n";
        }

        if( !environment(me)->query("flag") )
        {
                message_vision(HIG"$N�ɻ������������˵��������������û����ɻ�����\n"NOR,me);
                return "�����ˣ�";
        }
        else
        {
                message_vision(HIG"$N���˿�$n��ʹ���˵�������ðɣ��Ҿ����������졣��\n"NOR,me,ob);
                command("halt");
                command("follow none");
        }

        return "��Ҽ��͸ɣ�";
}

varargs void die(object killer)
{
        object me;
        int i;

        me = this_object();

        if( !killer ) killer = me->query_last_damage_from();
        if( objectp(killer) &&
            userp(killer) &&
            killer->query_temp("battle/team_name") != me->query_temp("battle/team_name") )
        {
                BATTLEFIELD_D->add_killnpc_score(killer, 1);
        }

        ::die(killer);
}

void unconcious()
{
        die(query_last_damage_from());
}
