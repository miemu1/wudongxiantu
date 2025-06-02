// File(/data/room/luoyuna/huayuan.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
	set("short", "��԰");
	set("long", "����С�׾ӵĺ�԰������һЩ��ײ�������ĺ�����ɽ�󴨵�
�滨��ݣ������ǳ��������ʱ��������ƣ���ˣ��͵�����������Ϣ��
���ͻ������������֣�������ͻ����У����������������ͨ����
�˾��������ţ���������һƬ���֡�
");

	set("exits", ([
		"south"  : __DIR__"houyuan",
		"east"   : __DIR__"zhulin",
	]));

	set("outdoors", "hell");
	set("sleep_room", 1);
        set("room_key", "1 of luoyuna");
	setup();

        set("KEY_DOOR", ([
    	    "exit" : "west",
    	    "room" : __DIR__"jusuo",
        ]));
    
        set("room_owner", "���");
        set("room_owner_id", "luoyuna");
        set("room_name", "С�׾�");
        set("room_id", "xiaobai");
        set("room_position", "�����Ľ�");
}

void init()
{
        ::init();
	add_action("do_sit", "sit");
	this_player()->delete_temp("has_sit");
}

int do_sit(string arg)
{
	object me;

	me = this_player();
	if (me->query_temp("has_sit"))
	{
		message_vision("$N��������ҡ��ҡ���ò���⡣\n", me);
		return 1;
	}

	message_vision("$N���˵ĵط���������������ȥ���ɶ��ˡ�\n", me);
	me->set_temp("has_sit", 1);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("has_sit"))
	{
		message_vision("$N����������վ��������\n", me);
		me->delete_temp("has_sit");
	}

	return ::valid_leave(me, dir);
}
