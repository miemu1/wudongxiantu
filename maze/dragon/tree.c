#include <room.h>
inherit ROOM;

void create()
{
      set("short","����");
      set("long",
"�����˲ι����ϡ�֦Ҷ������գ�һ��һ��Ľ������Ҷ����˸����\n"
"ϸ������ԭ������һ����С���ӵĹ��ӣ���ص����������˲ι���\n"
);
      set("exits",([ /* sizeof() == 1 */
          "down"  : __DIR__"ground",
      ]));
      set("objects", ([
//           "/d/wudang/obj/renshenguo"   : 2,
      ]));
      set("no_magic", 1);
	setup();
}

