
// Written by Lonely@nitan.org
// xiaofeng.c ����(�Ƿ�)

#include <ansi.h>
inherit NPC;

int check_out(object ob, object me);

void create()
{
        set_name("�Ƿ�", ({"qiao feng", "qiao", "feng"}));
        set("gender", "����");
        set("nickname",HIB"���ƽ���"NOR);
        set("age", 28);
        set("long",
                "������ؤ��ǰ�ΰ������򱻷����������˶��������롣\n"
                "�ڽ��������������Ľ�ٸ�����Ϊ�����Ƿ壬��Ľ�١���\n"
                "����һ����ͨ�Ĵֲ����ӣ�������һ���������һϵ��\n"
                "������������࣬���ʮ�ֿ��࣬����һ�������ֿ���ʮ\n"
                "�����Ի������ӣ�˫Ŀ��磬��������\n");
        set("attitude", "peaceful");

        set("str", 45);
        set("int", 30);
        set("con", 30);
        set("per", 19);
        set("dex", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "����̾�˿����������������벻�����������ж�����Ȼ��������һ�����죡\n",
        }));

        set("qi", 4000000);
        set("max_qi", 4000000);
        set("jing", 1500000);
        set("max_jing", 1500000);
        set("neili", 4000000);
        set("max_neili", 4000000);
        set("jiali", 2000);

        set("combat_exp", 1800000000);
        set("shen", 200000);

        set_skill("force", 1200);             // �����ڹ�
        set_skill("huntian-qigong", 1200);    // ��������
        set_skill("strike", 1200);           // ����ȭ��
        set_skill("dragon-strike", 1200);   // ����ʮ����
        set_skill("dodge", 1200);             // ��������
        set_skill("xiaoyaoyou", 1200);        // ��ң��
        set_skill("parry", 1200);             // �����м�
        set_skill("begging", 500);            // �л�����
        set_skill("checking", 500);           // ����;˵

        map_skill("force", "huntian-qigong");
        map_skill("strike", "dragon-strike");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dragon-strike");

        //set("master_ob", 4);
        set("auto_perform", 1);
        //set("clear_fuben", 1);
        setup();

        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        ::init();
        if( interactive(this_player()) && !is_fighting() )
                call_out("check_move", 2, this_object(), this_player());
}

int check_move(object ob, object me)
{
        remove_call_out("check_move");

        if( environment(ob)->query("short") == "�θ���Ժ" )
        {
                call_out("check_out", 180, ob, me);
                return 1;
        }

        if( !me || environment(ob) != environment(me) )
                call_out("check_move", 1, ob, me);
        else
        if( !ob->is_fighting() && !ob->is_busy() )
                ob->command("go west");
        else
                call_out("check_move", 1, ob, me);

        return 1;
}

int check_out(object ob, object me)
{
        if( !me || environment(me) != environment(ob) )
                die();

        me->remove_all_enemy(1);
        ob->remove_all_enemy(1);
        message_vision(HIY "$N����Ѳ����ڣ��������ˡ���ʱ��һλ������ɮͻȻ���֣���$N���ߡ�\n" NOR,
                ob, me);
        me->set_temp("juxianzhuang_step", 14);
        return 1;
}

void die()
{
        object usr;
        string dir;
        string quest, userid;

        dir = base_name(environment(this_object()));
        if (sscanf(dir,"/f/%s/%s/maze",quest,userid)==2) {
                usr = find_player("userid");
                if( objectp(usr) )
                        usr->delete_temp("juxianzhuang_step");
                FUBEN_D->delay_clear_fuben(quest, userid);
        }
}