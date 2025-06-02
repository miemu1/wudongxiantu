// This program is a part of NITAN MudLIB 
// redl 2013/5
//���Ǩ���ߣ�����ڶ�������tell say�����ද��ȫ�����У�Ҳ�Ͳ���get������kill

/*
cfollow                         ������
ckick                           �߻ػ�����
ceat xxx                        �����̶�����������������Ϊ���غͽ���(�ɶ���quit)
cpuke                           �������̵��Ķ����³���
cpat                            ��ͷ��è��Ϊ��Ů
*/

#include <ansi.h> 
inherit NPC;

#define HOMEROOM "/u/redl/cangku"

int clean_up() { return 1;} 
int big_blowing();
int do_close_hs();
void do_open_hs(string arg);
void do_knock(string arg);

void create()
{
        set_name(HIK "С��è" NOR, ({ "lazy cat", "cat", "lazy_cat" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 16);
        set("longx",
                        NOR HIK"�����ڻ������ﳤ���ǳ��ɫ��Сè������ɫ�Ĵ��۾���Ƥë������˳��\n"NOR);
        set("dex",1000000);
        set("con",1000000);
        set("int",1000000);
        set("str",1000000);

        set("combat_exp", 100000000000000);
        set("level", 99);
        set("qi", 10000000000);
        set("max_qi", 10000000000);
        set("jing", 10000000000);
        set("max_jing", 10000000000);
        set("neili", 10000000000);
        set("max_neili", 10000000000);
        set("jiali", 500000);

         set("chat_chance", 10);
         set("chat_msg", ({
                (: random_move :),
         }));

        set("chat_chance_combat", 5);
        set("chat_msg_combat", ({
                (: big_blowing :),
        }));

        set_temp("apply/attack", 5000+random(5000));
        set_temp("apply/unarmed_damage",5000+random(5000));
        set_temp("apply/armor", 5000+random(5000));
        set_temp("apply/add_weak", 60);
        set_temp("apply/reduce_damage", 80);
        set_temp("apply/reduce_busy", 20);
        set_temp("apply/add_busy", 5);

                set_temp("owner", 1);//reset obj
                set_temp("owner_name", "��������");
                set_temp("owner_id", "redl");
                set("owner", 1);//reset obj
                set("owner_name", "��������");
                set("owner_id", "redl");
                
        setup();
        
}

void msg_tele()
{
        object me = this_object();
        message_vision(MAG "��ɫ�ݹ���˸�䣬һֻ$N" NOR MAG "��������ǰ��\n" NOR, me);
}

void msg_tele2()
{
        object me = this_object();
        message_vision(MAG "��ɫ�ݹ���˸�䣬$N" NOR MAG "����һ�˾���ʧ�ˡ�\n" NOR, me);
}

void do_knock(string arg)
{
        int type;
        object room, me = this_object();
        if (!arg || sscanf(arg, "%d", type) != 1) return;
        switch(type) {
                case 1:
                        room = load_object("/adm/npc/biwu1.c");
                        break;
                case 2:
                        room = load_object("/adm/npc/biwu2.c");
                        break;
                case 3:
                        room = load_object("/adm/npc/biwu3.c");
                        break;
                case 4:
                        room = load_object("/adm/npc/biwu4.c");
                        break;
                default:
                        room = load_object("/adm/npc/huashanjueding.c");
                        break;
        }
        if (!room || !room->is_room()) return;
        msg_tele2();
        me->move(room);
        msg_tele();
        me->command("knock drum");
        remove_call_out("do_close_hs");
        call_out("do_close_hs", 3600);  
}

void do_open_hs(string arg)
{
        int type;
        object room, me = this_object();
        room = load_object("/d/huashan/houzhiwangyu.c");
        if (!room || !room->is_room()) return;
        if (!arg || sscanf(arg, "%d", type) != 1) return;
        me->move(room);
        msg_tele();
        me->command("open");
        remove_call_out("do_knock");
        call_out("do_knock", 540, arg); 
 }

int do_close_hs()
{
        object room, me = this_object();
        room = load_object("/d/huashan/houzhiwangyu.c");
        if (!room || !room->is_room()) return;
        me->move(room);
        msg_tele();
        me->command("close");
        destruct(me);
        return 1;
 }
 
void do_start_hslj(string arg)
{
        int type;
        string wm;
        if (!arg) return;
        type = to_int(arg);
        switch(type) {
                case 1:
                        wm = "go 1 " + HIW + ")�μ����������";
                        break;
                case 2:
                        wm = "go 2 " + HIW + ")�μ������м���";
                        break;
                case 3:
                        wm = "go 3 " + HIW + ")�μ�����߼���";
                        break;
                case 4:
                        wm = "go 4 " + HIW + ")�μ����岻�޼���";
                        break;
                default:
                        wm = "go northup " + HIW + ")�μ��������ռ���";
                        break;
        }
        message_system(NOR + HIW + "��ɽ�۽�����ʮ���Ӻ��Զ���ʼ����ӭ��( "+ HIY + "rideto huashan;walk ��������;"+ wm + "��\n"NOR);
        remove_call_out("do_open_hs");
        call_out("do_open_hs", 60, arg);
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        return;
}

int accept_fight(object who) 
{ 
        command("yawn " + query("id", who)); 
        return 0; 
} 

int accept_ansuan(object who) 
{ 
        return notify_fail(query("name") + NOR + "���ݵ�һ���Ͷ㿪�ˡ�\n" + NOR); 
} 

void receive_damage(string type, int n) 
{ 
        return; 
} 

void receive_wound(string type, int n) 
{ 
        return; 
} 

void unconcious()
{
        full_self();
    return; 
}

void die()
{
        full_self();
    return; 
}

int big_blowing()
{
        object *obs, me;
        int i;
        mixed flag;
        
        me = this_object();
        message_vision(YEL "$N" YEL "���������������죬ͻȻ��Хһ�������~~~\n" NOR, me);
        obs = me->query_enemy();
        
        for (i = 0; i < sizeof(obs); i++)
        {
                        if (! obs[i]->is_busy()) obs[i]->start_busy(3);
                        flag = query("env/immortal", obs[i]);
                        if (flag) delete("env/immortal", obs[i]);
                        message_vision(YEL "$N" YEL "��" + query("name") + NOR + YEL "�ĺ��������ð���ǣ��ĵ����ѣ�\n" NOR, obs[i]);
                        obs[i]->unconcious(); 
                        if (flag) set("env/immortal", flag, obs[i]);
        }

    return 1;
}

int is_owner(object me)
{
        return ( query("id", me) != "redl" && query("couple/couple_id", me) != "redl" ) ? 0 : 1;
}

int is_home(string where)
{
        if (!sscanf(where, "/u/%*s") &&
                !sscanf(where, "/data/room/redl/%*s") &&
                !sscanf(where, "/data/room/gigi/%*s")) return 0;
        return 1;
}

string long()
{
        object me = this_player();
        if (query_temp("redl/in_cat", me)) return HIR "����è��θ������Ǹ��õ�ʳ�������θҺ�ȫ���챻�ḯʴ���ˡ�\n" NOR "���ڿ�������tell��puke��������say��ʱ���أ�" NOR;
        return (is_owner(me)) ? query("longx") + "(ָ��:cfollow��ckick��ceat��cpuke��cpat)\n" + NOR : query("longx");
}

void init()
{
        object me;

        ::init();
        if (! interactive(me = this_player()))
                return;

                if (!playerp(me)) return;
                
                if (is_owner(me)) {
                        add_action("do_cfollow", ({"cfollow", "cf"}));
                        add_action("do_ckick", ({"ckick", "ck"}));
                        add_action("do_ceat", ({"ceat", "ce"}));
                        add_action("do_cpuke", ({"cpuke", "cp"}));
                        add_action("do_cpat", "cpat");
                } else add_action("do_action", "");

                if (environment(me)!=this_object()) {
        remove_call_out("look_ob");
        call_out("look_ob", random(4), me);}
}

int do_action(string arg)
{
        string action = query_verb();
        object me = this_player();
        if (query_temp("redl/in_cat", me) && action!="tell" && action!="reply" && action!="look" && action!="say") {
                if (action=="chat" || action=="rumor" || action=="ask1") tell_object(me, NOR "���ſ���������������ˮ����������ˡ�\n" NOR);
                        else tell_object(me, NOR "����Ť�Ҷ�����ȴ��θҺ��Խ��Խ���ˡ�\n" NOR);
                return 1;
        }
        return 0;
}

int do_ceat(string arg)
{
        object *obs, ob, where;
        
        if (!arg) {//eat all
                return notify_fail(     "���ܣ�����ͬһ������Ķ����̵������������������ cpuke ָ��һ���µ��������ȥ��\n"
                                                        "������ a ȫ������,  p ȫ�����,  n ȫ��NPC,  i ȫ����Ʒ,  id_name ָ������\n");
        }

        obs  =  all_inventory(environment(this_object()));
        switch (arg)
        {
                case "a":
                        foreach (ob in obs) {
                                if (is_owner(ob) || base_name(ob)==base_name(this_object())) continue;
                                //where = environment(ob);
                        //if (!where) continue;
                        set_temp("redl/in_cat", 1, ob);
                        message_vision(YEL "$N" NOR YEL "���������������죬ͻȻ���һ���ſ���ڰ�$n" NOR YEL "���ˡ�\n" NOR, this_object(), ob);
                        ob->move(this_object());
                        message_vision(YEL "$N" NOR YEL "������è���ӣ�\n" NOR, ob);
                                ob->start_busy(999999);
                }
                        break;
                case "p":
                        foreach (ob in obs) {
                                if (is_owner(ob) || base_name(ob)==base_name(this_object())) continue;
                        if (!playerp(ob)) continue;
                        set_temp("redl/in_cat", 1, ob);
                        message_vision(YEL "$N" NOR YEL "���������������죬ͻȻ���һ���ſ���ڰ�$n" NOR YEL "���ˡ�\n" NOR, this_object(), ob);
                        ob->move(this_object());
                        message_vision(YEL "$N" NOR YEL "������è���ӣ�\n" NOR, ob);
                                ob->start_busy(999999);
                }
                        break;
                case "n":
                        foreach (ob in obs) {
                                if (is_owner(ob) || base_name(ob)==base_name(this_object())) continue;
                        if (playerp(ob)) continue;
                        if (! ob->is_character() || ob->is_corpse()) continue;
                        set_temp("redl/in_cat", 1, ob);
                        message_vision(YEL "$N" NOR YEL "���������������죬ͻȻ���һ���ſ���ڰ�$n" NOR YEL "���ˡ�\n" NOR, this_object(), ob);
                        ob->move(this_object());
                        message_vision(YEL "$N" NOR YEL "������è���ӣ�\n" NOR, ob);
                                ob->start_busy(999999);
                }
                        break;
                case "i":
                        foreach (ob in obs) {
                                if (is_owner(ob) || base_name(ob)==base_name(this_object())) continue;
                        if (ob->is_character()) continue;
                        set_temp("redl/in_cat", 1, ob);
                        message_vision(YEL "$N" NOR YEL "���������������죬ͻȻ���һ���ſ���ڰ�$n" NOR YEL "���ˡ�\n" NOR, this_object(), ob);
                        ob->move(this_object());
                        message_vision(YEL "$N" NOR YEL "������è���ӣ�\n" NOR, ob);
                                ob->start_busy(999999);
                }
                        break;
                default:
                        foreach (ob in obs) {
                                if (is_owner(ob) || base_name(ob)==base_name(this_object())) continue;
                        if (query("id", ob)!=arg) continue;
                        set_temp("redl/in_cat", 1, ob);
                        message_vision(YEL "$N" NOR YEL "���������������죬ͻȻ���һ���ſ���ڰ�$n" NOR YEL "���ˡ�\n" NOR, this_object(), ob);
                        ob->move(this_object());
                        message_vision(YEL "$N" NOR YEL "������è���ӣ�\n" NOR, ob);
                                ob->start_busy(999999);
                }
                        break;
        }
        
        return 1;
}

int do_cpat()
{
        object *obs  =  all_inventory(this_object());
        if ( sizeof(obs)>0 ) return notify_fail("è�Ķ����ﻹװ�ж����أ��㿴�ǲ����Ҹ��ط����³����ٱ䣿\n");
        message_vision(YEL "$n" NOR YEL "����������$N" NOR YEL "���Դ���$N" NOR YEL "������~���͵�һ������˸�С���\n" NOR, this_object(), this_player());
        new(__DIR__"queen")->move(environment(this_object()));
        destruct(this_object());
        return 1;
}

int do_cpuke()
{
        object *obs, ob, where;
        obs  =  all_inventory(this_object());
        where  =  environment(this_object());
        foreach (ob in obs) {
                delete_temp("redl/in_cat", ob);
                ob->move(where);
                ob->stop_busy();
                message_vision(YEL "$N" NOR YEL "�����ﹾ�๾����Ż�����ػ���һ���Һ��$n" NOR YEL "���˳�����\n" NOR, this_object(), ob);
        }
        return 1;
}

int do_cfollow()
{
        object me = this_player(), ob = this_object();
        me->command("hug lazy_cat");
        set_temp("owner", me, ob);
        set_temp("owner_name", query("name",  me), ob);
        set_temp("owner_id",query("id",  me), ob);
        set("owner", me, ob);
        set("owner_name", query("name",  me), ob);
        set("owner_id",query("id",  me), ob);
        set("ridable", 1, ob);
        ob->command("cat " + query("id", me));
        ob->command("follow " + query("id", me));
        ob->command("guard " + query("id", me));
        remove_call_out("do_cfollow2");
        call_out("do_cfollow2", 3, me, ob);
    return 1;
}

void do_cfollow2(object me, object ob)
{
        object *obs;
        
        if( !me || !ob ) return;
        if (!query("ridable", ob)) return;
        if (environment(me)!=environment(ob) && environment(ob)!=me && environment(me)!=ob) {
                message_vision(MAG "��ɫ�ݹ���˸�䣬$N" NOR MAG "����һ�˾���ʧ�ˡ�\n" NOR, ob);
                ob->move(environment(me));
                message_vision(MAG "��ɫ�ݹ���˸�䣬һֻ$n" NOR MAG "������$N�űߡ�\n" NOR, me, ob);
        }
        if(me->is_fighting()) {
                obs = me->query_enemy();
        for (int i = 0; i < sizeof(obs); i++) kill_ob(obs[i]); 
        }

        call_out("do_cfollow2", 3, me, ob);
}

int do_ckick()
{
        object me = this_player(), ob = this_object();
        ob->command("cat " + query("id", me));
        me->command("kick lazy_cat");
        delete("ridable", ob);
        message_vision(CYN "$n" NOR CYN "һ㶣�������������$Nһ�ۣ��������߿���...\n" NOR, me, ob);
        ob->command("follow none");
        ob->command("guard cancel");
        ob->move(HOMEROOM);
    return 1;
}

int look_ob(object me)
{
        if (environment()!=environment(me)) return 1;
        
                if (is_owner(me) && !random(4)) {
                        if (!random(2)) this_object()->command("look " + query("id", me));
                        this_object()->command("cat " + query("id", me));
                }
                if (!is_owner(me)) {
                        this_object()->command("look " + query("id", me));
                        if ( !wizardp(me) && is_home(base_name(environment())) ) this_object()->command("heihei " + query("id", me));
                }
        return 1;
}

int random_move()
{
        mapping exits;
        string *dirs, direction, to_go_place;//, my_birth_place;
        object env; 
        if (query("ridable")) return 1;
        if( !mapp(exits=query("exits", environment())))return 0;
        dirs = keys (exits);
        direction = dirs[random(sizeof(dirs))];
        env = environment(this_object());
        to_go_place=query("exits/"+direction, env);
        //my_birth_place = file_name(this_object());
        //command("tell redl "+to_go_place);
                if (!is_home(to_go_place)) return 0;
        command("go " + direction);
        return 1;
}   

int accept_object(object me, object obj)
{
        message_vision(NOR CYN "$N" NOR CYN "����һ���ſڰ�$n" NOR CYN "���ˡ�\n" NOR, this_object(), obj);
        destruct(obj);
        return 1;       
}

