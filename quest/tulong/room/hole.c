#include <room.h>
inherit ROOM;

void create()
{
      set("short","���ƿ�");
      set("long",@LONG
���ƹ����������㸡�����⴦Զɽ���Ȼ��������ɾ����������Ƕ�
���ƺ�����Խǧɽ����Ů�塣������������ұڵĶ��ߣ��ƺ�������ʲô
�����ء�
LONG);
      set("exits",([ /* sizeof() == 1 */
//          "up"  : "/d/xuansu/shanjiao",
          "west"  : __DIR__"ground",
      ]));
      set("objects",([
//                 "/d/xuansu/npc/qilin" : 1,
      ]));
      setup();
      create_door("west", "ʯ��", "east", DOOR_CLOSED);
}
