// killer.c
// by doing

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIW"Ϲ��"NOR"", ({ "xiazi", "xiazi" }) );
	set("gender", "����" );
	set("age", 20 + random(20));

	set("long",
		"��Ҫ������\n"
	);

	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
    set("max_qi", 200000);
	set("eff_qi", 200000);
	set("qi", 200000);
	set("max_neili", 200000);
	set("neili", 200000);
	set("max_jing", 200000);
	set("eff_jing", 200000);
	set("jing", 200000);
	set("combat_exp", 200000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"Ϲ������������̵ģ��Һ��Ҷ�����֪��������ôд��ô��\n",
		"Ϲ�Ӻȵ�����ѱ��ｻ������������������С����\n",
		"Ϲ�ӺǺǴ�Ц���������������ң������ǵ�ù�ˣ�\n"
	}) );

	set_skill("blade", 480);
	set_skill("dodge", 480);
	set_skill("unarmed", 480);
	set_skill("parry", 480);
	set_skill("wuhu-duanmendao", 480);
	set_skill("feiyan-zoubi", 480);

	map_skill("blade", "wuhu-duanmendao");
	map_skill("parry", "wuhu-duanmendao");

	set_temp("apply/damage", 2115);
	set_temp("apply/attack", 1150);
	set_temp("apply/unarmed_damage", 3000);//�����˺�
	set_temp("apply/defense", 1050);

	setup();

	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();

	call_out("do_flee", 1800);
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
		message_vision("$N���������Ŀ���һ��������������ˡ�\n",this_object());
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
 if (sizeof(tar)==1)
		{
       tar[0]->add("jifeng",100);
	   tar[0]->add("combat_exp",5000);
	   tar[0]->add("potential",20000);
	tell_object(tar[0],HIC"��ɱ��"+name()+"��"HIY"�����100���ѵ�ȯ��5000����Ϊ��20000��Ǳ��"NOR"\n");
		}
	CHANNEL_D->do_channel(this_object(), "chat", HIR"������Ȼ����˸��֣�"NOR"");
	::die();
}
