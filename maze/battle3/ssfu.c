inherit ROOM;

void create()
{
        set("short", "���鸮");
        set("long", @LONG
�����Ǿ������鸮�ˣ����������Դ��˾����������ͣ��ͽӼ�
�������ݾ����ǰ��ʹ�ߡ�
LONG );
        set("outdoors", "city2");
        set("no_fly",1);

        set("exits", ([
                "west" : __DIR__"ssfmen",
        ]));

        set("objects", ([
               __DIR__"npc/zhao":  1,
        ]));

        setup();
        replace_program(ROOM);
 }
