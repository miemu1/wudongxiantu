#include <room.h>
inherit ROOM;

void create()
{
      set("short","树上");
      set("long",@LONG
这是人参果树上。枝叶遮天蔽日，一点一点的金光在树叶间闪烁。
仔细看看，原来是象一个个小孩子的果子，天地的至宝——人参果！
LONG);
      set("exits",([ /* sizeof() == 1 */
          "down"  : __DIR__"ground",
      ]));
      set("objects", ([
            "/d/wudang/obj/renshenguo"   : 2,
      ]));
      setup();
}
