// killer.c
// by doing
inherit NPC;
#include <ansi.h>
#include "/d/fuben/longzu/npc/fb_skill.h"





void create()
{
	set_name(HIW"äɮ"NOR"", ({ "mangseng", "mangseng" }) );
	set("gender", "����" );
	set("age", 20 + random(20));

	set("long",
		"��Ҫ������\n"
	);

	set("str", 25);
	set("con", 25);
	set("dex", 25);
	 set("lvl",100);//������������ɳ�ֵ
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

	

	map_skill("blade", "wuhu-duanmendao");
	map_skill("parry", "wuhu-duanmendao");
	set_temp("apply/damage", 215);
	 set("sequence",5);
	set_temp("apply/attack", 150);
	
	
	set_temp("apply/defense", 150);

	setup();

	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();

	call_out("do_flee", 1800);
	set_basic();
	setup();
}
int inheritman(object newob,object ob,int manskills,string*manmsg,int newsequence)
{
object me = this_object()->query_last_damage_from();
 

    newob->set("qi", ob->query("lvl")*50);
	newob->set("max_qi",ob->query("max_qi")*2);
	newob->set("eff_qi",ob->query("max_qi")*2 );
	newob->set("jing", ob->query("max_jing")*2);
	newob->set("max_jing", ob->query("max_jing")*2);
	newob->set("neili", ob->query("max_neili")*2);
	newob->set("max_neili", ob->query("max_neili")*2);
	newob->set("sequence",newsequence);
	
	 newob->set("name",manmsg[3]);
	 newob->set("title",manmsg[2]);
	newob->set("lvl",ob->query("lvl")+120);
	newob->set_temp("apply/jiali", ob->query("lvl"));
	newob->set_temp("apply/attack", ob->query("lvl"));
	newob->set_temp("apply/defense", ob->query("lvl"));
	newob->set_temp("apply/damage", ob->query("lvl")*3/2);
	newob->set_temp("apply/unarmed_damage", ob->query("lvl")*3/2);
	return 1;
}
int distribute_skill(object ob,int skill_level)
{
int ran,size,i;
string *skills;
	ran = random(sizeof(skill_map));
	size = sizeof(skill_map[ran]);
	skills = keys(skill_map[ran]);

	for(i = 0; i < size; i++)
	{
		if (!skill_map[ran][skills[i]])
		{
			ob->set_skill(skills[i], skill_level);
		}
		else
		{
			ob->set_skill(skills[i], skill_level);
			ob->set_skill(skill_map[ran][skills[i]], skill_level);
			ob->map_skill(skill_map[ran][skills[i]], skills[i]);
		}
	}
	return 1;
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

void die()
{
	mapping yours,my,a,b;
	object ob,*tar;
	  object gift;
	ob=this_object();
	tar = ob->query_enemy();
 if (sizeof(tar)==1)
		{
       tar[0]->add("jifeng",50);
	   tar[0]->add("combat_exp",5000);
	   tar[0]->add("potential",40000);
	tell_object(tar[0],HIC"��ɱ��"+name()+"��"HIY"�����50���ѵ�ȯ��5000����Ϊ��40000��Ǳ��"NOR"\n");
		}
	CHANNEL_D->do_channel(this_object(), "chat", HIR"������Ȼ����˸��֣�"NOR"");
	::die();
}
