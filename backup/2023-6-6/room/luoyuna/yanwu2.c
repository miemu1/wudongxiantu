// File(/data/room/luoyuna/yanwu2.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "С�׾�������");
	set("long", "����С�׾ӵ�����������ʱ��Щ�����������ᣬ��һ�����֣���
��������������
");

	set("exits", ([
		"east" : __DIR__"yishiting",
	]));

        set("objects", ([
    	    "/clone/weapon/zhubang" : 1,
    	    "/clone/weapon/zhujian" : 1,
    	    "/clone/weapon/mudao"   : 1,
        ]));

	set("no_sleep_room", 1);
	setup();

        set("room_owner", "���");
        set("room_name", "С�׾�");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "�����Ľ�");
}
