inherit ROOM;

void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
һ���谵��ʪ�ĵص����ص��ܳ������ߵ���������̫�����Ļ�ѣ�
���һ����൱�ѿ�����ӿ�Ų�����֪���ص��ľ�ͷ��ʲô�ط��� 
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                "west" : __DIR__"room1",
                "north" : __DIR__"room8",
                "east" : __DIR__"room3",
        ]));
        set("no_update", 1);

        setup();
}
//�Ǿ���
int is_jfb() { return 1; }

