// migong lev6

#include <ansi.h>

inherit NPC;



void create()

{

   set_name(HIW"��Գ"NOR, ({ "bai yuan" , "yuan" }));
                set("race", "Ұ��");
       set("long",
"һֻѩ�׵�Գ��������������ԡ�
��\n");

set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" , "claw" }) );
	       set("max_qi",40000+random(5000));
  set("max_qi",40000+random(5000));
  set("max_jing",40000+random(5000));
  set("max_sen",40000+random(5000));
  set("max_mana",40000+random(5000));
  set("max_neili",20000+random(5000));
  set("neili",20000+random(5000));

      set("dex",100);
     set("str" ,100);
set("no_get",1);
    set("age", 15);

       set("shen_type", -1);

        set("combat_exp", 6000000);

        set_temp("apply/attack", 200);
        set_temp("apply/damage", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/defence", 200);
        set_skill("houquan", 400+random(100));

        set_skill("dodge", 300+random(100));

        set_skill("unarmed", 300+random(100));

       set_skill("parry", 300+random(100));

       map_skill("unarmed", "houquan");

       map_skill("parry", "houquan");


   setup();




}

void init( )
{
	object ob;
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
 ob->start_busy(1);
        call_out("hunting",1);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",1);
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


int accept_object(object who, object ob)
{
	   if ((string)ob->query("id")=="xian tao") {
            say("��Գ���ĵĽ���һ����������һ����\n");
             move("/d/migong/lev6/dong102");
            }
		return 1;
}
int hit_ob(object me, object ob, int damage)
{
if (ob)
{
	ob->apply_condition("wugong_poison", 40);
        ob->apply_condition("chanchu_poison", 40);
        ob->apply_condition("xiezi_poison", 40);
        ob->apply_condition("snake_poison", 40);
        ob->apply_condition("zhizhu_poison", 40);
        tell_object(ob, HIG "����ñ����еĵط�һ��������\n" NOR );
}
}

void die()
{
        object ob, me, corpse,obj;
               int exp,pot,score,i;
        int maxpot;
        ob = this_object();
   //     me = query_temp("last_damage_from");
   me=  this_object()->query_last_damage_from();
   //        me = this_player();
if (!me) return;
              me->add("score",1);
        message_vision(WHT"$Nž��һ��̱���ڵ��ϡ�\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));me->add("combat_exp",random(12));me->add("potential",random(8));
if (me->query("migong/lev6"))
{
if( !environment(me)->query("no_fight")
&& random(4)==1)
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

if (!me->query("migong/lev6"))
{
me->set("migong/lev6",1);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "������Թ�������!"NOR"��\n", users());
exp = 260000+random(25000);
pot = exp/2;
score = random(300)+350;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
tell_object(me,HIW"�㱻�����ˣ�\n" +
             chinese_number(exp) + "��ʵս��Ϊ\n"+
             chinese_number(pot) + "��Ǳ��\n" +
            chinese_number(score)+"�㽭������\n"NOR);

}
        if((int)me->query("combat_exp") < 350000)   {


        message("vision", me->name() + "�ɹ�������Գ������4000��Ϊ��2000Ǳ�ܡ�\n", me);
        me->add("combat_exp",4000);
        me->add("potential",2000);
        destruct(ob);
        }
               destruct(ob);
        return;
}
