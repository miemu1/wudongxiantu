// Room: /city/beimen.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�տ��ֻ�");
	set("long", @LONG
�����տ��ֻ�ս������ʿ����ѹ�տܣ������л��ߣ���Զ���
LONG );
    
	set("exits", ([
		"northeast" : "/d/city/guangchang",
		

	]));

	set("outdoors", "city");
	setup();
}

