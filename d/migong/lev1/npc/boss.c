// migong lev5

#include <ansi.h>

inherit NPC;


void create()

{

   set_name(HIG"独眼巨鳄"NOR, ({ "big boss" , "boss" }));
                set("race", "野兽");
       set("long",
"一只长着独了一只眼的的巨鳄。
。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" , "claw" }) );
	       set("max_qi",14000+random(2000));
  set("max_jing",14000+random(2000));
  set("max_qi",14000+random(2000));
  set("max_mana",14000+random(2000));

      set("dex",100);
     set("str" ,100);

    set("age", 15);

       set("shen_type", -1);
set("no_get",1);
        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 2000000);

        set_temp("apply/attack", 200);
        set_temp("apply/damage", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/defence", 200);

   setup();


}


void init( )
{
	object ob;
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(3);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}



void hunting()
{
	int i;
        object *ob;
if (!environment(this_object())) return;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}
void unconcious()
{
    die();
}
void die()
{
        object ob, me, corpse,obj;
        int exp,pot,score,i;
        ob = this_object();
       // me = this_player();
       me=  this_object()->query_last_damage_from();
        
if (!me) return;
              me->add("score",1);
        message_vision(WHT"$N啪的一声瘫倒在地上。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));

if (!me->query("migong/lev1"))
{
me->set("migong/lev1",1);
message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "完成了迷宫第一层!"NOR"。\n", users());
exp = 80000+random(25000);
pot = exp/2;
score = random(300)+100;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
tell_object(me,HIW"你被奖励了：\n" +
             chinese_number(exp) + "点实战修为\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点江湖阅历\n"NOR);
}
        if((int)me->query("combat_exp") < 1500000)   {
        message("vision", me->name() + "成功打死猎物增加了4000修为和2000潜能。\n", me);
        me->add("combat_exp",4000);
        me->add("potential",2000);
   //     write(""+me->name() + "成功打死猎物增加了4000修为和2000潜能。\n");
        destruct(ob);
        }
        destruct(ob);
        return;
}


