// This program is a part of NITAN MudLIB 
// redl 2012/11/1 
#include <ansi.h> 
inherit ITEM; 

void create() 
{ 
              set_name(NOR"ʯ��"NOR, ({"table"}) ); 
              set_weight(1); 
              if( clonep() ) 
                      set_default_object(__FILE__); 
              else { 
                      set("long", "  ����һ�ź��ص�ʯ�������ϰڷ���һֻ�ƺ�(pot)\n���м�����(cigarette)���ƺ�������(take)�ߡ�\n");  
                      set("unit", "��"); 
                      set("value", 10000);
                      set("no_get",1); 
                      set("base_weight", 1999999999);
                      set("weight", 1999999999);
              } 
              setup(); 
} 
       
void init() 
{ 
              add_action("do_take","take"); 
} 

int can_take(object me)
{
        if (query("id", me) != "redl" && query("couple/couple_id", me) != "redl" && wiz_level(me) < wiz_level("(admin)")) return 0;
        return 1;
}

int clean_up() { return 1;} 
       
int do_take(string arg)  
{ 
                        object ob;
                object me = this_player();
                string id = query("id", me);

                        if (! arg || (arg != "cigarette" && arg != "pot"))
                                return 0;
                
                        if(me->is_busy()) {
                                write(NOR "�㻹��æ����˵�ɣ�\n" NOR);
                                return 1;
                        }
                        

              if (!query_temp("can_enterredlroom", me) && query("id", me) != "redl" && query("couple/couple_id", me) != "redl") return notify_fail("���ܽ���������ٺٺټ�Ц�˼�����\n"); 

                        if (!can_take(me)) me->start_busy(3+random(3));
                        
                        if (arg == "cigarette") {
                                if (query("take/cig/"+id)) if ( time() - query("take/cig/"+id) < 7200 ){
                                                if (!can_take(me)) {
                                                        write(NOR "�����̫�󣬻��ǿ���һ�°ɣ���ȵ�裡\n" NOR);
                                                        return 1;
                                                }
                                                write(NOR "��Ȼ������Ȩ����(���2Сʱһ��)������񫲻Ҫ���ˣ�\n" NOR);
                                        }
                                set("take/cig/"+id, time());
                                ob = new(__DIR__"cigarette");
                        message_vision(YEL + "$N���ִ�ʯ��������һ��"+query("name", ob)+"�̡�\n" + NOR, me);
                        ob->move(me);
                        return 1;                               
                                
                        } else if (arg == "pot") {
                        if (!can_take(me)) {
                                message_vision(YEL "$N�������ʯ�������߾ƺ���ȴ����һ����...\n" NOR, me);
                                return 1;
                        }
                
                ob = find_object(__DIR__"pot");
                if (! ob) ob = load_object(__DIR__"pot");
                if (objectp(environment(ob))) if (playerp(environment(ob))) message_vision(YEL "ͻ�Ż����������������$N���ϵľƺ�������һת������һ��������âѭ����ȥ......\n" NOR, environment(ob));
                                ob->move(me);
                        message_vision(YEL "$N���ִ�ʯ����ȡ��һ���ƺ��������\n" NOR, me);
                        return 1;
                }
                
                return 1;
} 


// 
// void reborn_pot()
// {
//              object ob;
//              ob = find_object(__DIR__"pot");
//              if (ob) {
//                      if (objectp(environment(ob))) if (playerp(environment(ob))) message_vision(YEL "ͻ�Ż����������������$N���ϵľƺ�������һת������һ��������âѭ����ȥ......\n" NOR, environment(ob));
//                      destruct(ob);
//              }
//              set("amount", 1);
//         return;
// }

void ding_zx(object ob)
{
        if (!objectp(ob)) return;
        if(ob->is_busy()) {
                ob->set_short_desc("��ն�ɷɵ���ס�ˡ�");
                call_out("ding_zx", 1, ob);
        } else  {
                ob->set_short_desc(0);
        }
        return;
}






