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
	set_name(RED"西门吹雪"NOR, ({ "ye gucheng", "ye","gucheng" }) );
    set("nickname", HIY "白云客卿" NOR);
    set("gender", "男性");
    set("shen_type", 1);
    set("age", 33);
    set("long",
        "他就是白云城客卿。
\n");
    set("attitude", "peaceful");

    set("per", 21+random(100));
    set("str", 21+random(100));
    set("int", 30+random(100));
    set("con", 26+random(100));
    set("dex", 30+random(100));
	//自动PFM
	set("auto_perform", 1);

    set("inquiry", ([
        "夜孤城"   : "呵呵 \n",
        "白云城" : "百云孤城\n",
    ]));


    set("qi", 2000000);
    set("max_qi", 200000);
    set("jing", 1000000);
    set("max_jing", 1000000);
    set("neili", 420000);
    set("max_neili", 420000);
    set("jiali", 4000);

    set("combat_exp", 2200000);
    set("score", 0);

        set_skill("force", 2000);
        set_skill("unarmed", 2000);
        set_skill("sword", 50);
        set_skill("parry", 2000);
        set_skill("dodge", 2000);
        set_skill("throwing", 2000);
	
        set_skill("doomforce", 2000);
        set_skill("doomstrike", 2000);
        set_skill("doomsteps", 2000);
		set_skill("doomsword", 2000);
	    set_skill("chuixue-jian",2000);

        map_skill("force", "doomforce");//吹雪神功
        map_skill("unarmed", "doomstrike");//寒天神掌
        map_skill("sword", "doomsword");//寒天吹雪剑
        map_skill("dodge", "doomsteps");//吹雪步法
    create_family("白云城", 1, "客卿");
	
	  set("inquiry", ([
                "拜师"        : "心有正气",
                //"电光四射"    : (: ask_skill1 :),
        ]));

    set("master_ob",5);
    
	setup();
     carry_object("/clone/weapon/gangjian")->wield();
   
    carry_object("/d/heimuya/obj/yuxiao");
}

 
void attempt_apprentice(object me)
{
        string purename, name, new_name;

       


	

        if ((int)me->query("shen") < 10000)
        {
                command("heng");
                command("say 我们孤山白云城向来不问江湖事，也不结交你这样的名声不好之人。");
                return;
        }

	
        if ((int)me->query("shen") < -1000)
        {
                command("heng");
                command("say 我白云城向来不问江湖事，更不会结交名声不好之人。");
                return;
        }

        command("say 好吧，既然你有心练武，我就收下你。");
        command("recruit " + me->query("id"));
}