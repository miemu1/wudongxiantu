#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_kungfu();
int ask_kungfu1();
int ask_kungfu2();
int kungfu_asked1();


void create()
{
	set_name("相乐左之助", ({ "zuo zhizu", "xiangle" }));
	set("nickname",HIW"斩左"NOR);
	set("gender", "男性");
            set("long", 
		" 这就是人称斩左的左之助了，在他衣服后面印了一个大大的恶字。\n");
	set("age", 23);
            set("dex", 43);
                 set("str", 45);
     set("per", 43);
	set("combat_exp", 3200000);
        set("max_neili",24000);
        set("neili",24000);
        set("max_qi",14000);
        set("eff_qi",14000);
        set("qi",14000);
        set("max_jingli",14000);
        set("eff_jingli",14000);
        set("jingli",4000);
        set_skill("cuff",300);
        set_skill("shayi",200 );
        set_skill("force", 280);
        set_skill("dodge", 200);
                 set_skill("xuanhualiu-quanfa",350);
                 set_skill("unarmed",350);
        set_skill("shayi-xinfa",280);

        map_skill("force","shayi-xinfa");
	map_skill("unarmed","xuanhualiu-quanfa");
	setup();
	carry_object("/clone/misc/cloth")->wear();
            set("inquiry",([
                    "喧哗流拳法" : (: ask_kungfu :),
                    "学艺" : (: ask_kungfu1 :),
                    "极限" : (: ask_kungfu2 :),
                    "剑法" : (: ask_kungfu2 :),
                    "绝招" : (: ask_kungfu :),
            ]));
          set("chat_chance_combat",80);
          set("chat_msg_combat",({
              (: perform_action,"unarmed.sanchong" :),
              (: exert_function,"recover" :),
          }));
       set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
          carry_object("/clone/misc/cloth")->wear();
}


void init()
{       
        object ob;

        if( interactive(ob=this_player()) && ob->query_temp("killwei") ) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}

int ask_kungfu()
{
           object me;
           mapping myparty;
           mapping myfam;
           int skills;

           me=this_player();
           myfam=(mapping)me->query("family");
           myparty=(mapping)me->query("party");
           skills=me->query_skill("xuanhualiu-quanfa",1);

           if ( (!myfam || myfam["family_name"]!="飞天御剑流") && (!myparty || myparty["party_name"]!=HIG"飞天御剑流"NOR) )
           {
                   command("say 我与你无缘，不会教你绝学的？");
                   return 1;
           }

           if ( me->query_temp("kungfu_asked1") )
           {
                command("hmm");
                command("say 这套绝学我只教一遍，学成与否就看你自己的造化了。");
                return 1;
           }

            if (myfam && myfam["family_name"]=="飞天御剑流")
{
           if ( me->query("combat_exp")<800000)
           {
                command("say 你的实战修为太低，学不了我的绝学。");
                return 1;
           }
             if ( me->query_skill("unarmed",1)<180)
           {
                command("say 你的拳法还欠火候，学不了我的绝学。");
                return 1;
           }
               if ( me->query_skill("aikido",1)<180)
           {
                command("say 你把日本的合气道学好了在来找我吧!");
                return 1;
           }

           if ( me->query("max_neili")<1500)
           {
                command("say 你的内力基础太差，学不了我的绝学。");
                return 1;
           }

             if (skills>=this_object()->query_skill("xuanhualiu-quanfa",1))
             {
                       command("say 我已经没什么可教的啦。");
                       return 1;
             }
             if ((skills*skills*skills/7)>me->query("combat_exp"))
             {
                       command("say 你的修为不够，说了你也听不懂。");
                       return 1;
             }
            if (me->query("jing")<200)
             {
                       command("say 你太累了，休息会吧。");
                       return 1;
             }
                 
            me->improve_skill("xuanhualiu-quanfa",random(10*me->query("int")));
            tell_object(me,"你向左之助请教了一些关于喧哗流拳法的疑问。\n");
          me->receive_damage("jing",me->query("jing")/20);
            
            return 1;

           }
           
            if (myparty && myparty["party_name"]==HIG"飞天御剑流"NOR)
           {
                  if ( myparty["level"]<4 )
                  {
                       command("say 这套绝学我不能教你，对不起。");
                       return 1;
                  }
             if ( me->query_skill("unarmed",1)<180)
                  {
                command("say 你的拳法还欠火候，学不了我的绝学。");
                       return 1;
                  }
                  if ( me->query("max_neili")<1500 )
                  {
                       command("say 你的内力还欠火候，学不了我的绝学。");
                       return 1;
                  }
          command("say 好吧，你看仔细了，我只演练一遍。");
           message_vision(HIY"$N走向一块巨石，微用拳劲击向石头，一声巨响石头变成了一堆粉末。\n"NOR,this_object());
           if ( me->query("int")<30 )
           {
                  message_vision(YEL"$N看了半天，毫无所得，想必你的资质太差了，掌握不了精髓。\n"NOR,me);
                      me->set_temp("kungfu_asked1",1);
                     return 1;
           }
                 message_vision(HIC"$N看了半天,掌握了这套绝学的精髓。\n"NOR,me);
                      me->set_temp("kungfu_asked1",1);
                     me->set_skill("xuanhualiu-quanfa",1);
                     return 1;
           }

           return 0;
}

int ask_kungfu1()
{
           object me;
           mapping myparty;
           mapping myfam;

           me=this_player();
           myfam=(mapping)me->query("family");
           myparty=(mapping)me->query("party");

           if ( (!myfam || myfam["family_name"]!="飞天御剑流") && (!myparty || myparty["party_name"]!=HIG"飞天御剑流"NOR) )
           {
                   command("say 你与本门毫无瓜葛，此话从何谈起？");
                   return 1;
           }
           
           command("smile");
           command("say 我比较精通拳法，你可以向我请教拳法的疑问。");
           
           return 1;
           
}
int ask_kungfu2()
{
           object me;
           mapping myparty;
           mapping myfam;
           int skills;

           me=this_player();
           myfam=(mapping)me->query("family");
           myparty=(mapping)me->query("party");
            skills=(int)me->query_skill("unarmed",1);

           if ( (!myfam || myfam["family_name"]!="飞天御剑流") && (!myparty || myparty["party_name"]!=HIG"飞天御剑流"NOR) )
           {
                   command("say 你与剑心毫无瓜葛，此话从何谈起？");
                   return 1;
           }
           
             if (skills>=this_object()->query_skill("xuanhualiu-quanfa",1))
             {
                       command("say 我已经没什么可教的啦。");
                       return 1;
             }

           if ((skills*skills*skills/7)>me->query("combat_exp"))
            {
                      command("say 你的修为不够，说了你也听不懂。");
                      return 1;
            }

           if (me->query("jing")<200)
            {
                      command("say 你太累了，休息会吧。");
                      return 1;
            }
                
           me->improve_skill("unarmed",random(5*me->query("int")));
           tell_object(me,CYN"你向左之助请教了一些关于拳法的疑问。\n"NOR);
          me->receive_damage("jing",me->query("jing")/20);
           
           return 1;
           
}

