inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "��ԭ");
        set("long", @LONG
�����Ѿ������ӽ��ɹž�Ӫ�ˣ�����е��˴�����ǰ��Ȼ������
����������ȥ���Ĵ�����ãã��ݺ������˲���������һ����������
׳�ĸо���
LONG );
        set("outdoors", "xiangyang");
        set("no_magic",1);

        set("exits", ([
                "east"  : __DIR__"shanlu3",
                "west"  : __DIR__"shanlu3",
        ]));

        setup();
}

void init()
{
        object me=this_player();

        me->start_busy(random(2));


        if( query_temp("yidao/mark_steps", me)>11 )
        {
         me->move(__DIR__"caoyuan");
         delete_temp("yidao", me);
         tell_object(me,YEL"һ·�糾����֮���ɹŴ��ԭ�Ѿ�������ǰ��......\n"NOR);
         return;
        } 

        if( query_temp("yidao/mark_steps", me)<-11 )
        {
         me->move(__DIR__"dhunya");
         delete_temp("yidao", me);
         tell_object(me,YEL"һ·�糾����֮�󣬶ϻ����Ѿ�������ǰ��......\n"NOR); 
         return;
        }
        tell_object(me,HIG"��ָ���Ŵ�����н���ãã�Ĳ�ԭ��......\n"NOR);  
}

int valid_leave(object me,string dir)
{
       if( dir == "west" )
       addn_temp("yidao/mark_steps", -random(2), me);
       if(  dir == "east" )
       addn_temp("yidao/mark_steps", random(2), me);
       return ::valid_leave(me,dir);
}
