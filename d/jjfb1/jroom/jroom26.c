inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
һ���谵��ʪ�ĵص����ص��ܳ������ߵ���������̫�����Ļ�ѣ�
���һ����൱�ѿ�����ӿ�Ų�����֪���ص��ľ�ͷ��ʲô�ط��� 
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                "west" : __DIR__"jroom25",
                "south" : __DIR__"jroom20",
                "east" : __DIR__"jroom27",
        ]));
        set("no_update", 1);

        setup();
}
//�Ǿ���
int is_jjfb() { return 1; }

