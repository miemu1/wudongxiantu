// yang.c ���

inherit NPC;

void random_move();

void create()
{
        set_name("���", ({"yang guo", "yang"}));
        set("gender", "����");
        set("age", 26);
        set("long", @LONG
������ȥüĿ֮����һ������֮����Ȼ������ԼԼȴ���˸е�һ����֮�飬
����յ����ģ���Ȼ���ǲм���
LONG );
        set("attitude", "friendly");

        set("str", 35);
        set("int", 36);
        set("con", 34);
        set("dex", 32);

        set("qi", 300000);
        set("max_qi", 300000);
        set("jing", 200000);
        set("max_jing", 200000);
        set("neili", 100000);
        set("max_neili", 100000);
        set("jiali", 500);

        set("combat_exp", 575000000);

        set("couple/id", "xiao longnv");
        set("couple/name", "С��Ů");

        set_skill("force", 600);
        set_skill("yunv-xinfa", 600);
        set_skill("surge-force", 600);
        set_skill("sword", 600);
        set_skill("yunv-jian", 600);
        set_skill("quanzhen-jian", 600);
        set_skill("xuantie-jian", 600);
        set_skill("dodge", 600);
        set_skill("yunv-shenfa", 600);
        set_skill("parry", 600);
        set_skill("unarmed", 600);
        set_skill("meinv-quan", 600);
        set_skill("strike", 600);
        set_skill("sad-strike", 600);
        set_skill("fireice-strike", 600);
        set_skill("tianluo-diwang", 600);
        set_skill("literate", 600);
        set_skill("taoism", 600);
        set_skill("medical", 600);
        set_skill("yunv-xinjing", 600);
        set_skill("throwing", 600);
        set_skill("yufeng-zhen", 600);
        set_skill("martial-cognize", 600);

        map_skill("force", "surge-force");
        map_skill("sword", "xuantie-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "sad-strike");
        map_skill("strike", "tianluo-diwang");

        prepare_skill("unarmed", "sad-strike");

        create_family("��Ĺ��", 3, "����");

        set("inquiry", ([
                "������" : "��...�٣�",
                "����"   : "�������������Ĵ�����",
                "����"   : "��ʦ��ô...�治��˵����",
                "С��Ů" : "����������Ӹ�ʲô��",
        ]));
        set("chat_msg", ({ (: random_move :) }));
        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "strike.wang" :),
                (: perform_action, "unarmed.xiao" :),
                (: perform_action, "unarmed.tuo" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: random_move :),
        }));

        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();

        carry_object("/clone/cloth/qingyi")->wear();
}

mixed teach_sad()
{
        object ob = this_player();

        if (ob->query_skill("sad-strike", 1) >= 1)
        {
                command("say �㲻���Ѿ�������");
                return 1;
        }

        if (ob->query("gender") != "����")
        {
                command("say �������书ֻ�ʺ������������㻹�����˰ɣ�");
                return 1;
        }

        if (ob->query("static/sadly") < 3)
        {
                command("say ����᲻������˼�����ӵ��黳��"
                        "�޷�����ҵ���Ȼ�����ƣ�");
                return 1;
        }

        if (ob->query("character") == "���ռ�թ" || 
            ob->query("character") == "�ĺ�����")
        {
                command("say ��һ������ȥ���ˣ��޷�������Ȼ����ľ��磡");
                return 1;
        }

        if (ob->query("int") < 34)
        {
                command("say ���������Բ��㣬�޷�������Ȼ�����ơ�");
                return 1;
        }

        if (ob->query("str") < 34)
        {
                command("say ������������㣬�޷�������Ȼ�����ơ�");
                return 1;
        }

        if ((int)ob->query("max_neili") < 3000)
        {
                command("say ���������Ϊ���㣬�޷�����Ȼ�����ơ�");
                return 1;
        }
}

void unconcious()
{
        object ob;

        ob = query("mate");
        if (objectp(ob))ob->die_msg();
        
        die();
}

void die_msg()
{
        command("chat ���� ����");
        destruct(this_object());
}

void random_move()
{
        string dir;
        string route;
        object env;

        if (query_temp("dest_now"))
        {
                destruct(this_object());
                return;
        }

        if (XYWAR_D->dest_status() == 1)
        {
                set_temp("dest_now", 1);
        }
}
