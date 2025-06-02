// tangtian.c
#include <ansi.h>
#include "tangmen.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "tang tian", "tang", "tian"}));
	set("long", "�������������ӵĴ����ˣ���������һ������֮�У���������Ҳ��ȻΪһ��֮�ۡ���\n");
	set("gender", "Ů��");
	set("age", 25);
        set("class", "tangmen");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 28);
        set("max_qi", 8000);
        set("max_jingli", 1500);
        set("max_jing", 1500);
        set("neili", 4000);
        set("max_neili", 4000);
        set("yanli",200);
        set("jiali", 100);
        set("combat_exp", 1000000);
        set("level", 35);
        set("shen",3000);
        set("score", 7000);

        set_skill("force", 150);
        set_skill("throwing", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("literate", 150);
        set_skill("hand", 150);
        set_skill("sword", 150);
        set_skill("boyun-suowu", 150);
        set_skill("poison", 150);
        set_skill("medical", 150);
        set_skill("biyun-xinfa", 150);
        set_skill("qiulin-shiye", 150);
        set_skill("wuzhan-mei", 150);
        set_skill("tangmen-throwing", 150);
        set_skill("tangmen-poison", 150);
        set_skill("tangmen-medical", 150);        
        
        map_skill("force", "biyun-xinfa");
        map_skill("throwing", "tangmen-throwing");
        map_skill("dodge", "qiulin-shiye");
        map_skill("parry", "wuzhan-mei");
        map_skill("sword", "wuzhan-mei");
        map_skill("hand", "boyun-suowu");
        map_skill("medical", "tangmen-medical");
        map_skill("poison", "tangmen-poison");
        
        prepare_skill("hand", "boyun-suowu");
        
	create_family("��������", 3, "����");

	
        set_temp("apply/damage", 100);  
        set_temp("apply/unarmed_damage", 100);  
        set_temp("apply/armor", 200);          

        set("master_ob", 2);
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
        set_temp("handing", carry_object("/d/tangmen/obj/jili"));          
}


void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))  
                return;
                        
        if ( ob->query("family/family_name") != "��������" )
        {
                command("say �����Ĵ����������������ң��������������ˣ��Ҳ�������Ϊͽ����\n");
                return;
        }

        if ( (int)ob->query ("combat_exp") < 200000) 
        {
        	command("say �������Ϊ̫�٣��������õĹ���ģ���\n");
        	return;
        }	

        if ( ob->query_skill("biyun-xinfa", 1) < 80 && ob->query_skill("tangmen-throwing", 1) < 80 )
        {
        	command("say ������ķ��Ͱ�����̫������Ҫ���Ͱ�����\n");
        	return;
        }	
        

        command("say ���ðɣ��ӽ��������������ĵ����ˡ���\n");
        command("recruit " + ob->query("id"));
}


