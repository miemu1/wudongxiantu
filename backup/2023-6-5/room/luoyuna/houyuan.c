// File(/data/room/luoyuna/houyuan.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", "����С�׾ӵĺ�Ժ������һ����ɽ����Ȼ�������ǳ���ΰ������
һˮ�أ���ɽ���ߣ���Ȼ��Ϣ��������������֮���������ǳ�����
");

	set("exits", ([
		"south" : __DIR__"zhongting",
		"north" : __DIR__"huayuan",
		"east"  : __DIR__"lianwu",
		"west"  : __DIR__"chufang",
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
