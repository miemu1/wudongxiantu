inherit ROOM;

#include <ansi.h>
void create()
{
      set("short", "竹径");
      set("long", @LONG
这里是一段落满青苔的青石板小路，右边是流水回萦，小桥略
陈，左边是竹树掩映，山花浪漫，真个是幽深静谧，秀丽清朗。
向北是一片草地，远远地似乎就已经闻到了花香。
LONG );
      set("outdoors", "nightstar");
      set("no_fight", "1");
      set("no_steal", "1");
      set("exits", ([
            "south"   : __DIR__"bamboo",
            "northup": __DIR__"ground",
            "north"   : __DIR__"bamboo1",
      ]));
}

int valid_leave(object me, string dir)
{
      int c_exp,c_skill;
        me = this_player();
      if (dir == "north")
      {
        if ((int)me->query("qi") < 50)
                return notify_fail("悠着点，小心身体。\n");
             c_exp=me->query("combat_exp");
             c_skill=me->query_skill("dodge",1);
             if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<301))
                   me->improve_skill("dodge", (int)me->query_skill("dodge", 1)*10);
            me->receive_damage("qi",30);

             tell_object(me,"你在竹林里悠闲地漫步，竟对轻功修为有所领悟。\n");
      }
        return 1;
}
