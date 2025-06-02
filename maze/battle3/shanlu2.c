inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�����Ѿ������������ˣ�������ȥ�������������۵�ɽ�������
�е��˴������󶼿�ʼ��Щ����������
LONG );
        set("outdoors", "xiangyang");
        set("no_magic",1);

        set("exits", ([
                "north"  : __DIR__"shanlu2",
                "south"  : __DIR__"shanlu2",
        ]));

        setup();
}

void init()
{
        object me=this_player();

        if (! me->is_busy())
        me->start_busy(random(2));


        if( query_temp("yidao/mark_steps", me)>11 )
        {
         me->move(__DIR__"dhunya");
         delete_temp("yidao", me);
         tell_object(me,YEL"һ·�糾����֮�󣬶ϻ����Ѿ�������ǰ��......\n"NOR);
         return;
        } 

        if( query_temp("yidao/mark_steps", me)<-11 )
        {
         me->move(__DIR__"wsling");
         delete_temp("yidao", me);
         tell_object(me,YEL"һ·�糾����֮����ʯ���Ѿ�������ǰ��......\n"NOR); 
         return;
        }

        tell_object(me,YEL"��ָ���Ŵ�����н������۵�ɽ����......\n"NOR); 
}

int valid_leave(object me,string dir)
{
       if( dir == "south" )
       addn_temp("yidao/mark_steps", -random(2), me);
       if(  dir == "north" )
       addn_temp("yidao/mark_steps", random(2), me);
       return ::valid_leave(me,dir);
}
