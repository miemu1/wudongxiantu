// File(/data/room/luoyuna/lianwu.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "���䳡");
	set("long", "�˴�����С�׾ӵ����䳡�����ڽ������书���򲻿ɻķϡ�
");

	set("exits", ([
		"west" : __DIR__"houyuan",
	]));

        set("objects", ([
    	    "/clone/npc/mu-ren" : 4,
        ]));

	set("outdoors", "hell");
	set("no_sleep_room", 1);

	setup();
    
        set("room_owner", "���");
        set("room_name", "С�׾�");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "�����Ľ�");
}
