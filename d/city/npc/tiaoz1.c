// yanshang2.c ����ͷ��
//Yanqi 08/11/2k
//������160k������@yeju

#include <ansi.h>
inherit NPC;
int ask_job();
int ask_rbd();

void create()
{
        set_name(HIR"����"NOR, ({ "jiangjun", "jiang", "jun" }));
        set("gender", "����");
        set("age", 30+random(20));
        set("long", "����һ��ս���պյĽ�����������ļ������ʿ��\n");
        set("combat_exp", 90000000);        
        set("shen_type", 1);
        set("attitude", "peaceful");
        
        set_skill("force", 6500);
        set_skill("unarmed", 6500);
        set_skill("sword", 6500);
        set_skill("parry", 6500);
        set_skill("dodge", 6500);
        set_skill("throwing", 6500);
	
        set_skill("doomforce", 6500);
        set_skill("doomstrike", 6500);
        set_skill("doomsteps", 6500);
		set_skill("doomsword", 6500);
	    set_skill("chuixue-jian",6500);

        map_skill("force", "doomforce");//��ѩ��
        map_skill("unarmed", "doomstrike");//��������
        map_skill("sword", "chuixue-jian");//���촵ѩ��
        map_skill("dodge", "doomsteps");//��ѩ����
		

     set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chuixuei" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.tianwai" :),
		(: perform_action, "sword.wuhen" :),
	}));
	    set_temp("apply/defense", 2500);
	    set_temp("apply/unarmed_damage", 2500);
	    set_temp("apply/armor", 2500);
        set_temp("apply/attack", 2000005);
        //set_temp("apply/defense", 200005);
        set("inquiry", ([
                "�տ��ֻ�": (: ask_job :),
			    // "�տ��ֻ�": (: ask_rbd :),
                 
        ]));
        set("chat_chance", 3);
        set("chat_msg", ({
                "�������ξ����٣���λ��ʿ������ӣ�һ�𿹻��տ��տ��أ�\n",
        }) );
        //carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
        setup();  
        carry_object("/clone/weapon/changjian")->wield();		
}

void init()
{
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

int ask_job()
{
        object me;
        int exp1;
        
        me=this_player();

        exp1=me->query("zhuanshi");
    
        if( exp1 > 7)
        {
                command("say ��ʵ��̫ǿ�޷��޷��ξ�");
                return 1;
        }
/*        
        if (me->query_condition("job_busy")) 
        {
                command("say ����æ������������أ���һ����������Ҫ����ɣ���Ҳ��������cond����鿴�Լ�������״̬��");
                return 1;
        }
*/                       
command("whisper "+me->query("id")+" �տ�ʮ��ǿ�����Ҫ���İ������������ȥ�ֻ�ս����");
	me->move("/d/maze/jiutou/enter1");
        return 1;
}


int ask_rbd()
{
        object me;
        int exp1;
        
        me=this_player();

        exp1=me->query("combat_exp");
    
        if( exp1 < 400000)
        {
                command("say ��ʵ��̫���޷���ս");
                return 1;
        }
/*        
        if (me->query_condition("job_busy")) 
        {
                command("say ����æ������������أ���һ����������Ҫ����ɣ���Ҳ��������cond����鿴�Լ�������״̬��");
                return 1;
        }
*/                       
command("whisper "+me->query("id")+"�����Ҫ���İ������������ȥ��");
	me->move("/d/maze/rbd/dadao1");
        return 1;
}
