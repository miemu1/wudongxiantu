inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "������");
        set("long",
"\n"
"                         s________________s
                        /LLLLLLLLLLLLLLLLLL\\
    []__[]             ^^||======||======||^^             []__[]
    []==[]_[]__[]__[]__[]||[]__[]||[]__[]||[]__[]__[]__[]_[]==[]
    []==[]|__|__|__|__|__|__|����������_|__|__|__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_��"HIW"������"NOR"��__|__|__|__|__|__|_[]==[]
    []==[]|__|__|__|__|__|__|����������_|__|__|__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_/        \\__|__|__|__|__|__|_[]==[]
    []==[]_|__|__|__|__|__|__|        |_|__|__|__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_|        |__|__|__|__|__|__|_[]==[]
    []==[]_|__|__|__|__|__|__|        |_|__|__|__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_|        |__|__|__|__|__|__|_[]==[]
    []==[]_|__|__|__|__|__|__|        |_|__|__|__|__|__|__[]==[]\n\n" 
);
        set("outdoors", "city2");
        set("no_fly",1);

        set("exits", ([
                "north"    : __DIR__"hgdadao1",
                "south"    : __DIR__"center",
                "east" : __DIR__"ssfmen",
        ]));

        set("objects", ([
                __DIR__"npc/jinyiwei" : 3,   
        ]));
        setup();
}

int valid_leave(object me,string dir)
{
       object *env,room;
       int i;

       room=this_object();
       if( userp(me) && query("degree_jungong", me)<8 && dir == "north" )
       {
        addn_temp("voilet_hg", 1, me);
        if( query_temp("voilet_hg", me)<3 )
        {
         if( query("degree_jungong", me) )
         return notify_fail(
         "������һ����ס��������˹ٵ�λ��������ܹ�������ʥ��\n");
         else
         return notify_fail(
         "������һ����ס������������ĵ��񣬻���������ȥ�������ݹֵ������飡\n");
        } else
        {
         if( query_temp("voilet_hg", me) == 3 )
         { 
          env=all_inventory(room);
          for(i=0;i<sizeof(env);i++)
          {
           if( query("id", env[i]) == "jinyiwei" )
           env[i]->kill_ob(me);
          }
          return notify_fail(HIR"�����һ�ᣬ���������ʹ���\n"NOR); 
         }
        }
      }
      return ::valid_leave(me,dir);
}
