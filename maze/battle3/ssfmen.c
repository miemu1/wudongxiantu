inherit ROOM;

void create()
{
        set("short", "���鸮����");
        set("long", @LONG
�����Ǿ������鸮���ţ��������˽������ɼ��������Ϊ���²�
�ͺε�֮�����ˣ��ſ��������ҽ��������������ȻҲû�������㣬
������֡�
LONG );
        set("outdoors", "city2");
        set("no_fly",1);

        set("exits", ([
                "west" : __DIR__"ydmen",
                "east" : __DIR__"ssfu",
        ]));

        set("objects", ([
  
        ]));

        setup();
        replace_program(ROOM);
}

