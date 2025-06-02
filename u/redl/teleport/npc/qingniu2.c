//��ʼ�Ķ��ļ���/kungfu/class/misc/houwang.c
//redl 2015/5
#include <ansi.h>
inherit NPC;

int is_niuren() { return 1;}

void heart_beat()
{
        object me = this_object();
        me->stop_busy();
        return ::heart_beat();
}


int is_home(string where)
{
        if (strsrch(where, "dongtian") != -1)
                return 0;
        return 1;
}

int random_move()
{
        mapping exits;
        string *dirs, direction, to_go_place;
        object env; 
        string *list=query("slots");

                if (!query("can_move")) return 0;
        if( !mapp(exits=query("exits", environment())))return 0;
        if (this_object()->is_fighting()) return 0;
        dirs = keys (exits);
        direction = dirs[random(sizeof(dirs))];
        if (strsrch(direction, "west") != -1 || 
                (query("rnd_stp") > 8)
                ) {
                delete("rnd_stp");      
                env = environment(this_object());
                to_go_place=query("exits/"+direction, env);
            if (!is_home(to_go_place)) return 0;
                command("go " + direction);
                if (!list || !sizeof(list)) {
                        list = ({env->short()});
                                CHANNEL_D->channel_broadcast("rumor", "�ݴ����ӵ�׷�������Ѿ��뿪��" + env->short() + "��");
                } else if (member_array(env->short(), list)==-1) {
                        list += ({env->short()});
                                CHANNEL_D->channel_broadcast("rumor", "�ݴ����ӵ�׷�������Ѿ��뿪��" + env->short() + "��");
                }
                set("slots", list);
        }
        addn("rnd_stp", 1);
        return 1;
}   


void create()
{
        set_name(HIG "����ţ" NOR, ({ "qing niu", "qing", "niu" }));
        set("title", CYN "ʥ������" NOR);
        set("race", "Ұ��");
        set("age", 48);
        set("long", "����һֻҰ�������������㽡׳ţ��������\n");
        set("rank_info/rude", "����");
        set("rank_info/respect", "��ţ");
        set("combat_exp", 5000000000);
        set("attitude", "heroism");
        set("str", 8000);
        set("int", 5);
        set("con", 8000);
        set("dex", 30);

        set("max_jing", 1000 * 2000);
        set("jing", query("max_jing"));
        set("max_qi", 1000 * 2000);
        set("qi", query("max_qi"));
        set("shadow_hp", 1000 * 2000);

        set("auto_perform", 1);
                set_heart_beat(1);

                set("chat_chance", 16);
        set("chat_msg", ({
                (: random_move :),
        }));
        
        setup();
}
        
int receive_damage(string type, int n, object who) 
{ 
        object ob;
        string unit;
        n = n / 100000000;
        if (!who) return;
        if (!userp(who) && !objectp(who=(query("owner")))) return;
        if (!who || !userp(who)) return;
        if (n > 1000) n = 1000;
        if (query_temp("qingniu2/time", who) < time() && random(3000) < n) {
                set_temp("qingniu2/time", time(), who);
                if (!random(100)) ob = new("/d/dongtian/obj/wanxiangbook");
                else if (!random(18)) ob = new("/clone/medicine/yuqingwan");
                else ob = new("/clone/gift/jiuzhuan");
                if (objectp(ob))
                {
                        unit = query("base_unit", ob);
                        if (!unit) unit = query("unit", ob);
                        ob->move(who, 1);
                        tell_object(who, HIW "���" + name() + NOR + HIW + "����������һ" + unit + ob->name() + "��\n" NOR);                            
                }
        }
        addn("shadow_hp", -n);
        if (query("shadow_hp")<0) {
                set("killer", who);
        }
        return ::receive_damage(type, n , who);
} 
      
int receive_wound(string type, int n) 
{ 
     return;
} 
      
int accept_kill(object who)
{
        object *t;
        set("enemy_player", who);
        this_object()->kill_ob(who);
        who->kill_ob(this_object());
        if (t && sizeof(t)) {
                t -= ({ 0 }); 
                foreach (object tob in t) 
                        tob->kill_ob(who);
        }
    return 1;//::accept_kill(who); 
}

int accept_fight(object who)
{
        return accept_kill(who); 
}

int accept_ansuan(object who)
{
        return 0; 
}

int accept_hit(object who)
{
        return accept_kill(who); 
}

void die(object killer)
{
        string prop, name;
        mapping data;
        object *obs, ob, where;
                object *enemies, *enemies2, enemy, enemy2;
                int num, radd;
        enemy = query("killer");                        
                if (objectp(enemy) && 
                        environment(this_object()) == environment(enemy)) {
                        message_vision(HIW "\n$N" HIW "ץסţ�ǣ�����ţ������$n" HIW "������һ���ƣ��ɵ���$n" HIW "��\n\n" NOR, enemy, this_object());
                        radd = 10000 + random(query("level", enemy) * query("level", enemy));
                        addn("drug_addjingli", radd, enemy);
                tell_object(enemy, HIC "�㷭��" HIY "��̫���鱦���ӻ������" HIC "���������޶�������" HIY + chinese_number(radd) + HIC "�㡣\n" NOR);
                        return ::die(enemy);
                }
                
        if( objectp(ob = previous_object(0)) && sscanf(base_name(ob), "/kungfu/skill/%*s") )
        {
                ob = previous_object(4);
                if (userp(ob) && environment(this_object()) == environment(ob))
                        this_object()->receive_damage("qi", 800, ob);
            return;
        }

        if (!objectp(enemy)) return;
    return ::die(killer);
}

void unconcious()
{
     object ob,me = this_object();
     if(!objectp(ob)) ob = me->query_last_damage_from();
     if(!objectp(ob)) ob = query_temp("last_damage_from",me);
     die(ob);
}

void start_move()
{
        set("can_move", 1);
}

