// File(/data/room/luoyuna/zuoxiang.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "���᷿");
	set("long", "����С�׾ӵ����᷿���ǿ��˾�ס�ĵط�����Ȼ�����ݻ���ȴҲ
���õ÷ǳ����ʡ�һ�Ŵ�����ɾ���û�ж������ƣ�����������ʵ��
ʹ���ڹ���ǡ���ô���
");

	set("exits", ([
		"west" : __DIR__"zhongting",
	]));

	set("sleep_room", 1);
	set("no_fight", 1);

	create_door("west", "ľ��", "east", DOOR_CLOSED);

        set("room_owner", "���");
        set("room_name", "С�׾�");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "�����Ľ�");
}
