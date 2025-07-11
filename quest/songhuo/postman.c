//[lover 1999]
#include <ansi.h>
#define QUEST_LETTER __DIR__"quest"
#define QUEST_NAME __DIR__"name"
inherit NPC;
//inherit F_MASTER;

int time_period(int timep, object me);

void create()
{
        set_name("陈老板",({"chen laoban","laoban"}));
        set("long","这是一个拷给别人送货发了财的老板.\n");
        set("title", HIC"送货大王"NOR);
        set("gender", "男性");
        set("attitude", "friendly");
        set("age", 40);
        set("shen_type", 0);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);

        set("max_qi", 4500);
        set("max_jing", 3000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 50);
        set("combat_exp", 3000000);
        set("score", 10000);
        set("env/wimpy", 10000);
        set("inquiry", ([
                "任务": "我正在发愁怎么处理这些货物呢，你来的正好! \n",
        ]) );
        set("no_get", 1);

        set_skill("force", 170);
        set_skill("dodge", 170);
        set_skill("cuff", 175);
        set_skill("parry", 170);
        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{

add_action("give_quest", "quest");

}

int accept_object(object who, object ob)
{
        if (ob->query("money_id"))
        {
               if(!who->query("quest") || ( ob->value() < 2000))
             {
                   message_vision("我正缺钱用，多谢您了！\n",who);
                   return 1;
             }
             else
             {
message_vision("陈老板叹了口气道：好吧，不想做就算了,我去另请高明。\n",who);
                   who->apply_condition("hxsd_busy",1+random(4));
                   who->apply_condition("menpai_busy",6);
                   who->set("quest",0);
                   who->set_temp("menpaijob",0);
                   who->delete_temp("menpaijob");
                   destruct(present("huo wu",who));
                   return 1;
             }
         }
return 0;
}

int give_quest()
{
        mapping quest ;
        mapping name ;

        object me,letter;
        int combatexp, timep, factor;

        me = this_player();
        combatexp = (int)(me->query("combat_exp"));

        if((quest =  me->query("quest")))
               return notify_fail("你现在有别的任务！\n");

      if ((int)me->query_condition("hxsd_busy"))
            {
                      message_vision("陈老板对着$N摇了摇头说：你办事不利,等会再来!\n", me);
                      return 1;
            }

       if(combatexp < 50000)
       {
message_vision("陈老板对$N说：你修为不够，怕你送不了哟！\n",me);
         return 0;
        }

// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
                if( ((int)me->query("task_time")) >  time() ){
                message_vision("陈老板对$N说：你得把货物帮我送到呀。\n", me);
                   me->set_temp("menpaijob",0);
                   me->delete_temp("menpaijob");
                        return 0;
                }
        }
                if (((int)time() - (int)me->query("last_task_time")) < 1)
                 {
                   message_vision("陈老板对$N说：现在连我都闲得发慌，你还是等会再来吧。\n",me);

                   return 0;
                 }
                else
                {
                   message_vision("陈老板对$N说：你来得正好，我这儿刚好有一批货物要送出去。\n",me);
}
        quest = QUEST_LETTER->query_quest();
        name = QUEST_NAME->query_quest();
        timep = random(100) + 300;
        time_period(timep, me);
        tell_object(me, "把货物送给『" + quest["quest"] + "』你的任务就完成了。\n" NOR);
        letter = new(__DIR__"letter");
        letter->set("name",name["quest"]);
        letter->move(me);
        message_vision("$N给了$n货物"HIG"『" + letter->query("name") + "』。\n"NOR,this_object(),me);
        quest["quest_type"] = "把货物送给";
        quest["exp_bonus"] = random(500) + 800;
        quest["pot_bonus"] = random(500) + 600;
        quest["score"] = 2;
if ( quest["time"] <= 120)
{
quest["time"] = 200;
}
if (me->query("combat_exp") > 5000000)
{
        quest["exp_bonus"] = random(100) + 500;
        quest["pot_bonus"] = random(100) + 500;
        quest["score"] = 2;
}
        me->set("tzjob",1);
        me->set_temp("tufei",0);
        me->set("quest", quest);
        me->set("task_time", (int)time() + timep);
        me->set("quest_factor", factor);
        me->set("last_task_time", time());
        return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d)
                time = chinese_number(d) + "天";
        else
                time = "";
        if(h)
                time += chinese_number(h) + "小时";
        if(m)
                time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me, HIW "陈老板说道：\n在" + time + "内");

                return 1;
}
