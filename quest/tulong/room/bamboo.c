#include <room.h>
inherit ROOM;

void create()
{
      set("short","紫竹林");
      set("long",@LONG
锦绣花园后的紫竹林，是夜辰闲时休憩常到的所在。紫竹细疏，
清风微拂。漫步于此，世事之纷扰顿时烟消云散。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "west"  : __DIR__"bamboo2",
          "north"  : __DIR__"bamboo1",
      ]));
      setup();
}
