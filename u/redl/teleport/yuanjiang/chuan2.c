//redl 2015
inherit __DIR__"normal.c"; 

void create()
{
        set("short", "��ɽ�");
        set("long", @LONG
����ǹ�ɽ����Ӵ�Ĵ���Ⱥ���ڲ���ͨ�˴��Ҫ���ĵر������£�
��Ը�����������Ķᱦ���鰡��
LONG );
//         set("exits", ([
//                 "south" : __DIR__"chuan" + (string)random(50),
//                 "north" : __DIR__"chuan" + (string)random(50),
//                 "west" : __DIR__"chuan" + (string)random(50),
//                 "east" : __DIR__"chuan" + (string)random(50),
//         ]));
//              map_delete(query("exits"),keys(query("exits"))[random(sizeof(query("exits")))]);
//              if (random(3))
//                      map_delete(query("exits"),keys(query("exits"))[random(sizeof(query("exits")))]);
//              if (random(2))
//                      map_delete(query("exits"),keys(query("exits"))[random(sizeof(query("exits")))]);
//              if (sizeof(query("exits"))==1){
//                      while(strsrch(__FILE__, query("exits")[keys(query("exits"))[0]])!=-1) {
//                              set("exits", ([keys(query("exits"))[0] : __DIR__"chuan" + (string)random(50),]));
//                      }       
//              }
        set("objects", ([ 
                "/clone/fam/max/zaohua" : (random(4) ? 1+random(3) : 0),
                "/d/dongtian/obj/wanxiangbook" : (!random(20) ? random(8)+1 : 0),
                //"/clone/tessera/rune" + to_string(28 + random(4)) : (!random(20) ? 1 : 0),
                "/clone/money/yuanbao" : (!random(4) ? random(30)+1 : 0),
                
        ])); 
        set("stop_run", random(10));
                set("no_protect", 1);
                set("no_rideto", 1);
                set("no_flyto", 1);
                set("no_fly", 1);
                set("no_sleep_room", 1); 
                set("yuan_ci_num", (random(2) ? random(2) + 1 : 0));
                
        setup();
}

int user_cant_unconcious(object me)
{
        if (!playerp(me)) {
                return 0;
        }
        me->die();
    return 1;
}
