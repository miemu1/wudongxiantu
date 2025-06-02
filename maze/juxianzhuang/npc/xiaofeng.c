// Written by Lonely@nitan.org
// xiaofeng.c ����(�Ƿ�)

#include <ansi.h>
inherit NPC;

string *quest_msg = ({
        "���������˵��������˵��Ĵ����Ѿã�����һ�������������鴫��\n",
        "���ϲ�����������ң���ȴû�б����ð��죬�����������ˡ�\n",
        "���ڰ��������ֻ��Ѧ��ҽ����ҽ�Σ����������Ѧ��ҽ���þ��������ׯ�ϡ�\n",
        "�������һ����ʣ��������ԣ������������֮�⡣\n",
        "�������˵������������Ǳ�����ׯ����Ѧ��ҽ°�ߣ����ư���֮�ˣ���Ȼ�������׵İ취��\n",
        "���Ƿ��Ƕ������صĺ��ӣ�����������͵͵����֮�¡�\n",
        "�������þ���ׯ�ϵ���֪����Ҫ����Ȼ�����������Ĵ��Ű���������ׯ����Ѧ��ҽҽ�Ρ�\n",
        "��ʱ��ʹ�Ƿ������������ڣ�����Ҳ��Ȼ�ܵõ�Ѧ��ҽ�����ơ�\n",
        "��ǧ�顢�������������������ھ�ǡ���ھ���ׯ�����һ��������ˣ���������Ӧ�þͻ������������Ϣ���������ֵܺ�Ѧ��ҽ��\n"
});

int do_report(string arg);
void quest_stage(object ob, int stage);

void create()
{
        set_name("����", ({"xiao feng", "xiao", "feng"}));
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
        set("per",19);
        set("dex", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "����̾�˿����������������벻�����������ж�����Ȼ��������һ�����죡\n",
        }));

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);

        set("combat_exp", 180000);
        set("shen", 20000);

        set_skill("force", 120);             // �����ڹ�
        set_skill("huntian-qigong", 120);    // ��������
        set_skill("unarmed", 120);           // ����ȭ��
        set_skill("xianglong-zhang", 120);   // ����ʮ����
        set_skill("dodge", 120);             // ��������
        set_skill("xiaoyaoyou", 120);        // ��ң��
        set_skill("parry", 120);             // �����м�
        set_skill("begging", 50);            // �л�����
        set_skill("checking", 50);           // ����;˵

        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "xianglong-zhang");

        //set("master_ob", 4);
        setup();

        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                if( (int)ob->query_temp("juxianzhuang_step") == 6 )
                {
                        call_out("quest_stage", 0, ob, 0);
                        return;
                }

                if( (int)ob->query_temp("juxianzhuang_step") == 10 )
                {
                        call_out("greeting", 1, ob);
                        return;
                }
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        say( "����˵�������Ѿ���ܱ�ǧ�顢��������������������������(report)��\n" );
        add_action("do_report", "report");
}

void quest_stage(object ob, int stage)
{
        if (! ob || ! present(ob)) return;

        tell_object(ob, HIW + quest_msg[stage] + NOR);
        if (++stage < sizeof(quest_msg))
        {
                call_out( "quest_stage", 1, ob, stage );
                return;
        }
        ob->set_temp("juxianzhuang_step", 7);
}

int do_report(string arg)
{
        object me;

        me = this_player();

        if( (int)me->query_temp("juxianzhuang_step") != 10 )
                return 0;

        tell_object(me, HIW "����˵������İ�������ĳ�м�������������һ�磬���Ǿ��������Ƕ��������\n" NOR );
        me->set_temp("juxianzhuang_step", 11);
        destruct(this_object());
        return 1;
}
