//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit NPC;

void create()
{
        set_name("��������", ({ "dragon", "long" }));
           set("title",HIM "СС��С����"+NOR);
        set("race","Ұ��");
        set("age", 999);
        set("attitude", "aggressive");
        set("str", 40);
        set("int", 25);
        set("con", 40);
        set("cor", 40);
        
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 3000);
        set("max_neili", 2000);
        set("jiali", 60);
        set("combat_exp", 50000000);
        set("limbs", ({ "ͷ��", "����", "ǰצ", "β��", "��Ƥ", "��צ"}) );
        set("verbs", ({ "bite", "claw"}) );
/*
        set_skill("force", 120);
        set_skill("dragonforce", 120);
        set_skill("dodge", 4000);
        set_skill("parry", 120);
        set_skill("unarmed", 120);
        set_skill("spells", 120);
        set_skill("seashentong", 120);
        set_skill("dragonfight", 120);
        set_skill("dragonstep", 120);   

        map_skill("dodge", "dragonstep");
        map_skill("spells", "seashentong");
        map_skill("force", "dragonforce");
        map_skill("unarmed", "dragonfight");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
//              (: cast_spell, "breathe" :),
//              (: exert_function, "shield" :),
//              (: exert_function, "roar" :),
                (: perform_action, "unarmed","double" :),
        }) );
*/
   add_temp("apply/damage", 50);
   add_temp("apply/armor", 50);
        setup();
}

