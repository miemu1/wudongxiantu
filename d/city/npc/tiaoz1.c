// yanshang2.c 盐商头子
//Yanqi 08/11/2k
//提升到160k可以做@yeju

#include <ansi.h>
inherit NPC;
int ask_job();
int ask_rbd();

void create()
{
        set_name(HIR"将军"NOR, ({ "jiangjun", "jiang", "jun" }));
        set("gender", "男性");
        set("age", 30+random(20));
        set("long", "他是一个战功赫赫的将军，正在招募抗日勇士。\n");
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

        map_skill("force", "doomforce");//吹雪神功
        map_skill("unarmed", "doomstrike");//寒天神掌
        map_skill("sword", "chuixue-jian");//寒天吹雪剑
        map_skill("dodge", "doomsteps");//吹雪步法
		

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
                "日寇侵华": (: ask_job :),
			    // "日寇侵华": (: ask_rbd :),
                 
        ]));
        set("chat_chance", 3);
        set("chat_msg", ({
                "将军：参军光荣，哪位勇士加入军队，一起抗击日寇日寇呢？\n",
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
                command("say 你实力太强无法无法参军");
                return 1;
        }
/*        
        if (me->query_condition("job_busy")) 
        {
                command("say 你正忙着做别的任务呢？过一会再来向我要任务吧，你也可以输入cond命令查看自己的任务状态。");
                return 1;
        }
*/                       
command("whisper "+me->query("id")+" 日寇十分强大，你可要当心啊，我这就送你去侵华战场！");
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
                command("say 你实力太弱无法挑战");
                return 1;
        }
/*        
        if (me->query_condition("job_busy")) 
        {
                command("say 你正忙着做别的任务呢？过一会再来向我要任务吧，你也可以输入cond命令查看自己的任务状态。");
                return 1;
        }
*/                       
command("whisper "+me->query("id")+"，你可要当心啊，我这就送你去！");
	me->move("/d/maze/rbd/dadao1");
        return 1;
}
