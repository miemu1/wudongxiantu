#include <room.h>
inherit ROOM;

void create()
{
      set("short","���ƿ�");
      set("long",
"���ƹ����������㸡�����⴦Զɽ���Ȼ��������ɾ����������Ƕ�\n"
"���ƺ�����Խǧɽ����Ů�塣������������ұڵĶ��ߣ��ƺ�������ʲô\n"
"�����ء�\n"
);
      set("exits",([ /* sizeof() == 1 */
//          "up"  : "/d/xuansu/shanjiao",
          "west"  : __DIR__"ground",
      ]));
      set("objects",([
//                 "/d/xuansu/npc/qilin" : 1,
      ]));
      set("no_magic", 1);
	setup();
      create_door("west", "ʯ��", "east", DOOR_CLOSED);
}

