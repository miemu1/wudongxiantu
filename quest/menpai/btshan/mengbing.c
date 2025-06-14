#include <ansi.h>
inherit NPC;

int do_copy(object me,int maxpot,int type);

void create()
{
      string weapon;
        set_name("�ɹŴ�", ({ "menggu dahan","dahan"}));
        set("gender", "����");
        set("age", random(20) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("combat_exp", 80000 + random(40000));
        set("attitude", "friendly");
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("cuff", 50);
        set_skill("blade", 50);
        set_skill("taizu-quan", 50);
        set_skill("qingmang-jian", 50);
        set_skill("yijinjing",50);
        set_skill("wind-blade", 80+random(180));
        map_skill("blade", "wind-blade");
        map_skill("parry", "wind-blade");
        set_temp("apply/damage", 150);

	map_skill("dodge", "qingmang-jian");
        map_skill("sword", "qingmang-jian");
        map_skill("cuff", "taizu-quan");
        map_skill("force", "yijinjing");

        prepare_skill("cuff", "taizu-quan");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );
        set("max_qi", 450);
        set("eff_jingli", 400);
        set("neili", 700);
        set("max_neili", 700);
        set("jiali", 30);
        weapon = random(2)?"/clone/weapon/gangdao":"/clone/weapon/gangdao";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int do_copy(object me,int maxpot,int type)
{
        int i,j;
        object ob;
        ob = this_object();
        i=maxpot;
        if(type==1)
		i = i - random(20);
		else
	    i = i +10+ random(10);
        if( i < 100) i = 100;

        ob->set("combat_exp", me->query("combat_exp"));
        ob->set_skill("force", i*2/3);
        ob->set_skill("blade", i*2/3);
        ob->set_skill("cuff",  i*2/3);
		ob->set_skill("blade", i*2/3);
        ob->set_skill("dodge", i*2/3);
        ob->set_skill("parry", i*2/3);
        ob->set_skill("wind-blade", i*2/3);
        ob->set_skill("taizu-quan", i*2/3);
        set_skill("yijinjing",i*2/3);
		ob->set("max_qi",     i*10);
        ob->set("eff_jingli", me->query("eff_jingli")*2/3);
        ob->set("max_neili",  i*10);
        ob->set("jiali", i/6);
        if(type==3)
		{ob->set("max_qi",     i*30);
		 ob->set("max_neili",  i*15);
		}
		if(type==2)
        ob->set("max_qi",     i*20);
		ob->reincarnate();
        ob->set("qi",ob->query("max_qi"));
        ob->set("neili",ob->query("max_neili"));
	    return 1;
}

