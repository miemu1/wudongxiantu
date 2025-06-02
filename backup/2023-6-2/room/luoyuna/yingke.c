// File(/data/room/luoyuna/yingke.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "С�׾�ӭ����");
	set("long", "������С�׾ӵ����˴��ӭ�Ӱ˷����͵ĵط����󷲿������ݼ�
��ף��ٲ��������ﺮ���𻰣��˾���Ľ֮�顣����ͨ��һ�����ң�
��������ͬ����Ʒ����������֮����
");

	set("exits", ([
		"north"  : __DIR__"yishiting",
		"south"  : __DIR__"zoudao",
		"east"   : __DIR__"chashi",
	]));

	create_door("east", "ľ��", "west", DOOR_CLOSED);

        set("objects", ([
    	    "/d/room/roomnpc/yahuan" : 2,
        ]));

	set("no_sleep_room", 1);
	setup();

        set("room_owner", "���");
        set("room_name", "С�׾�");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "�����Ľ�");
}
