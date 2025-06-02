// This program is a part of NITAN MudLIB 
// redl 2015/10
#include <ansi.h> 
#include <room.h> 
#include <transmsg.h>

inherit ROOM;

int valid_leave(object me, string dir)
{
        if (random(2) && me->is_fighting())
        {
                tell_object(me, "�㻹���Ƚ��Ŀǰ�ĵ��˰ɣ�\n"); 
                return 0;
        }
                
        return ::valid_leave(me, dir);
}

int discmds() 
{ 
        tell_object(this_player(), "�㲻��������ë��ë�š�\n");  
        return -1;  
} 

int do_esc() 
{ 
        if (!query_temp("jinchuan/iesc", this_player())) {
                tell_object(this_player(), "���Ѿ�û��СǬ�����ˡ�\n");  
                return -1;
        }
        if (strsrch(base_name(this_object()), "yuanjiang/chuan7")!=-1) {//����10��ɴ���ʱ
                tell_object(this_player(), "��û��������ʹ��СǬ������\n");  
                return -1;
        }
        addn_temp("jinchuan/iesc", -1, this_player());
        message_vision(HIY "$N" HIY "һ�����䣬����һƬ���ͻȻ��ʧ�ˡ�\n" NOR, this_player());
        this_player()->move(get_object(__DIR__"chuan" + (string)random(50)));
        message_vision(HIY "$N" HIY "����һƬ���ͻȻ��������������\n" NOR, this_player());
        return 1;  
} 

int do_get()
{
        if (this_player()->is_fighting())
             {
                if (strsrch(base_name(this_object()), "yuanjiang/chuan7")!=-1) {//����10��ɴ���ʱ������ս������ǰgetʤ��Ʒ
                tell_object(this_player(), "ս����û��ȥ������\n"); 
                return -1;
            }
        }
    return 0;
}

int do_chou()
{
        object me = this_player();
        int rnd = random(5)+1;
        int num = query("yuan_ci_num", this_object());
        string msg = "";
        
        if (num<1) {
                tell_object(me, NOR "�˵�Ԫ�������Ѿ��ѷ���\n" NOR); 
                return -1;
        }
        
        if (me->is_busy())
        {
                tell_object(me, NOR BUSY_MESSAGE NOR); 
                return -1;
        }
        else if (!random(3))
                me->start_busy(1);      
                        
        addn("gcjinchuan_yuancizhenqi/" + (string)rnd, 1, me);
        addn("yuan_ci_num", -1, this_object());
        tell_object(me, NOR "�����ƴӲյ׵��ƶ���������Ԫ����������ĵط��˹�һ�����õ�һ��" + HIY + ({"","��","ľ","��","ˮ","��"})[rnd] + NOR "��Ԫ��������\n" NOR); 
        for (int i = 1; i <= 5; i++) {
                msg += ({"","��","ľ","��","ˮ","��"})[i] + "." + (string)(query("gcjinchuan_yuancizhenqi/" + (string)i, me)) + "  ";
        }
                tell_object(me, NOR + msg + "\n" + NOR);
        return 1;
}

void init()
{
        object room, who, *objs, *doors;
        
        add_action("do_esc", ({"esc", "escape"})); 
        add_action("do_get", ({"get", "eat"})); 
        if (!playerp(this_player())) return;
        set("trans_msg_to", __DIR__"chuancenter");
        set("trans_msg_id", query("id", this_player()));
        add_action("do_chou", "xi"); 
        if (wiz_level(this_player()) < 2) add_action("discmds", ({  
                        "steal", "cast", "conjure", "array", "fight", "hit",   
                        "home", "ansuan", "touxi", "ride", "qi", "stab", "fbattle",
                        "surrender", "array", "battle", "accept", "swear",
                        "recall", "quit", "exit", "miss", "rideto", "chatroom",
        }));  
        room = this_object();
        doors = filter_array( all_inventory(room), (: strsrch(base_name($1), "yuanjiang/npc/obj/door")!=-1 :) );
        if (sizeof(doors)>0) {
                tell_object(this_player(), NOR"\n�㷢����һ�����صĲ���(door)��\n\n"NOR); 
                return;
        }

        if ( query("env/invisible", this_player()) ) return;//wiz

        if(!query_temp("apply/shade_vision", this_player()) || query_temp("apply/shade_vision", this_player())<1 ) {            
                objs = filter_array(all_inventory(room), (: playerp($1) && (query("id", $1)!=query("id", this_player())) :));
                if (sizeof(objs)>0) {
                        who = objs[random(sizeof(objs))];
                        if(!query_temp("apply/shade_vision", who) || query_temp("apply/shade_vision", who)<1 ) {
                                this_player()->kill_ob(who);
                                who->kill_ob(this_player());
                        }
                }
        }
        
        if ( query("stop_run") ) return;
        tell_object(this_player(), NOR"\n�𴬺�¡һҡ����ˤ��һ�����˽ţ����춼����������\n\n"NOR); 
        if (query_temp("apply/shade_vision", this_player()) && !random(4)) {
                delete_temp("apply/shade_vision", this_player());
        message_vision(HIK "$N" HIK "����������¶��������������ɼ���\n" NOR, this_player());
        }
        this_player()->start_busy(2+ random(4));
        set("stop_run", random(3), room);
        
}


