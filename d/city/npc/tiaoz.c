// yanshang2.c 盐商头子
//Yanqi 08/11/2k
//提升到160k可以做@yeju

#include <ansi.h>
inherit NPC;
int ask_job();
int ask_rbd();
int ask_lhfb();

void create()
{
        set_name(HIR"挑战使"NOR, ({ "fu ben", "fu", "ben" }));
        set("gender", "女性");
        set("age", 12+random(20));
        set("long", "他是boss挑战传送使。\n");
        set("combat_exp", 90000000);        
        set("shen_type", 1);
        set("attitude", "peaceful");
        
        set_skill("unarmed", 90000000);
        set_skill("dodge", 2000000);
        set_temp("apply/attack", 2000005);
        //set_temp("apply/defense", 200005);
        set("inquiry", ([
                "穷奇妖兽挑战": (: ask_job :),
			    // "日寇侵华": (: ask_rbd :),
				"轮回副本": (: ask_lhfb :),
                 
        ]));
        set("chat_chance", 3);
        set("chat_msg", ({
                "挑战使：那位英雄来挑战一下穷奇妖兽呢？\n",
        }) );
        //carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
        setup();        
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
command("whisper "+me->query("id")+" 穷奇妖兽十分强大，你可要当心啊，我这就送你去无尽深渊！");
	me->move("/d/maze/jiutou/enter");
        return 1;
}

int ask_lhfb()
{
        object me;
        int exp1;
        
        me=this_player();

        exp1=me->query("combat_exp");
    
        if( exp1 < 4000000000&&(me->query("id") != "dodge_1")&&(me->query("id") != "sword_1"))
        {
                command("say 你实力太弱无法挑战");
                return 1;
        }
		
		if (!(me->query_skill("lunhui-sword", 1)))
                return notify_fail("你六道仙经火候不够，难以施展" + name() + "。\n");
/*        
        if (me->query_condition("job_busy")) 
        {
                command("say 你正忙着做别的任务呢？过一会再来向我要任务吧，你也可以输入cond命令查看自己的任务状态。");
                return 1;
        }
*/                       
command("whisper "+me->query("id")+" 轮回副本神秘莫测，变化无常，路上小心！");
write(HIB+"\n你只觉得眼前一花，突然什么也听不见，什么也看不见......\n\n"+NOR,);
        write(HIB+"只觉得身体不断的下坠......\n\n"+NOR,);
       write( HIB+"坠向无尽的黑暗......\n\n"+NOR,);
        write(HIB+"忽然仿佛一只大手托了你一下......\n\n"+NOR,);
        write(HIB+"冥冥中隐约传来阵阵叮叮当当碰撞声......\n\n"+NOR,);
        write(HIB+"你睁眼一看，发现自己已置身于一个喧嚣而似乎并不陌生的世界......\n\n"+NOR,);
	
	me->move("/d/death/liudaolunhui/wujiandao");
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
