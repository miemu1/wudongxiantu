//edit by jerry
//1508.11.22

#include <ansi.h>
inherit NPC;



void create()
{
	set_name(HIW"����ɥʬ"NOR, ({ "wanlin"}));
	set("gender", "����");
	set("age",26);
	set("long", "һֻ�������Ե�ɥʬ��\n");
        set("attitude", "aggressive");
        set("no_update", 1);
        set("str", 300 + random(100));
        set("int", 300 + random(100));
        set("con", 300 + random(100));
        set("dex", 300 + random(100));
        set("kar", 300 + random(100));
	    set("shen_type", -1);
        set("qi", 1000000 + random(1000000));
        set("max_qi", 1000000+ random(1000000));
        set("jing", 10000000 + random(300000));
        set("max_jing", 10000000 + random(300000));
        set("neili", 2000000 + random(300000));
        set("max_neili", 2000000 + random(300000));
        set("max_jingli", 2000000 + random(300000));
        set("jingli", 1200000 + random(300000));
        set("jym_level/level",20);
        set("jiali", 500 + random(150));
        set("combat_exp", 2000000 + random(30000));
        set_skill("force", 500 + random(1500));
        set_skill("dodge", 500 + random(1500));
        set_skill("parry", 500 + random(1500));
        set_skill("sword", 500 + random(1500));
        set_skill("unarmed", 500 + random(1500));
		set_skill("cuff", 500 + random(1500));		
        set_skill("yinyang-shiertian", 500 + random(1500));	 
        map_skill("unarmed", "yinyang-shiertian");   
        map_skill("dodge", "yinyang-shiertian");
        map_skill("parry", "yinyang-shiertian");
        map_skill("sword", "yinyang-shiertian");
        prepare_skill("sword","yinyang-shiertian");

        setup();

        carry_object("/clone/cloth/cloth")->wear();

}

void init()
{
	object me,ob;
	::init();
	if (interactive(me = this_object()))
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, me);
	}
}

 void die()
{
         object nvh;//���ó�������npc
         object ob =  this_object()->query_last_damage_from();
         object *players;
         int w,i;
		 int xiuwei;
		 int qianneng;
		  if(!objectp(this_object())) return;//��� ������Ҳ����� ֹͣ
		 xiuwei =ob->query("combat_exp")/4000;//��Ϊ����3000���ڻ�õ���Ϊ
		 qianneng=(xiuwei/1000)*15;//Ǳ�ܳ���1000����15���ڻ�õ�Ǳ��
		 

          ob->start_busy(1);
		 players = ob->query_team();
		 w = sizeof(players);
		 if (sizeof(ob->query_team()) >= 2)//����������ڵ���2��ӽ���
		 {
         
           for(i = 0; i<sizeof(players); i++)
         {
		 
         players[i]->add("combat_exp", xiuwei);//���
		 players[i]->add("potential", qianneng);//���	
		
		 tell_object(players[i],HIC"\n������"+xiuwei+"����Ϊ"+qianneng+"��Ǳ��\n"NOR"\n");
		 
        
         }

		 }
	    else//����
        //if (sizeof(ob->query_team()) > 1)
        {
      
		
		ob->add("combat_exp", xiuwei);//����
		ob->add("potential", qianneng);//����	
	
        tell_object(ob,HIC"\n������"+xiuwei+"����Ϊ"+qianneng+"��Ǳ��\n"NOR"\n");
		
       
       
        }
        /*else
        {
         //players = users();
        // players->add("combat_exp", 10000);
		 tell_object(players,HIR"��Ϊһ��\n"NOR);
         }*/     
       ::die();
}

//������Ѱ��
/*void findPlayer()
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
*/