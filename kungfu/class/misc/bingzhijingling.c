#include <ansi.h>
inherit NPC;

void create()
{
//        set_name(HIY "冰之精灵" NOR, ({ "bingzhijingling" }) );
 
        set("gender", "无性");
        set("age", 35);

        // yun perform
        set("chat_chance_combat", 120); 
        set("chat_msg_combat", ({ 
              // 冰之盛典
              (: command("perform spells.binga6") :),
              (: command("perform spells.binga5") :), 
              (: command("perform spells.binga4") :), 
              (: command("perform spells.binga2") :), 

              (: exert_function, "binga6" :), 
              (: exert_function, "binga5" :),
              (: exert_function, "binga4" :), 
              (: exert_function, "binga2" :), 
        }));

        //setup();

}


void init_npc(object me)
{
        object env, ob;
        
        mapping map_status, hp_status, my;
        string *mname;
        int i, temp;
        int percent;

        ob = this_object();
        env = environment(me);

        // 设置出生时间
        ob->set("start_time", time());
        // 设置出生地点
        ob->set("start_place", env);
        // 设置归属
        ob->set("owner",me->query("id"));
		ob->set_leader(me);

        set_name(HIB+me->name()+HIY"的冰之精灵"NOR,({me->query("id")+"bingzhijingling"}));
        set("long", HIM "据说冰之盛典修炼到一定程度便能\n"
                        "召唤出来自极寒之地的冰之精灵助战。\n" NOR);
        // 设置百分比
        if (me->query_skill("bingzhi-shengdian") >= 4000)
        {
                percent = 150;
        }
        else if (me->query_skill("bingzhi-shengdian") >= 3000)
        {
                percent = 145;
        }       
        else if (me->query_skill("bingzhi-shengdian") >= 2000)
        {
                percent = 140;
        }
        else if (me->query_skill("bingzhi-shengdian") >= 1900)
        {
                percent = 135;
        }
        else if (me->query_skill("bingzhi-shengdian") >= 1800)
        {
                percent = 130;
        }
        else if (me->query_skill("bingzhi-shengdian") >= 1700)
        {
                percent = 125;
        }
        else if (me->query_skill("bingzhi-shengdian") >= 1600)
        {
                percent = 120;
        }
        else if (me->query_skill("bingzhi-shengdian") >= 1500)
        {
                percent = 115;
        }
        else if (me->query_skill("bingzhi-shengdian") >= 1400)
        {
                percent = 110;
        }
        else if (me->query_skill("bingzhi-shengdian") >= 1300)
        {
                percent = 105;
        }
        else if (me->query_skill("bingzhi-shengdian") >= 1200)
        {
                percent = 100;
        }
        else
        {
                percent = 75;
        }
        
        // 削弱修正
        percent -= 20;
        
        // 设置技能     
        if (mapp(map_status = me->query_skill_map()))
        {
                mname = keys(map_status);

                temp = sizeof(map_status);
                for (i = 0; i < temp; i++)
                {
                       // 设置基本技能
                       ob->set_skill(mname[i], me->query_skill(mname[i], 1) * percent / 75); 
                       // 设置激发技能
                       ob->set_skill(map_status[mname[i]], me->query_skill(map_status[mname[i]], 1) * percent / 75);
                       // 激发技能
                       ob->map_skill(mname[i], map_status[mname[i]]);
                }
        }

        hp_status = me->query_entire_dbase();
        my = ob->query_entire_dbase();

        my["str"] = hp_status["str"] * percent / 25;
        my["int"] = hp_status["int"] * percent / 25;
        my["con"] = hp_status["con"] * percent / 25;
        my["dex"] = hp_status["dex"] * percent / 25;

        my["max_qi"]     = hp_status["max_qi"] / 50  * percent + 50000;
        my["eff_qi"]     = hp_status["eff_qi"]  / 50  * percent + 50000;
        my["qi"]         = hp_status["qi"] / 50  * percent + 50000;
        my["max_jing"]   = hp_status["max_jing"] / 125  * percent + 10000;
        my["eff_jing"]   = hp_status["eff_jing"] / 125  * percent + 10000;
        my["jing"]       = hp_status["jing"] / 125  * percent + 10000;
        my["jingli"]     = hp_status["jingli"] / 125 * percent + 10000;
        my["max_jing"]   = hp_status["max_jing"] / 125  * percent + 10000;
        my["max_jingli"] = hp_status["max_jingli"] / 125  * percent + 10000;
        my["max_neili"]  = hp_status["max_neili"] / 125  * percent + 10000;
        my["neili"]      = hp_status["neili"] / 125  * percent + 10000;
        my["jiali"]      = 1000;
        my["combat_exp"] = hp_status["combat_exp"] / 1  * percent;

        set_temp("apply/attack",me->query_temp("apply/attack")/2);
        set_temp("apply/damage",me->query_temp("apply/damage")/2*percent);

        ob->reset_action();

        ::setup();

        // 衣服
        carry_object("/clone/GMwupin/GMSSS35")->wear();
        // 武器
//        carry_object("/clone/GMwupin/GMSSS36")->wield();
}

void heart_beat()
{
        object ob, env, owner, obtar;
        object *obs;
        
        keep_heart_beat();
        
        // 每3次心跳检查1次
        if (time() - query("last_check_heart_beat") >= 6)
        {
                set("last_check_heart_beat", time());
                
                // 如果不在出生房间超过1次则消失
                env = environment(this_object());
                if (! objectp(env) || env != query("start_place"))
                {
                        if (query("no_in_place") > 0)
                        {
                                // 消失
                                message_vision(HIG "$N" HIG "周身白光笼罩，伴随着刺眼的光芒，$N" HIG 
                                                   "瞬间化为乌有！\n" NOR, this_object());
                                destruct(this_object());
                                return;
                        }
                        else
                        {
                                add("no_in_place", 1);
                        }
                }
                // 如果超过时间则消失
                if (time() - query("start_time") > 1*30)
                {
                        message_vision(HIG "$N" HIG "周身白光笼罩，伴随着刺眼的光芒，$N" HIG 
                                        "瞬间化为乌有！\n" NOR, this_object()); 
                        destruct(this_object());
                        return;
                }
                
                // 三次检查OWNER不存在则消失
                owner = find_player(query("owner"));
                if (! objectp(owner))
                {
                        add("no_find_owner", 1);
                        if (query("no_find_ower") >= 3)
                        {
                                message_vision(HIG "$N" HIG "周身白光笼罩，伴随着刺眼的光芒，$N" HIG 
                                                "瞬间化为乌有！\n" NOR, this_object()); 
                                destruct(this_object());
                                return;                         
                        }
                }
                else // 随机攻击OWNER攻击的目标
                {
                        if (owner->is_fighting() && ! this_object()->is_fighting())
                        {
                                obs = owner->query_enemy();
                                if (sizeof(obs))
                                {
                                        obtar = obs[random(sizeof(obs))];
                                        message_combatd(HIR "\n$N" HIR "对$n" HIR "发动攻击……\n\n" NOR, this_object(), obtar); 
                                        this_object()->kill_ob(obtar);
                                }
                        }
                }
        }
        return ::heart_beat();
}

void init()
{

}

int accept_hit(object me)
{
        this_object()->kill_ob(me);
        return 1;
}

int accept_fight(object me)
{
        this_object()->kill_ob(me);
        return 1;
}

int accept_kill(object me)
{
        this_object()->kill_ob(me);
        return 1;
}

void unconcious()
{
        die();
}

void die(object killer)
{
        message_vision(HIG "$N" HIG "周身白光笼罩，伴随着刺眼的光芒，$N" HIG 
                                     "瞬间化为乌有！\n" NOR, this_object());
        destruct(this_object());
        return;
}
