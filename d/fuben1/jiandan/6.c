// pangu.c �̹�

#include <ansi.h>

inherit NPC;
void do_bite();

void create()
{
	set_name(HIR"����[��]"NOR, ({ "cao zheng" }));
	set("gender", "����");
      set("title",HIR "BOSS" NOR);
      set("age", 20);
	set("attitude", "friendly");
      
 

        set("str", 500);
        set("int", 500);
        set("con", 500);
        set("dex", 500);
      set("per", 30);
	set("shen_type", -1);


	set("combat_exp", 200000000);
	set("max_qi", 1000000);
	set("max_jing", 1000000);
	set("qi", 1000000);
	set("jing", 1000000);
	set("neili", 1000000);
	set("max_neili", 1000000);
      set("mana", 999999999999);
	set("max_mana", 999999999999);
	set("jiali", 10000);
      set("score", 500000);

      set_skill("count", 400);
	set_skill("kuihua-dafa", 400);
	set_skill("unarmed", 400);
	set_skill("dodge", 400);
	set_skill("force", 400);
	set_skill("parry", 400);
      set_skill("martial-cognize",400);

	
	map_skill("dodge", "kuihua-dafa");
	map_skill("force", "kuihua-dafa");
      map_skill("parry", "kuihua-dafa");
      map_skill("unarmed", "kuihua-dafa");

        set("chat_chance", 50);
        set("chat_msg", ({
				(: random_move :),
				(: random_move :),
        }));	
	set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: do_bite() :),
        }) ); 


	setup();
	set_temp("apply/attack", 2500);
	set_temp("apply/defense", 2500);
	set_temp("apply/unarmed_damage", 2500);
	set_temp("apply/armor", 2500);

	setup();

         }
void do_bite(object me)
{
	        object *enemies,enemy;
        object *obs;			
        string msg;

        clean_up_enemy();
        enemies = query_enemy();
	        obs = all_inventory(environment(this_object()));		

if(!this_player())
{
::kill_ob(me);
return;
}

        if( !enemies || sizeof(enemies)==0 )
                return;
        enemy = enemies[random(sizeof(enemies))];
        if( !userp(enemy) ) return;
        message_vision(HIR"$N�ó��̵���$n�̳���������\n"NOR,this_object(),enemy);
        enemy->receive_wound("qi",500+random(500),this_object());
        msg = "( $n" + 
              COMBAT_D->status_msg(enemy->query("qi") * 100 / 
              (enemy->query("max_qi") ? enemy->query("max_qi") : 100)) + ")\n"; 
        message_vision(msg, this_object(), enemy);
		
        this_object()->receive_wound("qi",500+random(500));
        this_object()->receive_damage("qi",500+random(500));


        if( !this_object()->is_busy() )
                this_object()->start_busy(2);

}
void init()
{
        object ob, me;

        me = this_player();
        ob = this_object();

        ::init();
        if( interactive(me) && visible(me) &&
            !is_fighting()) {
                //NPC_D->copy_from_me(ob, me, 10, 1);
        }
}
void kill_ob(object me)
{
	        object *obs;			
	        obs = all_inventory(environment(this_object()));		

if(!this_player())
{
::kill_ob(me);
return;
}

 if(this_player()->query("max_jing") > 1)
{
	command("say �����ɣ���\n");
      this_player()->start_busy(1);
	::kill_ob(me);



}
}

void unconcious()
{
    die();
}
void die()
{
	object me,ob,memory,env,obj,item,corpse,obj1;
	mapping team;
        object *obs;
	
	string location;
	int i,size,level,exp,rand,pot;
	string file;

	ob = this_object();
	me  = ob->query_last_damage_from();
//	CHANNEL_D->do_channel( this_object(), "sys", HIY"���npc��ɱ���ˣ�"+ZJURL("cmds:snoop "+me->query("id"))ZJSIZE(20)+""+me->query("name")+""NOR"\n");
//		log_file("dangkou", sprintf("%s��%s(%s) �������boss��\n", ctime(time()),me->name(1),me->query("id")) );

        obs = all_inventory(environment(this_object()));

        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
	size = sizeof(team);
        env = environment(this_object());
		

	me->add("combat_exp",10000);
        me->add("jifeng",20);
	me->add("potential",15000);


			
// 		obj = new("/clone/money/xueye");
//		obj->set_amount(50);
 //       obj->move(me);					
 //		obj = new("/clone/money/jjd");
//		obj->set_amount(50);
//        obj->move(me);						
        tell_object(me,ZJSIZE(22)GRN"���ڻ�ɱboss֮�������ˣ�\n" +
        15000 + "Ǳ��\n" +		
        10000 + "��Ϊֵ\n" +			
        20 + "��ȯ\n" +			

		        NOR);
//	destruct(ob);

        message_vision("\n$Nҡ��һ�Σ���Ϊһ����������ɢ�ˡ�\n", this_object());
//        obj1 = new("/d/fuben/dangkou/npc/2");
//        obj1->move(environment(ob));
        destruct(ob);
}
