inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "��̶");
        set("long",
"[1;32m��ΧһƬ�ڰ�������Ѿ�����ص��˰ɡ�����̦޺��������\n"
"���׹⣬���Կ���ǰ����Զ����һ����̶(tan)���������ˡ�\n"
);
        set("exits", ([ 
       "eastup" : __DIR__"spirit6",
        ]) );


        set("no_magic", 1);
	setup();
}


void init()
{
        add_action("do_look", "look");
        add_action("do_approach", "approach");
}

int do_look(string arg)
{
        object me;
        object room;
        me = this_player();
        if(!arg || arg != "��̶" && arg != "tan" ) return 0;
        switch ( random (2)) {
                case 0:
tell_object(me,"̶�߳�����̦޺�����ǲ�Ҫ������������裩��̫����\n"); 
                break;
                case 1:
message_vision("$N̽ͷ��̶����ȥ�� \n", me); 
tell_object(me,"�ڲ�¡�˵�̶ˮ����ס� \n");
                break;
        }


        return 1;
}
int do_approach(string arg)
{
        object me;
        object room;
        me = this_player();
        if(!arg || arg != "��̶" && arg != "tan" ) return 0;
        switch ( random (3)) {
                case 0:
message_vision("$N�߽���̶̽ͷ������ȥ�� \n", me); 
tell_object(me,"̶ˮ����ף��������ƺ���������������ˮ�������� \n");
                break;
                case 1:
message_vision("$N�߽���̶̽ͷ������ȥ����ѽ��һ��С�ĵ��˽�ȥ��\n", me); 
message_vision("$N��ͷײ��̶���ϣ�һ���ӻ��˹�ȥ��\n", me); 
                call_out("be_saved",8);
                me->unconcious();
                room = find_object(__DIR__"spirit10");
                 if(!objectp(room)) room=load_object(__DIR__"spirit10");
                me->move(room);
                break;
                case 2:
message_vision("$N�߽���̶̽ͷ������ȥ����ѽ��һ��С�ĵ��˽�ȥ��\n", me);
              room = find_object(__DIR__"underwater");
                if(!objectp(room)) room=load_object(__DIR__"underwater");
                me->move(room);
                break;
        }

        return 1;
}

int be_saved()
{   
            object me;            me=this_player();

            me->remove_call_out("revive");
            me->revive();
            me->reincarnate();
message_vision("$N�������ѹ����������Լ���һ��С���У�\n", me); 
message_vision("һ�������ľ�����Ů�ӿ���$N�ָ���֪�������е����˹�����\n", me);
           return 1;
}

