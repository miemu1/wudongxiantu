// File(/data/room/luoyuna/chashi.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "����");
	set("long", "��һ������С�ɵĲ��ң������Եþ��¡�������һ�輸��������
������������Ů�������������˵ķԸ�(tea)��
");

	set("exits", ([
		"west"  : __DIR__"yingke",
	]));

        set("objects", ([
    	    "/d/room/roomnpc/teagirl" : 2,
        ]));

	create_door("west", "ľ��", "east", DOOR_CLOSED);

	set("no_sleep_room", 1);
	setup();

        set("room_owner", "���");
        set("room_name", "С�׾�");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "�����Ľ�");
}
