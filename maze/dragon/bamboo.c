#include <room.h>
inherit ROOM;

void create()
{
      set("short","������");
      set("long",
"���廨԰��������֣���ҹ����ʱ�����������ڡ�����ϸ�裬���\n"
"΢���������ڴˣ�����֮���Ŷ�ʱ������ɢ��\n"
);
      set("exits",([ /* sizeof() == 1 */
          "west"  : __DIR__"bamboo2",
          "north"  : __DIR__"bamboo1",
      ]));
      set("no_magic", 1);
	setup();
}

