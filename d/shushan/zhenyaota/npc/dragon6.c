//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit NPC;

void create()
{
        set_name("��������", ({ "dragon", "long" }));
         set("title",BLU "�ڰ���֮��"+NOR);
        set("race","Ұ��");
        set("age", 999);
        set("attitude", "aggressive");
        set("str", 40);
        set("int", 25);
        set("con", 40);
        set("cor", 40);
        
        set("max_qi", 100000);
        set("max_jing", 3000);
        set("neili", 3000000);
        set("max_neili", 2000);
        set("jiali", 60);
        set("combat_exp", 300000000);
	 set_skill("dodge", 4000);
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
   set_temp("apply/damage", 2050);
   set_temp("apply/armor", 2050);
        setup();
}

void die()
{
object fengzhu;
if( environment() ) {
fengzhu=new("/d/shushan/zhenyaota/obj/fengzhu");
fengzhu->move(environment());
        message("sound", CYN"ͻȻһ�����ӴӺڰ���֮���������˳�����\n" NOR, environment());
}
destruct(this_object());
}

