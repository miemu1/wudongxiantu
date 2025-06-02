// killer.c
// by doing

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIC"��"HIG"��"NOR"", ({ "shushen", "shushen" }) );
	set("gender", "����" );
	set("age", 20 + random(20));

	set("long",
		"��������ɲ��һ������ī�͡�\n"
	);

	set("str", 250);
	set("con", 250);
	set("dex", 250);
	set("int", 250);
    set("max_qi", 1000000);
	set("eff_qi", 1000000);
	set("qi",1000000);
	set("max_neili",1000000);
	set("neili",1000000);
	set("max_jing",1000000);
	set("eff_jing",1000000);
	set("jing",1000000);
	set("combat_exp",1000000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("jiali", 300);
	set("chat_msg_combat", ({
		HIR"�����޵������𣬹��ܣ���������\n",

	}) );

	set_skill("blade", 380);
	set_skill("dodge", 380);
	set_skill("force", 380);
	set_skill("unarmed", 380);
	set_skill("parry", 380);
	set_skill("rulai-shenzhang", 380);
	set_skill("wuhu-duanmendao", 380);
	set_skill("feiyan-zoubi", 380);

	map_skill("blade", "wuhu-duanmendao");
	map_skill("parry", "wuhu-duanmendao");
	map_skill("dodge", "feiyan-zoubi");
	map_skill("unarmed", "rulai-shenzhang");

	set_temp("apply/damage", 425);
	set_temp("apply/unarmed_damage", 300);//�����˺�
	set_temp("apply/attack", 450);
	set_temp("apply/defense", 450);

	setup();

	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();

	call_out("do_flee", 3600);
}

void do_flee()
{
		object ob;
		object a=this_object();
		ob=new("/d/city/wlcw/npc/fulao");
        if(a->is_fighting())
			return 0;
	if (objectp(present(ob, environment(a))))
			return 0;
		message_vision("$N����һ̾��һ���ṦƮȻ��ȥ��\n",this_object());
	destruct(this_object());
}
/*
void init()
{
	object ob;

	::init();

	ob = this_player();
	remove_call_out("kill_ob");
      call_out("kill_ob", 1, ob); 
}*/
void die()
{
	mapping yours,my,a,b;
	object ob,*tar;
	  object gift;
	ob=this_object();
	tar = ob->query_enemy();
		::die();
 if (sizeof(tar)==1)
		{
       tar[0]->add("jifeng",500);
	   tar[0]->add("combat_exp",100000);
	   tar[0]->add("potential",500000);
    gift = new("/clone/gift/tianwai");
    gift->move(tar[0]);
	tell_object(tar[0],HIC"��ɱ��"+name()+"��"HIY"�����500��ȯ��10�����Ϊ��50���Ǳ��,������һ��������ʯ��"NOR"\n");
		}else if(sizeof(tar)==2)
		{
       tar[0]->add("jifeng",500);
	   	   tar[0]->add("combat_exp",100000);
	   tar[0]->add("potential",500000);
	  gift = new("/clone/gift/tianwai");
    gift->move(tar[0]);
	tell_object(tar[0],HIC"��ɱ��"+name()+"��"HIY"�����500��ȯ��10�����Ϊ��50���Ǳ��,������һ��������ʯ��"NOR"\n");
       tar[1]->add("jifeng",500);
	   tar[1]->add("combat_exp",100000);
	   tar[1]->add("potential",500000);
	       gift = new("/clone/gift/tianwai");
    gift->move(tar[1]);
	tell_object(tar[1],HIC"��ɱ��"+name()+"��"HIY"�����500��ȯ��10�����Ϊ��50���Ǳ��,������һ��������ʯ��"NOR"\n");
		}else if(sizeof(tar)==3)
		{
			    gift = new("/clone/gift/tianwai");
    gift->move(tar[0]);
       tar[0]->add("jifeng",500);
	   tar[0]->add("combat_exp",100000);
	   tar[0]->add("potential",500000);
	tell_object(tar[0],HIC"��ɱ��"+name()+"��"HIY"�����500��ȯ��10�����Ϊ��50���Ǳ��,������һ��������ʯ��"NOR"\n");
       tar[1]->add("jifeng",500);
	   	   tar[1]->add("combat_exp",100000);
	   tar[1]->add("potential",500000);
	       gift = new("/clone/gift/tianwai");
    gift->move(tar[1]);
	tell_object(tar[1],HIC"��ɱ��"+name()+"��"HIY"�����500��ȯ��10�����Ϊ��50���Ǳ��,������һ��������ʯ��"NOR"\n");
       tar[2]->add("jifeng",500);
	   	   tar[2]->add("combat_exp",100000);
	   tar[2]->add("potential",500000);
	       gift = new("/clone/gift/tianwai");
    gift->move(tar[2]);
	tell_object(tar[2],HIC"��ɱ��"+name()+"��"HIY"�����500��ȯ��10�����Ϊ��50���Ǳ��,������һ��������ʯ��"NOR"\n");
		}
CHANNEL_D->do_channel(this_object(), "chat", HIR"˭���Լǣ��¹������⣿"NOR"");	

}
