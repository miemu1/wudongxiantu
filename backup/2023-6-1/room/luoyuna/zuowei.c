// File(/data/room/luoyuna/zuowei.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        object ob;

        set("short", "С�׾�������");
	set("long", "�����������ᣬ�ǿ���С�׾Ӵ��ŵļҶ����ڵĵط���
");

	set("exits", ([
		"west"   : __DIR__"qianting",
	]));

        set("objects", ([
    	    "/d/room/roomnpc/shouwei" : 2,
        ]));

	set("no_sleep_room", 1);
	setup();

        ob = present("shou wei", this_object());
        ob->set("coagents", ({
    	    ([ "startroom" : __DIR__"zuowei",
    	       "id"	: "shou wei 1" ]),
    	    ([ "startroom" : __DIR__"zuowei",
    	       "id"	: "shou wei 2" ]),
    	    ([ "startroom" : __DIR__"youwei",
    	       "id"	: "shou wei 2" ]),
    	    ([ "startroom" : __DIR__"youwei",
    	       "id"	: "shou wei 1" ]),
        }));

        ob = present("shou wei 2", this_object());
        ob->set("coagents", ({
    	    ([ "startroom" : __DIR__"zuowei",
    	       "id"	: "shou wei 1" ]),
    	    ([ "startroom" : __DIR__"zuowei",
    	       "id"	: "shou wei 2" ]),
    	    ([ "startroom" : __DIR__"youwei",
    	       "id"	: "shou wei 2" ]),
    	    ([ "startroom" : __DIR__"youwei",
    	       "id"	: "shou wei 1" ]),
        }));

        set("room_owner", "���");
        set("room_name", "С�׾�");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "�����Ľ�");
}
