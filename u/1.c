// This program is a part of NITAN MudLIB

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIM "��ħ" NOR, ({ "xinmo" }));
        set("gender", "����" );
        set("age", 30 + random(30));
        set("long", "��������޷����˿��������һ���ˡ�");
        set("str", 800);
        set("int", 800);
        set("con", 800);
        set("dex", 800);
        set("shen", 0);
        set_temp("apply/attack", 500);
        set_temp("apply/unarmed_damage", 500);
        set_temp("apply/damage", 500);
        set_temp("apply/armor", 500);
        set_temp("apply/reduce_busy", 100);
        set_temp("apply/avoid_forget", 100);
        set("reborn/times", 1);
        set("max_qi", 2100000);
        set("eff_qi", 2100000);
        set("qi", 2100000);
        set("max_jing", 1000000000);
        set("jing", 1000000000);
        set("eff_jing", 1000000000);
        set("max_jingli", 1000000000);
        set("jingli", 1000000000);
        set("neili", 200000000);
        set("max_neili", 1000000);
        set("jiali", 50000);
        set("combat_exp", 2100000000);
        set_skill("unarmed", 500+random(50));
        set_skill("finger", 500+random(50));
        set_skill("claw", 500+random(50));
        set_skill("strike", 500+random(50));
        set_skill("hand", 500+random(50));
        set_skill("cuff", 500+random(50));
        set_skill("parry", 500+random(50));
        set_skill("dodge", 500+random(50));
        set_skill("force", 500+random(50));
        set_skill("sword",500+random(50));
        set_skill("blade", 500+random(50));
        set_skill("zuoyou-hubo", 360);
        set_skill("kuihua-mogong", 500+random(50));
        set_skill("qiankun-danuoyi", 500+random(50));
        set_skill("martial-cognize", 500+random(50));
        set_skill("literate", 500+random(50));
        map_skill("parry", "qiankun-danuoyi");
        map_skill("force", "kuihua-mogong");
        map_skill("dodge", "kuihua-mogong");
        map_skill("unarmed", "kuihua-mogong");
        map_skill("finger", "kuihua-mogong");
        map_skill("strike", "kuihua-mogong");
        map_skill("hand", "kuihua-mogong");
        map_skill("cuff", "kuihua-mogong");
        map_skill("claw", "kuihua-mogong");
        map_skill("sword", "kuihua-mogong");
        map_skill("force", "kuihua-mogong");
        map_skill("dodge", "kuihua-mogong");
        map_skill("unarmed", "kuihua-mogong");
        map_skill("sword", "kuihua-mogong");
        map_skill("parry", "kuihua-mogong");
        prepare_skill("unarmed", "kuihua-mogong");
        prepare_skill("finger", "kuihua-mogong");

        set("chat_chance", 60);

        setup();
         carry_object("/clone/weapon/gangjian")->wield();         
	//     carry_object("/clone/newbox/equip/armor-box")->set_amount(1);

}

void init() 
{ 
        object ob, me;
        
        me = this_player();  
        ob = this_object();
         
        ::init(); 
        if (interactive(me) && visible(me) &&  
            ! is_fighting())  
        { 
                ob->set_name((me->query("name") + "--ħ"), ({ (me->query("id") + "-xinmo") }));
                NPC_D->copy_from_me(ob, me, 200);
                kill_ob(me); 
        } 
} 


int accept_fight(object ob)
{
        ob=this_player();
        command("say ���úã��ҿ��ǲ�����������ġ�\n"); 
        ob->set_temp("m_success/��Ӱ",1);  
        remove_call_out("kill_ob");
        call_out("kill_ob", 1, ob);
        return 1;
}

void die()
{
	object me,ob,jmem,item;
	mapping team;
	int i,size,level,exp,rand,pot;
	string file;

	ob = this_object();
	me = ob->query_temp("last_damage_from");

        rand = 2+random(100);
	if(rand >= 1)
	{
		item = new("/d/maze/qnmj/obj/qn");
		if(item)
		{
			item->set_amount(50);
			item->move(environment(ob));
		}
	}


	destruct(ob);
}
