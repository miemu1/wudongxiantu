// File(/data/room/luoyuna/zhulin.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "����");
	set("long", "�������źô�һƬ���֣��ǳ��ľ�����һ�������Ҷɳɳ���죬
��ʱ��׾�ȥ���θ�Ĭ�����������������书��
");

	set("exits", ([
		"west" : __DIR__"huayuan",
		"east" : __DIR__"tingtao",
	]));

	set("outdoors", "hell");
	set("sleep_room", 1);
	setup();

        set("room_owner", "���");
        set("room_name", "С�׾�");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "�����Ľ�");
}
