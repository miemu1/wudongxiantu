//tangjue.c

#include <ansi.h>;
#include "tangmen.h"

inherit NPC;
inherit F_MASTER;

int carry_obj();


void create()
{
        set_name("�ƾ�", ({ "tang jue","tang"}));
        set("nickname", HIR "������" NOR);
        set("long", 
"��������֮һ���ƾ�������������������˶���֪�����ľ��������еľ��Ű������������á�\n");
        set("gender", "����");
        set("age", 32);
        set("class", "tangmen");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 26);
        set("con", 26);
        set("dex", 27);
        set("max_qi", 8000);
        set("max_jingli", 2500);
        set("max_jing", 1600);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 120);
        set("combat_exp", 1500000);
        set("level", 45);
        set("score", 8000);

        set_skill("force", 180);
        set_skill("throwing", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("literate", 180);
        set_skill("hand", 180);
        set_skill("sword", 180);
        set_skill("boyun-suowu", 180);
        set_skill("biyun-xinfa", 180);
        set_skill("qiulin-shiye", 180);
        set_skill("wuzhan-mei", 180);
        set_skill("medical", 180);
        set_skill("poison", 180);
        set_skill("tangmen-throwing", 180);
        set_skill("tangmen-poison", 180);
        set_skill("tangmen-medical", 180);        
        
        map_skill("force", "biyun-xinfa");
        map_skill("throwing", "tangmen-throwing");
        map_skill("dodge", "qiulin-shiye");
        map_skill("parry", "boyun-suowu");
        map_skill("sword", "wuzhan-mei");        
        map_skill("hand", "boyun-suowu");
        map_skill("poison", "tangmen-poison");
        map_skill("medical", "tangmen-medical");
        
        prepare_skill("hand", "boyun-suowu");
        
        set_temp("apply/damage", 100);  
        set_temp("apply/unarmed_damage", 100);  
        set_temp("apply/armor", 200);  
        
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        	( : command("yun recover") : ),
        	( : command("yun recover") : ),
        	( : command("use qian") : ),
        	( : command("use hua") : ),
                ( : command("wield all") : ),
                ( : command("wield all") : ),
        	(: perform_action, "throwing.san" :), 
        	( : carry_obj : ),
        	( : carry_obj : ),
        	
        }) );
        
        set("chat_chance" , 8 );
        set("chat_msg" , ({
        	"����֮�󣬵����ݲ�Ф�ӵܣ�\n",
        	"ѧ��֮�������ڷܣ�\n",
        	"���ŵĵ���Ҫ�Ǻð���\n",
        }) );
 	
        	
        	
        create_family("��������", 2, "��ϵ����");

        set("master_ob", 3);
	setup();
        carry_object("/clone/misc/cloth")->wear();
        set_temp("handing", carry_object("/d/tangmen/obj/jili"));  
        carry_object("/d/tangmen/obj/qinglianzi")->wield();
}

int carry_obj()
{
	object me,ob;
	
	me = this_object();
	
        switch(2)
	{
        case 0:
                ob = new("/kungfu/class/tangmen/obj/hua");
	        break;
        case 1:
                ob = new("/d/tangmen/obj/qianqian");
	        break;
        }
	 
        ob->move(me);
	return 1;
}	 

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))  
                return;
                        
	if ((int)ob->query("shen") < 5000 )
	 {
		command("say ����ͽ��ע�ص��У�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}

	if ((int)ob->query_skill("biyun-xinfa", 1) < 120) {
		command("say ������Ȼ�԰���Ϊ����������Ҫ����������"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ���ڱ����ķ��϶��µ㹦��");
		return;
	}
	if (ob->query("int") < 25) {
		command("say ��������ע�ص��ӵ���ѧ��Ϊ��");
		command("say ���ɹ���Ҫ���������ã��������������������Զ�⾳�����Բ����ǲ��еġ�");
		command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
		return;
	}
	command("say ���������Ҿ������㣬��ס�Ժ�Ҫ�ڽ�����������ร�");
	command("recruit " + ob->query("id"));
}
