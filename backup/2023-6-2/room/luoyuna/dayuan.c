// File(/data/room/luoyuna/dayuan.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "С�׾Ӵ�Ժ");
	set("long", "����һ��������Ժ�䣬���Ÿ�����ľ������������͸������Ͷ��
���Ӱ�ӡ�һ����·ͨ�����棬�ȵ÷ǳ�ƽ���ģ������Ǿ���������
����
");

	set("exits", ([
		"north"  : __DIR__"qianting",
		"out"    : "/data/hell/4/wulinsi22",
	]));

	set("outdoors", "hell");
	set("no_sleep_room", 1);
	set("valid_startroom", 1);
	setup();

        set("room_owner", "���");
        set("room_name", "С�׾�");
        set("room_OWNER_id", "luoyuna");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "�����Ľ�");
}
