inherit NPC;

void create()
{
        set_name("����ɮ��", ({
                "shaolin sengren",
                "seng ren",
        }));
        set("long",
                "����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
                "̫��Ѩ�߸߹����ƺ��������书��\n"
        );


        set("nickname", "�����޺�");
        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 60);
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_qi", 1500000);
        set("max_jing", 1000000);
        set("neili", 1000000);
        set("max_neili", 1000000);
        set("jiali", 1000);
        set("combat_exp", 100000000);
        set("score", 5000);

        set_skill("force", 850);
        set_skill("hunyuan-yiqi", 850);
        set_skill("dodge", 850);
        set_skill("shaolin-shenfa", 1200);
        set_skill("staff", 900);
        set_skill("wuchang-zhang", 1300);
        set_skill("parry", 850);
        set_skill("buddhism", 85);
        set_skill("literate", 85);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("staff", "wuchang-zhang");
        map_skill("parry", "wuchang-zhang");

        set("env/wimpy", 60);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "regenerate" :),
                (: exert_function, "recover" :),
        }) );

        create_family("������", 37, "����");
        set("auto_perform", 1);
        setup();

        carry_object("/d/shaolin/obj/chanzhang")->wield();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();

}