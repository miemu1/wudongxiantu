inherit ROOM;

void create()
{
        set("short", "�����Ͻ�");
        set("long", @LONG
�������ϴ���ˣ�������һ�ҵ��̣�ǽ��д��һ�����ġ�����
�֣���ϸ��������������ѹ�͵��ּۻ��۵�������������һ��Ǯׯ��
��ʱ����Ǯ�������Ķ�������
LONG );
        set("outdoors", "city2");
        set("no_fly",1);

        set("exits", ([
                "north" : __DIR__"nandajie2",
                "south" : __DIR__"chengmen",
        ]));  
        set("objects", ([
//                "/d/shaolin/npc/tiao-fu" : 1,
//                "/maze/battle3/npc/xiaofan" : 1,
        ]));

        setup();
  }
