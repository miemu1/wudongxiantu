//shangren

inherit NPC;

void create()
{
        set_name("����", ({ "shangren"}) );
        set("gender", "����" );
        set("age", 36);
        set("long", "����һλ����ԭ�������ˡ�\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set_skill("cuff", 30);
        set_skill("dodge", 50);
        set("chat_chance", 10);
        set("chat_msg", ({
                "���������๼��˵�����Ҽ����������ŵİ����£�\n",
        }) );
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                "����˵���������Ҵ����ŵİ��������������ھ�ȻҪ����·�ߣ�\n",
                }) );

        setup();
        add_money("silver", 50);
        carry_object("/clone/misc/cloth")->wear();
}

