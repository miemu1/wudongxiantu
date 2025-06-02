
#include <ansi.h>

inherit "/inherit/char/punisher";

void create()
{
        set_name("������ʿ", ({ "yin shi", "yin", "shi" }));
        set("long",  "���������ŵĸ��֣���˵����������ɽ�С�\n");
        set("gender", "����");
        set("age", 55);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 28);
        set("max_qi", 80000);
        set("max_jingli", 15000);
        set("max_douzhi", 5000);
        set("douzhi", 5000);
        set("neili", 40000);
        set("max_neili", 40000);
        set("yanli",2000);
        set("jiali", 1000);
        set("combat_exp", 800000);
        set("level", 15);
        set("shen",3000);
        set("score", 7000);
        set("class","tangmen");
        set_skill("force", 2800);
        set_skill("throwing", 2800);
        set_skill("dodge", 2800);
        set_skill("parry", 2800);
        set_skill("literate", 2800);
        set_skill("hand", 2800);
        set_skill("sword", 2800);
        set_skill("boyun-suowu", 2800);
        set_skill("biyun-xinfa", 2800);
        set_skill("qiulin-shiye", 2800);
        set_skill("wuzhan-mei", 2800);
        set_skill("poison", 2800);
        set_skill("medical", 2800);
        set_skill("tangmen-throwing", 2800);
        set_skill("tangmen-poison", 2800);
        set_skill("tangmen-medical", 2800);
        map_skill("force", "biyun-xinfa");
        map_skill("throwing", "tangmen-throwing");
        map_skill("dodge", "qiulin-shiye");
        map_skill("parry", "wuzhan-mei");
        map_skill("sword", "wuzhan-mei");
        map_skill("hand", "boyun-suowu");
        map_skill("poison", "tangmen-poison");
        map_skill("medical", "tangmen-medical");

        prepare_skill("hand", "boyun-suowu");

        create_family("��������", 0, "��ʿ");

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/tangmen/obj/feidao")->wield();
        carry_object("/d/tangmen/obj/fhshi")->wield();
        carry_object("/d/tangmen/obj/tiejili")->wield();
        carry_object("/d/tangmen/obj/feidao")->wield();
        carry_object("/d/tangmen/obj/fhshi")->wield();
        carry_object("/d/tangmen/obj/tiejili")->wield();
        carry_object("/d/tangmen/obj/qinglianzi")->wield();
        carry_object("/d/tangmen/obj/qinglianzi")->wield();

}
