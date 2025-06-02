// This program is a part of NITAN MudLIB  
// redl 2014/8
#include <ansi.h>  
#include <room.h>  

inherit "/u/redl/teleport/normal.c";  

string* MAJIU = ({"/d/beijing/majiu","/d/changan/majiu","/d/chengdu/majiu","/d/city/majiu","/d/city2/majiu","/d/dali/majiu",
                                "/d/foshan/majiu","/d/fuzhou/majiu","/d/guanwai/majiu","/d/hangzhou/majiu","/d/hanzhong/majiu","/d/hasake/majiu",
                                "/d/henshan/majiu","/d/jiaxing/majiu","/d/jingzhou/majiu","/d/kaifeng/majiu","/d/kunming/majiu","/d/lanzhou/majiu",
                                "/d/lingzhou/majiu","/d/luoyang/majiu","/d/nanyang/majiu","/d/quanzhou/majiu","/d/suzhou/majiu","/d/wuchang/majiu",
                                "/d/wuxi/majiu","/d/xiangyang/majiu","/d/xingxiu/majiu","/d/yanping/majiu","/d/yongdeng/majiu","/d/zhongzhou/majiu"});

int is_qkroom() {return 1;}

void create()
{
        set("short","Ǭ������");
        set("long", @LONG
��������ϼ�������Ǭ�������ϵ�һ�����������������Ϲ�ʱٲ
Ȼ���Գ���أ���ҿ��Է��ĵ��ڴ˼ƻ������������м�ֻʯ��Χ��
��ʯ���������ƺ��и�����(help qk)���Ա߻��м�����衣
LONG );
        set("exits",([ 
            "down"  : __FILE__,
        ]));
        set("objects", ([ 
               "/u/redl/teleport/npc/chachong1" :       1, 
               "/u/redl/teleport/npc/chachong2" :       1, 
               "/u/redl/teleport/npc/chachong3" :       1, 
               "/u/redl/teleport/npc/chachong4" :       1, 
               "/u/redl/teleport/npc/chachong5" :       1, 
               "/u/redl/teleport/npc/chachong6" :       1, 
               "/u/redl/teleport/npc/chachong7" :       1, 
               "/u/redl/teleport/npc/chachong8" :       1, 
               "/u/redl/teleport/npc/chachong9" :       1, 
        ])); 
        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         
        set("no_rideto", 1);
        set("no_flyto", 1);
        set("no_user_kill", 1); 
        set("dongtianfudi", 1000); 
        set("sleep_room", 1); 
        setup();
}

int do_guantian(object me)
{
        int cost;
        object *obs, ob;
        if (query("guantian_time") < time()     ) {
                obs = filter_array(users(), (: wiz_level($1)<1 :));
                set("guantian_target", obs[random(sizeof(obs))]);
                set("guantian_time", time() + 30 + random(7)*5);
                message_vision(NOR YEL "$N" NOR YEL  "���˳���������ĺ��壬��ڷ���������һ��������˾���\n" NOR, me);
        }
        
        ob=query("guantian_target");
        if (!ob || !environment(ob)) {
                tell_object(me, NOR HIC "��ʧȥ�˹۲�Ŀ�ꡣ\n" NOR);
                return 1;
        }
        
        cost = 1000 + query("level", ob) * query("level", ob);
        tell_object(me, NOR HIC "��͸�����쾵�Ƶ����ƣ��ƺ�������" HIY + ob->name() + HIC "����Ӱ...\n" 
                 NOR " ( ��ľ����ܵ� "+(string)cost+" �㷴���˺� ) \n" NOR);
        me->receive_wound("jing", cost);        

        if (query("eff_jing", me) < 100000 || query("jing", me) < 100000) {
                set_temp("die_reason", NOR + "��Ǭ��������Ĺ��쾵���ɶ���" + NOR, me);
                set("eff_jing", -1, me);
                set("jing", -1, me);
                me->die();
                return 1;
        }
                        
        tell_object(ob, NOR "����Լ�е���һ˿�˳��������������..\n" NOR);
        "/cmds/std/look.c"->look_room(me, environment(query("guantian_target")));
        return 1;
}

int do_look(string arg)
{
                string msg = "";
        object me = this_player();
        if ( arg && arg=="down" ) {
    //                  if( query("eff_jing", me) < 100000 )
//                              tell_object(me, NOR "�㾫��״̬���ѣ�ʲôҲ����������\n" NOR);
                if (me->is_busy())
                                tell_object(me, NOR "��������ȥ��ֻ�����Ʋ��ã�ʱ������������ֹ��\n" NOR);
                        else {
                                me->start_busy(2);
                                do_guantian(me);
                        }       
                        return -1;
        }
        else if ( arg && arg=="chong" ) {
                msg += "���Ǽ�����裬���Ƶ�����������\n";
                        tell_object(me, NOR + msg + NOR);
                        return -1;
        }
        return 0;
}

int init() 
{ 
        add_action("do_look", "look");
} 

int valid_leave(object me, string dir)
{
        string path;
                if (dir=="down") {
                        if (query("to_down")) {
                                message_vision(NOR YEL "$N" NOR YEL  "�������ǿ������һվ������������С����������ʧ�����С�\n" NOR, me);
                                me->move(query("to_down"));
                                message_vision(NOR YEL "����ͻȻð��ö�����ӣ������Ǵ�$N" NOR YEL  "�������߳����󣬺������ֳ�����¡�\n" NOR, me);
                                return 1;
                        }
                        path = MAJIU[random(sizeof(MAJIU))];
                        if ( file_size(path + ".c") < 1 ) {
                                error( path + ".cȱʧ. \n");
                                return 1;
                        }
                        message_vision(NOR YEL "$N" NOR YEL  "�������ǿ������һվ������������С����������ʧ�����С�\n" NOR, me);
                        me->move(path);
                        message_vision(NOR YEL "����ͻȻð��ö�����ӣ������Ǵ�$N" NOR YEL  "�������߳����󣬺������ֳ�����¡�\n" NOR, me);
                        return 1;
                }
                
        return ::valid_leave(me, dir);
}

