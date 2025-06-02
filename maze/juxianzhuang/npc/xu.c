// xu.c

#include <ansi.h>;
inherit NPC;

string *quest_msg1 = ({
        "�쳤��˵����������������������һ����Ȼ�����鴫��ʧ��ʧ����\n",
        "��ε����ִ�ᣬ�����ҸôӺ�˵���أ����Ų��Ұ���\n",
        "��ʵ�Ȿ������ؤ���Լ������飬��Ҳ����������ɱ����ɱĸ��ɱʦ�Ķ��У������Ƿ���Ϊ�����ǡ���\n",
        "�쾪�׿������Ի�ı��飬����˵����\n",
        "������֤��ɽ���Ƿ��ⷬ�����ӣ�����������ݱ��Ҵ����ѳ�ؤ��֮��ɱ�����Լ����常��ĸ��\n"
        "��ɱ�����Լ�����ҵ��ʦ�����ʦ������������������ͼ�����Լ�����������ݣ�˭��ȴԽĨԽ�ڣ�\n",
        "��Ȼ�Ƿ�����Ϊؤ��Ҳ�����º����ͣ������Ҵ������ڣ�ؤ��Ҳ���Իػ�������\n",
        "�����ֵܺ�Ѧ��ҽ�ٿ����ִ�ᣬ����Ϊ�˾����ַ��Ƿ塣Ⱥ�����ף���Ҷ�ϣ�������뵽�����ϵ¸�\n"
        "���ص�ǰ�������ǳ�͢����������ҵ����䣬�Ͼ����Ѿ�������ͨ�ļҺޣ����й����ˡ���\n",
        "��������֮�󣬾��ô�����������������������ʵ���ѡ����֪�������������Ϥ��ϣ�����ܳ��棬����������������ִ�ᡣ\n",
});

string *quest_msg2 = ({
        "�쳤��˵�����벻��������������������ڲ��ˣ���������ʹ�İ���\n",
        "��Ҳ�ѹ֣��������Ǵ����ˣ������˽������˶Դ�������˶�ô���ص��˺���\n",
        "�Ƿ�ɱ����ɱĸ��ɱʦ�����������û�����ۼ�����������������ɮ�Ļ����ѵ����Ǽٵģ�\n",
        "���ˣ����ˣ���Ȼ����ү˵����ô�����ˣ�����Ҳ����ǿ�����ѡ�\n",
        "˵�������£����鷳��ȥһ�������£��������������ȷ��ɲμӾ���ׯ���ɡ�\n",
        "��֪�������ȷ���������һЩ�ѽ�Ľᣬ���ǲ������μ����ִ��ģ���������뵽���Ѵ�ʦ������\n"
        "��ʦ������ׯ��Ҳ��������Ӣ���и����Ĺ��ˡ��Ͼ��������书�������\n",
});

int ask_juxianzhuang();
int do_report();

void create()
{
        set_name("�쳤��", ({"xu zhanglao", "xu", "zhanglao"}));
        set("gender", "����");
        set("age", 85);
        set("long", "����Ʈ��������һ�������۵����£��Ǹ���ͼ��ߵ���ؤ��\n");
        set("title", "ؤ��Ŵ�����");
        set("attitude", "peaceful");
        set("class", "beggar");
         set("beggarlvl", 9);
        set("no_get", "1");

        set("str", 24);
        set("int", 20);
        set("con", 24);
        set("dex", 20);

        set("qi", 900000);
        set("max_qi", 900000);
        set("jing", 100000);
        set("max_jing", 10000);
        set("neili", 1500000);
        set("max_neili", 1500000);
        set("jiali", 1000);

        set("combat_exp", 100000000);
        set("score", 20000);

        set_skill("force", 950);            // �����ڹ�
        set_skill("huntian-qigong", 900);   // ��������
        set_skill("hand", 900);             // �����ַ�
        set_skill("suohou-hand", 850);      // ����������
        set_skill("staff", 900);            // �����ȷ�
        set_skill("fengmo-zhang", 850);     // ��ħ�ȷ�
        set_skill("dodge", 900);            // ��������
        set_skill("xiaoyaoyou", 950);       // ��ң��
        set_skill("parry", 850);            // �����м�
        set_skill("staff", 900);            // ��������
        set_skill("strike",850);  // �����Ʒ�
        set_skill("lianhua-zhang",850); // ������
        set_skill("xianglong-zhang",850);

        map_skill("strike","lianhua-zhang");
        prepare_skill("strike","lianhua-zhang");

        map_skill("force", "huntian-qigong");
        map_skill("staff", "fengmo-zhang");
        map_skill("parry", "fengmo-zhang");
        map_skill("hand", "suohou-hand");
        map_skill("dodge", "xiaoyaoyou");
        prepare_skill("hand", "suohou-hand");

        set("inquiry", ([
                "Ӣ����": (: ask_juxianzhuang :),
                "���ִ��": (: ask_juxianzhuang :),
        ]) );

        //set("party/party_name", HIC"ؤ��"NOR);
        //set("party/rank", RED"�Ŵ�����"NOR);
        //set("party/level", 9);
        create_family("ؤ��", 18, "����");

        setup();

        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/gangzhang")->wield();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() &&
            ob->query_temp("juxianzhuang_step") == 5 ) {
                add_action("do_report", "report");
        }
}

int ask_juxianzhuang()
{
        object me = this_player();

        if( (int)me->query_temp("juxianzhuang_step") != 1 )
        {
                tell_object(me, "�쳤�Ͽ��˿��㣬��ҡ��ҡͷ��\n");
                return 1;
        }

        call_out("quest_stage", 0, me, 0);
        return 1;
}

void quest_stage(object ob, int stage)
{

        if (! ob || ! present(ob)) return;

        tell_object(ob, HIW + quest_msg1[stage] + NOR);
        if (++stage < sizeof(quest_msg1))
        {
                call_out( "quest_stage", 1, ob, stage );
                return;
        }
        ob->set_temp("juxianzhuang_step", 2);
}

void quest_stage2(object ob, int stage)
{

        if (! ob || ! present(ob)) return;

        tell_object(ob, HIW + quest_msg2[stage] + NOR);
        if (++stage < sizeof(quest_msg2))
        {
                call_out( "quest_stage2", 1, ob, stage );
                return;
        }
        ob->set_temp("juxianzhuang_step", 4);
}

int do_report()
{
        object me, ob;

        me = this_player();
        ob = this_object();

        if( (int)me->query_temp("juxianzhuang_step") != 5 )
                return 0;

        message_vision("$n��ϸ����$N�㱨��ȥ�����������ȷ��ɵľ�����\n", ob, me);

        command("say ��Ȼ���Ѵ�ʦ�����Ŵ�ʦ��λ��ɮҪ������ׯ��������Ӣ�۾Ͳ���Ⱥ�������ˡ�\n");
        command("say ��л���ˣ������������£����Ժ;���ׯ�ڵ�Ӣ���ǽύһ�¡�\n");
        me->set_temp("juxianzhuang_step", 6);
        return 1;
}

int accept_object(object me, object ob)
{
        if( ob->query("id") != "letter" )
                return 0;

        if( !ob->query("send_to")
        ||  ob->query("send_to") != query("id")
        ||  !ob->query("send_from")
        ||  ob->query("send_from") != me->query("id") )
        {
                return 0;
        }

        if( (int)me->query_temp("juxianzhuang_step") != 3 )
                return 0;

        call_out("quest_stage2", 0, me, 0);
        destruct(ob);
        return 1;
}
