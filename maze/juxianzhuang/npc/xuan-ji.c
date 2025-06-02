// Npc: /kungfu/class/shaolin/xuan-ji.c
// Date: YZC 96/01/19

inherit NPC;

void create()
{
        set_name("���Ŵ�ʦ", ({
                "xuanji dashi",
                "xuanji",
                "dashi",
        }));
        set("long",
                "����һλ�����ü����ɮ����һϮ��˿�ػ����ġ�����ĸߴ�\n"
                "���ֹ�ϥ��˫Ŀ������գ�ȴ��ʱ���һ�ƾ��⡣\n"
        );


        set("nickname", "����Ժ����");
        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 70);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 150);
        set("combat_exp", 1000000);
        set("score", 500000);

        set_skill("force", 1400);
        set_skill("yijin-jing", 1400);
        set_skill("dodge", 1400);
        set_skill("shaolin-shenfa", 1400);
        set_skill("parry", 1400);
        set_skill("hand", 1400);
        set_skill("claw", 1400);
        set_skill("club", 1400);
        set_skill("staff", 1400);
        set_skill("zui-gun", 1400);
        set_skill("pudu-zhang", 1400);
        set_skill("qianye-shou", 1400);
        set_skill("yingzhua-gong", 1400);
        set_skill("buddhism", 1400);
        set_skill("literate", 1400);

        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("finger", "nianhua-zhi");
        map_skill("hand", "qianye-shou");
        map_skill("claw", "yingzhua-gong");
        map_skill("staff", "pudu-zhang");
        map_skill("club", "zui-gun");
        map_skill("parry", "yingzhua-gong");

        prepare_skill("finger", "nianhua-zhi");

        create_family("������", 36, "����");

        set("auto_perform", 1);
        setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

