// File(/data/room/luoyuna/jusuo.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "����");
	set("long", "�����С�׾����˴����Ϣ������ĵط���¥�Ͼ������˵����ң�
���������鷿��
");

	set("exits", ([
		"up"   : __DIR__"woshi",
		"west" : __DIR__"shufang",
	]));

	set("no_sleep_room", 1);
	setup();

        set("KEY_DOOR", ([
    	    "exit" : "east",
    	    "room" : __DIR__"huayuan",
        ]));
    
        set("room_owner", "���");
        set("room_name", "С�׾�");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "�����Ľ�");
}
