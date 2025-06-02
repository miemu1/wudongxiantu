// This program is a part of NITAN MudLIB 
// redl 2013/9
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 

int do_action(string arg)
{
        string action = query_verb();
        object me = this_player();
        if (query("no_get") && (action=="get" || action=="uget" || action=="drop")) {
                        tell_object(me, NOR "�㲻���������������ӡ�\n" NOR);
                        return -1;
                }
        return 0;
}

int discmds() 
{ 
        tell_object(this_player(), "�㲻��������ë��ë�š�\n");  
        return 1;  
} 

int disyanjiu() 
{ 
        tell_object(this_player(), "�㲻���������о���ϰ��\n");  
        return 1;  
} 

void init()
{
        object *inv;
        int countp;
        object me = this_player();
        
        if ( wiz_level(me) > 5 ) return;
        
        if (playerp(me))  {     
        
        //��������
                        inv = all_inventory();
                        if( sizeof(inv) > 0 ) {
                foreach( object ob2 in inv ) {
                        if ( playerp(ob2) ) countp ++;
                }
                }
    if(query("max_carry_user") && query("max_carry_user")<countp && query("max_carry_exit")) {
                tell_object(me, "\n�㷢����Ϊ�������أ���ռ���ֲ��ȶ���״̬���ŵøϽ��˳���\n\n");  
                me->command(query("max_carry_exit"));
                return;         
    }
        
        add_action("do_action", "");
        if (query("no_user_kill")) add_action("discmds", ({  
                                                                "steal", "cast", "conjure", "array", "fight", "hit",   
                                                                "quit", "exit", "recall", "kill", "ansuan", "touxi", 
                                                  "stab",
                                                  "ride","qi",
                                                                "surrender", "exert", "team", "chatroom", "rideto", "array",
        }));  
        if (query("no_user_yanjiu")) add_action("disyanjiu", ({"research", "yanjiu", "practice", "lian"})); 
        
        }
}


