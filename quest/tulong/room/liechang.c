inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "ɽ��");
        set("long", HIG @LONG �˴���Щϡ�����ľ����ǰ������һ��ǧ����䡢�����Ե�
ɽ�壬Χ��һ���Ĺȣ�����һ����̶��Ȫˮ�ӷ�䱼�����£�����
й��ֱ����̶�����м�ֻС��������̶�߷��衣�˴���������ʪ
�������ķΣ�����ȴ�������κ����Եĳ�·����������ֻ���Ĵ�
תת(around)���ˡ�
LONG
        ); 
        set("exits", ([
        ]) );

        set("objects", ([
          "/quest/tulong/npc/hunter": 1, 
          "/quest/tulong/npc/spirit1": 3,
          "/quest/tulong/obj/kaolu": 1,
        ]) );

        setup();
}
void init()
{
   add_action("do_west", "west");
   add_action("do_around", "around");

}

int do_around(string arg)
{
   object me, room;

   me = this_player(); 
   if (random(20)<10)
   { 
   tell_object(me, "��ת��תȥ��Ҳû�ҵ����ڣ�������·����\n\n");
   room = find_object(__DIR__"spirit0");
   if(!objectp(room)) room=load_object(__DIR__"spirit0");
   me->move(room);
   return 1;
   }
   else  
   tell_object(me, "�㷢�������ƺ�����·(west)��\n\n");
   return 1;
}
 
int do_west(string arg)
{
        object me;
        object room;
        me = this_player();
        message_vision("$N�����ߵ�������ȥ . \n", me);

        room = load_object(__DIR__"spirit3");
        if(room) me->move(room);

        return 1;
}

