inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
һ���谵��ʪ�ĵص����ص��ܳ������ߵ���������̫�����Ļ�ѣ�
���һ����൱�ѿ�����ӿ�Ų�����֪���ص��ľ�ͷ��ʲô�ط��� 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "west" : __DIR__"jroom15",
                "south" : __DIR__"jroom10",
                "north" : __DIR__"jroom22",
                "east" : __DIR__"jroom17",
        ]));
        set("no_update", 1);

        setup();
}
//�Ǿ���
int is_jjfb() { return 1; }

