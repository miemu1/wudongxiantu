// This program is a part of NT MudLIB

#include <ansi.h>
#define FUBEN_D  "/adm/npc/fubend"
inherit NPC;

int ask_me();

void create()
{
        set_name("ѦĽ��", ({ "xue muhua", "xue", "muhua" }));
        set("long", "�����Ǻų������е���ҽѦĽ������˵��\n"
                    "��ͨҽ����������������\n");
        set("gender", "����");
        set("title", "��ң�ɺ��Ȱ���");
        set("nickname", HIM "������" NOR);
        set("age", 50);
        set("class", "shaman");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 27);
        set("con", 25);
        set("dex", 25);

        set("inquiry", ([
                "����" : (:ask_me:),
        ]) );

        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 100);
        set("level", 10);
        set("combat_exp", 1000000);

        set_skill("force", 160);
        set_skill("xiaowuxiang", 160);
        set_skill("dodge", 140);
        set_skill("feiyan-zoubi", 140);
        set_skill("strike", 160);
        set_skill("liuyang-zhang", 160);
        set_skill("hand", 160);
        set_skill("qingyun-shou", 160);
        set_skill("parry", 160);
        set_skill("blade", 140);
        set_skill("ruyi-dao", 140);
        set_skill("xiaoyao-qixue", 220);
        set_skill("medical", 220);
        set_skill("literate", 120);
        set_skill("martial-cognize", 140);

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("hand", "qingyun-shou");
        map_skill("strike", "liuyang-zhang");
        map_skill("parry", "liuyang-zhang");
        map_skill("blade", "ruyi-dao");
        map_skill("medical", "xiaoyao-qixue");

        prepare_skill("hand", "qingyun-shou");
        prepare_skill("strike", "liuyang-zhang");

        create_family("��ң��", 3, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "hand.zhuo" :),
                (: perform_action, "strike.pan" :),
                (: exert_function, "recover" :),
        }));

        set("master_ob", 3);
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

int ask_me()
{
        object ob=this_player();
        object me = this_object();
        object azhu;
        string dir;
        string quest, userid;

        dir = base_name(environment(me));
        if (sscanf(dir,"/f/%s/%s/maze",quest,userid)!=2) {
                command("say ������û�գ�");
                return 1;
        }

        azhu = present("a zhu", environment(me));
        if(me->is_fighting() || me->query_temp("busy"))
        {
                command("say ������û�գ�");
                return 1;
        }

        if((int)ob->query_temp("juxianzhuang_step") != 14)
        {
                command("say ��Ϊ��ҪΪ�������ˣ�");
                return 1;
        }
        if(!objectp(azhu))
        {
                command("say ��û�����κ��˰���");
                return 1;
        }
        else
        {
                message_vision("ѦĽ��ι$N����һ��ҩ�裬Ȼ����ϥ���£�˫������$N�ı��ġ�\n", azhu);

                ob->delete_temp("juxianzhuang_step");
                FUBEN_D->delay_clear_fuben(quest, userid);
                return 1;
        }
}

