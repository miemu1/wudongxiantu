// migong lev14

#include <ansi.h>

inherit NPC;


void create()

{

   set_name(HIR"大火龙"NOR, ({ "huo long" , "long" , "dragon" }));
                set("race", "野兽");
       set("long",
"一条巨大的龙，嘴里喷着火，看到了你，向你扑了过来。
它充斥着这整个洞穴，你顿觉空气的压抑，觉得它十分地可怕
。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" , "claw"}) );
	       set("max_qi",80000+random(20000));
  set("max_jing",80000+random(20000));
  set("max_sen",80000+random(20000));
  set("max_mana",80000+random(20000));
  set("max_neili",80000+random(20000));
set("neili",850000+random(20000));
      set("dex",120);
      set("con",100);
     set("str" ,100);
       set("no_get",1);
    set("age", 150);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 11000000+random(2000000));
            set_temp("apply/attack", 500);
        set_temp("apply/damage", 500);
        set_temp("apply/armor", 500);
        set_temp("apply/defence",500);
       set_skill("dodge", 600+random(100));

      set_skill("unarmed", 600+random(100));

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
void unconcious()
{
    die();
}
void die()
{
        object ob, me,obj, jla,corpse;
int maxpot,exp,score,pot,i;
        ob = this_object();
  //      me = query_temp("last_damage_from");
me=  this_object()->query_last_damage_from();
if (!me) return;
              me->add("score",1);
        message_vision(WHT"$N一声怒吼，浑身鲜血直流，缓缓躺倒在地。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
        if (me->query("migong/lev14"))
{
if( !environment(me)->query("no_fight")
&& random(4)==1)
{
obj=new("/d/migong/obj/npct");
maxpot=me->query_temp("maxpot")+10;
obj->do_copy(me,maxpot,2);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N狂笑道：让你见识是一下武术的真髓! !\n"NOR, obj);
me->start_busy(3);
me->kill_ob(obj);
obj->kill_ob(me);
}

}
if (!me->query("migong/lev14"))
{
me->set("migong/lev14",1);
message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "完成了迷宫第十四层!"NOR"。\n", users());
exp = 480000+random(25000);
pot = exp/2;
score = random(300)+950;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
tell_object(me,HIW"你被奖励了：\n" +
             chinese_number(exp) + "点实战修为\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点江湖阅历\n"NOR);

}

        if (userp(me) && (int)me->query("combat_exp") < 16000000)
        {

             message_vision("$N得到一件火龙丹。\n",me);
             command("rumor "+me->query("name")+"得到一件"HIR"火龙丹"NOR"。\n");
             jla=new("/d/migong/obj/dan3");
             jla->move(me);

               }

               destruct(ob);
        return;
}
