//by ���� ranger's ednpc tools.
// shanzei1.c

#include <ansi.h>
inherit NPC;

string *random_ob = ({
  "/fuben/wuguan/obj/putao",
    "/fuben/wuguan/obj/dan_chongmai1",
    "/fuben/wuguan/obj/book_wuliang",    
});

void create()
{
object ob = this_player();
int lvl = ob->query("qi");
int sklv;
sklv = to_int(pow(to_float(ob->query("combat_exp")*10),0.333333333)+random(15));
if (ob->query("combat_exp")<100000){
sklv = 100;
}
if (lvl > 7000){
lvl = 7000;
}

	set_name(HIY"С�ձ�����"NOR,({"wo kou"}));
	set("gender", "����");
	set("per",20);
	set("age", 30);
	set("combat_exp", 1000000+random(3000000));
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_neili", lvl);
	set("neili", lvl);
	set("eff_qi", lvl);
	set("max_qi", lvl);
	set("qi", lvl);
	set("max_jing", lvl);
	set("jing", lvl);
	set("max_jingli", lvl);
    set("eff_jingli", lvl);
 	set("jingli", lvl);
		
	set_skill("force", sklv/2);
	set_skill("dodge", sklv/2);
	set_skill("hand", sklv/2);
	set_skill("cuff", sklv/2);	
	set_skill("parry", sklv/2);
    set_skill("mizong-neigong", sklv/2);	
    set_skill("shenkong-xing", sklv/2);
    set_skill("dashou-yin", sklv/2);	
    set_skill("yujiamu-quan", sklv/2);	        	    	
	
	map_skill("force", "mizong-neigong");
	map_skill("dodge", "shenkong-xing");
	map_skill("hand", "dashou-yin");
	map_skill("cuff", "yujiamu-quan");	
	map_skill("parry", "dashou-yin");	
	
	prepare_skill("hand", "dashou-yin");
	prepare_skill("cuff", "yujiamu-quan");
	setup();
}

void die()
{
	string id = random_ob[random(sizeof(random_ob))];//�����Ʒ
	object killer,ob;
	int exp;

	if (objectp(killer = query_last_damage_from()))
	{
		killer->add("combat_exp",3500);
		killer->add("potential",3500);
		killer->add("jifeng",5);
		tell_object(killer,"��ɱ��"+name()+"�����3500����Ϊ��3500��Ǳ�ܣ�5�ŵ�ȯ��\n");
		if(killer->query("zhanling/s6") < 10)
		{
		killer->add("zhanling/a6",5);
		killer->add("zhanling/s6",5);
		tell_object(killer,"��ɱ��"+name()+"�����1ս����Ϊ��\n");
		}
	}
	
	switch (random(11))
	{
		case 0 : 
			new(id)->move(killer);
			new(id)->move(killer);
		break;

		case 5 :
			new(id)->move(killer);
			new(id)->move(killer);
		break;

		case 9 :
			new(id)->move(killer);
			new(id)->move(killer);

//CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"�ڷ�����������л����"+id->short()+"��");
		break;
	}
	::die();
}

void unconcious()
{
	die();
}