//boy.c

inherit NPC;

void create()
{
        int i,amun;
        string *order = ({"��", "��", "��", "��", "��", "��", "֣", "��", "��",
                "��", "��", "��", "��", "��", "��", "κ", "��", "��", "��", "��"});
        string *orderr = ({"����", "����", "�Թ�", "СС", "����",
                "����", "ѻѻ", "����", "èè"});
        set_name( order[random(20)] + orderr[random(8)], ({ "boy", "kid" }) );
        set("title", "��֪�к�");
        set("gender", "����" );
        set("age", random(5)+4);
        set("long",
                "����С, �ܺ��۷�.\n");
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set("attitude", "peaceful");
        set("combat_exp", random(1000));
        set("max_qi", 100);
        set("qi", 100);
        set("max_jingli", 100);
        set("jingli", 100);
        set_skill("cuff", 1+random(10));
        setup();
        carry_object("clone/misc/cloth")->wear();
}

