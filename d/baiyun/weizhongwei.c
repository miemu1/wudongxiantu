// jiulou.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "东大街");
	set("long", @LONG
这里是一条宽阔的青石板街道，向东西两头延伸。
LONG);
	set("exits", ([
	    //"west"  : __DIR__"nandajie",
	    //"north"  : __DIR__"chufang",
		"east"    : __DIR__"dongdajie",
		"west"    : __DIR__"nandajie",
	]));
	set("objects", ([
	   // __DIR__"npc/xiaoer3" : 1,
	]));
	set("item_desc", ([
	   // "【牌子】" : "
//佛跳墙(Fotiaoqiang)   ：五两白银
//福建老酒(Jiuping)     ：二两白银\n",
	]));
	set("outdoors", "by");
	setup();
}

