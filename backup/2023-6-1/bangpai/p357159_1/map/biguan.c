// by ranger_����
// banghui.c
//#include <bangpai.h>

inherit ROOM;

void create()
{
	set("short", "�չ���");
	set("long", "�����ǰ������ֵܱչصĵط��������쳣��");
	set("exits", ([
		"south" : __DIR__"guangchang",
	]));
		set("bangpai_room","1");
    set("close_room", 1);
	set("no_fight","1");
	set("bangpai/biguan",1);
	setup();
}

