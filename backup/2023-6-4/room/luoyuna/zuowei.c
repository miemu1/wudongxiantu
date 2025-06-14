// File(/data/room/luoyuna/zuowei.c) of luoyuna's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        object ob;

        set("short", "小白居左卫舍");
	set("long", "这里是左卫舍，是看护小白居大门的家丁放哨的地方。
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

        set("room_owner", "大白");
        set("room_name", "小白居");
        set("room_id", "xiaobai");
        set("room_owner_id", "luoyuna");
        set("room_position", "武林四街");
}
