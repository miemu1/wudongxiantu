// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "ɽ·");
        set ("long", @LONG
����һ��ͨ���Թ����ڵ�ɽ·��
LONG);


        set("exits", ([
        "south"    :       __DIR__"toby2",
        "west" :      "/d/xiangyang/caodi3",
        ]));

        set("outdoors", "12gong");
        setup();
}
