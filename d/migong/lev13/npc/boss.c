// migong lev13

#include <ansi.h>

inherit NPC;


void create()

{

   set_name(HIR"����"NOR, ({ "huo long" , "long" , "dragon" }));
                set("race", "Ұ��");
       set("long",
"һ���޴�������������Ż𣬿������㣬�������˹�����
���������������Ѩ����پ�������ѹ�֣�������ʮ�ֵؿ���
��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" , "claw"}) );
	       set("max_qi",70000+random(20000));
  set("max_jing",70000+random(20000));
  set("max_sen",70000+random(20000));
  set("max_mana",70000+random(20000));
   set("max_neili",70000+random(20000));
    set("neili",70000+random(20000));
      set("dex",100);
      set("con",100);
     set("str" ,100);
       set("no_get",1);
    set("age", 150);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 9000000+random(2000000));
            set_temp("apply/attack", 500);
        set_temp("apply/damage", 500);
        set_temp("apply/armor", 500);
        set_temp("apply/defence",500);
      set_skill("dodge", 500+random(100));

      set_skill("unarmed", 500+random(100));

       set_skill("dragon", 600+random(100));

      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 90);
        set("chat_msg_combat", ({

    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
    (: perform_action, "unarmed.yaoyao" :),

 }) );

   setup();



}

void init( )

{
	object ob;
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void die()
{
        object ob, me,obj, jla,corpse;
           int exp,pot,score,i;
        int maxpot;
        ob = this_object();
        me=  this_object()->query_last_damage_from();
        if (!me) return;
                if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
 if (me->query("migong/lev13"))
{
if( !environment(me)->query("no_fight")&& random(4)==1)
{
obj=new("/d/migong/obj/npct");
maxpot=me->query_temp("maxpot")+10;
obj->do_copy(me,maxpot,2);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N��Ц���������ʶ��һ������������! !\n"NOR, obj);
me->start_busy(3);
me->kill_ob(obj);
obj->kill_ob(me);
}
}


if (!me->query("migong/lev13"))
{
me->set("migong/lev13",1);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "������Թ���ʮ����!"NOR"��\n", users());
exp = 440000+random(25000);
pot = exp/2;
score = random(300)+650;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
tell_object(me,HIW"�㱻�����ˣ�\n" +
             chinese_number(exp) + "��ʵս��Ϊ\n"+
             chinese_number(pot) + "��Ǳ��\n" +
            chinese_number(score)+"�㽭������\n"NOR);

}

        if (userp(me)&& (int)me->query("combat_exp") < 14000000)
        {


             message_vision("$N�õ�һ�������ס�\n",me);
             command("rumor "+me->query("name")+"�õ�һ��"HIR"������"NOR"��\n");
             jla=new("/d/migong/obj/jia2");
             jla->move(me);


             }
        if((int)me->query("combat_exp") < 7000000)   {
        message("vision", me->name() + "Ϊ��������,������11000��Ϊ��6000Ǳ�ܡ�\n", me);
        me->add("combat_exp",11000);
        me->add("potential",6000);
		
        destruct(ob);
        }
        destruct(ob);
        return;
}