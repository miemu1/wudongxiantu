// migong lev13

#include <ansi.h>

inherit NPC;


void create()

{

   set_name(WHT"����"NOR, ({ "yi long" , "long" , "dragon" }));
                set("race", "Ұ��");
       set("long",
"���ź���˫���ж����ݵľ���
��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" , "claw"}) );
	       set("max_qi",15000+random(10000));
  set("max_jing",15000+random(10000));
  set("max_sen",15000+random(10000));
  set("max_mana",15000+random(10000));

      set("dex",100);
      set("con",100);
     set("str" ,100);

    set("age", 80);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 8000000+random(2000000));
            set_temp("apply/attack", 400);
        set_temp("apply/damage", 400);
        set_temp("apply/armor", 400);
        set_temp("apply/defence",400);
      set_skill("dodge", 500+random(100));

      set_skill("unarmed", 400+random(100));

       set_skill("dragon", 500+random(100));

      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
      set("chat_chance", 20);
        set("chat_msg", ({
		(: command("get silver") :),
		(: command("get coin") :),
                (: random_move :),
           }) );

   setup();



}

void init()
{	
	object ob; 

	ob = this_player();
	::init();
	if (interactive(ob) && ! is_fighting()){
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
		kill_ob(ob);
}

void die()
{
        object ob, me;
        ob = this_object();
        me=  this_object()->query_last_damage_from();
        if (!me) 
        return;            
        message_vision(WHT"$N������Ѫ����,���ض�����\n"NOR,ob,me);
        if((int)me->query("combat_exp") > 1000000)   {
        message("vision", me->name() + "Ϊ��������,������700��Ϊ��700Ǳ�ܡ�\n", me);
        me->add("combat_exp",700);
        me->add("potential",700);
        }

        ::die();
}