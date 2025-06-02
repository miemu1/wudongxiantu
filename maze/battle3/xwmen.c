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
    []==[]__|__|__|__|__|__|_��"MAG"������"NOR"��__|__|__|__|__|__|_[]==[]
    []==[]|__|__|__|__|__|__|����������_|__|__|__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_/        \\__|__|__|__|__|__|_[]==[]
    []==[]_|__|__|__|__|__|__|        |_|__|__|__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_|        |__|__|__|__|__|__|_[]==[]
    []==[]_|__|__|__|__|__|__|        |_|__|__|__|__|__|__[]==[]\n\n" 
);
        set("outdoors", "city2");
        set("no_fly",1);

        set("exits", ([
                "north"    : __DIR__"hgdadao4",
                "south"    : __DIR__"hgdadao3",
        ]));

        set("objects", ([
                __DIR__"npc/jinyiwei" : 3,   
                __DIR__"npc/shiwei" : 4,
                __DIR__"npc/zongguan" : 1,     
        ]));
        setup();
} 

int valid_leave(object me,string dir)
{
       object *env,room;
       int i;

       room=this_object();
       if( userp(me) && query("degree_jungong", me)<8 )
       {
        env=all_inventory(room);
        for(i=0;i<sizeof(env);i++)
        if( query("id", env[i]) == "jinyiwei" )
          {
           env[i]->command("say "+"�󵨿�ͽ����Ȼ�ҵ���������Ұ�������ɣ�\n");
           env[i]->kill_ob(me);
          } 
       }
       return ::valid_leave(me,dir);
}
