//shushan2 by yushu@SHXY 2000.12 
inherit NPC;
void create()
{
       set_name("��ɽ����", ({"shouwei dizi", "dizi"}));
       set("title", "��������");
       set("long","��ɽ���ɵĽ�������\n");
       set("gender", "����");
       set("age", 28);
	set("str", 25);
       set("attitude", "aggressive");
        set("max_jingli", 400);
        set("jingli", 400);
        set("max_neili", 400);
        set("neili", 400);
        set("jiali", 400);
       set_skill("sword",140);
       set_skill("parry",140);
	set_skill("dodge",140);
        set_skill("fumozhang",140);
       set_skill("unarmed",140);
       set_skill("force",140);
      set_skill("shushan-force",140);
 	set_skill("yujianshu",140);
	set_skill("zuixian-steps",140);
	map_skill("dodge", "zuixian-steps");
	map_skill("sword", "yujianshu");
	map_skill("parry", "yujianshu");
	map_skill("unarmed", "fumozhang");
	map_skill("force", "shushan-force");
       set("max_qi",1000);
	set("bellicosity", 5000);
       set("max_jing",1000);
       set("neili",2000);
       set("max_neili",1000);
       set("jiali", 100);
       set("combat_exp", 300000);
       set("chat_chance_combat", 20);
       set("chat_msg_combat", ({
                (: perform_action, "sword", "fumo" :),
                (: cast_spell, "fu" :),
}) );

       setup();
       carry_object("/clone/weapon/changjian")->wield();
       carry_object("/clone/cloth/cloth")->wear();
//        carry_object("/d/obj/armor/yinjia")->wear();
       add_money("silver", 50);
       }
       void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "��ɽ���Ӻȵ������������ˣ��ô���ɽ���أ�������ˣ�\n");
}
