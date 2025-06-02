// Room: /city/kefang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "���ſ͵��¥");
        set("long",
"����һ��ܴ�Ŀͷ�������ʮ�ּ�ª����ǽ����ʮ����Сľ��������\n"
"���������¶��ԣ������Ӷ��Ǻ����Ĵ������������Ŵ��ǿյģ�������\n"
"��ŵ����˹�ȥ��\n"
);

        
        set("valid_startroom", 1);
        set("sleep_room", "1");
        set("no_fight", "1");
        set("hotel",1);

        set("exits", ([
                "down" : __DIR__"kedian",
        ]));

        set("area", "����");

        setup();
}

int valid_leave(object me, string dir)
{
        if ( dir == "down" ) me->delete_temp("rent_paid");

        return ::valid_leave(me, dir);
}



