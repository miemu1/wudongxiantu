// tangzg.c ���ƹ� 

inherit NPC;
inherit F_VENDOR;
//inherit F_DEALER;

void create()
{
        set_name("���ƹ�", ({ "tang zhanggui", "tang" }));
        set("title", "�Ƽ������ϰ�");
        set("shen_type", 1);

        set("gender", "����");
        set("age", 45);
        set("long",
                "���ƹ������ŵļ��ˣ����˶���������ˡ�\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);

        set("combat_exp", 40000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/tangmen/obj/beixin",
                "/d/tangmen/obj/huwan",
                "/d/tangmen/obj/zhitao",
                "/d/tangmen/obj/shoutao",
                
                
        }));
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}


