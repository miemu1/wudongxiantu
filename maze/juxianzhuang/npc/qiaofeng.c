// Written by Lonely@nitan.org
// xiaofeng.c ����(�Ƿ�)

#include <ansi.h>
inherit NPC;

string *quest_msg = ({
        "�Ƿ������˵������ʵ����һ��ΰ������ѣ�����ĳ�Ⱳ�ӣ��������ˣ�\n",
        "�Ƿ履����˪�����ϣ�����һ˿�ѵõ�Ц�⡣\n",
        "�������ڿ������ˣ���������������ˣ���ʱ�����ڳ��С����ģ�����һ����ʤ���ġ�\n",
        "���죬��Ҳһ����û�µģ������˺��ˣ����Ǿ�ȥ����һ�����������Ҳ�������ˡ�\n",
        "�߰ɣ�\n"
});

void quest_stage(object ob, int stage);

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
        set("jiali", 1000);

        set("combat_exp", 1800000000);
        set("shen", 200000);

        set_skill("force", 1200);             // �����ڹ�
        set_skill("huntian-qigong", 1200);    // ��������
        set_skill("unarmed", 1200);           // ����ȭ��
        set_skill("xianglong-zhang", 1200);   // ����ʮ����
        set_skill("dodge", 1200);             // ��������
        set_skill("xiaoyaoyou", 1200);        // ��ң��
        set_skill("parry", 1200);             // �����м�
        set_skill("begging", 500);            // �л�����
        set_skill("checking", 500);           // ����;˵

        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "xianglong-zhang");

        //set("master_ob", 4);
        set("auto_perform", 1);
        setup();

        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                if( (int)ob->query_temp("juxianzhuang_step") == 11 )
                {
                        call_out("quest_stage", 1, ob, 0);
                        return;
                }

                if( base_name(environment()) == "/maze/juxianzhuang/damen" )
                {
                        this_object()->set_leader(0);
                        message_vision("$n��$N�Լ�����һ����������ׯ��ǰ���쳤��ӭ�����������ڹ���֮�飬Ȱ$N�뿪��\n"
                                       "Ȼ��$Nһ��ֻ��Ϊ�������ˣ������ϵ�ɽ�»�Ҳ������ϧ��\n"
                                       "$N���Ű���ֱ�Ӵ����˾���ׯ��\n",
                                       this_object(), ob);
                        ob->set_temp("juxianzhuang_step", 13);
                        destruct(this_object());
                }
        }
}

void quest_stage(object ob, int stage)
{
        remove_call_out("quest_stage");

        if (! ob || ! present(ob)) return;

        tell_object(ob, HIW + quest_msg[stage] + NOR);
        if (++stage < sizeof(quest_msg))
        {
                call_out( "quest_stage", 1, ob, stage );
                return;
        }
        ob->set_temp("juxianzhuang_step", 12);
        this_object()->set_leader(ob);
        message_vision("$N������ʼ����$nһ���ж���\n", this_object(), ob);
        return;
}
