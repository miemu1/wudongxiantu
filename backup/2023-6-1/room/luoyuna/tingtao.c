// File(/data/room/luoyuna/tingtao.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "���θ�");
	set("long", "��������һ�ǵ����θ�������紵��Ҷ�������������ķǳ���
�У����������Ŀ�������ʵ����һ�������书�ĺ�ȥ����
");

	set("exits", ([
		"west" : __DIR__"zhulin",
	]));

	set("sleep_room", 1);
	setup();

        set("research_improve", 15);  //15% improved
    
        set("room_owner", "���");
        set("room_name", "С�׾�");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "�����Ľ�");
}
