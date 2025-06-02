//edit by rock
//2008.10.20

#include <ansi.h>
inherit NPC;


void create()
{
	set_name("��ɣ��ʿ", ({ "wushi"}));
	set("gender", "����");
	set("age",26);
	set("long", "����һλ��ɣ��ʿ��Ǳ���о���ԭ�������ꡣ\n");
	set("str", 100);
	set("int", 24);
	set("con", 100);
	set("dex", 100);

    set("qi", 100000+random(100000));
	set("max_qi", 100000+random(100000));
	set("jing", 200000);
	set("max_jing", 200000);
	set("neili", 200000);
	set("max_neili",200000);
	set("jiali", 300);

	set("combat_exp", 40000000);
	set("score", 200000);
	set("shen", -100000);

//	set_skill("fengmo-zhang",400+random(200));
	//set_skill("liuhe-zhang",400+random(200));
	set_skill("strike",400+random(200));
	set_skill("force", 400+random(200));             // �����ڹ�
	set_skill("huntian-qigong", 400+random(200));    // ��������
	set_skill("unarmed", 400+random(200));           // ����ȭ��
	//set_skill("xianglong-zhang", 400+random(200));   // ����ʮ����
	set_skill("dodge", 400+random(200));      	     // ��������
	set_skill("xiaoyaoyou", 400+random(200));        // ��ң��
	set_skill("parry", 400+random(200));             // �����м�
	set_skill("staff", 400+random(200));             // ��������
	set_skill("dagou-bang", 400+random(200));        // �򹷰���
	set_skill("begging", 400+random(200));           // �л�����
	set_skill("checking", 400+random(200));          // ����;˵
	set_skill("training", 400+random(200));         // Ԧ����

	//set_skill("yuejia-qiang", 400+random(200));        // �򹷰���
	//set_skill("suohou-gong", 400+random(200));        // �򹷰���
	//set_skill("chansi-shou", 400+random(200));        // �򹷰���
	set_skill("claw", 400+random(200));        // �򹷰���
	set_skill("hand", 400+random(200));        // �򹷰���
	set_skill("club", 400+random(200));        // �򹷰���

	map_skill("force", "huntian-qigong");
//map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
	//map_skill("strike", "xianglong-zhang");
	//map_skill("claw", "suohou-gong");
	//map_skill("hand", "chansi-shou");
    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
                (: perform_action, "unarmed.mielong" :),
                (: perform_action, "unarmed.mielong" :),
                (: perform_action, "unarmed.kanglongwuhui" :),
                (: perform_action, "unarmed.hui" :),
                (: perform_action, "unarmed.fei" :),
                (: perform_action, "unarmed.qu" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "unarmed.leiting" :),
                (: perform_action, "unarmed.xianglong" :),
                (: perform_action, "dodge.gjtq" :),
                (: perform_action, "dodge.canghaiyixiao" :),
                (: perform_action, "dodge.maishou" :),
        }) );
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_temp("apply/armor",1000);
	set_temp("apply/damage",1000);
	setup();
	carry_object("/clone/weapon/dadao")->wear();
}

void init()
{
	call_out("findPlayer",5); //Ѱ��
}

void die()
{
	object me,ob,memory,item;
	mapping team;
	string location;
	int i,size,level,exp,rand,pot,x;
	string file;
	x = random(10000);
	ob = this_object();
	me = ob->query_last_damage_from();
	team = me->query_team();
	memory = (object)me->query_temp("mirror/mirror_memory");

//tell_object(find_player("rock"),sprintf("%O %O %O\n",team,memory,me));
	if(!team || !clonep(memory) || !team || !me || !userp(me))
	{
		tell_room(environment(ob),HIM"��~~~~��\n��ɣ��ʿ�ֻ�֮�£����������������ˡ�\n"NOR);
		destruct(ob);
		return;
	}

	memory->add("make_boss",1);
	tell_room(environment(ob),HIM"��~~~~��\n��ɣ��ʿ�ֻ�֮�£����������������ˡ�\n"NOR);

	size = sizeof(team);
	for(i=0;i<size;i++)
	{
		if(!team[i]) continue;
		level = 100+random(100);
		exp = 100 * size + random(1000);

		if(exp)
		{
			pot = exp/2;
			tell_object(team[i],sprintf("������%d����Ϊ��%d��Ǳ�ܡ�\n",exp,pot));
			team[i]->add("combat_exp",exp);
			team[i]->add("potential",pot);
			if(team[i]->query("zhuanshen"))
			{
				team[i]->add("yuanshen/exp",level);
				tell_object(team[i],sprintf("���������%d��Ԫ����Ϊ��\n",level));
			}
		}
	}
		/*if(x <= 5)
		{
			location = pojun4[random(sizeof(pojun4))];
			item = new(location);
			item->move(me);
			tell_object(me,sprintf("������һ��"+item->name()+"��\n"));
		}else if( x <= 20 )
		{
			location = pojun3[random(sizeof(pojun3))];
			item = new(location);
			item->move(me);
			tell_object(me,sprintf("������һ��"+item->name()+"��\n"));
		}else if (x <= 50)
		{
			location = pojun2[random(sizeof(pojun2))];
			item = new(location);
			item->move(me);
			tell_object(me,sprintf("������һ��"+item->name()+"��\n"));
		}else if (x <= 100)
		{
			location = pojun1[random(sizeof(pojun1))];
			item = new(location);
			item->move(me);
			tell_object(me,sprintf("������һ��"+item->name()+"��\n"));
		}*/
	destruct(ob);
}

//������Ѱ��
void findPlayer()
{
	object map,*players,ob;
	int i,size,rand;

	ob = this_object();
	map = environment(ob);
	players = all_inventory(map);

	size = sizeof(players);
	rand = random(size);
	if(userp(players[rand])) ob->kill_ob(players[rand]);
	call_out("findPlayer",1+random(5));
}
