//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit NPC;

void create()
{
        set_name("��������", ({ "dragon", "long" }));
          set("title", HIY"̫Ԫ���ɵ�����" +NOR);
        set("race","Ұ��");
        set("age", 999);
        set("attitude", "aggressive");
        set("str", 40);
        set("int", 25);
        set("con", 20);
        set("cor", 20);
        
        set("max_qi", 30000);
        set("max_jing", 30000);
        set("neili", 3000);
        set("max_neili", 2000);
        set("jiali", 60);
        set("combat_exp", 50000000);
        set("limbs", ({ "ͷ��", "����", "ǰצ", "β��", "��Ƥ", "��צ"}) );
        set("verbs", ({ "bite", "claw"}) );

        set_skill("force", 1200);
        set_skill("dodge", 1200);
        set_skill("parry", 1200);
        set_skill("unarmed", 1200);
/*
        map_skill("dodge", "dragonstep");
        map_skill("spells", "seashentong");
        map_skill("force", "dragonforce");
        map_skill("unarmed", "dragonfight");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "breathe" :),
//              (: exert_function, "shield" :),
//              (: exert_function, "roar" :),
        }) );
*/
   add_temp("apply/damage", 500);
   add_temp("apply/armor", 500);
        setup();
}

