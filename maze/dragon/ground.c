#include <room.h>
inherit ROOM;

void init();
int do_climb(string arg);

void create()
{
      set("short","���ݵ�");
      set("long",
"�ҷ��Ĳݵأ��������滨��ݡ���һ���������(tree)�ڲ�ƺ���룬\n"
"�������ƺ���һ��������\n"
);
      set("exits",([ /* sizeof() == 1 */
          "southdown"  : __DIR__"bamboo1",
          "east"  : __DIR__"hole",
      ]));
      set("item_desc",([
                 "tree" :"��ɫ��������Ӳ�ޱȣ����Ǵ�˵�е��˲ι�����\n"
      ]));
      set("objects", ([
  //       "/d/shenlong/obj/hua4" : 2,
      ]));
      set("no_magic", 1);
	setup();
      create_door("east", "ʯ��", "west", DOOR_CLOSED);
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
      object me;
      me = this_player();
      if (!arg || arg != "tree")
   {
            return notify_fail("��Ҫ��ʲô��\n");
    }
        if ((int)me->query("qi") < 70)
                return notify_fail("��������㣬����������ȥ��\n");
        if ((int)me->query_skill("dodge", 1) < 130)
{
          message_vision("$N��������ȥ����������һ���һͷ����������\n\n",me);
            me->receive_damage("qi",60);
         return 1;
}
else
          message_vision("$N�ѵ�Ь�ӣ��������¾���������ȥ��\n\n",me);
            me->receive_damage("qi",60);
                  me->move(__DIR__"tree");
       return 1;
}

