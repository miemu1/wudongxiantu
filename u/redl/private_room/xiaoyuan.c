// File(/data/room/redl/xiaoyuan.c) of redl's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "����СԺ");
	set ("long", @LONG
������һ�����ķ�����Ժ�ӣ�Ժǽ�����ú�ש���ɣ�����ߣ���
�Ƿǳ���ˬ���䡣Ժ�м��ù�ľ������Ȼ��һ��������Դ�ĸо���
Ժ��������Լ��Ϫ��С·��Ժ�ӵı�����һ��ľ�š� 
LONG );

        set("room_key", "1 of redl");
        setup();

        set("exits", ([
                "out"    : "/d/chengdu/path1",
        ]));

        set("outdoors", "chengdu");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "��������");
        set("room_name", "����");
        set("room_id", "redl");
        set("room_owner_id", "redl");
        set("room_position", "Ϫ��С·");
}
