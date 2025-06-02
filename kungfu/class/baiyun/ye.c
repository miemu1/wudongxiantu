// dongfang.c
//Updated by y111

#include <ansi.h>


inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

string ask_book();
mixed ask_pfm();

void create()
{
	set_name(RED"Ҷ�³�"NOR, ({ "ye gucheng", "ye","gucheng" }) );
    set("nickname", HIY "����" NOR);
    set("gender", "����");
    set("shen_type", 1);
    set("age", 33);
    set("long",
        "�����ǽ���Ҷ�³ǣ����Ƴǳ�����
\n");
    set("attitude", "peaceful");

    set("per", 21+random(100));
    set("str", 21+random(100));
    set("int", 30+random(100));
    set("con", 26+random(100));
    set("dex", 30+random(100));
	//�Զ�PFM
	set("auto_perform", 1);

    set("inquiry", ([
        "ҹ�³�"   : "�Ǻ� \n",
        "���Ƴ�" : "���ƹ³�\n",
    ]));


    set("qi", 900000);
    set("max_qi", 900000);
    set("jing", 1000000);
    set("max_jing", 1000000);
    set("neili", 450000);
    set("max_neili", 450000);
    set("jiali", 4000);

    set("combat_exp", 25000000);
    set("score", 0);

	
	
	 
	 
    set_skill("parry", 2000);
    set_skill("dodge", 2000);
    set_skill("force", 2000);
    set_skill("literate", 2200);
	set_skill("sword", 2000);
	set_skill("unarmed",2000);
	set_skill("changquan",2000);
	set_skill("feixian-steps",2000);
	set_skill("feixian-sword",2000);
	set_skill("feixian-jian",2000);
	set_skill("jingyiforce",2000);
	set_skill("jingyi-shengong",2000);
    map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-jian");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");
	
	
	

	
	
    create_family("���Ƴ�", 1, "����");

    set("master_ob",5);
    
	setup();
     carry_object("/clone/weapon/gangjian")->wield();
    //carry_object("/d/wanjiegu/npc/obj/qi-dress")->wear();
    carry_object("/d/heimuya/obj/yuxiao");
}

 

void attempt_apprentice(object ob)
{
     
     if((string)ob->query("family/master_name") == "Ҷ�³�")
     {
          command("say ��Խ����Խ��˳�ۣ�����ҹ���");
          return;
     }
     if ((int)ob->query("combat_exp") < 600000)
     {
          command("say �������΢ĩ���򣬻����ȸ���ͽ�ܶ������ɣ�");
          return;
     }

     /*if((int)ob->query_skill("feixian-steps", 1) < 50)
     {
          command("say ���ŵ��ڹ��������㻹û���ã���Ҫ���¿๦���У�");
          return;
     }*/

     command("xixi");
     command("recruit " + ob->query("id")); 
     command("say �ã��ã��Ұ��Ƴ��ֶ���һ����������");
     ob->set("title", HIR "�����״�" NOR);
}

